#include <SoftwareSerial.h>
#include <EEPROM.h>
#define GPRSPEED  9600
//#define WaitOK(n) delay(n)
#define WaitOK(n) {delay(n); while( this->serie.available() ) Serial.write((byte)this->serie.read());}
#define SerieRx D7
#define SerieTx D8

class SMS {
private:
  SoftwareSerial serie;
public:
  SMS();
  void send(String message);

};
