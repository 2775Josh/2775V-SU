#include "vex.h"



void autonomous(void) { 
  vex::task positiontrack = task(positionTrack);
  

  switch(currentselection){  
 case 0:
  rightAuto();
  break;
 case 1:
  HauntedSkillsAuto();
  break;
 case 2:
  leftAuto();
  break;
 case 3:
  rightAuto();
  break;
 case 4:
  WPAuto();
  break;
 }
}