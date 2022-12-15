#include "vex.h"

/*void twelveSkillsAuto() {
  vex::task positiontrack = task(positionTrack);
  task::sleep(250);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(34, 10, 180);
  straightdrive(38, 14, 0, 1.5, 0, 1, 1, 0, 2.5, 8, 4, 1, 300);
  turn(-45);
  Intake.spin(fwd, 100, pct);
  straightdrive(16, 30, 0, 1, 0, 3, 1, 0, 2.5, 6, 4);
  turn(-90);
  Intake.stop(coast);
  setDriveVoltage(4, 4);
  task::sleep(1000);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(10, absGlobalY, -90);
  velcontroller(68);
  straightdrive(20, 30, 0, 1.5, 0, 1, 1, 0, 2.5, 8, 4, 3, 20);
  turn(0);
  straightdrive(20, 78);
  turntopoint(15, 128, 0, 1, 750);
  Intake.spin(reverse, 100, pct);
  Intake.spin(fwd, 100, pct);
  velcontroller(71);
  straightdrive(20, 44);
  straightdrive(60, 84, 0, 1, 0, 3, 1, 0, 2.5, 4, 4, 1.5, 20);
  turntopoint(15, 128, 0, 1, 750);
  Intake.spin(reverse, 100, pct);
  straightdrive(61, 83);
  velcontroller(68);
  turn(45);
  Intake.spin(fwd, 100, pct);
  straightdrive(96, 124, 0, 1, 0, 3, 1, 0, 2.5, 10, 4, 36);
  straightdrive(96, 124, 0, 1, 0, 3, 1, 0, 2.5, 3, 4, 1.5);
  turn(0, 0, 1, 500);
  setDriveVoltage(4, 4);
  task::sleep(1500);
  driveReset(absGlobalX, 134, 0);
  straightdrive(96, 120);
  turn(-90);
  straightdrive(66, 120);
  turntopoint(18, 124, 0, 1, 750);
  Intake.spin(reverse, 100, pct);
  straightdrive(92, 124);
  turn(135);
  Intake.spin(fwd, 100, pct);
  straightdrive(120, 96, 0, 1, 0, 3, 1, 0, 2.5, 3, 4, 1.5, 20);
  turn(90, 0, 1, 300);
  setDriveVoltage(4, 4);
  task::sleep(1500);
  driveReset(134, absGlobalY, 90);
  straightdrive(120, 96);
  turn(180);
  velcontroller(69);
  straightdrive(120,66);
  turntopoint(128, 18, 0, .5, 750);
  Intake.spin(reverse, 100, pct);
  turn(0);
  Intake.spin(fwd, 100, pct);
  straightdrive(116, 126);
  turn(0, 0, 1, 500);
  Intake.stop(coast);
  setDriveVoltage(4, 4);
  task::sleep(1500);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(absGlobalX, 134, 0);
  straightdrive(122, 116, 0, 1, 0, 3, 1, 0, 2.5, 6, 4);
  turn(90, 0, 1, 500);
  Intake.stop(coast);
  setDriveVoltage(4, 4);
  task::sleep(1500);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(134, absGlobalY, Gyro.heading());
  straightdrive(126, 126);
  turn(-138, 0, .5, 1000);
}

void fifteenSkillsAuto() {
  vex::task positiontrack = task(positionTrack);
  setDriveVoltage(4, 4);
  task::sleep(250);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(34, 10, 180);
  straightdrive(39, 15, 0, 1.5, 0, 1, 1, 0, 2.5, 8, 4, 3, 20);
  Intake.spin(fwd, 100, pct);
  straightdrive(15, 30, 0, 1, 0, 3, 1, 0, 2.5, 6, 4, 2);
  turn(-90);
  Intake.stop(coast);
  setDriveVoltage(7, 7);
  task::sleep(750);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(10, absGlobalY, -90);
  velcontroller(68);
  straightdrive(20, 30, 0, 1.5, 0, 1, 1, 0, 2.5, 8, 4, 3, 20);
  turn(0, 0, 4, 20);
  straightdrive(20, 78, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 3, 20);
  turntopoint(15, 128, 0, 1, 250);
  Intake.spin(reverse, 100, pct);
  Intake.spin(fwd, 100, pct);
  velcontroller(72);
  straightdrive(20, 44, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 3);
  straightdrive(60, 84, 0, 1, 0, 3, 1, 0, 2.5, 6, 4, 1.5, 20);
  turntopoint(15, 128, 0, 1, 250);
  Intake.spin(reverse, 100, pct);
  velcontroller(69);
  turn(45, 0, 3, 20);
  Intake.spin(fwd, 100, pct);
  straightdrive(96, 124, 0, 1, 0, 3, 1, 0, 2.5, 6, 4);
  turn(0, 0, 1, 250);
  setDriveVoltage(7, 7);
  task::sleep(1500);
  driveReset(absGlobalX, 134, 0);
  straightdrive(96, 120, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 1.5, 20);
  turn(-90, 0, 3, 20);
  Intake.spin(reverse, 100, pct);
  straightdrive(66, 120);
  turntopoint(18, 122, 0, 1, 250);
  straightdrive(92, 124, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 2);
  turn(135, 0, 3, 20);
  Intake.spin(fwd, 100, pct);
  straightdrive(120, 96, 0, 1, 0, 3, 1, 0, 2.5, 5, 4, 1.5, 20);
  turn(90, 0, 1, 100);
  setDriveVoltage(7, 7);
  task::sleep(1000);
  driveReset(134, absGlobalY, 90);
  straightdrive(119, 96, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 3);
  turn(180, 0, 3, 20);
  velcontroller(70);
  straightdrive(120,66);
  turntopoint(129, 17, 0, .5, 250);
  Intake.spin(reverse, 100, pct);
  velcontroller(75);
  straightdrive(120, 100, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 4, 20);
  Intake.spin(fwd, 100, pct);
  straightdrive(84, 60, 0, 1, 0, 3, 1, 0, 2.5, 6, 4, 1.5, 20);
  turntopoint(129, 17, 0, 1, 250);
  turn(-135, 0, 3, 20);
  straightdrive(44, 20, 0, 1, 0, 3, 1, 0, 2.5, 6, 4);
  straightdrive(84, 60, 0, 1, 0, 3, 1, 0, 2.5, 6, 4, 1.5, 20);
  Intake.spin(reverse, 100, pct);
  turntopoint(129, 17, 0, 1, 250);
  turn(45, 0, 3, 20);
  straightdrive(120, 100, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 5, 20);
  turn(0, 0, 3, 20);
  Intake.spin(fwd, 100, pct);
  straightdrive(116, 126, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 1.5, 20);
  turn(0, 0, 1, 100);
  Intake.stop(coast);
  setDriveVoltage(7, 7);
  task::sleep(1000);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(absGlobalX, 134, 0);
  straightdrive(122, 116, 0, 1, 0, 3, 1, 0, 2.5, 10, 4, 1.5);
  turn(90, 0, 1, 100);
  Intake.stop(coast);
  setDriveVoltage(7, 7);
  task::sleep(1000);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(134, absGlobalY, Gyro.heading());
  straightdrive(126, 126);
  turn(-135, 0, .5, 100);
}*/

