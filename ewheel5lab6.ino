
char recieved[1]; //Initialized variable to store recieved data

void setup() {
      
  // setting up serial
  Serial.begin(9600);

}

void loop() {

  if (Serial.available()) {
    Serial.readBytes(Mymessage,5); //Read the serial data and store in var
    Serial.println(Mymessage); //Print data on Serial Monitor
    delay(1000);
  }
  else{

    char thismsg[1] = '1';
    Serial.write(thismsg,5); //Write the serial data
    delay(1000)
  }
}
