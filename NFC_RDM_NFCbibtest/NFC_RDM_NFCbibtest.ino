#include "RDMmaster.h"
#include "NFC.h"
#include <String.h>

#define DMXADRESS "512"
#define DMXMODE "10"


String data = {"1;1"};
int test;

void setup() {
  char write[] = (DMXADRESS ";" DMXMODE);
  RDM.initPins();
  RDM.initRDMdata();
  Nfc.begin();
  delay(100);
  NDEF_WriteText(write);

  while(1){
      test = Nfc.readFixtureData(&data);
      delay(500);

  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
