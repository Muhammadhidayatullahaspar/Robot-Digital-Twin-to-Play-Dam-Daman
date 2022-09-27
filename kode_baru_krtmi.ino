#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <PS2X_lib.h>
PS2X ps2x;

int error = 0;
byte type = 0;
byte vibrate = 0;
#define ena1 8
#define in1 9
#define in2 10
#define enb1 13
#define in3 11
#define in4 12
#define ena2 2
#define in5 3
#define in6 4
#define enb2 7
#define in7 5
#define in8 6
int motorSpeedA1 = 0;
int motorSpeedB1 = 0;
int motorSpeedA2 = 0;
int motorSpeedB2 = 0;
int speedcar = 100;
int berhenti = 0;

#define PS2_DAT        22      
#define PS2_CMD        24   
#define PS2_SEL        26  
#define PS2_CLK        28  

Servo servo1;
Servo servo2;
Servo servo3;


void setup() {
  servo1.attach(30);
  servo2.attach(32);
  servo3.attach(34);
  servo1.write(25);
//*****************  lcd 16x2  ***********************************

  lcd.init();
  lcd.backlight();
  lcd.clear();
  Serial.begin(9600);
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT,true,true);
  for(int i=2; i<=9; i++){
    pinMode(i,OUTPUT);
  }


  pinMode(ena1, OUTPUT);
  pinMode(enb1, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ena2, OUTPUT);
  pinMode(enb2, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  
  delay(500);
  lcd.clear();

}


 void maju(){ 
           // ban 1
     Serial.print("Up held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
   //ban 2
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // ban 3
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
   //ban 4
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
    analogWrite(ena1, speedcar);
    analogWrite(enb1, speedcar);
    analogWrite(ena2, speedcar);
    analogWrite(enb2, speedcar);
    }
   
    void mundur(){
            Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
       //ban 1
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH);
       // ban 2
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);
        //ban 3
        digitalWrite(in5, LOW);
        digitalWrite(in6, HIGH);
        // ban 4
        digitalWrite(in7, LOW);
        digitalWrite(in8, HIGH);
        analogWrite(ena1, speedcar);
        analogWrite(enb1, speedcar);
        analogWrite(ena2, speedcar);
        analogWrite(enb2, speedcar);
       }

      void kanan(){
              Serial.print("Right held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
        // ban 1
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    //ban 2
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      // ban 3
      digitalWrite(in5, HIGH);
      digitalWrite(in6, LOW);
    //ban 4
      digitalWrite(in7, LOW);
      digitalWrite(in8, HIGH);
         analogWrite(ena1, 200);
        analogWrite(enb1, 200);
        analogWrite(ena2, 200);
        analogWrite(enb2, 200);
      }

       void kiri(){
              Serial.print("LEFT held this hard: ");
      Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
           // ban 1
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
   //ban 2
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // ban 3
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
   //ban 4
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
       analogWrite(ena1, 200);
        analogWrite(enb1, 200);
        analogWrite(ena2, 200);
        analogWrite(enb2, 200);
       }

       void putarkanan(){
              Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_CIRCLE), DEC);
       //ban 1
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH);
       // ban 2
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
        //ban 3
        digitalWrite(in5, LOW);
        digitalWrite(in6, HIGH);
        // ban 4
        digitalWrite(in7, HIGH);
        digitalWrite(in8, LOW);
           analogWrite(ena1, 120);
        analogWrite(enb1, 120);
        analogWrite(ena2, 120);
        analogWrite(enb2, 120);
       }

       void putarkiri(){
              Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_SQUARE), DEC);
       //ban 1
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       // ban 2
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);
        //ban 3
        digitalWrite(in5, HIGH);
        digitalWrite(in6, LOW);
        // ban 4
        digitalWrite(in7, LOW);
        digitalWrite(in8, HIGH);
             analogWrite(ena1, 120);
        analogWrite(enb1, 120);
        analogWrite(ena2, 120);
        analogWrite(enb2, 120);
       }

       void majukanan(){
        // ROBOT MAJU KANAN
      Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_START), DEC);
       //ban 1
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       // ban 2
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
        //ban 3
        digitalWrite(in5, HIGH);
        digitalWrite(in6, LOW);
        // ban 4
        digitalWrite(in7, LOW);
        digitalWrite(in8, LOW);
        analogWrite(ena1, 180);
        analogWrite(enb1, 180);
        analogWrite(ena2, 180);
        analogWrite(enb2, 180);
       }

   void majukiri() {  // ROBOT MAJU KIRI
      Serial.println(ps2x.Analog(PSB_SELECT), DEC);
       //ban 1
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       // ban 2
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
        //ban 3
        digitalWrite(in5, LOW);
        digitalWrite(in6, LOW);
        // ban 4
        digitalWrite(in7, HIGH);
        digitalWrite(in8, LOW);
        digitalWrite(in7, LOW);
        digitalWrite(in8, LOW);
        analogWrite(ena1, 180);
        analogWrite(enb1, 180);
        analogWrite(ena2, 180);
        analogWrite(enb2, 180);
   }

           void stoprobot(){
                   digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       // ban 2
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
        //ban 3
        digitalWrite(in5, LOW);
        digitalWrite(in6, LOW);
        // ban 4
        digitalWrite(in7, LOW);
        digitalWrite(in8, LOW);
        analogWrite(ena1, berhenti);
        analogWrite(enb1, berhenti);
        analogWrite(ena2, berhenti);
        analogWrite(enb2, berhenti);
           }

       void servo1naiksetengah(){
        Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_R1), DEC);
        servo1.write(70);
       }

       void servo1naikfull(){
        Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_L1), DEC);
        servo1.write(25);
       }

       void servo1turun(){
        Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_R3), DEC);
        servo1.write(90);
       }

       void servo2berdirisetengah(){
        Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_L2), DEC);
        servo2.write(90);
       }

           void servo2berdirifull(){
        Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_R2), DEC);
        servo2.write(180);
       }

       void servo2rebahan(){
        Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_L3), DEC);
        servo2.write(0);
       }

            void servo3ambil(){
        Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_CROSS), DEC);
        servo3.write(150);
       }

       void servo3lepas(){
        Serial.print("DOWN held this hard: ");
      Serial.println(ps2x.Analog(PSB_TRIANGLE), DEC);
        servo3.write(0);
       }

