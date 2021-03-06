extern float absGlobalX; 

extern float absGlobalY;

void setDriveVoltage(float leftVolts, float rightVolts);

void setDriveVelocity(float leftVelo, float rightVelo);

float reduceAngle0to360(float angleDeg);

float reduceAngleMinus180to180(float angleDeg);

void updatePosition();

int positionTrack();

void driveReset(float X = 0, float Y = 0, float OrientationDeg = 0);

void turn(float angle, float timeout = 0, float settlingerror = 1, float settlingtime = 40, float kp = 1, float ki = .00, float kd = 2.5, float maxvoltage = 12);

void turntopoint(float x, float y, float timeout = 0, float settlingerror = .5, float settlingtime = 20, float kp = 1, float ki = .00, float kd = 2.5, float maxvoltage = 12);

void straightdrive(float x, float y, float timeout = 0, float kp = 1, float ki = 0, float kd = 3, float turnp = 1, float turni = 0, float turnd = 2.5, float maxvoltage = 10, float turnmaxvoltage = 4, float settlingerror = 1.5, float settlingtime = 20);

void aligndrive(float x, float y, float finalorientation, float timeout = 0, float kp = 1, float ki = 0, float kd = 3, float angleagression = 3, float turnp = 1, float turni = 0, float turnd = 2.5, float maxvoltage = 10, float turnmaxvoltage = 4, float settlingerror = 1, float settlingtime = 20);