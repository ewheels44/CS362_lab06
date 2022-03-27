
char recieved[1]; //Initialized variable to store recieved data

const int button_pin = 11;   // button led on and off

int buttonState = 0;         // variable for reading the pushbutton status

const int yellow =  10;      // the number of the LED pin

void setup() {
      
  // setting up serial
  Serial.begin(9600);
  pinMode(yellow, OUTPUT);
  pinMode(button_pin, INPUT);
}

void loop() {
  buttonState = digitalRead(button_pin);    // pressed = 0, not pressed = 1

  Serial.println(buttonState);

  if (Serial.available()) {
    Serial.readBytes(recieved,1); //Read the serial data and store in var
    Serial.println(recieved); //Print data on Serial Monitor

    digitalWrite(yellow, HIGH);

  }
  else{
    digitalWrite(yellow, LOW);
  }

  if(buttonState == 0){
    char thismsg[1] = "0";
    Serial.write(thismsg,5); //Write the serial data

  }

  /* else{ */

  /*   char thismsg[1] = "0"; */
  /*   Serial.write(thismsg,5); //Write the serial data */
  /*   delay(2000); */
  /* } */
}
