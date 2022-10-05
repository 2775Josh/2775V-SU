#include "vex.h"



void usercontrol( void ) {
  vex::task positiontrackingtask = task(positionTrack);
  vex::task bangbangcontrol = task(bangbangcontroller);

  float throttle;
  float turn;
  float drivescalefactor = 0.09448818897;
  while (1) {
    throttle = drivescalefactor*Controller1.Axis3.value();
    turn = drivescalefactor*Controller1.Axis1.value();

    setDriveVoltage(throttle+turn,throttle-turn);

    if(Controller1.ButtonL2.pressing()){
      while(Controller1.ButtonL2.pressing()){}
    Intake.rotateFor(fwd, 95, deg, 100, velocityUnits::pct, false);
    }

    if (Controller1.ButtonR1.pressing()) {
      Intake.spin(fwd, 100, pct);
    } else if (Controller1.ButtonR2.pressing()) {
      Intake.spin(reverse, 100, pct);
    } else if (Intake.isDone()){
      Intake.stop(coast);
    }

    if (Controller1.ButtonA.pressing()) {
      velcontroller(70);
    } else if (Controller1.ButtonB.pressing()) {
     velcontroller(0);
    } else if (Controller1.ButtonX.pressing()){
     velcontroller(90);
    }

    if (Controller1.ButtonA.pressing()){
    Endgame3.set(false);
    }
    else {
    Endgame3.set(true);
    }
  
  }
  }
