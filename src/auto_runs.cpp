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
  velcontroller(91,1); 
  driveReset(39.5, 9, 180);
  setDriveVoltage(10, 10);
  task::sleep(250);
  Intake.rotateFor(fwd, 1500, deg, 100, velocityUnits::pct, false);
  task::sleep(750);
  straightdrive(39.5, 18);
  turntopoint(16,132, 0, 1, 2000);
  quickshoot(100,150);
  quickshoot(0,0); 
  task::sleep(400);
  quickshoot(100,400);
  velcontroller(88,1);
  turn(58, 0, 1, 100);
  Intake.spin(fwd, 12, volt);
  straightdrive(70, 46, 0, 2, 0, 10, 1, .01, 3, 10, 2, 33, 20);
  straightdrive(70, 46, 0, 2, 0, 10, .75, .01, 3, 4, 2, 2, 20);
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
  straightdrive(70, 47, 0, 2, 0, 10, .75, .01, 3, 3, 2, 2, 20);
  turntopoint(16,128, 0, 1, 40);
  task::sleep(250);
  repeat(2){
  quickshoot(100,150);
  quickshoot(0,0); 
  task::sleep(400);
   } 
  quickshoot(100,300);
  turn(35, 0, 4, 20, .4, 0);
  velcontroller(94,1);
  Intake.spin(fwd,12,volt);
  straightdrive(122, 97, 0, 2, 0, 9, 1, .01, 3, 8, 6, 4, 20, 15);
  turntopoint(18,127, 0, 1, 40);
  task::sleep(250);
  repeat(2){
  quickshoot(100,150);
  quickshoot(0,0); 
  task::sleep(400);
  } 
  quickshoot(100,300);
  task::sleep(100);
  turn(45, 0, 5, 40);
  straightdrive(130,108);
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
  velcontroller(92,1);
  driveReset(127, 87, 0); 
  straightdrive(127,107, 0, 2, 0, 10, 1, .01, 3, 7, 5, 1.5, 40);
  turn(90, 0, 1, 40);
  setDriveVoltage(4, 4);
  task::sleep(800);
  setDriveVoltage(5, 2);
  Intake.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(250);
  straightdrive(130,absGlobalY);
  turntopoint(24,128, 0, 1, 40);
  task::sleep(600);
  quickshoot(100,400);
  task::sleep(400);
  velcontroller(85,1);
  turn(-135);
  Intake.spin(fwd,12,volt);
  straightdrive(84,59, 0, 2, 0, 8, 1, .01, 3, 5);
  task::sleep(150);
  straightdrive(96,72);
  turntopoint(14,128, 0, 1, 40);
  task::sleep(250);
  repeat(2){
  quickshoot(100,150);
  quickshoot(0,0); 
  task::sleep(350);
   } 
   quickshoot(100,200);
}

