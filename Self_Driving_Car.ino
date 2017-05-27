int echo = 8, trig = 9; // 초음파 센서
int ADir = 4, BDir = 7; // 모터 회전 방향
int APWM = 5, BPWM = 6; // 모터 회전 속도

void setup() {
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(ADir,OUTPUT);
  pinMode(BDir,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int d = ultrasonic(echo,trig);
  Serial.println(d);

  if(d>30) {Forward(255);}
  
  else if(30>=d>29) {Forward(250);}
  else if(29>=d>28) {Forward(245);}
  else if(28>=d>27) {Forward(240);}
  else if(27>=d>26) {Forward(235);}
  else if(26>=d>25) {Forward(200);}
  else if(20>d) {Backward(255);}
  else if(21>=d>22) {Backward(255);}
  else if(22>=d>23) {Backward(250);}
  else if(23>=d>24) {Backward(249);}
  else if(24>=d) {Backward(245);}
  else {Forward(0);}
  }

int ultrasonic(int echo, int trig) // 초음파 센서 함수
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