void leftAuto(){
  vex::task bangbangcontrol = task(bangbangcontroller);
  vex::task positiontrack = task(positionTrack);
  vex::task PIDcontrol = task(pidcontroller); 
  DSwitcher.set(true);
  velcontroller(91,1); 
  driveReset(39.5, 9, 180);
  setDriveVoltage(10, 10);
  task::sleep(250);
  Intake.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(250);
  DSwitcher.set(false);
  straightdrive(39.5, 18);
  turntopoint(19,132, 0, 1, 1500);
  quickshoot(100,150);
  quickshoot(0,0); 
  task::sleep(400);
  quickshoot(100,400);
  velcontroller(88,1);
  turn(58, 0, 1, 100);
  Intake.spin(fwd, 12, volt);
  straightdrive(72, 48, 0, 2, 0, 10, 1, .01, 3, 10, 2, 36, 20);
  straightdrive(72, 48, 0, 2, 0, 10, 1, .01, 3, 3, 2, 2, 20);
  task::sleep(500);
  straightdrive(58,35);
  turntopoint(16,132, 0, 1, 300);
  repeat(2){
  quickshoot(100,150);
  quickshoot(0,0); 
  task::sleep(350);
   } 
  quickshoot(100,400);
}

void sixDiscLeftAuto(){
  vex::task bangbangcontrol = task(bangbangcontroller);
  vex::task positiontrack = task(positionTrack);
  vex::task PIDcontrol = task(pidcontroller); 
  DSwitcher.set(true);
  wait(100, msec);
  velcontroller(92,1); 
  driveReset(39.5, 9, 180);
  setDriveVoltage(10, 10);
  task::sleep(250);
  Intake.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(250);
  DSwitcher.set(false);
  straightdrive(39.5, 20);
  turntopoint(19,132, 0, 1, 1500);
  repeat(2){
  Intake.rotateFor(reverse, 250, deg, 100, velocityUnits::pct, true);
  wait(300, msec);
   } 
  velcontroller(87,1);
  turn(58, 0, 1, 100);
  Intake.spin(fwd, 12, volt);
  straightdrive(72, 48, 0, 2, 0, 10, 1, .01, 3, 10, 2, 36, 20);
  straightdrive(76, 50, 0, 2, 0, 10, 1, .01, 3, 3, 2, 2, 20);
  task::sleep(500);
  turntopoint(16,132, 0, 1, 300);
  repeat(3){
  Intake.rotateFor(reverse, 200, deg, 100, velocityUnits::pct, true);
  wait(250, msec);
   } 
  velcontroller(83, 1);
  turn(110);
  Intake.spin(fwd, 12, volt);
  setDriveVoltage(6, 6);
  wait(400, msec);
  straightdrive(76, 50, 0, 2, 0, 10, 1, .01, 3, 6, 2, 2, 20);
  turntopoint(16,132, 0, 1, 300);
  quickshoot(100,400);
  
}

