extern float absGlobalX; 

extern float absGlobalY;

extern float absOrientationDeg;

void setDriveVoltage(float leftVolts, float rightVolts);

void setDriveVelocity(float leftVelo, float rightVelo);

float reduceAngle0to360(float angleDeg);

float reduceAngleMinus180to180(float angleDeg);

void updatePosition();

int positionTrack();

void driveReset(float X = 0, float Y = 0, float OrientationDeg = 0);

void turn(float angle, float timeout = 0, float settlingerror = 1, float settlingtime = 20, float kp = .4, float ki = .05, float kd = 1.5, float maxvoltage = 12, float starti = 15);

void turntopoint(float x, float y, float timeout = 0, float settlingerror = 1, float settlingtime = 20, float kp = .4, float ki = .05, float kd = 1.5, float maxvoltage = 12, float starti = 15);

void straightdrive(float x, float y, float timeout = 0, float kp = 2, float ki = 0, float kd = 10, float turnp = 1, float turni = .01, float turnd = 3, float maxvoltage = 9, float turnmaxvoltage = 8, float settlingerror = 2, float settlingtime = 20, float starti = 15);

void funnystraightdrive(float x, float y, float angle, float timeout = 0, float kp = 2, float ki = 0, float kd = 10, float turnp = 1, float turni = .001, float turnd = 3, float maxvoltage = 10, float turnmaxvoltage = 8, float settlingerror = 1.5, float settlingtime = 20, float starti = 15);

void aligndrive(float x, float y, float finalorientation, float timeout = 0, float kp = 1, float ki = 0, float kd = 3, float angleagression = 3, float turnp = 1, float turni = 0, float turnd = 2.5, float maxvoltage = 10, float turnmaxvoltage = 4, float settlingerror = 1, float settlingtime = 20);