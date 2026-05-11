#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Einstellungen
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Buttons
const int button1 = 6;
const int button2 = 8;

// LEDs
const int led1 = 5;
const int led2 = 7;

unsigned long startZeit;

bool spielLaeuft = false;

// Punkte
int scoreP1 = 0;
int scoreP2 = 0;

void setup() {

  Serial.begin(9600);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // OLED starten
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {

    while(true);
  }

  // Startbildschirm
  display.clearDisplay();

  display.setTextSize(2);

  display.setTextColor(WHITE);

  display.setCursor(5,20);

  display.println("ReflexRush");

  display.display();

  delay(2000);

  resetScreen();
}

void loop() {

  // Spiel starten
  if (!spielLaeuft) {

    if (digitalRead(button1) == LOW ||
        digitalRead(button2) == LOW) {

      // Startanzeige
      display.clearDisplay();

      display.setTextSize(1);

      display.setCursor(0,0);

      display.println("Spiel startet!");

      display.display();

      // LEDs blinken
      for (int i = 0; i < 4; i++) {

        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);

        delay(250);

        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);

        delay(250);
      }

      // Zufallspause
      delay(random(1500,6000));

      // GO
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);

      display.clearDisplay();

      display.setTextSize(3);

      display.setCursor(25,20);

      display.println("GO!");

      display.display();

      startZeit = millis();

      spielLaeuft = true;
    }
  }

  // Spieler 1 gewinnt
  if (spielLaeuft && digitalRead(button1) == LOW) {

    unsigned long zeit = millis() - startZeit;

    scoreP1++;

    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);

    display.println("Spieler 1 gewinnt!");

    display.print("Zeit: ");

    display.print(zeit);

    display.println(" ms");

    display.println();

    display.print("P1 Siege: ");
    display.println(scoreP1);

    display.print("P2 Siege: ");
    display.println(scoreP2);

    display.display();

    // Für Website
    Serial.print("P1|");
    Serial.print(zeit);
    Serial.print("|");
    Serial.println(scoreP1);

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);

    spielLaeuft = false;

    delay(3000);

    resetScreen();
  }

  // Spieler 2 gewinnt
  if (spielLaeuft && digitalRead(button2) == LOW) {

    unsigned long zeit = millis() - startZeit;

    scoreP2++;

    display.clearDisplay();

    display.setTextSize(1);

    display.setCursor(0,0);

    display.println("Spieler 2 gewinnt!");

    display.print("Zeit: ");

    display.print(zeit);

    display.println(" ms");

    display.println();

    display.print("P1 Siege: ");
    display.println(scoreP1);

    display.print("P2 Siege: ");
    display.println(scoreP2);

    display.display();

    // Für Website
    Serial.print("P2|");
    Serial.print(zeit);
    Serial.print("|");
    Serial.println(scoreP2);

    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);

    spielLaeuft = false;

    delay(3000);

    resetScreen();
  }
}

// Startbildschirm
void resetScreen() {

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(0,0);

  display.println("Button druecken");

  display.println("zum Starten");

  display.println();

  display.print("P1 Siege: ");
  display.println(scoreP1);

  display.print("P2 Siege: ");
  display.println(scoreP2);

  display.display();
}