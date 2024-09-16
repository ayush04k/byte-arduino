int buttonPin= 11;
int redPin= 3;
int greenPin= 9;
int bluePin= 6;
// All the above pins should be digital
// We use analog pins for sensing nature!!!
// we use analog write for controlling the values which may not be 0 and 1!
int buttonVal=0;
int lastButtonVal=0;
int ledNum=0; 
// 0:red, 1:green, 2:blue
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  Serial.println("Setup complete. Waiting for button presses...");

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal= digitalRead(buttonPin);
  if (buttonVal!=lastButtonVal){
    if (buttonVal==LOW){
      ledNum=(ledNum+1)%3;
      updateLed();
    }
    delay(100);
  }
  Serial.println(buttonVal);
  lastButtonVal=buttonVal;
}

void updateLed(){
  if (ledNum==0){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else if(ledNum==1){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else if(ledNum==2){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }
}













