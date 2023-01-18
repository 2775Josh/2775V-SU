#include "vex.h"

int currentselection = 0;

bool autonSelector = true;

void pre_auton(){

  

  Endgame.set(false);
  Deflector.set(false);
  
  if (!(R1.installed() && 
        R2.installed() && 
        R3.installed() && 
        L1.installed() && 
        L2.installed() && 
        L3.installed() && 
        Intake.installed() && 
        Flywheel.installed() &&
        Gyro.installed())){
    while(1){
      Controller1.rumble("-");
      task::sleep(20);
    }
  }

  while(autonSelector){

    Brain.Screen.clearScreen();

    switch(currentselection){
    case 0:
      Brain.Screen.printAt(50, 50, "No Auto");

      Brain.Screen.printAt(50, 70, "%f Degrees", Gyro.rotation(deg));
      break;
    case 1:
      Brain.Screen.printAt(50, 50, "Skills");

      Brain.Screen.printAt(50, 70, "%f Degrees", Gyro.rotation(deg));
      break;
    case 2:
      Brain.Screen.printAt(50, 50, "Left");

      Brain.Screen.printAt(50, 70, "%f Degrees", Gyro.rotation(deg));
      break;
    case 3:
      Brain.Screen.printAt(50, 50, "Right");

      Brain.Screen.printAt(50, 70, "%f Degrees", Gyro.rotation(deg));
      break;
    case 4:
      Brain.Screen.printAt(50, 50, "AWP");

      Brain.Screen.printAt(50, 70, "%f Degrees", Gyro.rotation(deg));
      break;
    }


    if(Cycle.pressing()){
      while(Cycle.pressing()) {}
    currentselection ++;
    }

    else if(currentselection == 6){
    currentselection = 0;
    }
    task::sleep(20);

  }
}