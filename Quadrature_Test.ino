
//Spencer Neilan, 2014
//Senior Design Project Powder Horn, Team221 Robotics LLC
//This program tests the Quadrature Subsystem, by interfacing to the ATTiny45s via I2C.

#include <Wire.h>
#include <TQED.h>

TQED qed0(0x36);
TQED qed1(0x37);
unsigned long qed0time, qed1time;
unsigned int qed0old, qed1old;
unsigned int qed0new, qed1new;
unsigned int speed0, speed1;

void setup()
{
  qed0time=qed1time=millis();
  Serial.begin(115200);  // start serial for output
  Serial.println("TQED Test");
}

void loop()
{
  qed0new=qed0.getCount();
  qed1new=qed1.getCount();
  
  //calculate the speed. This should be negative if reversing
  speed0=(qed0new-qed0old)/(qed0time-millis());
  speed1=(qed1new-qed1old)/(qed1time-millis());
  
  //Display the counter value
  Serial.print("QED0: ");
  Serial.print(qed0new);
  Serial.print(" QED1: ");
  Serial.print(qed1new);
  //Display the speed
  Serial.print(" speed0: ");
  Serial.print(speed0);
  Serial.print(" speed1: ");
  Serial.print(speed1);
  
  delay(100);
  qed0time=qed1time=millis();
  qed0old=qed0new;
  qed1old=qed1new;
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


