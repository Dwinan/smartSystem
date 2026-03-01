#define TRIG_PIN D0  
#define ECHO_PIN D1  

void setup() {
  Serial.begin(9600);            
  pinMode(TRIG_PIN, OUTPUT);       
  pinMode(ECHO_PIN, INPUT);        
}

void loop() {
  long durasi;
  float jarak;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  durasi = pulseIn(ECHO_PIN, HIGH);

  jarak = durasi * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  delay(1000); 
}