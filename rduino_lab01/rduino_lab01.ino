const int ledPin = 13;
const int loopStart = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}


int stateON() {
  Serial.println("Allume - 6229147");

  digitalWrite(ledPin, HIGH);
  // la del reste alluméependant 2 secondes
  delay(2000);
}

int stateBlink(int blinkAmount) {
  Serial.println("Clignotement - 6229147");
  // la lumière clignote 3 fois pendant 500ms
  for (int i = loopStart; i < blinkAmount; i++) {
    digitalWrite(ledPin, HIGH);
    //250 ms pour chaque demi blink (eteint allume)
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  }
}

int stateFade() {
  int intensite = 255;

  Serial.println("Variation - 6229147");

  //Tant que l'intensité n'atteint pas zéro, on continue de diminuer l'intensité
  while (intensite >= loopStart) {
    analogWrite(ledPin, intensite);
    intensite--;
    //8 ms de délai car on fait 256 décrémentation d'intensité (8 *256 = 2048)
    delay(8);
  }
}

int stateEteint() {
  Serial.println("Eteint - 6229147");

  // on éteint la del pendant 2s
  digitalWrite(ledPin, LOW);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int message = 0;
  int blinkAmount = (4 / 2) + 1;

  // state 01 : Lumière allumée
  stateON();
  // State 02 : Lumière clignotante
  stateBlink(blinkAmount);
  // State 03 : Variation d'intensité
  stateFade();
  // State 04 : Lumière Éteinte
  stateEteint();
}
