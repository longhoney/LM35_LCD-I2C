#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
//0x27 la dia chi man hinh trong bus I2C. Phan nay chung ta khong can phai qua ban tam vi hau het man hinh (20x4,...) deu nhu the nay!
//16 la so cot cua man hinh (neu dung loai man hinh 20x4) thi thay bang 20
//2 la so dong cua man hinh (neu dung loai man hinh 20x4) thi thay bang 4

byte temperature[8] = {
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000
};

int sensorPin = A0;// chan analog A0 ket noi voi chan tin hieu LM35

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  lcd.init();       //Khoi dong man hinh. Bat dau cho phep Arduino su dung man hinh, cung giong nhu dht.begin() trong chuong trinh tren
  
  lcd.backlight();   //Bat den nen
  lcd.print("Nhiet do: ");  //Xuat ra chu Hello world, mac dinh sau khi init thi con tro tai cot 0 hang 0 (trong C, khac voi quy uoc cua tieng Viet, moi chi so deu bat dau bang so 0, vi vay ban can hieu rang, neu ta ke mot bang co 2 hang va 16 cot thi o goc tren cung ben trai la o (0,0) tuong tu voi cac o khac, ta cu tang dan gia tri len!
  lcd.setCursor(0,1); //Dua con tro toi hang 1, cot 0
  lcd.print("Do am: ");// Ban thay tren man hinh roi chu?

  lcd.createChar(1, temperature);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A0:
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * 5.0 / 1024.0;
  float temperature = voltage * 100.0;
  // print out the value you read:
  Serial.println(temperature);
  delay(1000);  // 1000 milisecond = 1 second, delay in between reads for stability
}