void WPAuto(){
  vex::task bangbangcontrol = task(bangbangcontroller);
  vex::task positiontrack = task(positionTrack);
  vex::task PIDcontrol = task(pidcontroller); 
  velcontroller(85,1); 
  driveReset(36, 9, 180);
  setDriveVoltage(6, 6);
  task::sleep(250);
  Intake.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(250);
  straightdrive(36, 17, 0, 2, 0, 10, 1, 0, 3, 10, 7, 6);
  turn(66, 0, 3, 20, .4, 0);
  Intake.spin(fwd, 12, volt);
  straightdrive(70, 47, 0, 2, 0, 10, 1, .01, 3, 10, 2, 34, 20);
  straightdrive(70, 45, 0, 2, 0, 10, .75, .01, 3, 3, 2, 2, 20);
  turntopoint(17,129, 0, 1, 40);
  task::sleep(250);
  repeat(3){
  Intake.rotateFor(reverse, 215, deg, 100, velocityUnits::pct, true);
  wait(300, msec);
   } 
  turn(35, 0, 4, 20, .4, 0);
  velcontroller(93,1);
  Intake.spin(fwd,12,volt);
  straightdrive(122, 97, 0, 2, 0, 9, 1, .01, 3, 8, 6, 4, 20, 15);
  turntopoint(18,127, 0, 1, 40);
  task::sleep(250);
  repeat(3){
  Intake.rotateFor(reverse, 225, deg, 100, velocityUnits::pct, true);
  wait(275, msec);
   } 
  task::sleep(100);
  turn(45, 0, 5, 40);
  straightdrive(130,105);
  turn(90, 0, 1, 40);
  Intake.stop();
  setDriveVoltage(4, 4);
  task::sleep(500);
  setDriveVoltage(4, 0);
  task::sleep(100);
  Intake.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, false);
}

void rightAuto(){
  vex::task bangbangcontrol = task(bangbangcontroller);
  vex::task positiontrack = task(positionTrack);
  vex::task PIDcontrol = task(pidcontroller); 
  DSwitcher.set(true);
  velcontroller(88,1);
  driveReset(127, 87, 0); 
  straightdrive(127,107, 0, 2, 0, 10, 1, .01, 3, 7, 5, 1.5, 40);
  turn(90, 0, 1, 40);
  setDriveVoltage(4, 4);
  task::sleep(800);
  setDriveVoltage(5, 2);
  Intake.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(250);
  DSwitcher.set(false);
  straightdrive(120,absGlobalY);
  wait(250, msec);
  turntopoint(24,127, 0, 1, 40);  
  Intake.rotateFor(reverse, 225, deg, 100, velocityUnits::pct, false);
  wait(500, msec);
  quickshoot(100, 400);
  velcontroller(87,1);
  turn(-135);
  Intake.spin(fwd,12,volt);
  straightdrive(84,59, 0, 2, 0, 8, 1, .01, 3, 5);
  task::sleep(150);
  straightdrive(96,72);
  turntopoint(14,128, 0, 1, 40);
  task::sleep(250);
  repeat(2){
  Intake.rotateFor(reverse, 225, deg, 100, velocityUnits::pct, false);
  wait(375, msec);
  }
  quickshoot(100, 400);
  turn(177);
  velcontroller(85,1);
  Intake.spin(fwd, 12, volt);
  straightdrive(96, 57, 0, 2, 0, 10, 1, .01, 3, 6, 4);
  wait(100, msec);
  straightdrive(96,72);
  wait(100, msec);
  turntopoint(14,128, 0, 1, 40);
  wait(100, msec);
  Intake.spin(reverse, 12, volt);
}

