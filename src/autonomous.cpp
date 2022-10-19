#include "vex.h"



void autonomous(void) {
  switch(currentselection){
 case 0:
  leftAuto();
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