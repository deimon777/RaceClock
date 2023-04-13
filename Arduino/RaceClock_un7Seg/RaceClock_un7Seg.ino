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
  for (int i = 0; i < 10; i++) {
    digitalWrite(STCP_pin, LOW);
    shiftOut(DS_pin,   SHCP_pin, LSBFIRST, dec_digits[i]);
    digitalWrite(STCP_pin, HIGH);
    delay(1000);
  }
}
