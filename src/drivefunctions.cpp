#include "vex.h"

float pi = 3.14159265359; //Pi

//Physical Distances on the Bot, measured in inches from the center
float rWidth = (12.625/2)-4;
float lWidth = (12.625/2)-4;
float bLength = (17.5/2)-2;

//Ratios of Odom Wheels, in Inches/Degrees
float rWheelRatio = 2.75*pi/360*1.015;
float lWheelRatio = 2.75*pi/360*1.015; 
float bWheelRatio = 2.75*pi/360*1.015; 

//Variables to Calulate Deltas in Encoder Values
float prevL = 0;
float prevR = 0; 
float prevB = 0;

//Variables for Position
float prevOrientationRad = 0;
float prevGlobalX = 0; 
float prevGlobalY = 0; 
float absOrientationRad = 0; 
float absOrientationDeg = 0; 

//Used as a Reference for Global X and Y
float localX = 0;
float localY = 0;

//Deltas in Wheels
float deltaL = 0; 
float deltaR = 0;
float deltaB = 0; 

//Absolute Positions
float absGlobalX = 0; 
float absGlobalY = 0; 

//Constants for Motion Control, where "P" is proportional and "D" is derivative.
float turnP = 1.2;
float driveP = 6;
float turnD = 20;
float driveD = 40;
float turnMax = 40;
float driveMax = 60;
float errorMarginBase = 1;
float errorMarginTurnDeg = 0.5;

//Encoder Values
float currentL = 0;
float currentR = 0;
float currentB = 0;

float reduceAngle0to360( float angleDeg ) { //Takes an input angle in degrees and converts it to a positive angle value below 360.
  while(!(angleDeg >= 0 && angleDeg < 360)) {
    if( angleDeg < 0 ) { angleDeg += 360; }
    if(angleDeg >= 360) { angleDeg -= 360; }
  }
  return(angleDeg);
}

float reduceAngleMinus180to180( float angleDeg ) { //Takes an input angle in degrees and converts it to an angle between -180 and 180.
  while(!(angleDeg >= -180 && angleDeg < 180)) {
    if( angleDeg < -180 ) { angleDeg += 360; }
    if(angleDeg >= 180) { angleDeg -= 360; }
  }
  return(angleDeg);
}

void setDriveVoltage(float leftVolts, float rightVolts) {
  DriveL.spin(fwd, leftVolts, volt);
  DriveR.spin(fwd, rightVolts, volt);
}

void setDriveVoltageNoSlop(float leftVolts, float rightVolts) {
  L1.spin(fwd, leftVolts, volt);
  L2.spin(fwd, leftVolts, volt);
  L3.spin(fwd, leftVolts*0.6, volt);
  R1.spin(fwd, rightVolts, volt);
  R2.spin(fwd, rightVolts, volt);
  R3.spin(fwd, rightVolts*0.6, volt);
}

void setDriveVelocity(float leftVelo, float rightVelo) {
  DriveL.spin(fwd, leftVelo, pct);
  DriveR.spin(fwd, rightVelo, pct);
}

void driveHold( void ) {
  DriveL.stop(brakeType::hold);
  DriveR.stop(brakeType::hold);
}


void updatePosition() { //Approximates the motion of the robot as an arc, and updates its position accordingly
    currentR = (EncoderR.rotation(rotationUnits::deg))*(rWheelRatio); 
    currentB = -(EncoderB.rotation(rotationUnits::deg))*(bWheelRatio);

    deltaR = currentR - prevR;
    deltaB = currentB - prevB;
    
    prevR = currentR;
    prevB = currentB; 

    absOrientationDeg = Gyro.rotation(deg)*360.0/357.0; 

    absOrientationRad = absOrientationDeg/(180/pi);

    float deltaA = absOrientationRad-prevOrientationRad; //Change in angle.

    //Calulates coordinates relative to the chord of the robot's arc.
    if (deltaA == 0) { //Prevents divide by zero error.
        localX = deltaB;
        localY = deltaR;
    } else {
        localX = (2*sin(deltaA/2))*((deltaB/deltaA)+bLength); 
        localY = (2*sin(deltaA/2))*((deltaR/deltaA)-rWidth);
    }

    float localPolarAngle = 0;
    float localPolarLength = 0;

    //Caluclates polar coordinates.
    if (localX == 0 && localY == 0){ //Prevents two zeros from being passed to atan2.
        localPolarAngle = 0;
        localPolarLength = 0;
    } else {
        localPolarAngle = atan2(localY, localX); 
        localPolarLength = sqrt(pow(localX, 2) + pow(localY, 2)); 
    }

    //Converts polar coordinates to global coordinates.
    float globalPolarLength = localPolarLength; 
    float globalPolarAngle = localPolarAngle - prevOrientationRad - (deltaA/2);

    float globalX = globalPolarLength*cos(globalPolarAngle); 
    float globalY = globalPolarLength*sin(globalPolarAngle); 

    //Calulates absolute position and orientation.
    absGlobalX = prevGlobalX + globalX; 
    absGlobalY = prevGlobalY + globalY; 

    prevGlobalX = absGlobalX;
    prevGlobalY = absGlobalY;

    //Sets up the previous orientation for deltas.
    prevOrientationRad = absOrientationRad;
}

