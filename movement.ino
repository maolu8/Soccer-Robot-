char t;
 
void setup() {
pinMode(7,OUTPUT);   //left motors  forward
pinMode(6,OUTPUT);   //left motors reverse
pinMode(5,OUTPUT);   //right  motors forward
pinMode(4,OUTPUT);   //right motors reverse

pinMode(2, INPUT); //check if there is voltage entering the PIN
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move  forward(all motors rotate in forward direction)
  digitalWrite(7,HIGH);
  digitalWrite(5,HIGH);
}
 
else if(t == 'B'){      //move reverse (all  motors rotate in reverse direction)
  digitalWrite(6,HIGH);
  digitalWrite(4,HIGH);
}
  
else if(t == 'L'){      //turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
  digitalWrite(7,HIGH);
}
 
else  if(t == 'R'){      //turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
  digitalWrite(5,HIGH);
}

else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
}
}

