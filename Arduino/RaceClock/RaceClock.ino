// https://projecthub.arduino.cc/mdraber/d8d362f1-45df-418e-8b27-804e8152a48c?ref=user&ref_id=1474727&offset=4
// https://www.youtube.com/watch?v=QI1IJLB42G8

int DS_pin = 4;
int STCP_pin = 3;
int SHCP_pin = 2 ;

int dec_digits   [10] {1, 79, 18, 6, 76, 36, 32, 15, 0, 4};

void setup() {
  pinMode(DS_pin,   OUTPUT);
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
}

void   loop() {
  for (int horaDec = 0; horaDec < 3; horaDec++) {
    for (int horaUni = 0; horaUni < 10; horaUni++) {
      for (int minDec = 0; minDec < 6; minDec++) {
        for (int minUni = 0; minUni < 10; minUni++) {
          for (int segDec = 0; segDec < 6; segDec++) {
            for (int segUni = 0; segUni < 10; segUni++) {
              //for (int miliDec = 0; miliDec < 6; miliDec++) {
                for (int miliUni = 0; miliUni < 10; miliUni++) {
                  digitalWrite(STCP_pin, LOW);
                  shiftOut(DS_pin, SHCP_pin, LSBFIRST, dec_digits[miliUni]);
                  //shiftOut(DS_pin, SHCP_pin, LSBFIRST, dec_digits[miliDec]);
                  shiftOut(DS_pin, SHCP_pin, LSBFIRST, dec_digits[segUni]);
                  shiftOut(DS_pin, SHCP_pin, LSBFIRST, dec_digits[segDec]);
                  shiftOut(DS_pin, SHCP_pin, LSBFIRST, dec_digits[minUni]);
                  shiftOut(DS_pin, SHCP_pin, LSBFIRST, dec_digits[minDec]);
                  shiftOut(DS_pin, SHCP_pin, LSBFIRST, dec_digits[horaUni]);
                  shiftOut(DS_pin, SHCP_pin, LSBFIRST, dec_digits[horaDec]);
                  digitalWrite(STCP_pin, HIGH);
                  delay(100);
                }
              //}
            }
          }
        }
      }
    }
  }
}
