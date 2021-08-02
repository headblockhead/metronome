#include <heltec.h>

int BPM = 75;
int maxcount = 3;
int count = 1;
bool oddbeat = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Heltec.begin(true,false,true);
  Heltec.display->setContrast(255);
  Heltec.display->clear();
  Heltec.display->display();
  Heltec.display->setColor(WHITE); //color to use
  Heltec.display->display();
}

void loop() {
  Heltec.display->clear();
  if (count == maxcount) {
    Serial.println("BAR");
  } else {
    Serial.println("BEAT");
  }
  if (oddbeat) {
    Heltec.display->drawLine(80, 50, 55, 10);
    oddbeat = false;
  } else {
    Heltec.display->drawLine(80, 50, 105, 10);
    oddbeat = true;
  }
  Heltec.display->drawLine(100, 55, 80, 3);
  Heltec.display->drawLine(60, 55, 80, 3);
  Heltec.display->drawLine(100, 55, 60, 55);
  Heltec.display->drawString(0, 10, "BPM: " + String(BPM));
  Heltec.display->drawProgressBar(0, 40, 45, 10, 100 / maxcount * count);
  Heltec.display->drawString(0,20, "Beat: " + String(count) + "/" + String(maxcount));
  Heltec.display->display();
  if (count == maxcount) {
    count = 0;
  }
  delay(60000 / BPM);
  count ++;
}
