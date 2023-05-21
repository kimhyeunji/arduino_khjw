const byte button_pin = 2;
const byte ledPin = 8;
const byte soundPin = 7;
volatile byte state = LOW;
unsigned long previousMillis = 0;
unsigned long soundDuration = 100;  // 소리가 울리는 시간 (0.1초)
int count = 0;

void setup()
{
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(soundPin, OUTPUT);
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(button_pin), inter_func, FALLING);
}

void loop()
{
  if (state == HIGH) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= soundDuration) {
      digitalWrite(ledPin, LOW);
      digitalWrite(soundPin, LOW);
      state = LOW;
    }
  }
}

void inter_func()
{
  state = HIGH;
  previousMillis = millis();
  digitalWrite(ledPin, HIGH);
  digitalWrite(soundPin, HIGH);
  count++;
  Serial.print("Button pressed count: ");
  Serial.println(count);
  

  
}
