#define SwitchPin 6

unsigned long lastTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 8;

long interval = (3600000 * 0) + (60000 * 0) + (1000 * 10); //hours (0) + minutes (0) + secounds (10)

void setup() {
  // put your setup code here, to run once:
  for (int i = 8; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(SwitchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned  long currentTime = millis();
  if(currentTime - lastTime > interval){
    lastTime = currentTime;
    digitalWrite(led,HIGH);
    led++;
    if(led >= 14){
      led = 8;
    }
  }
  switchState = digitalRead(SwitchPin);
  if(switchState != prevSwitchState){
    for (int i = 8; i < 14; i++) {
      digitalWrite(i, LOW);
    }
    led = 8;
    lastTime = currentTime;
  }
  prevSwitchState = switchState;
  Serial.println(currentTime - lastTime);
}
