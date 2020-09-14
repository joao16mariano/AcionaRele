#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>


// Set these to run example.
#define FIREBASE_HOST "joao-e0c75.firebaseio.com"
#define FIREBASE_AUTH "YQO4u3dec4TJ77NKImwekW3w4OiUPvMxC7gUOGk0"
#define WIFI_SSID "Joao10Mariano"
#define WIFI_PASSWORD "mariano75" 


int LAMP_PIN = D5; 
int LAMP_PIN1 = D3;  
int LAMP_PIN2 = D1;
int LAMP_PIN3 = D2;



//Define FirebaseESP8266 data object
//FirebaseData firebaseData;
FirebaseData lampValue;
FirebaseData lampValue1;
FirebaseData lampValue2;
FirebaseData lampValue3;

FirebaseJson json;


void setup()
{
  Serial.begin(9600);
 
  pinMode(LAMP_PIN,OUTPUT);
  digitalWrite(LAMP_PIN, HIGH); 
  
  pinMode(LAMP_PIN1,OUTPUT);
  digitalWrite(LAMP_PIN1, HIGH); 
  
  pinMode(LAMP_PIN2,OUTPUT);
  digitalWrite(LAMP_PIN2, HIGH); 
  
  pinMode(LAMP_PIN3,OUTPUT);
  digitalWrite(LAMP_PIN3, HIGH); 
  
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}


void loop() {
  
   if (Firebase.getString(lampValue, "/home/casa1")){
    Serial.println(lampValue.stringData());
    if (lampValue.stringData() == "true") {
    digitalWrite(LAMP_PIN, LOW);
    }
  else if (lampValue.stringData() == "false"){
    digitalWrite(LAMP_PIN, HIGH);
    }
  }
  delay(100);


  if (Firebase.getString(lampValue1, "/home/casa2")){
    Serial.println(lampValue1.stringData());
    if (lampValue1.stringData() == "true") {
    digitalWrite(LAMP_PIN1, LOW);
    }
  else if (lampValue1.stringData() == "false"){
    digitalWrite(LAMP_PIN1, HIGH);
    }
  }
  delay(100);

  if (Firebase.getString(lampValue2, "/home/casa3")){
    Serial.println(lampValue2.stringData());
    if (lampValue2.stringData() == "true") {
    digitalWrite(LAMP_PIN2, LOW);
    }
  else if (lampValue2.stringData() == "false"){
    digitalWrite(LAMP_PIN2, HIGH);
    }
  }
  delay(100);


   if (Firebase.getString(lampValue3, "/home/casa4")){
    Serial.println(lampValue3.stringData());
    if (lampValue3.stringData() == "true") {
    digitalWrite(LAMP_PIN3, LOW);
    }
  else if (lampValue3.stringData() == "false"){
    digitalWrite(LAMP_PIN3, HIGH);
    }
  }
  delay(100);
}
