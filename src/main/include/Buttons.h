#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <frc/XboxController.h>

// Seperate all buttons into a namespace
namespace BUTTON
{
  // Declare controler in namespace
  frc::XboxController stick {0};

  // Define all operations as inline functions

  inline bool GRABBER_INTAKE()
  {
      return stick.GetLeftBumperReleased();
  }

  inline bool GRABBER_EXTAKE()
  {
    return stick.GetRightBumperReleased();
  }

  inline double ELEVATOR_AXIS()
  {
     return stick.GetRightY();
  }

  inline double THROTTLE_AXIS()
  {
    return  ( stick.GetRightTriggerAxis()-stick.GetLeftTriggerAxis() ) ;
  }

  inline double TURN_AXIS()
  {
    return stick.GetLeftX();
  }

  inline bool INTAKE_IN()
  {
    return stick.GetLeftBumper();
  }

  inline bool INTAKE_OUT()
  {
    return stick.GetRightBumper();
  }

  inline bool WRIST_TOGGLE()
  {
    return stick.GetRightBumper();
  }

  inline bool CLIMBER_UP()
  {
    if (stick.GetPOV() == 0)
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
    if (stick.GetPOV() <= 225 && stick.GetPOV() >= 135)
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