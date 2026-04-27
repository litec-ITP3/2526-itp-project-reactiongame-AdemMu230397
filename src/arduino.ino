const int button1 = 6;
const int button2 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {

  if(digitalRead(button1)==LOW){
    Serial.println("Spieler1");
    delay(500);
  }

  if(digitalRead(button2)==LOW){
    Serial.println("Spieler2");
    delay(500);
  }

}