int positionTrack() { //Background thread used to position track full time.
  while(1){
    updatePosition();

    Brain.Screen.printAt(1, 20, "Absolute X: %f Inches", absGlobalX);
    Brain.Screen.printAt(1, 40, "Absolute Y: %f Inches", absGlobalY);
    Brain.Screen.printAt(1, 60, "Absolute Rotation: %f Radians, %f Degrees", Gyro.rotation(deg), absOrientationDeg);
  }
}

void driveReset(float X, float Y, float OrientationDeg) { //Tells the robot its position on the field at the beginning of a match.
  prevB=0;
  prevL=0;
  prevR=0;
  currentB = 0;
  currentL = 0;
  currentR = 0;
  EncoderB.resetRotation();
  EncoderR.resetRotation();
  absGlobalX=X;
  absGlobalY=Y;
  prevGlobalX=X;
  prevGlobalY=Y;
  prevOrientationRad=OrientationDeg*pi/180;
  absOrientationDeg=OrientationDeg;
  Gyro.setRotation(OrientationDeg*357.0/360.0,deg);
}

void straightdrive(float x, float y, float timeout, float kp, float ki, float kd, float turnp, float turni, float turnd, float maxvoltage, float turnmaxvoltage, float settlingerror, float settlingtime, float starti){
  float starttime = Brain.timer(msec);
  if(timeout == 0) { starttime = 99999999;}
  bool settled = false;
  float error = hypot(y-absGlobalY, x-absGlobalX);
  float p = 0;
  float i = 0;
  float d = 0;
  float output = 0;
  float accerror = 0;
  float turnaccerror = 0;
  float preverror = error;
  float turnpreverror = 0;
  float settlecounter = 0;
  float turnscale = 1;
  float turn = 0;
  float turnerror = 0;
  float turnerrorRad = 0;
  while(settled == false && Brain.timer(msec) < starttime + timeout){
    error = hypot(y-absGlobalY, x-absGlobalX);
    p = error*kp;
    i = accerror*ki;
    d = (error-preverror)*kd;
    turnerror = reduceAngleMinus180to180(180/pi*(atan2(x-absGlobalX,y-absGlobalY))-absOrientationDeg);
    turnerrorRad = turnerror/180*pi;
    turnscale = cos(turnerrorRad);
    output = turnscale*(p+i+d);
    if(output>maxvoltage){
      output = maxvoltage;
    }
    if(output<-maxvoltage){
      output = -maxvoltage;
    }
    if (turnerror>90) {turnerror-=180;}
    if (turnerror<-90) {turnerror+=180;}
    if (error<settlingerror) {turnerror = 0;}
    if (turni != 0) {
      if (fabs(turnerror) < starti){
        turnaccerror += turnerror;
      }
      if ((turnerror>0 && turnpreverror<0)||(turnerror<0 && turnpreverror>0)){
        turnaccerror = 0;
      }
    }
    turn = turnp*turnerror+turni*turnaccerror+turnd*(turnerror-turnpreverror);

    if(turn>turnmaxvoltage){
      turn = turnmaxvoltage;
    }
    if(turn<-turnmaxvoltage){
      turn = -turnmaxvoltage;
    }
  
    turnpreverror=turnerror;
    setDriveVoltage(output+turn, output-turn);
    if(output == maxvoltage || output == -maxvoltage){
      accerror = 0;
    }else{
      accerror += error;
    }
    preverror=error;
    if(error < settlingerror && error > -settlingerror){
      settlecounter+=1;
    } else {
      settlecounter = 0;
    }
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(100, 100, "%f", turnerror);
    if (settlecounter > settlingtime/20){
      settled = true;
    }
    task::sleep(20);
  }
  DriveL.stop(hold);
  DriveR.stop(hold);
}