void WPISkillsAuto(){
  vex::task positiontrack = task(positionTrack);
  vex::task bangbangcontrol = task(bangbangcontroller);
  vex::task PIDcontrol = task(pidcontroller);  
  float barrierspeed = 62;
  float crosscourtspeed = 84.5;
  float rollertime = 400;
  float rollerrotation = 500;
  float shottime = 850;
  float starttime = Brain.timer(msec);
  Deflector.set(true);
  driveReset(36, 9, 180);
  setDriveVoltage(8, 8);
  task::sleep(100);
  velcontroller(barrierspeed,1);
  Intake.rotateFor(fwd, rollerrotation, deg, 100, velocityUnits::pct, false);
  task::sleep(rollertime);
  DriveL.spin(reverse, 20, pct);
  DriveR.rotateFor(reverse, 1100, deg, 100, velocityUnits::pct, true);
  DriveL.stop();
  Intake.spin(fwd, 100, pct);
  straightdrive(10, 24, 4000, 4, 0, 10, 1, .01, 3, 12, 8, 3);
  Intake.stop();
  setDriveVoltage(8, 8);
  task::sleep(100);
  Intake.rotateFor(fwd, rollerrotation, deg, 100, velocityUnits::pct, false);
  task::sleep(rollertime);
  driveReset(8.5,absGlobalY,absOrientationDeg);
  DriveR.spin(reverse,1,pct);
  task::sleep(5);
  DriveL.setRotation(0, deg);
  while(DriveL.rotation(deg)>-1300){
    DriveL.spin(reverse,12,volt);
  }
  task::sleep(5);
  Intake.spin(fwd,100,pct);
  straightdrive(15, 93, 2500, 1.2, 0, 10, 1, .01, 3, 12, 8, 3, 0);
  turntopoint(21,123, 0, 2, 200);
  quickshoot(100,shottime);

  turn(90, 2000, 2, 20, .4, .05, 1.5, 4);
  Intake.spin(fwd, 100, pct);
  straightdrive(100, absGlobalY, 4000, 2, 0, 10, 1, .01, 3, 3, 0, 53);
  straightdrive(22, absGlobalY, 2000, 2, 0, 10, 1, .01, 3, 10, 0, 5);
  DriveR.rotateFor(reverse, 1100, deg, 100, velocityUnits::pct, true);
  turntopoint(21,123, 0, 3, 300);
  quickshoot(100,shottime);

  DriveR.rotateFor(fwd, 450, deg, 100, velocityUnits::pct, true);
  Deflector.set(false);
  velcontroller(crosscourtspeed, 1);
  Intake.spin(fwd,100,pct);
  straightdrive(39, 57, 3000, 2, 0, 10, 1, .01, 3, 12, 8, 25);
  straightdrive(39, 57, 3000, 1.5, 0, 10, .6, .01, 3, 3, 3, 3);
  task::sleep(5);
  DriveR.rotateFor(fwd, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(5);
  DriveL.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, true);
  task::sleep(5);
  straightdrive(66, 82, 4000, 2, 0, 10, .6, .001, 1.5, 3.5, 4, 2, 250);
  turntopoint(123,18,0,1,300);
  repeat(2){
  quickshoot(100,200);
  quickshoot(0,0); 
  task::sleep(300);
   } 
  quickshoot(100,400);

  velcontroller(barrierspeed,1);
  task::sleep(5);
  DriveL.rotateFor(fwd, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(5);
  DriveR.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, true);
  task::sleep(5);
  Deflector.set(true);
  Intake.spin(fwd,100,pct);
  straightdrive(105,129,0,2,0,10,1,.01,3,8,8, 40);
  straightdrive(105,129,0,2,0,10,.75,.01,3, 3, 5, 2);
  setDriveVoltage(2, 10);
  Intake.stop(coast);
  task::sleep(400);
  setDriveVoltage(8, 8);
  Intake.rotateFor(fwd, rollerrotation, deg, 100, velocityUnits::pct, false);
  task::sleep(rollertime);
  driveReset(absGlobalX,135,absOrientationDeg);
  DriveL.spin(reverse,1,pct);
  task::sleep(5);
  DriveR.setRotation(0, deg);
  while(DriveR.rotation(deg)>-1250){
    DriveR.spin(reverse,12,volt);
  }
  task::sleep(5);
  Intake.spin(fwd,100,pct);
  straightdrive(49, 130, 2500, 1.2, 0, 10, 1, .01, 3, 12, 8, 3, 0);
  turntopoint(21,124, 0, 2, 200);
  quickshoot(100,shottime);

  DriveL.rotateFor(fwd, 400, deg, 100, velocityUnits::pct,true);
  Intake.spin(fwd,100,pct);
  straightdrive(133,98,0,2,0,10,1,.01,3,8,8, 40);
  straightdrive(133,98,0,2,0,10,.75,.01,3, 3, 5, 2);
  DriveL.rotateFor(reverse, 400, deg, 100, velocityUnits::pct,true);
  task::sleep(300);

  //HALFWAY

  setDriveVoltage(8,8);
  task::sleep(500);
  Intake.rotateFor(fwd, rollerrotation, deg, 100, velocityUnits::pct, false);
  task::sleep(rollertime);
  driveReset(8.5,141-absGlobalY,absOrientationDeg+180);
  DriveR.spin(reverse,1,pct);
  task::sleep(5);
  DriveL.setRotation(0, deg);
  while(DriveL.rotation(deg)>-1250){
    DriveL.spin(reverse,12,volt);
  }
  task::sleep(5);
  Intake.spin(fwd,100,pct);
  straightdrive(16, 93, 2500, 1.2, 0, 10, 1, .01, 3, 12, 8, 3, 0);
  turntopoint(21,123, 0, 2, 200);
  quickshoot(100,shottime);

  turn(90, 2000, 2, 20, .4, .05, 1.5, 4);
  Intake.spin(fwd, 100, pct);
  straightdrive(100, absGlobalY, 4000, 2, 0, 10, 1, .01, 3, 3, 0, 53);
  straightdrive(22, absGlobalY, 2000, 2, 0, 10, 1, .01, 3, 10, 0, 5);
  DriveR.setRotation(0, deg);
  while(DriveR.rotation(deg)>-1250){
    DriveR.spin(reverse,12,volt);
  }
  turntopoint(21.5,123, 0, 3, 300);
  quickshoot(100,shottime);

  DriveR.rotateFor(fwd, 450, deg, 100, velocityUnits::pct, true);
  Deflector.set(false);
  velcontroller(crosscourtspeed, 1);
  Intake.spin(fwd,100,pct);
  straightdrive(39, 57, 3000, 2, 0, 10, 1, .01, 3, 12, 8, 25);
  straightdrive(39, 57, 3000, 1.5, 0, 10, .6, .01, 3, 3, 3, 3);
  task::sleep(5);
  DriveR.rotateFor(fwd, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(5);
  DriveL.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, true);
  task::sleep(5);
  straightdrive(66, 82, 4000, 2, 0, 10, .6, .001, 1.5, 3.5, 4, 2, 250);
  turntopoint(121,18,0,1,300);
  repeat(2){
  quickshoot(100,200);
  quickshoot(0,0); 
  task::sleep(300);
   } 
  quickshoot(100,400);


  velcontroller(barrierspeed,1);
  task::sleep(5);
  DriveL.rotateFor(fwd, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(5);
  DriveR.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, true);
  task::sleep(5);
  Deflector.set(true);
  Intake.spin(fwd,100,pct);
  straightdrive(100,121,0,2,0,10,1,.01,3,8,8, 30);
  straightdrive(100,121,0,2,0,10,.75,.01,3, 2.5, 5, 2);
  DriveR.rotateFor(reverse, 450, deg, 100, velocityUnits::pct, true);
  straightdrive(51, 130, 2500, 1.2, 0, 10, 1, .01, 3, 12, 8, 3, 0);
  turntopoint(21,124, 0, 2, 200);
  quickshoot(100,shottime);

  straightdrive(124,116);
  turn(45);
  Endgame.set(true);
  Endgame2.set(true);
  task::sleep(999999999);
}