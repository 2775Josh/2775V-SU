#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
inertial Gyro = inertial(PORT8);
motor Flywheel = motor(PORT10, ratio6_1, false);
motor Intake = motor(PORT9, ratio6_1, true);
motor L1 = motor(PORT6, ratio6_1, false);
motor L2 = motor(PORT4, ratio6_1, true);
motor L3 = motor(PORT3, ratio6_1, true);
motor R1 = motor(PORT7, ratio6_1, true);
motor R2 = motor(PORT5, ratio6_1, false);
motor R3 = motor(PORT2, ratio6_1, false);
motor_group DriveL = motor_group(L1,L2,L3);
motor_group DriveR = motor_group(R1,R2,R3);
encoder EncoderR = encoder(Brain.ThreeWirePort.A);
encoder EncoderB = encoder(Brain.ThreeWirePort.C);
digital_out Deflector = digital_out(Brain.ThreeWirePort.E);
digital_out Endgame = digital_out(Brain.ThreeWirePort.F);
bumper Cycle = bumper(Brain.ThreeWirePort.G);
line Line = line(Brain.ThreeWirePort.H);

 
void vexcodeInit( void ) {
  // nothing to initialize
}