#include "vex.h"

float flywheelVelocity = 0;

float kP = .02;
float kF = .12;
float error = 0;
float power = 0;
float target = 0;

int bangbangcontroller() {
while(true){
 double vel = Flywheel.velocity(pct);
 error = target - vel;

 power = (error *kP + target * kF);
 
   if( vel < target){
   Flywheel.spin(fwd, 12, volt);
   }
  else{
    Flywheel.spin(fwd, 0, volt);
 }

 if (target == 0){
   Flywheel.stop(coast);
 }   else if (vel < (target - 10)){
   Flywheel.spin(fwd, 12, volt);
 } else {
 Flywheel.spin(fwd, power, volt);
 }

 
 vex::task::sleep(20);
 }
 
 return 0;

} 

void velcontroller(double vel){
 target = vel;
}

void quickshoot(float speed, float sleep){
  Intake.spin(reverse,speed,pct);
  task::sleep(sleep);
}