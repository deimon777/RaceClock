// https://projecthub.arduino.cc/mdraber/d8d362f1-45df-418e-8b27-804e8152a48c?ref=user&ref_id=1474727&offset=4
// https://www.youtube.com/watch?v=QI1IJLB42G8
int DS1_pin = 4;
int STCP1_pin = 3;
int SHCP1_pin = 2 ;

int  digits [10][8] {
  {0, 1, 1, 1, 1, 1, 1, 0}, // digit 0
  {0, 0, 1, 1, 0, 0, 0, 0}, // digit  1
  {0, 1, 1, 0, 1, 1, 0, 1}, // digit 2
  {0, 1, 1, 1, 1, 0, 0, 1}, // digit 3
  {0, 0, 1, 1, 0, 0, 1, 1}, // digit 4
  {0, 1, 0, 1, 1, 0, 1, 1}, // digit 5
  {0, 1, 0, 1, 1, 1, 1, 1}, // digit 6
  {0, 1, 1, 1, 0, 0, 0, 0}, // digit 7
  {0, 1, 1, 1, 1, 1, 1, 1}, // digit 8
  {0, 1, 1, 1, 1, 0, 1, 1} // digit 9
};


void display_digit(int d) {
  if (digits[d][0] == 1)  digitalWrite(7, LOW); else digitalWrite(7, HIGH); //A
  if (digits[d][1] == 1)  digitalWrite(8, LOW); else digitalWrite(8, HIGH); //B
  if (digits[d][2] == 1)  digitalWrite(9, LOW); else digitalWrite(9, HIGH); //C
  if (digits[d][3] == 1)  digitalWrite(2, LOW); else digitalWrite(2, HIGH); //D
  if (digits[d][4] == 1)  digitalWrite(3, LOW); else digitalWrite(3, HIGH); //E
  if (digits[d][5] == 1)  digitalWrite(5, LOW); else digitalWrite(5, HIGH); //F
  if (digits[d][6] == 1)  digitalWrite(4, LOW); else digitalWrite(4, HIGH); //G
}

void DisplayDigit(int  Digit)
{
  digitalWrite(STCP1_pin, LOW);
  for (int i = 7; i >= 0; i--)
  {
    digitalWrite(SHCP1_pin, LOW);
    if (digits[Digit][i] == 1) digitalWrite(DS1_pin,  LOW);
    if (digits[Digit][i] == 0) digitalWrite(DS1_pin, HIGH);
    digitalWrite(SHCP1_pin, HIGH);
  }
  digitalWrite(STCP1_pin, HIGH);
}


void setup() {
  pinMode(DS1_pin, OUTPUT);
  pinMode(STCP1_pin, OUTPUT);
  pinMode(SHCP1_pin,  OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    DisplayDigit(i);
    delay(300);
  }
}
