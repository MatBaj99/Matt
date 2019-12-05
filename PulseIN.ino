  int ENA = 2; //Setting pin 2 as a PWM for A
  int IN1 = 49; //Setting pin 49 for the MC pin 1
  int IN2 = 48; //Setting pin 48 for the MC pin 2
  int IN3 = 47; //Setting pin 47 for the MC pin 3
  int IN4 = 46; //Setting pin 46 for the MC pin 4
  int ENB = 3; //Setting pin 3 as a PWM for B
  int MOTORA = 235;
  int MOTORB = 235;
  int tachA = 10;
  int tachB = 11;
 /* unsigned long widthA;
  unsigned long widthB; */
  int widthA;
  int widthB;
  
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(tachA,INPUT);
    pinMode(tachB,INPUT);   
}
 void forward(){
    analogWrite(ENA, MOTORA);
    analogWrite(ENB, MOTORB);
    /*digitalWrite(ENA, HIGH);
    digitalWrite(ENB,HIGH);*/
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Forward");

}

void comparison(){
  // Cheching MOTORB is quicker than MOTORA
    if((widthA > widthB) && (widthA < 255)){
    MOTORA++
    }
    else if((widthA > widthB) && (widthA = 255 )){
    MOTORB--
    }      
  
  // Cheching MOTORA is quicker than MOTORB
  if((widthA < widthB) && (widthB < 255)){
    MOTORB++
    }
    else if((widthA < widthB) && (widthB = 255 )){
    MOTORA--
    }
  
}

void loop() {
  // put your main code here, to run repeatedly:
    widthA = pulseIn(tachA, HIGH);
    Serial.print("This is widthA: ");
    Serial.println(widthA);
    widthB = pulseIn(tachB, HIGH);
    Serial.print("This is widthB: ");
    Serial.println(widthB);
    comparison();
}
