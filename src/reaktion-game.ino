#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



// OLED Einstellungen
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Initialisierung für I2C (Pins 20 & 21 am Mega werden automatisch genutzt)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);



// Pins
const int button1 = A0;
const int button2 = A1;


int winsP1 = 0;
int winsP2 = 0;
int rounds = 0;


void setup() {
  Serial.begin(9600); // Zum Testen in VS Code (Serieller Monitor)

 
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);


  // OLED starten (Adresse meist 0x3C)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED nicht gefunden!"));
    for(;;);
  }


  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 20);
  display.print("REAKTIONSTEST");
  display.display();
  delay(2000);
}



void loop() {
  if (rounds < 3 && winsP1 < 2 && winsP2 < 2) {
    playRound();
  } else {
    showWinner();
    while(true);
  }
}



void playRound() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Runde: "); display.println(rounds + 1);
  display.display();
  delay(1500);



  // Countdown

  for (int i = 3; i > 0; i--) {
    display.clearDisplay();
    display.setTextSize(3);
    display.setCursor(55, 20);
    display.print(i);
    display.display();
    delay(1000);
  }



  display.clearDisplay();
  display.display();
  delay(random(1000, 4000)); // Zufallspause


  display.clearDisplay();
  display.setCursor(35, 20);
  display.print("GO!");
  display.display();

 
  long startTime = millis();
  long reaction = 0;
  int winner = 0;


  // Wer drückt zuerst?

  while (winner == 0) {
    if (digitalRead(button1) == LOW) {
      reaction = millis() - startTime;
      winner = 1;
      winsP1++;
    } else if (digitalRead(button2) == LOW) {
      reaction = millis() - startTime;
      winner = 2;
      winsP2++;
    }
  }


  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Spieler "); display.print(winner); display.println(" gewinnt!");
  display.print("Zeit: "); display.print(reaction); display.println(" ms");
  display.display();

 
  rounds++;
  delay(3000);

}


void showWinner() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 10);
  if (winsP1 > winsP2) display.print("SIEG: P1");
  else display.print("SIEG: P2");
  display.display();
}

