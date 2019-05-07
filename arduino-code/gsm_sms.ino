//Libraries
#include "DHT.h"
#include "hx711.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1);
//#define calibration_factor -7050.0
//Constants
#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

Hx711 scale(A1,A2);

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

const int AOUTpin=0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
//const int DOUTpin=8;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino

int limit;
int value;

void setup()
{
    mySerial.begin(9600);
    Serial.begin(9600);
  dht.begin();
  //Serial.println(scale.read());
  //scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  //scale.tare();
  delay(100);

}

void loop()
{
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    //Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %\n Temp: ");
    Serial.print(temp);
    Serial.print("Celsius\n");
    
    value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
    Serial.print("CO value: ");
    Serial.print(value/7.7);//prints the CO value
    Serial.print("\n");
    Serial.print("Weight: "); 
    Serial.print(scale.getGram(),1);
    Serial.println("g");
    if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());

    //delay(2000); //Delay 2 sec.
}



void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919971559931\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("I am SMS from GSM Module");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);
 }
   