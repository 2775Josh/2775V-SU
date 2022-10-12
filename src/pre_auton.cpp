#include "vex.h"

int currentselection = 0;

bool autonSelector = true;

void pre_auton(){

Endgame.set(false);
DSwitcher.set(false);

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

else if(Confirm.pressing()){
 autonSelector = false;
}

else if(currentselection == 5){
 currentselection = 0;
}
task::sleep(20);

 }
}
