/*Description voir C:\Users\Stephan\Desktop\Projet arduino\Projet arduino.txt */
/*Modele 3D voir C:\Users\Stephan\Desktop\Projet arduino\Cave a vin arduino.stl */
// Version 0.0  22/06/2018
// Version 0.1  20/07/2018 ( En France )
// Version 0.2  04/08/2018

#include <DHT.h> //Inclusion de la librarie DHT.
#define DHTPIN 4 //Definition du pin pour le DHT11(Pin 4)
#define DHTTYPE DHT11
DHT dht (DHTPIN,DHTTYPE);
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,20,4); //Definition du tipe de lcd (20x4)
int lm35_h = 2; //Capteur lm35 superieur dans le pin 2.
int lm35_b = 3; //Capteur lm35 inferieur dans le pin 3.

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  dht.begin();
  lcd.setCursor(0,0);
  lcd.print("Allumage en cours");
  lcd.setCursor(0,1);
  lcd.print("V 0.1");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ETAT: "); //Systeme actif ou pas.
  lcd.setCursor(0,1);
  lcd.print("TEMPERATURE: "); //Moyenne de la temperature.
  /*lcd.setCursor(0,2);
  lcd.print("HUMIDITE: "); //Humidite.*/  //Pas asez de resources pour implementation hardware.
  lcd.clear();
}

void loop() {
  
}

float lecture_lm35(int lm){ // A remplacer par la fonction correspondante au capteur utilisse.
  int valcapteur = analogRead(lm);
  float temperature =  (valcapteur * (5.0 / 1024 * 100.0));
  return temperature;
}
float lecture_dht11(){
  float temperature = dht.readTemperature();
  float humidite = dht.readHumidity();
  if(isnan(temperature) || isnan(humidite)){
    return 0.0;
  }
  else{
    return temperature,humidite;
  }
}
