# Installation
 
1. Benötigte Hardware
Besorgen Sie sich zuerst folgende Komponenten:
- 1x Arduino Mega mit passendem Panel/Gehäuse.
- 1x OLED-Display (Anschluss über I2C).
- 2x Taster mit eingebauten LEDs.

2. Hardware-Anschluss
Verbinden Sie die Komponenten wie folgt mit dem Arduino Mega:
- Taster (Buttons)
- Spieler 1: Schließen Sie den Taster an Pin D7 an.
- Spieler 2: Schließen Sie den Taster an Pin D5 an.

(Vergessen Sie nicht, auch die internen LEDs der Knöpfe entsprechend mit Strom zu versorgen).
Verbindung zum Endgerät

- Schließen Sie den Arduino Mega über das USB-Kabel an Ihr Endgerät (PC/Laptop) an.

3. Software-Einrichtung
Um das Projekt zu starten, müssen zwei Komponenten installiert werden:
- Arduino Code:
    - Laden Sie die beigefügte .ino-Datei herunter.
    - Öffnen Sie diese in der Arduino IDE und laden Sie den Code auf den Mega hoch.
- Webseite (Ergebnisanzeige):
    - Laden Sie das beigefügte HTML-Dokument herunter.
    - Öffnen Sie die Datei in einem Browser Ihrer Wahl, um die Spielergebnisse live anzeigen zu lassen.

4. Inbetriebnahme
Sobald der Code hochgeladen ist und die Hardware steht, starten sie das System.
Achten Sie darauf, dass die Verbindung zum Endgerät bestehen bleibt, damit die Daten an die Webseite übertragen werden können.