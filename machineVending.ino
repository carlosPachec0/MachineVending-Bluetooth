#include <Servo.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo1, servo2, servo3, servo4;   // DS04-NFC motors

#define coinDetector 9

#define button1 13
#define button2 12
#define button3 11
#define button4 10

int botonPresionado;
int estado = 0;

void setup() {
  
  Serial.begin(9600);
  
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);


  pinMode(coinDetector, INPUT);

  // Activating the digital pins pull up resistors
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bienvenido");
  lcd.setCursor(0,1);
  lcd.print("Ingeniero");
  delay(2500);
  lcd.clear();
 
  
}
void loop() {
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Inserta moneda");
  
  // espera a detectar moneda
  while (true) {
    if (digitalRead(coinDetector) == LOW) { // Si detecta moneda, manda a low y sale del bucle while
      break;
    }
  }
  
  delay(10);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Elige producto");
  lcd.setCursor(0, 1);
  lcd.print(" 1, 2, 3 o 4?");
  
  // Espera detectar que boton es presionado
  while (true) {

    if(Serial.available() > 0 || digitalRead(button2) == HIGH || digitalRead(button2) == HIGH || digitalRead(button3) == HIGH || digitalRead(button4) == HIGH)
    {
    estado = Serial.read();

      if(estado == 'a' || digitalRead(button1) == HIGH){
        botonPresionado = 1;
        break;
        }
      if(estado == 'b' || digitalRead(button2) == HIGH){
        botonPresionado = 2;
        break;
        }
      if(estado == 'c' || digitalRead(button3) == HIGH){
        botonPresionado = 3;
        break;
        }
      if(estado == 'd' || digitalRead(button4) == HIGH){
        botonPresionado = 4;
        break;
        }
    }
    
    /* if (digitalRead(button1) == HIGH) {
            botonPresionado = 1;
            break;
          }
          if (digitalRead(button2) == HIGH) {
            botonPresionado = 2;
            break;
          }
          if (digitalRead(button3) == HIGH) {
            botonPresionado = 3;
            break;
          }
          if (digitalRead(button4) == HIGH) {
            botonPresionado = 4;
            break;
    */
    }

  
  // Imprime "Surtiendo" 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Surtiendo");
   
  switch (botonPresionado) {
    case 1:
     
      servo1.writeMicroseconds(2000); // rotate
      delay(950);
      servo1.writeMicroseconds(1500);  // stop
      delay(500);
      
      break;
    
     case 2:
      
      servo2.writeMicroseconds(2000); // rotate
      delay(950);
      servo2.writeMicroseconds(1500);  // stop
      delay(500);
      
      break;

      case 3:
      
      servo3.writeMicroseconds(2000); // rotate
      delay(950);
      servo3.writeMicroseconds(1500);  // stop
      delay(500);
     
      break;

      case 4:
      
      servo4.writeMicroseconds(2000); // rotate
      delay(950);
      servo4.writeMicroseconds(1500);  // stop
      delay(500);
     
      break;
  }
  
  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("Producto"); 
  lcd.setCursor(0, 1);
  lcd.print("Entregado"); 
  delay(2000);
}
