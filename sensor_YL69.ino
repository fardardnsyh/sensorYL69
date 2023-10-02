#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


const int sensor = A0; //inisialisasi pin sensor A0
const int pompa = 8;       // inisialisasi pompa pin pada 8
const int buzzer = 2;     // inisialisasi buzzer pin pada 2

void setup() {
Serial.begin(9600);
lcd.init();
lcd.backlight();
lcd.clear();
pinMode(sensor, INPUT);   //menetapkan pin A0 sebagai input sensor kelembaban analog
pinMode(pompa, OUTPUT);   //menetapkan pin 8 sebagai output
pinMode(buzzer, OUTPUT);  //menetapkan pin 2 sebagai output

}

void loop() {
int dataAnalog = analogRead (sensor);  //membaca nilai dari pin sensor
Serial.print ("A0 : ");
Serial.print (dataAnalog);

//jika nilai A0 kurang dari 500, print kata dan menampilkan nilai dan kata di lcd serta matikan Buzzer dan pompa 
if (dataAnalog < 500) {     //nilai awalnya 500 (jika nilainya kecil/500 dan tanah sedikit basah maka pompa/relay dan buzzer off)
  Serial.println(". Media Masih Basah"); 
  digitalWrite(buzzer, LOW);
  digitalWrite(pompa, HIGH);
  lcd.setCursor(5, 0);
  lcd.print("A0 : ");
  lcd.print(dataAnalog);
  lcd.setCursor(4, 1);
  lcd.print("Media Masih Basah");
  delay(2000);
  lcd.clear();  
  }

 //tetapi, jika nilai A0 kurang dari 800, print kata dan menampilkan nilai dan kata di lcd serta matikan Buzzer dan pompa 
 else if (dataAnalog  < 800) { //nilai awalnya 800 (jika nilainya kecil/800 dan tanah masih cukup basah maka pompa/relay dan buzzer off)
   Serial.println(". Kelembaban Tanah Masih Cukup"); 
    digitalWrite(buzzer, LOW);
    digitalWrite(pompa, HIGH);
  lcd.setCursor(2, 0);
  lcd.print("A0 : ");
  lcd.print(dataAnalog);
  lcd.setCursor(1, 1);
  lcd.print("Kelembaban Tanah Masih Cukup");
  delay(1000);
  lcd.clear();  
      
 }

 //selain dari itu, hanya nyalakan buzzer dan pompa air
 else { 
  Serial.println (". Perlu Tambahan Air"); 
  digitalWrite(buzzer, HIGH);
  digitalWrite(pompa, LOW);
  lcd.setCursor(1, 0);
  lcd.print("A0 : ");
  lcd.print(dataAnalog);
  lcd.setCursor(2, 1);
  lcd.print("Perlu Tambahan Air");
  delay(6000);
  lcd.clear();  
    
 }
 
  }
