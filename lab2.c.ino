#include<Wire.h>
#include<MPU6050.h>
const int MPU=0x6B; 
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;


//joystick
int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 

  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);

}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, 512, -512);

  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);


if (mapX == 12 && mapY == 512){
  Serial.print("w\n");
 delay(10);
}
if (mapX == 12 && mapY == -512){
  Serial.print("s\n");
 delay(10);
}
if (mapX == -512 && mapY == 12){
  Serial.print("a\n");
 delay(10);
}
if (mapX == 512 && mapY == 12){
  Serial.print("d\n");
 delay(10);
}

//gyro
/*
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  

  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");
  delay(100);
*/

  delay(10);

}
