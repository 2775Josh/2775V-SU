using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern inertial Gyro;
extern motor Flywheel;
extern motor Intake;
extern motor L1;
extern motor L2;
extern motor L3;
extern motor R1;
extern motor R2;
extern motor R3;
extern motor_group DriveL;
extern motor_group DriveR;
extern encoder EncoderR;
extern encoder EncoderB;
extern digital_out Deflector;
extern digital_out Endgame;
extern bumper Cycle;
extern line Line;
extern triport Expander;
extern digital_out DSwitcher;
extern digital_out Endgame2; 

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );