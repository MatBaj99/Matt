  int FR = 52; //setting pin 50 to the Front Right sensor
  int FL = 53; //setting pin 51 to the Front Left sensor
  int BL = 50; //setting pin 52 to the Back Left sensor
  int BR = 51; //setting pin 53 to the Back Right sensor
  
  int ENA = 10; //Setting pin 2 as a PWM for A changed to 10
  int IN1 = 49; //Setting pin 49 for the MC pin 1
  int IN2 = 48; //Setting pin 48 for the MC pin 2
  int IN3 = 47; //Setting pin 47 for the MC pin 3
  int IN4 = 46; //Setting pin 46 for the MC pin 4
  int ENB = 11; //Setting pin 3 as a PWM for B changed to 11
  int MOTORA = 180;
  int MOTORB = 200;
  int tachA = 3; // changed from 10 -> 3
  int tachB = 2; // changed from 11 -> 2
  int widthA;  int widthB;
  int MA1;  int MA2;  int MA3;  int MA4;  int MA5;  int MA6;  int MA7;  int MA8;  int MA9;  int MA10;  int MA11;  int MA12; 
  int MB1;  int MB2;  int MB3;  int MB4;  int MB5;  int MB6;  int MB7;  int MB8;  int MB9;  int MB10;  int MB11;  int MB12; 
  int AVwidthA;  int AVwidthB;
  
void setup() {
  // put your setup code here, to run once:
    pinMode(BR, INPUT);
    pinMode(BL, INPUT);
    pinMode(FR, INPUT);
    pinMode(FL, INPUT);
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
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void back() {
  analogWrite(ENA, MOTORA);
  analogWrite(ENB, MOTORB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}

void right() {
  analogWrite(ENA, MOTORA);
  analogWrite(ENB, MOTORB);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Right");
}

void left() {
  analogWrite(ENA, MOTORA);
  analogWrite(ENB, MOTORB);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Left");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
}



void comparison(){
  // Cheching MOTORB is quicker than MOTORA
  /*MA1 = pulseIn(tachA, HIGH);
  MB1 = pulseIn(tachB, HIGH);
  MA2 = pulseIn(tachA, HIGH);
  MB2 = pulseIn(tachB, HIGH);
  MA3 = pulseIn(tachA, HIGH);
  MB3 = pulseIn(tachB, HIGH);
  MA4 = pulseIn(tachA, HIGH);
  MB4 = pulseIn(tachB, HIGH);
  MA5 = pulseIn(tachA, HIGH);
  MB5 = pulseIn(tachB, HIGH);
  MA6 = pulseIn(tachA, HIGH);
  MB6 = pulseIn(tachB, HIGH);
  MA7 = pulseIn(tachA, HIGH);
  MB7 = pulseIn(tachB, HIGH);
  MA8 = pulseIn(tachA, HIGH);
  MB8 = pulseIn(tachB, HIGH);
  MA9 = pulseIn(tachA, HIGH);
  MB9 = pulseIn(tachB, HIGH);
  MA10 = pulseIn(tachA, HIGH);
  MB10 = pulseIn(tachB, HIGH);
  MA11 = pulseIn(tachA, HIGH);
  MB11 = pulseIn(tachB, HIGH);
  MA12 = pulseIn(tachA, HIGH);
  MB12 = pulseIn(tachB, HIGH);
  widthA = ((MA1 + MA2 + MA3 + MA4 + MA5 + MA6 + MA7 + MA8 + MA9 + MA10 + MA11 + MA12)/120); // Averages the values if the value of 60 is increased by a power of 10 it
  widthB = ((MB1 + MB2 + MB3 + MB4 + MB5 + MB6 + MB7 + MB8 + MB9 + MB10 + MB11 + MB12)/120); //reduces the accuracy
  Serial.print("This is widthA: ");
  Serial.println(widthA);
  Serial.print("This is MOTORA: ");
  Serial.println(MOTORA);
  Serial.print("This is widthB: ");
  Serial.println(widthB);
  Serial.print("This is MOTORB: ");
  Serial.println(MOTORB);
  
  if((widthA > widthB) && (MOTORB >= 150)){
    MOTORB--;
    }
  else if((widthA < widthB) && (MOTORB < 250)){
    MOTORB++;
    }
  else if((widthA < widthB) && (MOTORB >= 250 )){
    MOTORB -= 10;
    }
  else if(MOTORB < 150 ){
    MOTORA == 0;
    MOTORB == 0;
    }  
  else{
    Serial.println("SYNCHED");
    }*/
}


void obstacleavoidance(){
  if((digitalRead(FR)==HIGH) && (digitalRead(FL)==HIGH)){
    Serial.println("FRONT DETECT");
    stop();
    delay(10);
    back();
    delay(10);
    right();
    delay(50);
  }
  else if((digitalRead(FR)==HIGH) && (digitalRead(FL)==LOW)){
    Serial.println("Front Right Active - STOP");
    stop();
    delay(10);
    left();
    delay(50);  
  }
  else if((digitalRead(FR)==LOW) && (digitalRead(FL)==HIGH)){
    Serial.println("Front Left Active - STOP");
    stop();
    delay(10);
    back();
    delay(10);
    right();
    delay(50);
    }
  
  else{
    forward();
    comparison();
    delay(10);
}
}


void obstacleseeking(){   // Reverse of ObstacleAvoid

  if((digitalRead(FR)==HIGH) && (digitalRead(FL)==HIGH)){
    Serial.println("FRONT DETECT");
    stop();
    delay(100);
    back();
    delay(100);
   //Toucbar activates  
   //SPIN Around 180 degrees
  }

  else if((digitalRead(FR)==HIGH) && (digitalRead(FL)==LOW)){
    Serial.println("Front Right Active - STOP");
    stop();
    delay(100);
    back();
    delay(100);
    right();
    delay(500);
    stop();
    delay(100);
    back(); 
    // Toucbar activates  
    //SPIN Around 180 degrees
  }

  else if((digitalRead(FR)==LOW) && (digitalRead(FL)==HIGH)){
    Serial.println("Front Left Active - STOP");
    stop();
    delay(100);
    back();
    delay(100);
    left();
    delay(500);
    stop();
    delay(100);
    back();
    // Toucbar activates  
    // SPIN Around 180 degrees
   }

  else{
    forward();
    /* comparison(); */
    delay(100);
}
}

void loop() {
  // put your main code here, to run repeatedly:
    obstacleavoidance();
    obstacleseeking();

}





//Whitebox (Stay within whitebox)
//Touchbars
