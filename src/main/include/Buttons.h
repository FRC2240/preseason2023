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
    return  ( joystick.GetLeftTriggerAxis()-joystick.GetRightTriggerAxis() ) ;
  }

  inline double TURN_AXIS()
  {
    return joystick.GetLeftY();
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
    if (joystick.GetPOV() >= 315.0 && joystick.GetPOV() <= 45.0)
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
    if (!BUTTON::CLIMBER_UP())
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
