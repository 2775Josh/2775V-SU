#include "vex.h"


float kP = .01;
float kI = .05;
float kD = 0;
float kF = .12;
float starti = 50;
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
 if (kI != 0) {
      if (fabs(error) < starti){
        integral += error;
      }
      if ((error>0 && prevError<0)||(error<0 && prevError>0)){
        integral = 0;
      }
    }
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

void matchload(float time){
  float starttime = Brain.timer(msec);
  while(Brain.timer(msec)<starttime+time){
    if(Intake.velocity(pct)<1){
      Intake.spin(reverse, 12, volt);
      task::sleep(100);
      Intake.spin(fwd, 12, volt);
      task::sleep(50);
    }
  }
}