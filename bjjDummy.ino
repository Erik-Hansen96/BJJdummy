int force1 = 0;
int force2 = 0;
unsigned long startTime;
bool condition = false;
bool end = true;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  force1 = analogRead(A0);
  force2 = analogRead(A1);

  if (force1 > 200 and force2 > 200){
    if(!condition){
    	startTime = millis();
      	condition = true;
    }
  } else {
    condition = false;
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  }
  
  
  if(condition and (millis() - startTime >= 1000 and condition)){
  	digitalWrite(9,HIGH);
  }
  if(condition and (millis() - startTime >= 2000 and condition)){
  	digitalWrite(10,HIGH);
  }
  if(condition and (millis() - startTime >= 3000 and condition)){
  	digitalWrite(11,HIGH);
  }
  if(condition and (millis() - startTime >= 4000 and condition)){
  	digitalWrite(12,HIGH);
  }
  
  if(condition and (millis() - startTime >= 5000 and condition)){
  	digitalWrite(13,HIGH);
  }
  if(condition and (millis() - startTime >= 6000 and condition)){
  	condition = false;
    while(true){
    	digitalWrite(9,LOW);
    	digitalWrite(10,LOW);
    	digitalWrite(11,LOW);
    	digitalWrite(12,LOW);
    	digitalWrite(13,LOW);
      force1 = analogRead(A0);
      force2 = analogRead(A1);
      if(force1 < 200 or force2 < 200) break;
    	delay(250);
    	digitalWrite(9,HIGH);
    	digitalWrite(10,HIGH);
    	digitalWrite(11,HIGH);
    	digitalWrite(12,HIGH);
    	digitalWrite(13,HIGH);
      force1 = analogRead(A0);
      force2 = analogRead(A1);
      if(force1 < 200 or force2 < 200) break;
    	delay(250);
    }
  }
  
}