#include "vex.h"

void twelveSkillsAuto() {
  vex::task positiontrack = task(positionTrack);
  vex::task velcontrol = task(bangbangcontroller);
  setDriveVoltage(4, 4);
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
  repeat(3){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(600);
  }
  Intake.spin(fwd, 100, pct);
  velcontroller(71);
  straightdrive(20, 44);
  straightdrive(60, 84, 0, 1, 0, 3, 1, 0, 2.5, 4, 4, 1.5, 20);
  turntopoint(15, 128, 0, 1, 750);
  Intake.spin(reverse, 100, pct);
  repeat(3){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(600);
  }
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
  repeat(3){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(600);
  }
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
  repeat(3){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(600);
  }
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
  Endgame.set(true);
}

void fifteenSkillsAuto() {
  vex::task positiontrack = task(positionTrack);
  vex::task velcontrol = task(bangbangcontroller);
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
  repeat(2){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(unshootingtime);
  }
  Indexer.set(false);
  task::sleep(shootingtime);
  Indexer.set(true);
  Intake.spin(fwd, 100, pct);
  velcontroller(72);
  straightdrive(20, 44, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 3);
  straightdrive(60, 84, 0, 1, 0, 3, 1, 0, 2.5, 6, 4, 1.5, 20);
  turntopoint(15, 128, 0, 1, 250);
  Intake.spin(reverse, 100, pct);
  repeat(2){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(unshootingtime);
  }
  Indexer.set(false);
  task::sleep(shootingtime);
  Indexer.set(true);
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
  repeat(2){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(unshootingtime);
  }
  Indexer.set(false);
  task::sleep(shootingtime);
  Indexer.set(true);
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
  repeat(2){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(unshootingtime);
  }
  Indexer.set(false);
  task::sleep(shootingtime);
  Indexer.set(true);
  velcontroller(75);
  straightdrive(120, 100, 0, 1, 0, 3, 1, 0, 2.5, 12, 4, 4, 20);
  Intake.spin(fwd, 100, pct);
  straightdrive(84, 60, 0, 1, 0, 3, 1, 0, 2.5, 6, 4, 1.5, 20);
  turntopoint(129, 17, 0, 1, 250);
  repeat(2){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(unshootingtime);
  }
  Indexer.set(false);
  task::sleep(shootingtime);
  Indexer.set(true);
  turn(-135, 0, 3, 20);
  straightdrive(44, 20, 0, 1, 0, 3, 1, 0, 2.5, 6, 4);
  straightdrive(84, 60, 0, 1, 0, 3, 1, 0, 2.5, 6, 4, 1.5, 20);
  Intake.spin(reverse, 100, pct);
  turntopoint(129, 17, 0, 1, 250);
  repeat(2){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(unshootingtime);
  }
  Indexer.set(false);
  task::sleep(shootingtime);
  Indexer.set(true);
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
  Endgame.set(true);
}

void leftAuto(){
  vex::task positiontrack = task(positionTrack);
  vex::task velcontrol = task(bangbangcontroller);
  velcontroller(92);
  setDriveVoltage(4, 4);
  task::sleep(250);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(34, 10, 180);
  straightdrive(39, 15, 0, 1.5, 0, 1, 1, 0, 2.5, 12, 4, 3, 20);
  turntopoint(16, 144-16, 0, .5, 100);
  repeat(1){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(600);
  }
  Indexer.set(false);
  task::sleep(shootingtime);
  Indexer.set(true);
  velcontroller(84);
  turn(45, 0, 3, 20);
  Intake.spin(fwd, 100, pct);
  straightdrive(72, 48, 0, 1, 0, 3, 1, 0, 2.5, 6, 4);
  turntopoint(16, 144-18, 0, .5, 100);
  Intake.spin(reverse, 100, pct);
  repeat(2){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(600);
  }
  Indexer.set(false);
  task::sleep(shootingtime);
  Indexer.set(true);
}

void WPAuto(){
  leftAuto();
  turn(45);
  Intake.spin(fwd, 100, pct);
  straightdrive(128, 114);
  turn(90);
  Intake.stop(coast);
  setDriveVoltage(6, 6);
  task::sleep(1000);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  driveReset(134, absGlobalY, Gyro.heading());
  straightdrive(131, 114);
}

void rightAuto(){
  vex::task positiontrack = task(positionTrack);
  vex::task velcontrol = task(bangbangcontroller);
  straightdrive(0, 21);
  turn(90);
  setDriveVoltage(4, 4);
  task::sleep(1500);
  Intake.rotateFor(fwd, 95, deg, 90, velocityUnits::pct, true);
  velcontroller(90);
  driveReset(134, 108, 90);
  straightdrive(130, 104, 0, 1.5, 0, 1, 1, 0, 2.5, 8, 4, 1, 300);
  turntopoint(18, 144-18, 0, .5, 500);
  repeat(2){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(1000);
  }
  turn(-135);
  Intake.spin(fwd, 100, pct);
  velcontroller(85);
  straightdrive(84, 60, 0, 1, 0, 3, 1, 0, 2.5, 4, 4);
  turntopoint(18, 144-19, 0, .5, 500);
  repeat(3){
    Indexer.set(false);
    task::sleep(shootingtime);
    Indexer.set(true);
    task::sleep(1000);
  }
}
