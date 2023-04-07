/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6GSi5LjsU"
#define BLYNK_TEMPLATE_NAME "miniproject"
#define BLYNK_AUTH_TOKEN "SG5qu3n_z9vbSPZwnHpYgibnmsEWfba4"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

//pin
//#define relay D0
//#define senser A0
int Relay = D0;
int watersensor = D6;
int val = 0;


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Coming Soon_2.4GHz";
char pass[] = "060445Pop";


BLYNK_WRITE(V1){
  int relayIn = param.asInt();
  Serial.println(relayIn);  
  if(relayIn == 1){
    digitalWrite(Relay, HIGH);
  }
  else{
    digitalWrite(Relay, LOW);    
  }    
  //blynk.virtualWrite(D0, value)
}
BLYNK_WRITE(V0){
  int water = param.asInt();
  digitalWrite(Relay, LOW);
  if(water == 1){
    while(true) {
      val = digitalRead(watersensor);
      Serial.println(val);      
      if(val == 1){
        digitalWrite(Relay, LOW);
        Serial.println("เปิดน้ำ");
      }
      else if (val == 0){
        digitalWrite(Relay, HIGH);
        Blynk.virtualWrite(V0, 0);
        Serial.println("ปิดน้ำ");
        break;
      }
      delay(1000);  
    }
  } 
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  digitalWrite(Relay, LOW);
  pinMode(Relay, OUTPUT);
   
  //pinMode(relay, INPUT);

}

void loop()
{

  Blynk.run();

}


