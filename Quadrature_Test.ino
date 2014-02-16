
//Spencer Neilan, 2014
//Senior Design Project Powder Horn, Team221 Robotics LLC
//This program tests the Quadrature Subsystem, by interfacing to the ATTiny45s via I2C.
//modified  on 2/7/2014.
#include <Wire.h>
#include <TQED.h>


unsigned long qed0time, qed1time;  //timestamp the speed values
long qed0old, qed1old;    //
long qed0new, qed1new;
float speed0, speed1;

  TQED qed0(byte(0x36));
  TQED qed1(byte(0x37));

void setup()
{
  Serial.begin(115200);  // start serial for output
  Serial.println("TQED Test");

  qed0time=qed1time=millis();
  Wire.begin();
}

float getSpeed(TQED qed){
  static unsigned long lastTime=0;
  //units of ticks per second
  float speed = 1000000.0*(float)((32767.0-qed.getCount())/(micros()-lastTime));
  //bring the count back to 32767
  qed.centerCount();
  lastTime = micros();
  return speed;
}


void loop()
{
//qed0.resetCount();
  float speed0 = getSpeed(qed0);
  uint16_t count=qed0.getCount();
  Serial.print("QED0: ");
  Serial.println(speed0);
  delay(100);
//  qed0new=qed0.getCount();
//  qed1new=qed1.getCount();
//  
//  //calculate the speed. This should be negative if reversing
//  //later, disregard this value if it's greater than 1000
//  float speedold=speed0;
//  speed0=((float)(qed0new-qed0old))/(millis()-qed0time);
//  if(speed0>1000.0) speed0=speedold;
//  speed1=((float)(qed1new-qed1old))/(millis()-qed1time);
//  
//  //Display the counter value
//  Serial.println((float) (qed0new-qed0old));
//  Serial.println(millis() - qed0time);
//  delay(100);
//  
//  Serial.print("QED0: ");
//  Serial.print(qed0new);
//  //Serial.print(" QED1: ");
//  //Serial.print(qed1new);
//  //Display the speed
//  Serial.print(" speed0: ");
//  Serial.print(speed0);
//  //Serial.print(" speed1: ");
//  //Serial.print(speed1);
//  Serial.println();
//  
//  qed0time=qed1time=millis();
//  qed0old=qed0new;
//  qed1old=qed1new;
//  
//  //when qed count gets closer to 
//  
}

void ChangeAddress(TQED qed)
{
  Serial.println("Changing address to 0x38");
  qed.setAddress(0x38);
}

void Center(TQED qed)
{
  qed.centerCount();
}

void Reset()
{
  qed0.resetCount();
  qed1.resetCount();
}


