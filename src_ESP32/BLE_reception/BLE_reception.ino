

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>


String valeur;

/* Creation of global variables */
BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;

"""
@TODO : 
- Creation d'une fonction 'recevoir message' qui ecoutera sur le bon pCharateristic  

- Preparation du swtich qui va renvoyer des données a des services

- Creations de nouveaux CHARATERISTIQUES qui auront des UUID diff 

- Creation d'une fonction/class d'init des charateristiques 
http://www.louisreynier.com/fichiers/ArduinoClasses.pdf
Compo de la classe:


BLEService *pService
BLECharacteristic *pCharacteristic
        pCharac->addDescriptor(new BLE2902());
        pCharac->setCallbacks(new MyCallbacks())

BLEAdvertising *pAdvertising
        pAdvert->addServiceUUID(SERVICE_UUID);
        pAdvert->setScanResponse(false);
        pAdvert->setMinPreferred(0x0);

"""
#define SERVICE_UUID        "ad98364f-23d7-44d6-b096-0435adc622ad"
#define CHARACTERISTIC_UUID "44fb90c4-cf6d-4adb-81cf-f3d2d56f7e19"

/* *Call back pour renvoyer des notifs */
class MyServerCallbacks: public BLEServerCallbacks 
{
    void onConnect(BLEServer* pServer) 
    {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {

      deviceConnected = false;
    }
};

/* Classe de Callback appelé a chaque interuption */
class MyCallbacks: public BLECharacteristicCallbacks 
{
    void onWrite(BLECharacteristic *pCharacteristic) 
    {
      std::string value = pCharacteristic->getValue();
      if (value.length() > 0) 
      {
        valeur = "" ;
        Serial.println("*********");
        Serial.print("Valeur entrée: ");
        for (int i = 0; i < value.length(); i++)
        {
          //Serial.print(value[i]);
          valeur = valeur + value[i] ;
        }
        Serial.println();
        Serial.println(valeur);
        Serial.println("*********");
      }
      if(value[0] == '1')
      {
        Serial.println("WOOOOOOOOW T'es dingue mec !!!!!");
      }
    }
};

void setup() {
  Serial.begin(115200);
  Serial.println("----------------------------------------------------------");
  Serial.println("Démarrage du Service de reception Bluetooth LE");
  Serial.println("Nom de Réseau: . . . . . . PIZZATOR");
  Serial.println("Type de donnée recu:");
  Serial.println(" . . . . . . . . . . . . . nb_part");
  Serial.println(" . . . . . . . . . . . . . xxxxxxx");
  
  // On init le device BLE 
  BLEDevice::init("PIZZATOR"); 

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);
  // On lui affecte des characteristique par default (UUID ...)
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE );

  pCharacteristic->addDescriptor(new BLE2902());
  pCharacteristic->setCallbacks(new MyCallbacks()); // On lui affecte une callback
  // Valeur par defaut dans la charachteristic de base:

  /* Demmarage du Service */
  pService->start();
  /* Début de  l'advertising */
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);  
  BLEDevice::startAdvertising();
  Serial.println("Attente d'une connection d'un client pour notify...");
}

void loop()
{

    if (deviceConnected) 
    {
         //std::string value = pCharacteristic->getValue();
         // On recupere la valeur 
      std::string val = "SALUT BGGGG" ;
      envoyer_val(pCharacteristic, val) ;
 
    }
    // disconnecting
    if (!deviceConnected && oldDeviceConnected) 
    {
        Serial.println("* * * * * * ¡End of Connection! * * * * * * ");
        delay(500); // give the bluetooth stack the chance to get things ready
        pServer->startAdvertising(); // restart advertising
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
    }
    // connecting
    if (deviceConnected && !oldDeviceConnected) 
    {
        Serial.println("* * * * * * ¡New Connection! * * * * * * ");
        // do stuff here on connecting
        oldDeviceConnected = deviceConnected;
    }
}

void envoyer_val(BLECharacteristic *pCharacteristic, std::string valeur_send)
{

    Serial.println("Valeur envoyer:");
    Serial.print(valeur_send.c_str());
    Serial.println();
    pCharacteristic->setValue(valeur_send); 
    pCharacteristic->notify();
    delay(10); // bluetooth stack will go into congestion, if too many packets are sent.

} 
