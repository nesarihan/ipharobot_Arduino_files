/***************************************************************
   Motor driver function definitions - by Neslihan Demir
****************************************************************/

#ifdef L298_MOTOR_DRIVER
  //MOTOR - FRONT LEFT & RIGHT
  #define MOTOR_FRONT_LEFT1 4 //FORWARD
  #define MOTOR_FRONT_LEFT2 5 //BACKWARD
  #define MOTOR_FRONT_RIGHT1 10 //FORWARD
  #define MOTOR_FRONT_RIGHT 11 //BACKWARD
  #define MOTOR_FRONT_LEFT_ENABLE 8
  #define MOTOR_FRONT_RIGHT_ENABLE 44
  //MOTOR - BACK LEFT & RIGHT
  #define MOTOR_BACK_LEFT1 6 //FORWARD
  #define MOTOR_BACK_LEFT2 7 //BACKWARD
  #define MOTOR_BACK_RIGHT1 12 //FORWARD
  #define MOTOR_BACK_RIGHT 13 //BACKWARD
  #define MOTOR_BACK_LEFT_ENABLE 9
  #define MOTOR_BACK_RIGHT_ENABLE 46
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int f_leftSpeed, int f_rightSpeed, int b_leftSpeed, int b_rightSpeed);