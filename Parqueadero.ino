#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int dueno = "Sr. Rios ";
int vershon = "parking v0.2";

int trig = 9;
int eco = 8;
int led_verde = 4;
int led_amarillo = 3;
int led_rojo = 2;
int led_med = 5;
int duracion;
int distancia;

void setup()
{

  lcd.init();
  lcd.backlight();
  lcd.setBacklight(HIGH);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bienvenido ");
  lcd.setCursor(0, 1);
  lcd.print(dueno);
  delay(3000);
  lcd.clear();
  lcd.print("Asistente de  ");
  lcd.setCursor(0, 1);
  lcd.print(vershon);
  delay(3000);
  lcd.clear();

  // configuracion del sensor
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  // configuracion de las luces
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarillo, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_med, OUTPUT);

  Serial.begin(9600);
}

void loop()
{

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duracion = pulseIn(eco, HIGH);
  distancia = duracion / 58.2;
  Serial.print("distancia:");
  Serial.println(distancia);
  lcd.clear();
  lcd.print("DISTANCIA: ");
  lcd.print(String(distancia));
  lcd.setCursor(0, 1);
  lcd.print("Duracion:");
  lcd.print(String(duracion));
  delayMicroseconds(50);

  
  if( distancia <=300){
   digitalWrite(led_med, HIGH);
   lcd.clear();
   lcd.print("DISTANCIA:");
   lcd.print(String(distancia));
   lcd.setCursor(14,0);
   lcd.print("cm");
   delay(1000);
  
  
  }
  
  if(distancia <300 && distancia >=100){
   digitalWrite(led_verde, HIGH);
   delay((distancia)*10);
   digitalWrite(led_verde, LOW);
   lcd.clear();
   lcd.print("DISTANCIA:");
   lcd.print(String(distancia));
   lcd.setCursor(14,0);
   lcd.print("cm");
   lcd.setCursor(0,1);
   lcd.print("  <------------>");
   delay(1000);
  }
  if(distancia < 100 && distancia >= 95){
   digitalWrite(led_verde, HIGH);
  
   lcd.clear();
   lcd.print("DISTANCIA:");
   lcd.print(String(distancia));
   lcd.setCursor(14,0);
   lcd.print("cm");
   lcd.setCursor(0,1);
   lcd.print("   <----------->");
   delay(1000);
  }
  
  if(distancia < 95 && distancia >= 90){
   digitalWrite(led_verde, HIGH);
   digitalWrite(led_amarillo, HIGH);
   delay((distancia)*10);
   digitalWrite(led_amarillo, LOW);
  
   lcd.clear();
   lcd.print("DISTANCIA:");
   lcd.print(String(distancia));
   lcd.setCursor(14,0);
   lcd.print("cm");
   lcd.setCursor(0,1);
   lcd.print("     <--------->");
   delay(1000);
  }
  
  if(distancia < 90 && distancia >= 95){
   digitalWrite(led_verde, HIGH);
   digitalWrite(led_amarillo, HIGH);
  
   lcd.clear();
   lcd.print("DISTANCIA:");
   lcd.print(String(distancia));
   lcd.setCursor(14,0);
   lcd.print("cm");
   lcd.setCursor(0,1);
   lcd.print("      <-------->");
  delay(1000);
  }
  if(distancia < 95 && distancia >= 10){
   digitalWrite(led_verde, HIGH);
   digitalWrite(led_amarillo, HIGH);
   digitalWrite(led_rojo, HIGH);
   delay((distancia)*100);
   digitalWrite(led_rojo, LOW);
  
   lcd.clear();
   lcd.print("DISTANCIA:");
   lcd.print(String(distancia));
   lcd.setCursor(14,0);
   lcd.print("cm");
   lcd.setCursor(0,1);
   lcd.print("        <------>");
   delay(1000);
  
  }
  if(distancia < 10 && distancia >= 2){
   digitalWrite(led_verde, HIGH);
   digitalWrite(led_amarillo, HIGH);
    digitalWrite(led_rojo, HIGH);
  
   lcd.clear();
   lcd.print("DISTANCIA:");
   lcd.print(String(distancia));
   lcd.setCursor(14,0);
   lcd.print("cm");
   lcd.print("DISTANCIA:");
   lcd.print(String(distancia));
   lcd.setCursor(14,0);
   lcd.print("cm");
   lcd.setCursor(0,1);
   lcd.print("          <---->");
   delay(1000);
  
  
   if(distancia < 3){
             lcd.clear();
   lcd.setCursor(0,1);
   lcd.print("******ALTO******");
   delay(5000);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("APAGUE EL AUTO");
   lcd.setCursor(0,1);
   lcd.print("CIERRE LA PUERTA");
   delay(5000);
  
       for(int tiempo = 0; tiempo <=10; tiempo ++){
     delay(1000);
    Serial.print("tiempo:");
     Serial.println(tiempo);
     if(tiempo >= 10 ){
         digitalWrite(led_verde, LOW);
         digitalWrite(led_amarillo, LOW);
         digitalWrite(led_rojo, LOW);
         for(int i=0; i<4 ; i++){
         digitalWrite(led_med, LOW);
         delay (1000);
         digitalWrite(led_med, HIGH);
     }
     digitalWrite(led_med, LOW);
   // colocar un delay para apagar todo y esperar el sensado de la puerta
     break;
    }
  }
   }
  
  }
  
}