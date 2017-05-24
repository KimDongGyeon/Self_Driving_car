int echo = 8, trig = 9;
int ADir = 4, BDir = 7;
int APWM = 5, BPWM = 6;

void setup() {
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(ADir,OUTPUT);
  pinMode(BDir,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int dist = ultrasonic(echo,trig);
  int speed = 255;
  
  Serial.println(dist);

  if(dist>30) {Forward(speed);}
  
  else if(30>=dist>25) {
    for(;dist=26;){
      Forward(speed);
      speed-=5;
    }
  }

  else if(dist>20) {Backward(speed);}

  else if(dist<25) {
    for(;dist=24;)
    {
      Backward(speed);
      speed-=3;
    }
  }
  
  else{Forward(0);}
  
}

int ultrasonic(int echo, int trig)
{
  int distance;
  digitalWrite(trig, HIGH);delay(2);
  digitalWrite(trig, LOW);
  distance = pulseIn(echo,HIGH)/58;
  return distance;
}
    void Forward(int vel){
      digitalWrite(ADir,HIGH);
      digitalWrite(BDir,LOW);
      analogWrite(APWM,vel);
      analogWrite(BPWM,vel);}

      void Backward(int vel){
      digitalWrite(ADir,LOW);
      digitalWrite(BDir,HIGH);
      analogWrite(APWM,vel);
      analogWrite(BPWM,vel);}
