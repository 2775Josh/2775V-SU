extern float flywheelVelocity;

int bangbangcontroller();
int pidcontroller();
void velcontroller(double vel, bool controltype);
int rollerSpin(bool color = 0, float speed = 40, float timeout = 1000, float extraspin = 40);
void quickshoot(float speed = 100, float sleep = 800);