void loop() {

  lcd.setCursor(4, 0); 
  lcd.print("HALU OLEO"); 
  lcd.setCursor(0, 1); 
  lcd.print("KRTMI_ELEKTROBOT");
   ps2x.read_gamepad(); 

    if(ps2x.Button(PSB_PAD_UP)) maju();    // ROBOT MAJU
    else if(ps2x.Button(PSB_PAD_DOWN)) mundur();
    else if(ps2x.Button(PSB_PAD_RIGHT)) kanan();
    else if(ps2x.Button(PSB_PAD_LEFT)) kiri();
    else if(ps2x.Button(PSB_CIRCLE)) putarkanan();
    else if(ps2x.Button(PSB_SQUARE)) putarkiri();
    else if(ps2x.Button(PSB_R1)) servo1naiksetengah();
    else if(ps2x.Button(PSB_L1)) servo1naikfull();
    else if(ps2x.Button(PSB_R3)) servo1turun();
    else if(ps2x.Button(PSB_R2)) servo2berdirifull();
    else if(ps2x.Button(PSB_L2)) servo2berdirisetengah();
    else if(ps2x.Button(PSB_L3)) servo2rebahan();
    else if(ps2x.Button(PSB_CROSS)) servo3ambil();
    else if(ps2x.Button(PSB_TRIANGLE)) servo3lepas();
    else if (ps2x.Button(PSB_START)) majukanan();
    else if (ps2x.Button(PSB_SELECT)) majukiri();
    else stoprobot();
       
   }
