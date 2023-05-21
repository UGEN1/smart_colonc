#include "smart_colonca.h"

void setup () 
{
coloncainit();
}

void loop () 
{ 
    if(millis()%250==0)
    {   
        settime();
    }
     
    if (BLUETOOTH.available())
    {
    bt_signal=BLUETOOTH.read();
    int NUM=static_cast<int>(bt_signal);
    

      switch(bt_signal)
        {
          case ('1'):       //слушать ВСЕ!!!
           start_get();
           
           do{
                 bt_signal=BLUETOOTH.read();
                if((millis()%track_time)==0)
                 {
                  bt_signal=BLUETOOTH.read();
                 //if(bt_signal!='2')
                    //  { 
                          next_resume();
                          mp3_next ();
                // }
                         // delay(track_time); 
                      
                 
                  //else break;          
            i++;
                 }
              }while ((i<tracks)&&(bt_signal!='2'));
        
            
            i=0;
          break;
 
      
          case ('2'):          //стоп
            mp3_stop ();
            stop_get();

          break;
      
          case ('3'):     //следующий
            mp3_next ();
            next_resume();
          break;
           
          case ('4'):    //предыдущий        
          mp3_prev ();
            prev_resume();
          break;
          case ('N'):
          mp3_set_EQ (0);
           Serial.println("NORM");
             lcd.clear();
            lcd.println("NORM");
            delay(1000);
          break;
         
           case('P'):
                      
           mp3_set_EQ (1);
           Serial.println("POP");
           lcd.clear();
            lcd.println("POP");
            delay(1000);
          break;
          
           case('R'):
                  
           mp3_set_EQ (2);
           Serial.println("ROCK");
           lcd.clear();
            lcd.println("ROCK");
            delay(1000);
          break;
                  
          case('J'):
          
           mp3_set_EQ (3);
           Serial.println("JAZZ");
           lcd.clear();
            lcd.println("JAZZ");
            delay(1000);
          break;
          
          case('C'):
          
           mp3_set_EQ (4);
           Serial.println("CLASSIK");
           lcd.clear();
            lcd.println("CLASSIK");
            delay(1000);
          break;
          case ('6'):       //зациклить
           lcd.clear();
            lcd.println("RECYCLER");
           do{
                 bt_signal=BLUETOOTH.read();
                   if((millis()%track_time)==0)
                           {
                          mp3_play ();
                          lcd.clear();
                          lcd.println("Press NEXT twice");
                          lcd.setCursor (4,1);
                          lcd.print("to exit");
                           bt_signal=BLUETOOTH.read();
                          
                           }
                                    
           }
          while (bt_signal!='3'); 
            
          break;
          
          
    
      
      }
    }
}
    
	            
