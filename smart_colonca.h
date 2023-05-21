#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>

#include <Adafruit_ST7789.h> // library for this display
#include <iarduino_RTC.h>

iarduino_RTC murs (RTC_DS1307);
LiquidCrystal_I2C lcd(0x27,16,2); 

#define track_time 180000
#define tracks 11
#define sec 4
#define min 0
#define hour 0
#define day 4
#define month 3
#define weekday 3
#define year 2023
#define setime 10
#define sedata 11
SoftwareSerial COLONKA(A1, A2); // A1, A2
SoftwareSerial BLUETOOTH (2,3); //rx, tx
char bt_signal;
int tick;
static int i=0;
static int secuu=0,minuu=0,hoo=0,dayyy=0,montt=0,earr=0,wekdayy=0;
int Volium()
{
  if(millis()-tick>=100)
  {
    int h=analogRead (A0);
    int vol=map(h,10,1024,10,30);
    return vol;
    tick=millis();
  }
}
void start_get()
{

  lcd.clear();
  lcd.println("Starting");
    Serial.println("Starting");
     
    delay(2000);

}

void stop_get()
{

  lcd.clear();
  lcd.println("Stop");
    Serial.println("Stop");
     
    delay(2000);

}



void next_resume()
{
 
  lcd.clear();
  lcd.println("next");
   // Serial.println("next");
     
    delay(2000);

}

void prev_resume()
{

  lcd.clear();
  lcd.println("prev");
    Serial.println("prev");
     
    delay(2000);

}
void setmin()
{
int a,b,c,d,e,f;
do
                {
                   bt_signal=(char)BLUETOOTH.read();
                lcd.setCursor (8,0);
            lcd.print("T:  ");
          lcd.setCursor (10,0);
          lcd.print(map(analogRead(A0),0,1024,0,60));
           lcd.setCursor (13,0);
            lcd.print("___");
                //lcd.clear();
                  lcd.setCursor (0,0);
                  lcd.print("___min");
                  //Serial.println("SET TIME"); 
                          lcd.setCursor (8,0);
                 a=map(analogRead(A0),0,1024,0,60);
                
    
                 
                   murs.settime(0,a,0,0,0,0,0);
                   
                 murs.begin();
                 
                  }while(bt_signal!='h');
                  do
                {
                   bt_signal=(char)BLUETOOTH.read();
                lcd.setCursor (8,0);
            lcd.print("T:  ");
          lcd.setCursor (10,0);
          lcd.print(map(analogRead(A0),0,1024,0,24));
          lcd.setCursor (13,0);
            lcd.print("___");
                //lcd.clear();
                  lcd.setCursor (0,0);
                  lcd.print("__hour");
                  //Serial.println("SET TIME"); 
                          lcd.setCursor (8,0);
                 b=map(analogRead(A0),0,1024,0,24);
                
    
                 
                   murs.settime(0,a,b,0,0,0,0);
                   
                 murs.begin();
                 
                  }while(bt_signal!='d');
              do
                {
                   bt_signal=(char)BLUETOOTH.read();
                lcd.setCursor (8,0);
            lcd.print("T:  ");
          lcd.setCursor (10,0);
          lcd.print(map(analogRead(A0),0,1024,0,32));
          lcd.setCursor (13,0);
            lcd.print("___");
                //lcd.clear();
                  lcd.setCursor (0,0);
                  lcd.print("__data");
                  //Serial.println("SET TIME"); 
                          lcd.setCursor (8,0);
                 c=map(analogRead(A0),0,1024,0,32);
                
    
                 
                   murs.settime(0,a,b,c,0,0,0);
                   
                 murs.begin();
                 
                  }while(bt_signal!='M');
                  do
                {
                   bt_signal=(char)BLUETOOTH.read();
                lcd.setCursor (8,0);
            lcd.print("T:  ");
          lcd.setCursor (10,0);
          lcd.print(map(analogRead(A0),0,1024,1,13));
          lcd.setCursor (13,0);
            lcd.print("___");
                //lcd.clear();
                  lcd.setCursor (0,0);
                  lcd.print("__month");
                  //Serial.println("SET TIME"); 
                          lcd.setCursor (8,0);
                 d=map(analogRead(A0),0,1024,1,13);
                
    
                 
                   murs.settime(0,a,b,c,d,0,0);
                   
                 murs.begin();
                 
                  }while(bt_signal!='y');
     do
                {
                   bt_signal=(char)BLUETOOTH.read();
                lcd.setCursor (8,0);
            lcd.print("T  ");
          lcd.setCursor (9,0);
          lcd.print(map(analogRead(A0),0,1024,2000,2200));
                //lcd.clear();
                  lcd.setCursor (0,0);
                  lcd.print("__year");
                  //Serial.println("SET TIME"); 
                          lcd.setCursor (14,0);
                          lcd.print("___");
                 e=map(analogRead(A0),0,1024,2000,2200);
                
    
                 
                   murs.settime(0,a,b,c,d,e,0);
                   
                 murs.begin();
                 
                  }while(bt_signal!='w');
        do
                {
                   bt_signal=(char)BLUETOOTH.read();
                lcd.setCursor (8,0);
            lcd.print("T:  ");
          lcd.setCursor (10,0);
          lcd.print(map(analogRead(A0),0,1024,0,8));
          lcd.setCursor (12,0);
          lcd.print("___");
                //lcd.clear();
                  lcd.setCursor (0,0);
                  lcd.print("__week_");
                  //Serial.println("SET TIME"); 
                          lcd.setCursor (8,0);
                 f=map(analogRead(A0),0,1024,0,8);
                
    
                 
                   murs.settime(0,a,b,c,d,e,f);
                   
                 murs.begin();
                 
                  }while(bt_signal!='q');

    if(millis()%1000==0)
    {         
       
        lcd.clear();                  
        lcd.print (murs.gettime ("d M"));
        lcd.setCursor (4,1);
       
        lcd.print(murs.gettime("H:i:s"));
        Serial.print(murs.gettime("H:i:s"));

        delay(3000);

  }
}



