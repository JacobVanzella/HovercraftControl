int forward = -1;
int lift = 8;
int left = 2;
int leftB = 5;
int right = 3;
int rightB = 6;
int value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(forward, OUTPUT);
  pinMode(lift, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(forward, LOW); //Turns off propulsion fans.
  digitalWrite(lift, LOW); //Turns off lift fans.
  digitalWrite(left, LOW); //Turns off turning fans.
  digitalWrite(right, LOW); //Turns off turning fans.
}

void loop() {
  if(Serial.available() > 0){
    value = Serial.read();  //Reads value from bluetoothe serial.

    //Sets lift fans on or off.
    if(value == '1'){
      digitalWrite(lift, HIGH);  //Turns lift fans on.
      digitalWrite(LED_BUILTIN, HIGH);
      //Serial.println("Lift on");
    }else if(value == '-1'){
      digitalWrite(lift, LOW); //Turns lift fans off.
      digitalWrite(LED_BUILTIN, LOW);
      //Serial.println("Lift off");
    }

    //Sets fans forward.
    if(value == '2'){
      digitalWrite(left, HIGH);  //Turns on propulsion fans.
      digitalWrite(right, HIGH);  //Turns on propulsion fans.
      delay(15);
      //Serial.println("Forward on");
    }else{
      digitalWrite(left, LOW);  //Turns off propulsion fans.
      digitalWrite(right, LOW);  //Turns on propulsion fans.
      //Serial.println("Forward off");
    }

    //Sets fans reverse.
    if(value == '-2'){
      digitalWrite(leftB, HIGH);  //Turns on propulsion fans.
      digitalWrite(rightB, HIGH);  //Turns on propulsion fans.
      delay(15);
      //Serial.println("Forward on");
    }else{
      digitalWrite(leftB, LOW);  //Turns off propulsion fans.
      digitalWrite(rightB, LOW);  //Turns on propulsion fans.
      //Serial.println("Forward off");
    }

    if(value == '3'){
      digitalWrite(right, HIGH);  //Turns on propulsion fans.
      delay(15);
      //Serial.println("Turn left on");
    }else{
      digitalWrite(right, LOW);  //Turns on propulsion fans.
      //Serial.println("Turn left off");
    }

    if(value == '4'){
      digitalWrite(left, HIGH);  //Turns on propulsion fans.
      delay(15);
      //Serial.println("Turn right on");
    }else{
      digitalWrite(left, LOW);  //Turns on propulsion fans.
      //Serial.println("Turn right off");
    }

    value = 0;
  }
}
