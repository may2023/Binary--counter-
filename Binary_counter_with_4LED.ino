const int ledpin[] ={D2,D3,D4,D5,D6,D7,D8,D9};
const int buttonpin = D11;
int lastbutton_state;
int  buttonstate;
int binarystate = LOW;

void setup() {
  // put your setup code here, to run once:
  for (int i =0; i < 8; i++){
    pinMode(ledpin[i], OUTPUT);
   
  }
   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   buttonState();
  for (int decivalue = 0; decivalue < 256; decivalue++){
    binaryvalue(decivalue);
    delay(2000);
  }
}
void  binaryvalue(int decivalue){p[
    for(int i =0; i< 8; i++){
      int bytevalue =(decivalue >> i) & 1;
      digitalWrite(lefdpin[i],bytevalue);
      Serial.print(bytevalue);

      
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
       digitalWrite(ledpin, binarystate);
    }
  }
  
}



  
