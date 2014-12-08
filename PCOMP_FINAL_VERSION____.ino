//yurika and david pcomp final 12/8/14
//adfrsw

const int led1 = 11;
const int led2 = 10;
const int led3 = 9;
const int led4 = 6;
const int led5 = 5;
const int led6 = 3;
const int button = 0;

int forward;
int back;
int left;
int right;
int up;
int down;

int difference0;
int difference1;
int difference2;
int difference3;
int difference4;
int difference5;

int threshold0;
int threshold1;
int threshold2;
int threshold3;
int threshold4;
int threshold5;

int callibration[] = {
  300,300,300,300,300,300};



void setup(){
  Serial.begin(9600);
  Keyboard.begin();

  pinMode (button, INPUT);
  pinMode (led1, OUTPUT); 
  pinMode (led2, OUTPUT); 
  pinMode (led3, OUTPUT); 
  pinMode (led4, OUTPUT); 
  pinMode (led5, OUTPUT); 
  pinMode (led6, OUTPUT); 
}

void loop(){

  if(digitalRead(button)==HIGH){
    callibrate();
  }

  //
  forward = analogRead(A0);
  back = analogRead(A1);
  left = analogRead(A2);
  right = analogRead(A3);
  up = analogRead(A4);
  down = analogRead(A5);

//

  difference0 = forward -callibration[0];
  difference1 = back - callibration[1];
  difference2 = left - callibration[2];
  difference3 = right - callibration[3];
  difference4 = up - callibration[4];
  difference5 = down - callibration[5];
 
  if(difference0<threshold0){
    digitalWrite(led1, HIGH);
    Keyboard.press('w');
  } 
  else {
    digitalWrite(led1, LOW); 
    Keyboard.release('w');
  }
//
  if(difference1<threshold1){
    digitalWrite(led2, HIGH);
    Keyboard.press('s');
  }
 else {
   digitalWrite(led2, LOW); 
   Keyboard.release('s');
  }


  if(difference2<threshold2){
   digitalWrite(led3, HIGH);
   Keyboard.press('a');
 } 
 else {
  digitalWrite(led3, LOW); 
   Keyboard.release('a');
  }
 

 if(difference3<threshold3){
  digitalWrite(led4, HIGH);
   Keyboard.press('d');
  } 
  else {
   digitalWrite(led4, LOW); 
   Keyboard.release('d');
  }

 
 if(difference4<threshold4){
   digitalWrite(led5, HIGH);
   Keyboard.press('r');
 }
 else {
   digitalWrite(led5, LOW); 
   Keyboard.release('r');
 }

 if(difference5<threshold5){
  digitalWrite(led6, HIGH);
   Keyboard.press('f');
 } 
 else {
   digitalWrite(led6, LOW);
   Keyboard.release('f'); 
 }

}



void callibrate(){
  callibration[0]= analogRead(A0);
  callibration[1]= analogRead(A1);
  callibration[2]= analogRead(A2);
  callibration[3]= analogRead(A3);
  callibration[4]= analogRead(A4);
  callibration[5]= analogRead(A5);
  
  threshold0=difference0-20;
  threshold1=difference1-20;
  threshold2=difference2-20;
  threshold3=difference3-10;
  threshold4=difference4-20;
  threshold5=difference5-20;
}
//void callibrate(){
//callibrate[0]= analogRead(A0);
//

