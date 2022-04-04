#include "NFC.h"
#include "Arduino.h"

extern sCCFileInfo CCFileStruct;

// make this instance available in the sketch
NFC Nfc;

NFC::NFC(void){}

int NFC::begin()
{
  int ret = 0;
  ret = st25dv.begin(12, 7); // gpo, lpd
  if (ret != ST25DV_OK) {
    return ret;
  }
  return NDEF_OK;
}

int NFC::readFixtureData(String *t){
  String reads[2];
  uint16_t ret;
  NDEF_Text_info_t text_info;
  sRecordInfo_t recordInfo;
  // increase buffer size for bigger messages
  ret = NDEF_ReadNDEF(NDEF_Buffer);
    if (ret) {
      return ret;
    }

  ret = NDEF_IdentifyBuffer(&recordInfo, NDEF_Buffer);
    if (ret) {
       return ret;
    }

  ret = NDEF_ReadText(&recordInfo, &text_info);
    if (ret) {
      return ret;
    }
  char * pch; 
  pch = strtok(text_info.text,";");
    while(pch != NULL){
      int i;
      //Serial.println(pch);
      reads[i]= pch;
      pch = strtok(NULL, ";");
      i++;
    }

  RDM.setDMXaddress(reads[0].toInt());
  delay(500);
  RDM.setFixtureMode(reads[1].toInt());
  delay(500);
  }
