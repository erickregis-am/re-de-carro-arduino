 

 #include <Wire.h>
 #include <LiquidCrystal_I2C.h>
 #include <Ultrasonic.h>

 LiquidCrystal_I2C lcd(0x27, 16, 2);
 Ultrasonic medicao(5,4);
 long distancia;
 long int tempo;
 
  
 
 void setup(){
    lcd.init();
    lcd.clear();

     
 }

 void loop(){
    distancia = medicao.Ranging(CM);
    
    lcd.setBacklight(HIGH);
    lcd.setCursor(0,0);
    lcd.print("Detectando...   ");
    lcd.setCursor(0,1);
    lcd.print("Distancia: ");
    lcd.print(distancia);
    lcd.print("cm");
    delay(100);
    
    while(distancia <= 10){
      distancia = medicao.Ranging(CM);
      delay(1);
      tempo++;
      lcd.setCursor(0,0);
      lcd.print("Perto demais!");
      lcd.setCursor(0,1);
      lcd.print("Distancia: ");
      lcd.print(distancia);
      lcd.print("cm");
      delay(100);
      tone(10, 494, tempo);
    }
    


 } 

