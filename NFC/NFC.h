#ifndef _NFC_H_
#define _NFC_H_

#include "ST25DVSensor.h"
#include "BSP/x_nucleo_nfc04a1.h"
#include "RDMmaster.h"

class NFC : public ST25DV {
  public:
    NFC(void);
    int begin();
    int readFixtureData(String *t);

};

extern NFC Nfc;

#endif