const int Ledpin[]={2,3,4,5};
const int buttonpin = 7;
int lastbutton_state;
int  buttonstate;
int binarystate = LOW;

//long bitvalue;

void setup() {
  // put your setup code here, to run once:  // the void setup is use to initilize 
  for (int i = 0; i<4; i++){                 // the loop
    pinMode(Ledpin[i], OUTPUT);
    pinMode(buttonpin, INPUT);
  }
  lastbutton_state = digitalRead(buttonpin);
  Serial.begin(9600);
  

}



void loop(){
  buttonState();
  for (int decimalValue = 0; decimalValue<15; decimalValue++){
    binaryValue(decimalValue);
    //Serial.print(bitvalue);
    delay(5000);  
  }
 
  
 
}

void binaryValue(int decimalValue){ // this is a function to convert to decimal to binary
  for (int i = 0; i < 4; i++ ){
    int bitvalue = (decimalValue >> i)& 1 ;
    digitalWrite(Ledpin[i], bitvalue);
    Serial.print(bitvalue);
  }
  Serial.println();
}
void buttonState(){
  int lastbutton_state = digitalRead(buttonpin);
  if (buttonstate!= lastbutton_state ){
    lastbutton_state = buttonstate;
    if (buttonstate == LOW){
      if (binarystate==HIGH){
        binarystate = LOW;
      }
      else{
        binarystate = HIGH;
      } 
       digitalWrite(Ledpin, binarystate);
    }
  }
  
}