void coloncainit()
{
  Serial.begin (9600);
  lcd.init();                       
  lcd.backlight();
  murs.begin();
  murs.settime(sec,min,hour,day,month,year,weekday); 
	COLONKA.begin (9600);
  BLUETOOTH.begin (9600);
  BLUETOOTH.println ("AT+NAMECOLONCA");
	mp3_set_serial (COLONKA);	//set softwareSerial for DFPlayer-mini mp3 module 
  
	mp3_set_volume (30);
  lcd.setCursor (4,0);
  lcd.print("HELLO MURZA");
  delay(2000);
}
void settime()
{
         int v=Volium();
         lcd.clear ();   
                  
        lcd.print (murs.gettime ("d M"));
          //Serial.print (murs.gettime ("d M"));
        lcd.setCursor (4,1);
     
        lcd.print(murs.gettime("H:i:s"));
        //Serial.print(murs.gettime("H:i:s"));
          mp3_set_volume (v);
          lcd.setCursor (8,0);
          lcd.print("VOL:  ");
          lcd.setCursor (13,0);
          lcd.print(v);
          bt_signal=(char)BLUETOOTH.read();
          
          switch(bt_signal)
          {
            case('m'):
               {
                setmin();
                  break;
                  
                  }
                    
               case('h'):
               {
                  setmin();
                  break;
                  
                  }
                  case('d'):
               {
                 setmin();
                  break;
                  
                  }
                   case('M'):
               {
                 setmin();
                  break;
                  
                  }
                         case('y'):
               {
                 setmin();
                  break;
                  
                  }
                         case('w'):
               {
                 setmin();
                  break;
                  
                  }
                  default:
                  break;
                  
                  
          }

}
