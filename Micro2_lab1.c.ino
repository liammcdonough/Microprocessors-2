 
// Eric Flynn
// Liam McDonough
// Hari Sundararaman
// Micro 2 Lab 1
// Due: 10/10/21
 // Variables
int green = 2;
int yellow = 3;
int red = 4;
int pushButton = 5;
int buzzer = 8; 

 

 
void setup() {
  // Set lights and buzzer to output
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Set button to input
  pinMode(pushButton, INPUT);


  //While loop for button not press
  while(digitalRead(pushButton) == LOW){

  //red light on
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
 
  // Delay 1 second
  delay(1000);
 
  // Red light off
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

//delay 1 sec
  delay(1000); 

//if loop for button pressed
    if(digitalRead(pushButton) == HIGH) {
     changelights();
     
      delay(5000);
    }


 }
}



 
//R-G-Y Pattern looped
void loop() {
  
  if (digitalRead(pushButton) == HIGH) {
    delay(15);
    if(digitalRead(pushButton) == HIGH) {
      changelights();
      delay(5000);
    }
  }
}  



void changelights() {

  int x =1;
  while(x == 1){
  
  // Red light on
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
 
  // Delay 17 seconds
  delay(17000);
 
 
  //Turn buzzer on 
  digitalWrite(buzzer, HIGH);
 
  
  // Turn Buzzer off after 3 seconds
  delay(3000);
  digitalWrite(buzzer, LOW);
 
  
  // Red light off, Green Light on
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
 
 
  // Delay 17 seconds
  delay(17000);
 
 
  //Turn buzzer on
  digitalWrite(buzzer, HIGH);
  
  
  // Turn Buzzer off after 3 seconds
  delay(3000);
  digitalWrite(buzzer, LOW);

 //yellow light
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  delay(3000);
 
  digitalWrite(buzzer, HIGH);
  delay(3000);
  digitalWrite(buzzer, LOW);
  
  }
}
 
 
