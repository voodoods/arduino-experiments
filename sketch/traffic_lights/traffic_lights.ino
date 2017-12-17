const int red = 12;
const int yellow = 11;
const int green = 10;
const int f_red = 9;
const int f_green = 8;
const int button = 2;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(f_red, OUTPUT);
  pinMode(f_green, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  digitalWrite(green, HIGH);
  digitalWrite(f_red, HIGH);

  if ( digitalRead(button) == HIGH ) {
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(600);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(600);
    digitalWrite(f_red, LOW);
    digitalWrite(f_green, HIGH);
    delay(2000);
    digitalWrite(f_green, LOW);
    digitalWrite(f_red, HIGH);
    delay(600);
    digitalWrite(yellow, HIGH);
    delay(600);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    delay(2000);
  }
}
