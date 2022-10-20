#include "vex.h"


float kP = .2;
float kI = 0;
float kD = 0;
float kF = .12;
float target = 0;
float error = 0;
float integral = 0;
float prevError = error;
float derivative = error - prevError;
float power = 0;
bool mode = 0;

int pidcontroller() {
while(true){
 double vel = Flywheel.velocity(pct);
 error = target - vel;
 integral += error;
 derivative = error - prevError;

 power = (error *kP + integral * kI + derivative * kD + target * kF);

 prevError = error;
 if (target == 0){
   Flywheel.stop(coast);
 }
 
 else if (mode == 0){
 Flywheel.spin(fwd, power, volt);
 }

 vex::task::sleep(20);
 }
 
 return 0;
} 

int bangbangcontroller() {
while(true){
 double vel = Flywheel.velocity(pct);
 if (vel<target){
   power=100;
 }else{
   power=0;
 }

 prevError = error;
 if (target == 0){
   Flywheel.stop(coast);
 }
 
 else if (mode == 1){
 Flywheel.spin(fwd, power, volt);
 }

 vex::task::sleep(20);
 }
 
 return 0;
} 

void velcontroller(double vel, bool controltype){
 target = vel;
 mode = controltype;
}

void quickshoot(float speed, float sleep){
  Intake.spin(reverse,speed,pct);
  task::sleep(sleep);
}