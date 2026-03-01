int redLed = 12;
int greenLed = 11;
int buzzer = 10;

int smokeA0 = A0;
int flamePin = A1;

const int smokeThres = 500;
const int flameThres = 100;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(smokeA0, INPUT);
  pinMode(flamePin, INPUT);

  Serial.begin(9600);

  Serial.println("Fire Detection System Started");
}

void loop()
{
  int smokeValue = analogRead(smokeA0);
  int flameValue = analogRead(flamePin);

  bool smokeDetected = smokeValue > smokeThres;
  bool flameDetected = flameValue < flameThres;

  Serial.print("MQ2: ");
  Serial.print(smokeValue);

  Serial.print(" | Flame: ");
  Serial.print(flameValue);

  Serial.print(" | Status: ");

  if (smokeDetected && flameDetected)
  {
    Serial.println("KEBAKARAN TERDETEKSI");

    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);

    tone(buzzer, 1000);
  }
  else if (smokeDetected)
  {
    Serial.println("ASAP TERDETEKSI");

    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);

    tone(buzzer, 1000);
  }
  else if (flameDetected)
  {
    Serial.println("API TERDETEKSI");

    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);

    tone(buzzer, 1000);
  }
  else
  {
    Serial.println("AMAN");

    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);

    noTone(buzzer);
  }

  delay(200);
}