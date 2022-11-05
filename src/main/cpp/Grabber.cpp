#include <Grabber.h>

Grabber::STATES Grabber::Logic(
                               bool intake_button,
                               bool eject_button,
                               STATES last_state /*=NOTHING*/)
  /// Returns the current state of the machine at the end of the cycle
{
  if ( left_limit_switch.Get() || right_limit_switch.Get() )
    {
      //Grabber::Down();
    }
  else if (!left_limit_switch.Get() && right_limit_switch.Get() )
    {
      //Grabber::Up();
    }

  switch (last_state)
    {
  case INTAKING:
    if (&intake_button &&
        (!left_limit_switch.Get() || !right_limit_switch.Get() ) )
      {
        //Grabber::Down();
        Grabber::In();
        return INTAKING;
      }
    else if (&intake_button &&
             (left_limit_switch.Get() || right_limit_switch.Get() ) )
      {
        //Grabber::Down();
        m_motor_grabber_spin.Set(0.0);
        return NOTHING;
      }
    else
      {
        return NOTHING;
        // Do nothing at all.
      }
    break;

  case EJECTING:
    if (&eject_button)
      {
       Grabber::Out();
       return EJECTING;
      }
    else
      {
        return NOTHING;
      }
    break;

  case NOTHING:
    if (left_limit_switch.Get() && right_limit_switch.Get() )
      {
        //Grabber::Up();
        return NOTHING;
      }
    else if (&intake_button &&
             !left_limit_switch.Get() &&
             !right_limit_switch.Get() )
      {
        //Grabber::Down();
        Grabber::In();
        return INTAKING;
      }
    else if (&eject_button)
      {
        Grabber::Out();
        return EJECTING;
      }

    else
      {
        //Grabber::Down();
      }
    break;
  }
  return NOTHING;
}
/* 
void Grabber::Up(){


if (m_Grabber.ende

}


void Grabber::Down(){

if (m_Grabber.)

}
*/


void Grabber::In()
{

//Grabber Spining In//
m_motor_grabber_spin.Set(-0.5);

}

void Grabber::Out()
{

//Grabber Spining Out//
m_motor_grabber_spin.Set(0.5);
}
