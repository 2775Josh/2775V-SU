#include "vex.h"

int currentselection = 0;

bool autonSelector = true;

void pre_auton(){

  Endgame.set(false);
  Deflector.set(false);
  
  if (!(R1.installed() && R2.installed() && R3.installed() && L1.installed() && L2.installed() && L3.installed() && Intake.installed() && Flywheel.installed())){
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
      break;
    case 1:
      Brain.Screen.printAt(50, 50, "Skills");
      break;
    case 2:
      Brain.Screen.printAt(50, 50, "Left");
      break;
    case 3:
      Brain.Screen.printAt(50, 50, "Right");
      break;
    case 4:
      Brain.Screen.printAt(50, 50, "AWP");
      break;
    }


    if(Cycle.pressing()){
      while(Cycle.pressing()) {}
    currentselection ++;
    }

    else if(currentselection == 5){
    currentselection = 0;
    }
    task::sleep(20);

  }
}