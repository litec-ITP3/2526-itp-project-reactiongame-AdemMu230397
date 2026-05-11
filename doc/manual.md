# Manual - ReflexRush

1. Was ist das?
Ein Spiel für 2 Personen. Wer nach dem Signal am schnellsten drückt, gewinnt. Wer zu früh drückt, verliert die Runde.

2. Der Aufbau (Hardware)
Gehirn: Arduino Uno/Nano.

Output: LCD-Display (zeigt Status und Zeiten).

Input: 2 Taster (einer für jeden Spieler).

3. So wird gespielt
Start: Arduino einschalten.

Countdown: Auf dem Display erscheint 3... 2... 1....

Warten: Kurze Zufallspause (Spannung!).

Action: Sobald "GO!" dasteht -> DRÜCKEN!

Sieg: Das Display zeigt den Gewinner und die Zeit (ms) an.

Modus: Best-of-Three (Wer zuerst 2 Runden gewinnt, hat den Gesamtsieg).

4. Die goldene Regel (Frühstart)
Wer drückt, bevor "GO!" erscheint, verliert die Runde sofort. Der Punkt geht an den Gegner.

5. Technik-Check (Troubleshooting)
Display dunkel? Dreh am Kontrast-Rädchen (hinten am Display).

Reagiert nicht? Check die Kabel an den Tastern – sie lösen sich oft beim Transport.

Verantwortlichkeiten
Muhammeddjan: Programmierung & Design-Entwurf.

Maximilian: Hardware-Bau & Spielkonzept.

Zeitplan
April: Hardware fertigbauen & Programm schreiben.

Mai: Letzter Check & Abgabe.
