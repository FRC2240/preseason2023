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
      return (float)joystick.GetYButton();
  }

  inline float ELEVATOR_AXIS()
  {
     return (float)joystick.GetRightY();
  }

  inline float THROTTLE_AXIS()
  {
    return ( (float) (joystick.GetLeftTriggerAxis()-joystick.GetRightTriggerAxis() ) );
  }

  inline float TURN_AXIS()
  {
    return (float) joystick.GetLeftY();
  }

  inline float INTAKE_IN()
  {
    return (float) joystick.GetLeftBumper();
  }

  inline float INTAKE_OUT()
  {
    return (float) joystick.GetRightBumper();
  }

  inline float WRIST_TOGGLE()
  {
    return (float) joystick.GetRightBumper();
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
