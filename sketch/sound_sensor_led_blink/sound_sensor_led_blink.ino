// Base Code: test code for Grove - Sound Sensor
// LED additions by Norman Steger github@voodoods
// loovee @ 2016-8-30

const int led = 13
const int pinAdc = A0;

void setup()
{
    pinMode(led, OUTPUT);
    Serial.begin(115200);
}

void loop()
{1
    long sum = 0;
    for(int i=0; i<32; i++)1
    {
        sum += analogRead(pinAdc);
    }

    sum >>= 5;

    Serial.println(sum);
    digitalWrite(led, HIGH)
    delay(100)
    digitalWrite(led, LOW)
    delay(10);
}
