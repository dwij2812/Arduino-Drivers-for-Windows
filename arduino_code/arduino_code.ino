#define BAUD 9600

void setup(){
  Serial.begin(BAUD);
}

void loop(){
  Serial.println("This line is being written via serial of arduino");
  delay(5000);
}
