/*
   Name: Khizer Shareef - NetID: kshare2 , Ethan Wheeler - NetID: ewheel5
   Class: CS362 SP22
   Lab: 06 - Serial Communication ( option 1 )



   Description: Transmission over Serial connection between two arduinos



   Assumptions: Successfully implemented the knowledge of Serial connection. Used the 0 (RX) pin and 1 (TX) pin to send and receive data. In the beginning we connected 
                both boards on a one-to-one connection with pins 0,1 which obviously was not working. Then using simple logic we connected both boards vice versa on pins 0,1 that
                way one board sent a transimssion buf and the other read it. The hint for using the common ground was very helpful.

   In-person TA: Michael

*/
const int button_pin = 12;   // button led on and off
const int yellow =  10;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status

int buttonState_prev = 0;         // prev button state for button switch

int on_off_toggle = 0;          // 0 = off 1 = on 

void setup() {

  // setting up serial
  Serial.begin(9600);
  pinMode(yellow, OUTPUT);
  pinMode(button_pin, INPUT);
}

void loop() {

   if(Serial.available() > 0){              // check if there is msg to be recived 
      int recived = Serial.read();          // read msg

      //
      // turn light on or off 0 = OFF, 1 = ON
      //
      if (recived == 0) { 
        digitalWrite(yellow, LOW); 
      }
      if (recived == 1) { 
        digitalWrite(yellow, HIGH); 
      }

   }

  buttonState = digitalRead( button_pin );

  if(buttonState != buttonState_prev){          // if button state doesnt equal then turn on or off

    
    if( buttonState == HIGH){                   // when pressed
      if (on_off_toggle == 0){                  // if on_off_toggle = 0, turn light on
        Serial.write(1);
        on_off_toggle = 1;                      // set light state to on
      }
      else{
        Serial.write(0);                        // else the light was on, and turn it off
        on_off_toggle = 0;
      }
    }
  }

  buttonState_prev = buttonState;             // set curent buttonState to prev buttonState
}
