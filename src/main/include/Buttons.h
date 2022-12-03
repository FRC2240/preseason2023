#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <frc/XboxController.h>

// Seperate all buttons into a namespace
namespace BUTTON
{
  // Declare controler in namespace
  frc::XboxController joystick {0};

  // Define all operations as inline functions

  inline bool GRABBER_TOGGLE()
  {
      return joystick.GetYButton();
  }

  inline double ELEVATOR_AXIS()
  {
     return joystick.GetRightY();
  }

  inline double THROTTLE_AXIS()
  {
    return  ( joystick.GetRightTriggerAxis()-joystick.GetLeftTriggerAxis() ) ;
  }

  inline double TURN_AXIS()
  {
    return joystick.GetLeftX();
  }

  inline bool INTAKE_IN()
  {
    return joystick.GetLeftBumper();
  }

  inline bool INTAKE_OUT()
  {
    return joystick.GetRightBumper();
  }

  inline bool WRIST_TOGGLE()
  {
    return joystick.GetRightBumper();
  }

  inline bool CLIMBER_UP()
  {
    if (joystick.GetPOV() == 0)
      {
        return true;
      }
    else
      {
      return false;
      }
  }

  inline bool CLIMBER_DOWN()
  {
    if (joystick.GetPOV() <= 225 && joystick.GetPOV() >= 135)
      {
        return true;
      }
    else
      {
      return false;
      }
  }
}
#endif // BUTTONS_H_