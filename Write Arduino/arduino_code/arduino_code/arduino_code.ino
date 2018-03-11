//Default baud speed for communication
#define BAUD 9600
//led 
#define led 13
#define buzzer 8
//macro for on/off
#define on (digitalWrite(led, HIGH))
#define off (digitalWrite(led, LOW))

void setup(){
  Serial.begin(BAUD);
  pinMode(led, OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop(){
  String input;
  //If any input is detected in arduino
  if(Serial.available() > 0){
    //read the whole string until '\n' delimiter is read
    input = Serial.readStringUntil('\n');
    //If input == "ON" then turn on the led 
    //and send a reply
    if (input.equals("LEDON")){
      digitalWrite(led, HIGH);
      Serial.println("Led is on");
    }
    if (input.equals("BUZZON")){
      digitalWrite(buzzer, HIGH);
      Serial.println("Buzzer is on");
    }

    if (input.equals("BUZZOFF")){
      digitalWrite(buzzer, LOW);
      Serial.println("Buzzer is off");
    }
    //If input == "OFF" then turn off the led 
    //and send a reply
    else if (input.equals("LEDOFF")){
      digitalWrite(led, LOW);
      Serial.println("Led is off");
    }
  }
}
