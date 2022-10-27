#include "vex.h"


void usercontrol( void ) {
  vex::task positiontrackingtask = task(positionTrack);
  vex::task bangbangcontrol = task(bangbangcontroller);
  vex::task PIDcontrol = task(pidcontroller);


  float throttle;
  float turn;
  float drivescalefactor = 0.09448818897;
  bool mode = 0;
  while (1) {
    throttle = drivescalefactor*Controller1.Axis3.value();
    turn = drivescalefactor*Controller1.Axis1.value();

    setDriveVoltage(throttle+turn,throttle-turn);

    if(Controller1.ButtonUp.pressing()){
      while(Controller1.ButtonUp.pressing()){}
      if(mode==0){mode=1; DSwitcher.set(true);}else{mode=0; DSwitcher.set(false);}
    }

    if(Controller1.ButtonL1.pressing()){
      while(Controller1.ButtonL1.pressing()){}
      Intake.rotateFor(fwd, 400, deg, 100, velocityUnits::pct, false);
    }

    if (Controller1.ButtonR1.pressing()) {
      Intake.spin(fwd, 100, pct);
    } else if (Controller1.ButtonR2.pressing()) {
      Intake.spin(reverse, 100, pct);
    } else if(Controller1.ButtonL2.pressing()){
      Intake.spin(fwd,40, pct);
    }
    else if (Intake.isDone()){
      Intake.stop(coast);
    }

    if (Controller1.ButtonA.pressing()) {
      velcontroller(59,1);
    } else if (Controller1.ButtonB.pressing()) {
     velcontroller(0,1);
     velcontroller(0,0);
    } else if (Controller1.ButtonX.pressing()){
     velcontroller(80,0);
    } else if (Controller1.ButtonY.pressing()){
     velcontroller(52,1);
    } 


    if (Controller1.ButtonDown.pressing() && Controller1.ButtonLeft.pressing() && Controller1.ButtonRight.pressing()){
      Endgame.set(true);
    }
    else {
    Endgame.set(false);
    }
  
   if(Controller1.ButtonA.pressing() && Controller1.ButtonX.pressing() && Controller1.ButtonY.pressing() && Controller1.ButtonB.pressing()){
     while(Controller1.ButtonA.pressing() && Controller1.ButtonX.pressing() && Controller1.ButtonY.pressing() && Controller1.ButtonB.pressing()){
     HauntedSkillsAuto();
     }
   }


  }
  }
