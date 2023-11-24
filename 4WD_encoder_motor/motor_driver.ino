/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
****************************************************************/

#ifdef USE_BASE

#ifdef L298_MOTOR_DRIVER
  void initMotorController() {
    digitalWrite(MOTOR_FRONT_LEFT_ENABLE, HIGH);
    digitalWrite(MOTOR_FRONT_RIGHT_ENABLE, HIGH);
    digitalWrite(MOTOR_BACK_LEFT_ENABLE, HIGH);
    digitalWrite(MOTOR_BACK_RIGHT_ENABLE, HIGH);
  }

  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    if (spd < 0)
    {
      spd = -spd;
      reverse = 1;
    }
    if (spd > 255)
      spd = 255;
    
    if (i == Front_LEFT) { 
      if      (reverse == 0) { analogWrite(MOTOR_FRONT_LEFT1, spd); analogWrite(MOTOR_FRONT_LEFT2, 0); }
      else if (reverse == 1) { analogWrite(MOTOR_FRONT_LEFT2, spd); analogWrite(MOTOR_FRONT_LEFT1, 0); }
    }
    else if (i == Front_RIGHT) { 
      if      (reverse == 0) { analogWrite(MOTOR_FRONT_RIGHT1, spd); analogWrite(MOTOR_FRONT_RIGHT2, 0); }
      else if (reverse == 1) { analogWrite(MOTOR_FRONT_RIGHT2, spd); analogWrite(MOTOR_FRONT_RIGHT1, 0); }
    }
    else if (i == Back_LEFT) { 
      if      (reverse == 0) { analogWrite(MOTOR_BACK_LEFT1, spd); analogWrite(MOTOR_BACK_LEFT2, 0); }
      else if (reverse == 1) { analogWrite(MOTOR_BACK_LEFT2, spd); analogWrite(MOTOR_BACK_LEFT1, 0); }
    }
    else /*if (i == Back_RIGHT) //no need for condition*/ {
      if      (reverse == 0) { analogWrite(MOTOR_BACK_RIGHT1, spd); analogWrite(MOTOR_BACK_RIGHT2, 0); }
      else if (reverse == 1) { analogWrite(MOTOR_BACK_RIGHT2, spd); analogWrite(MOTOR_BACK_RIGHT1, 0); }
    }
  }
  
  void setMotorSpeeds(int f_leftSpeed, int f_rightSpeed, int b_leftSpeed, int b_rightSpeed) {
    setMotorSpeed(Front_LEFT, f_leftSpeed);
    setMotorSpeed(Front_RIGHT, f_rightSpeed);
    setMotorSpeed(Back_LEFT, b_leftSpeed);
    setMotorSpeed(Back_RIGHT, b_rightSpeed);
  }

#endif

#elif defined BTS_7960_MOTOR_DRIVER
    #include "BTS7960.h"

    /* Create the motor driver object */
    BTS7960 drive;

    void initMotorController() {
        drive.init();
    }


#endif

#else

  #error A motor driver must be selected!

#endif

#endif