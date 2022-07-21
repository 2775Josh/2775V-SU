#include "vex.h"

float shootingtime = 400;
float unshootingtime = 200;

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

int bangbangcontroller() {
while(true){
 double vel = Flywheel.velocity(pct);
 error = target - vel;
 integral += error;

 power = (error *kP + integral * kI + derivative * kD + target * kF);

 Flywheel.spin(fwd, power, volt);

 vex::task::sleep(20);
 }
 
 return 0;
} 

void velcontroller(double vel){
 target = vel;
 if(target == 0){
 Flywheel.stop(coast);
 }
}


