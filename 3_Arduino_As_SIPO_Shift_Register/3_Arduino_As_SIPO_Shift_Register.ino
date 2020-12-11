#define dataPin  12 
#define clockPin 11 
#define latchPin 10 
#define clearPin 9 
uint8_t arr[9] = {0};

void setup() 
{                
  Serial.begin(9600);

  pinMode(dataPin,  INPUT);
  pinMode(clockPin, INPUT);
  pinMode(latchPin, INPUT);
  pinMode(clearPin, INPUT);
  
  digitalWrite(dataPin,  LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
  digitalWrite(clearPin, HIGH);
  
}

void loop() {

  if(digitalRead(clockPin)==HIGH){
      Serial.println("In do while loop");
      //shiftig all the bits
      for(int j=7;j>=0;j--)
          arr[j+1]=arr[j];
      arr[0]=digitalRead(dataPin);
      while(digitalRead(clockPin)==HIGH);  
  }

  if(digitalRead(latchPin)==HIGH){
    Serial.println("The values of the shift register are: ");
    for(int j=0;j<8;j++)
      Serial.print(arr[j]);
    Serial.println("");
    while(digitalRead(latchPin)==HIGH);
  }


  if(digitalRead(clearPin)==LOW){
    for(int j=0;j<8;j++)
      arr[j]=0;    
  }
  delay(100);

}