void WPISkillsAuto(){
  vex::task positiontrack = task(positionTrack);
  vex::task bangbangcontrol = task(bangbangcontroller);
  vex::task PIDcontrol = task(pidcontroller);  
  float barrierspeed = 64;
  float barriercornerspeed = 85;
  float closespeed = 62;
  float farspeed = 81;
  float rollertime = 250;
  float shottime = 800;
  float starttime = Brain.timer(msec);
  Deflector.set(true);
  driveReset(36, 9, 180);
  setDriveVoltage(8, 8);
  task::sleep(100);
  velcontroller(barrierspeed,1);
  Intake.rotateFor(fwd, 600, deg, 100, velocityUnits::pct, false);
  task::sleep(rollertime);
  DriveL.spin(reverse, 20, pct);
  DriveR.rotateFor(reverse, 1100, deg, 100, velocityUnits::pct, true);
  DriveL.stop();
  Intake.spin(fwd, 100, pct);
  straightdrive(10, 24, 4000, 4, 0, 10, 1, .01, 3, 12, 8, 3);
  Intake.stop();
  setDriveVoltage(8, 8);
  task::sleep(100);
  Intake.rotateFor(fwd, 600, deg, 100, velocityUnits::pct, false);
  task::sleep(500);
  driveReset(8.5,absGlobalY,absOrientationDeg);
  DriveR.spin(reverse, 10, pct);
  task::sleep(5);
  DriveL.rotateFor(reverse, 1250, deg, 100, velocityUnits::pct, true);
  task::sleep(5);
  Intake.spin(fwd,100,pct);
  straightdrive(16, 93, 4000, 1.2, 0, 10, 1, .01, 3, 12, 8, 3, 300);
  turntopoint(21,123, 0, 1.5, 250);
  quickshoot(100,shottime);

  turn(90, 2000, 2, 20, .4, .05, 1.5, 4);
  Intake.spin(fwd, 100, pct);
  straightdrive(100, absGlobalY, 4000, 2, 0, 10, 1, .01, 3, 2.5, 0, 53);
  straightdrive(24, absGlobalY, 2000, 2, 0, 10, 1, .01, 3, 10, 0, 3);
  DriveR.rotateFor(reverse, 1000, deg, 100, velocityUnits::pct, true);
  turntopoint(21,123, 0, 1.5, 300);
  quickshoot(100,shottime);

  DriveR.rotateFor(fwd, 450, deg, 100, velocityUnits::pct, true);
  Deflector.set(false);
  velcontroller(barriercornerspeed, 1);
  Intake.spin(fwd,100,pct);
  straightdrive(39, 57, 3000, 2, 0, 10, 1, .01, 3, 12, 8, 25);
  straightdrive(39, 57, 3000, 1.5, 0, 10, 1, .01, 3, 3, 3, 3);
  task::sleep(5);
  DriveR.rotateFor(fwd, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(5);
  DriveL.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, true);
  task::sleep(5);
  straightdrive(64, 80, 4000, 2, 0, 2, .75, .001, 1.5, 4, 4, 2, 300);
  turntopoint(18,126,0,1,250);
  straightdrive(72,72,0,1.5,0,10,1,.01,3,5,0,4,250);
  repeat(2){
  quickshoot(100,200);
  quickshoot(0,0); 
  task::sleep(300);
   } 
  quickshoot(100,300);

  straightdrive(60,84,0,2,0,10,1,.01,3,12,0,4, 250);
  velcontroller(barrierspeed,1);
  Deflector.set(true);
  task::sleep(5);
  DriveR.rotateFor(fwd, 400, deg, 100, velocityUnits::pct, false);
  task::sleep(5);
  DriveL.rotateFor(reverse, 400, deg, 100, velocityUnits::pct, true);
  task::sleep(5);
  Intake.spin(fwd,100,pct);
  straightdrive(108,124,0,2,0,10,1,.01,3,8,8, 45);
  straightdrive(108,124,0,2,0,10,.75,.01,3, 3,3,3);
  DriveR.rotateFor(reverse, 700, deg, 100, velocityUnits::pct, false);
  straightdrive(75, 126, 4000, 1.2, 0, 10, 1, .01, 3, 6, 8, 3, 0);
  turn(90);
  while(Line.value(pct)>50){
    setDriveVoltage(-3,-3);
  }
  driveReset(48, absGlobalY,absOrientationDeg);
  turntopoint(20,124, 0, 1.5, 250);
  quickshoot(100,shottime);

  turn(180, 2000, 2, 20, .4, .05, 1.5, 4);
  Intake.spin(fwd, 100, pct);
  straightdrive(absGlobalX, 44, 4000, 2, 0, 10, 1, .01, 3, 2.5, 0, 53);
  straightdrive(absGlobalX, 118, 2000, 2, 0, 10, 1, .01, 3, 10, 0, 3);
  DriveL.rotateFor(reverse, 1000, deg, 100, velocityUnits::pct, true);
  turntopoint(21,123, 0, 1.5, 300);
  quickshoot(100,shottime);
  task::sleep(999999999);

  turn(-14);
  velcontroller(closespeed, 1);
  Deflector.set(true);
  Intake.spin(fwd,100,pct);
  setDriveVoltage(3,4);
  task::sleep(3000);
  turntopoint(18,126);
  quickshoot(100,shottime);


  Intake.spin(fwd, 100, pct);
  DriveL.rotateFor(fwd, 300, deg, 100, velocityUnits::pct, true);
  Deflector.set(false);
  velcontroller(farspeed,1);
  straightdrive(84, 108, 4000, 2, 0, 10, .4, .05, 1.5, 10, 4, 26);
  straightdrive(84, 108, 4000, 2, 0, 10, .4, .05, 1.5, 1.5, 4, 2, 750);
  turntopoint(18,128);
  Intake.stop();
  task::sleep(200);
  repeat(2){
  quickshoot(100,200);
  quickshoot(0,0); 
  task::sleep(350);
  } 
  quickshoot(100,500);

  straightdrive(80,112,4000,2,0,10,1,.01,3,9,8,5,20);
  turn(90);
  Intake.spin(fwd,100,pct);
  Deflector.set(true);
  velcontroller(closespeed, 1);
  DriveR.rotateFor(fwd, 400, deg, 100, velocityUnits::pct, false);
  straightdrive(135, 108, 4000, 2, 0, 10, 1, .01, 3, 9, 5, 45);
  straightdrive(135, 108, 4000, 2, 0, 10, 1, .01, 3, 3, 5, 5);
  setDriveVoltage(8, 8);
  task::sleep(250);
  Intake.rotateFor(fwd, 900, deg, 100, velocityUnits::pct, false);
  task::sleep(rollertime);
  driveReset(135,absGlobalY,absOrientationDeg);
  straightdrive(106,108,4000,2,0,10,.6,.01,3,3,2,2);
  turn(0, 0, 1, 200);
  straightdrive(108, 135, 4000, 2, 0, 10, 1, .01, 3, 10, 5, 5);
  setDriveVoltage(8, 8);
  task::sleep(250);
  Intake.rotateFor(fwd, 900, deg, 100, velocityUnits::pct, false);
  task::sleep(rollertime);
  driveReset(144-absGlobalX,8.5,absOrientationDeg+180);
  setDriveVoltage(0, 0);
  DriveL.rotateFor(reverse,300,deg,100,velocityUnits::pct,false);
  task::sleep(500);
  straightdrive(24,24,0,2,0,10,1,.01,3,5,5,2,500);
  turn(-135);
  Endgame.set(true);
  task::sleep(999999999);
  straightdrive(12, 92, 4000, 1.5, 0, 10, 1, .01, 3, 12, 8, 3);
  turntopoint(19,124, 0, 1.5);
  quickshoot(100,shottime);



  velcontroller(barriercornerspeed,1);
  DriveR.rotateFor(fwd, 450, deg, 100, velocityUnits::pct, true);
  Deflector.set(false);
  Intake.spin(fwd,100,pct);
  straightdrive(36,60, 4000, 1, 0, 10, 1, .01, 3, 10, 8, 3);
  DriveR.rotateFor(fwd, 480, deg, 100, velocityUnits::pct, false);
  DriveL.rotateFor(reverse, 480, deg, 100, velocityUnits::pct, true);
  straightdrive(60, 84, 4000, 2, 0, 10, 1.5, .001, 3, 5, 4, 2);
  turntopoint(18,126);
  quickshoot(100,shottime);

  if (Brain.timer(msec)-starttime<45000){
  turn(0);
  velcontroller(closespeed, 1);
  Deflector.set(true);
  Intake.spin(fwd,100,pct);
  setDriveVoltage(2.5,4);
  task::sleep(3000);
  turntopoint(18,126);
  quickshoot(100,shottime);


  Intake.spin(fwd, 100, pct);
  DriveL.rotateFor(fwd, 300, deg, 100, velocityUnits::pct, true);
  Deflector.set(false);
  velcontroller(farspeed,1);
  straightdrive(84, 108, 4000, 2, 0, 10, .4, .05, 1.5, 10, 4, 26);
  straightdrive(84, 108, 4000, 2, 0, 10, .4, .05, 1.5, 1.5, 4, 2, 750);
  turntopoint(18,128);
  Intake.stop();
  task::sleep(200);
  repeat(2){
  quickshoot(100,200);
  quickshoot(0,0); 
  task::sleep(350);
  } 
  quickshoot(100,500);
  }

  straightdrive(120,120,0,2,0,10,1,.01,3, 8, 8, 3, 300);
  turn(45);
  Endgame.set(true);
  task::sleep(999999999);
}