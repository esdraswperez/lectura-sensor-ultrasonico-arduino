//Librerías
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Constantes
const int trigPin = 9;
const int echoPin = 10;

//Varialbles
long duracion;
int distancia;
int ultimaDistancia = 0;

//Objeto para el Display LCD
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion * 0.034) / 2;
  //Serial.println(distancia);
  
  if(distancia != ultimaDistancia)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Distancia: ");
    lcd.print(distancia);
    lcd.print(" cm");
    ultimaDistancia = distancia;
  }
  delay(500);
}
