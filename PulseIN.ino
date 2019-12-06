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
  int MA1;
  int MB1;
  int MA2;
  int MB2;  
  int MA3;
  int MB3;
  int MA4;
  int MB4;
  int MA5;
  int MB5;  
  int MA6;
  int MB6;
  int AVwidthA;
  int AVwidthB;
  
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
    analogWrite(ENA, MOTORB);
    analogWrite(ENB, MOTORA);
    /*digitalWrite(ENA, HIGH);
    digitalWrite(ENB,HIGH);*/
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println("Forward");
    comparison();

}



void comparison(){
  // Cheching MOTORB is quicker than MOTORA
  widthA = pulseIn(tachA, HIGH);
  widthB = pulseIn(tachB, HIGH);
  MA1=widthA;
  MB1=widthB;
  delay(1);
  widthA = pulseIn(tachA, HIGH);
  widthB = pulseIn(tachB, HIGH);
  MA2=widthA;
  MB2=widthB;
  delay(1);
  widthA = pulseIn(tachA, HIGH);
  widthB = pulseIn(tachB, HIGH);
  MA3=widthA;
  MB3=widthB;


  widthA = pulseIn(tachA, HIGH);
  widthB = pulseIn(tachB, HIGH);
  MA4=widthA;
  MB4=widthB;
  delay(1);
  widthA = pulseIn(tachA, HIGH);
  widthB = pulseIn(tachB, HIGH);
  MA5=widthA;
  MB5=widthB;
  delay(1);
  widthA = pulseIn(tachA, HIGH);
  widthB = pulseIn(tachB, HIGH);
  MA6=widthA;
  MB6=widthB;

  AVwidthA = ((MA1 + MA2 + MA3 + MA4 + MA5 + MA6)/60); // Averages the values if the value of 60 is increased by a power of 10 it
  AVwidthB = ((MB1 + MB2 + MB3 + MB4 + MB5 + MB6)/60); //reduces the accuracy
 
  widthA = AVwidthA;
  widthB = AVwidthB;

    Serial.print("This is widthA: ");
    Serial.println(widthA);
    Serial.print("This is MOTORA: ");
    Serial.println(MOTORA);
    Serial.print("This is widthB: ");
    Serial.println(widthB);
    Serial.print("This is MOTORB: ");
    Serial.println(MOTORB);

    if((widthA > widthB) && (MOTORA < 250)){
      MOTORA == MOTORA++;
      }
    else if((widthA > widthB) && (MOTORA >= 250 )){
      MOTORB == MOTORB--;
      MOTORA--;
      }      
  // Cheching MOTORA is quicker than MOTORB
    else if((widthA < widthB) && (MOTORB < 250)){
      MOTORB == MOTORB++;
      }
    else if((widthA < widthB) && (MOTORB >= 250 )){
      MOTORA == MOTORA--;
      MOTORB--;
      }
    else{
      //do nothing
      Serial.println("SYNCHED");
      }
}



void loop() {
  // put your main code here, to run repeatedly:
    forward();

}
