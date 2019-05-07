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
    Serial.begin(9600);
  dht.begin();
  //Serial.println(scale.read());
  //scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  //scale.tare();

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
    delay(2000); //Delay 2 sec.
}

   