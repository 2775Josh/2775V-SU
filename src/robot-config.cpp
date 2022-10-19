#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Flywheel = motor(PORT9, ratio6_1, false);
motor Intake = motor(PORT10, ratio6_1, false);
motor R1 = motor(PORT5, ratio6_1, true);
motor R2 = motor(PORT6, ratio6_1, false);
motor R3 = motor(PORT4, ratio6_1, false);
motor_group DriveR = motor_group(R1, R2, R3);
motor L1 = motor(PORT8, ratio6_1, false);
motor L2 = motor(PORT7, ratio6_1, true);
motor L3 = motor(PORT20, ratio6_1, true);
motor_group DriveL = motor_group(L1, L2, L3);
encoder EncoderB = encoder(Brain.ThreeWirePort.A);
encoder EncoderR = encoder(Brain.ThreeWirePort.C);
inertial Gyro = inertial(PORT11);
controller Controller1 = controller(primary);
digital_out Endgame = digital_out(Brain.ThreeWirePort.E);
digital_out DSwitcher = digital_out(Brain.ThreeWirePort.H);
bumper Cycle = bumper(Brain.ThreeWirePort.F);
bumper Confirm = bumper(Brain.ThreeWirePort.F);
line Line = line(Brain.ThreeWirePort.G);


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}