void funnystraightdrive(float x, float y, float angle, float timeout, float kp, float ki, float kd, float turnp, float turni, float turnd, float maxvoltage, float turnmaxvoltage, float settlingerror, float settlingtime, float starti){
  float starttime = Brain.timer(msec);
  if(timeout == 0) { starttime = 99999999;}
  bool settled = false;
  float error = hypot(y-absGlobalY, x-absGlobalX);
  float p = 0;
  float i = 0;
  float d = 0;
  float output = 0;
  float accerror = 0;
  float turnaccerror = 0;
  float preverror = error;
  float turnpreverror = 0;
  float settlecounter = 0;
  float turnscale = 1;
  float turn = 0;
  float turnerror = 0;
  float turnerrorRad = 0;
  while(settled == false && Brain.timer(msec) < starttime + timeout){
    error = hypot(y-absGlobalY, x-absGlobalX);
    p = error*kp;
    i = accerror*ki;
    d = (error-preverror)*kd;
    turnerror = reduceAngleMinus180to180(angle-absOrientationDeg);
    turnerrorRad = turnerror/180*pi;
    turnscale = cos(turnerrorRad);
    output = turnscale*(p+i+d);
    if(output>maxvoltage){
      output = maxvoltage;
    }
    if(output<-maxvoltage){
      output = -maxvoltage;
    }
    if (turnerror>90) {turnerror-=180;}
    if (turnerror<-90) {turnerror+=180;}
    if (error<settlingerror) {turnerror = 0;}
    if (turni != 0) {
      if (fabs(turnerror) < starti){
        turnaccerror += turnerror;
      }
      if ((turnerror>0 && turnpreverror<0)||(turnerror<0 && turnpreverror>0)){
        turnaccerror = 0;
      }
    }
    turn = turnp*turnerror+turni*turnaccerror+turnd*(turnerror-turnpreverror);

    if(turn>turnmaxvoltage){
      turn = turnmaxvoltage;
    }
    if(turn<-turnmaxvoltage){
      turn = -turnmaxvoltage;
    }
  
    turnpreverror=turnerror;
    setDriveVoltage(output+turn, output-turn);
    if(output == maxvoltage || output == -maxvoltage){
      accerror = 0;
    }else{
      accerror += error;
    }
    preverror=error;
    if(error < settlingerror && error > -settlingerror){
      settlecounter+=1;
    } else {
      settlecounter = 0;
    }
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(100, 100, "%f", turnerror);
    if (settlecounter > settlingtime/20){
      settled = true;
    }
    task::sleep(20);
  }
  DriveL.stop(hold);
  DriveR.stop(hold);
}

void aligndrive(float x, float y, float finalorientation, float timeout, float kp, float ki, float kd, float angleagression, float turnp, float turni, float turnd, float maxvoltage, float turnmaxvoltage, float settlingerror, float settlingtime){
  float starttime = Brain.timer(msec);
  if(timeout == 0) { starttime = 99999999;}
  bool settled = false;
  float error = hypot(y-absGlobalY, x-absGlobalX);
  float p = 0;
  float i = 0;
  float d = 0;
  float output = 0;
  float accerror = 0;
  float turnaccerror = 0;
  float preverror = error;
  float turnpreverror = 0;
  float settlecounter = 0;
  float turnscale = 1;
  float turn = 0;
  float turnerror = 0;
  float turnerrorRad = 0;
  float sideerror = 0;
  while(settled == false && Brain.timer(msec) < starttime + timeout){
    error = hypot(y-absGlobalY, x-absGlobalX);
    p = error*kp;
    i = accerror*ki;
    d = (error-preverror)*kd;
    turnerror = reduceAngleMinus180to180(180/pi*(atan2(x-absGlobalX,y-absGlobalY))-absOrientationDeg);
    turnerrorRad = turnerror/180*pi;
    turnscale = cos(turnerrorRad);
    
    output = turnscale*(p+i+d); 
    if(output>maxvoltage){
      output = maxvoltage;
    }
    if(output<-maxvoltage){
      output = -maxvoltage;
    }
    turnerror = reduceAngleMinus180to180(180/pi*(atan2(x-absGlobalX,y-absGlobalY))-finalorientation);
    turnerrorRad = turnerror/180*pi;
    sideerror = error*sin(turnerrorRad);
    if (output < 0) {sideerror = -sideerror;}
    turnerror = reduceAngleMinus180to180(angleagression*sideerror-absOrientationDeg);
    if (error<settlingerror) {turnerror = 0;}
    turn = turnp*turnerror+turni*turnaccerror+turnd*(turnerror-turnpreverror);

    if(turn>maxvoltage){
      turn = maxvoltage;
    }
    if(turn<-maxvoltage){
      turn = -maxvoltage;
    }
  
    turnpreverror=turnerror;
    turnaccerror+=error;
    setDriveVoltage(output+turn, output-turn);
    if(output == maxvoltage || output == -maxvoltage){
      accerror = 0;
    }else{
      accerror += error;
    }
    preverror=error;
    if(error < settlingerror && error > -settlingerror){
      settlecounter+=1;
    } else {
      settlecounter = 0;
    }
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(100, 100, "%f", turnerror);
    if (settlecounter > settlingtime/20){
      settled = true;
    }
    task::sleep(20);
  }
  DriveL.stop(hold);
  DriveR.stop(hold);
}

