using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Flywheel;
extern motor Intake;
extern motor_group DriveR;
extern motor_group DriveL;
extern controller Controller1;
extern inertial Gyro;
extern encoder EncoderR;
extern encoder EncoderB;
extern digital_out Endgame;
extern digital_out DSwitcher;
extern bumper Cycle;
extern bumper Confirm;
extern motor L1, L2, L3;
extern motor R1, R2, R3;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );