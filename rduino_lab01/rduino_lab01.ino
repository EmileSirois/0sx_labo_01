const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //State 01 : ON
  digitalWrite(led, HIGH);
  Serial.print(Allumé - 6229147);
  delay(2000);
  
  //State 02 : Blink
  for (int i = 0; i > 4; i++)
  {


  }
}