void turn(float angle, float timeout, float settlingerror, float settlingtime, float kp, float ki, float kd, float maxvoltage, float starti){
  bool settled = false;
  float error = angle - Gyro.heading(deg);
  float starttime = Brain.timer(msec);
  if(timeout == 0) { starttime = 99999999;}
  float p = 0;
  float i = 0;
  float d = 0;
  float output = 0;
  float accerror = 0;
  float preverror = error;
  float settlecounter = 0;
  while(settled == false && Brain.timer(msec) < starttime + timeout){
    error = reduceAngleMinus180to180(angle - absOrientationDeg);
    p = error*kp;
    if (ki != 0) {
      if (fabs(error) < starti){
        accerror += error;
      }
      if ((error>0 && preverror<0)||(error<0 && preverror>0)){
        accerror = 0;
      }
    }
    i = accerror*ki;
    d = (error-preverror)*kd;
    output = p+i+d;
    if(output>maxvoltage){
      output = maxvoltage;
    }
    if(output<-maxvoltage){
      output = -maxvoltage;
    }
    setDriveVoltage(output, -output);
    preverror=error;
    if(error < settlingerror && error > -settlingerror){
      settlecounter+=1;
    } else {
      settlecounter = 0;
    }
    if (settlecounter > settlingtime/20){
      settled = true;
    }
    Brain.Screen.printAt(50, 50, "%f", error);
    task::sleep(20);
  }
  DriveL.stop(hold);
  DriveR.stop(hold);
}

void turntopoint(float x, float y, float timeout, float settlingerror, float settlingtime, float kp, float ki, float kd, float maxvoltage, float starti){
  bool settled = false;
  float error = reduceAngleMinus180to180(180/pi*(atan2(x-absGlobalX,y-absGlobalY))-absOrientationDeg);
  float starttime = Brain.timer(msec);
  if(timeout == 0) { starttime = 99999999;}
  float p = 0;
  float i = 0;
  float d = 0;
  float output = 0;
  float accerror = 0;
  float preverror = error;
  float settlecounter = 0;
  while(settled == false && Brain.timer(msec) < starttime + timeout){
    error = reduceAngleMinus180to180(180/pi*(atan2(x-absGlobalX,y-absGlobalY))-absOrientationDeg+180);
    p = error*kp;
    if (ki != 0) {
      if (fabs(error) < starti){
        accerror += error;
      }
      if ((error>0 && preverror<0)||(error<0 && preverror>0)){
        accerror = 0;
      }
    }
    i = accerror*ki;
    d = (error-preverror)*kd;
    output = p+i+d;
    if(output>maxvoltage){
      output = maxvoltage;
    }
    if(output<-maxvoltage){
      output = -maxvoltage;
    }
    setDriveVoltage(output, -output);
    preverror=error;
    if(error < settlingerror && error > -settlingerror){
      settlecounter+=1;
    } else {
      settlecounter = 0;
    }
    if (settlecounter > settlingtime/20){
      settled = true;
    }
    Brain.Screen.printAt(50, 50, "%f", error);
    task::sleep(20);
  }
  DriveL.stop(hold);
  DriveR.stop(hold);
}