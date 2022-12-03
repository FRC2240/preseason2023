#include <Grabber.h>

Grabber::STATES Grabber::Logic(
                               bool intake_button,
                               bool eject_button
                               )
  /// Returns the current state of the machine at the end of the cycle
{
  if ( left_limit_switch.Get() || right_limit_switch.Get() )
    {
      //Grabber::Down();
    }
  else if (!left_limit_switch.Get() && !right_limit_switch.Get() )
    {
      //Grabber::Up();
    }

  switch (last_state)
    {
  case INTAKING:
    if (intake_button &&
        (!left_limit_switch.Get() || !right_limit_switch.Get() ) )
      {
        //Grabber::Down();
        Grabber::In();
        last_state = INTAKING;
        return INTAKING;
      }
    else if (intake_button &&
             (left_limit_switch.Get() || right_limit_switch.Get() ) )
      {
        //Grabber::Down();
        m_motor_grabber_spin.Set(0.0);
        last_state = NOTHING;
        return NOTHING;
      }
    else
      {
        last_state = NOTHING;
        return NOTHING;
        // Do nothing at all.
      }
    break;

  case EJECTING:
    if (eject_button)
      {
       Grabber::Out();

       last_state = EJECTING;
       return EJECTING;
      }
    else
      {
        last_state = NOTHING;
        return NOTHING;
      }
    break;

  case NOTHING:
    if (left_limit_switch.Get() && right_limit_switch.Get() )
      {
        //Grabber::Up();
        last_state = NOTHING;
        return NOTHING;
      }
    else if (intake_button &&
             !left_limit_switch.Get() &&
             !right_limit_switch.Get() )
      {
        //Grabber::Down();
        Grabber::In();
        last_state = INTAKING;
        return INTAKING;
      }
    else if (eject_button)
      {
        Grabber::Out();
        last_state = EJECTING;
        return EJECTING;
      }

    else
      {
        //Grabber::Down();
        last_state = NOTHING;
        return NOTHING;
      }
    break;
  }
  last_state = NOTHING;
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

void Grabber::GrabberPIDInit() {
  m_grabber_wrist_PIDController.SetP(m_grabber_wrist_Coeff.kP);
  m_grabber_wrist_PIDController.SetI(m_grabber_wrist_Coeff.kI);
  m_grabber_wrist_PIDController.SetD(m_grabber_wrist_Coeff.kD);
  m_grabber_wrist_PIDController.SetIZone(m_grabber_wrist_Coeff.kIz);
  m_grabber_wrist_PIDController.SetFF(m_grabber_wrist_Coeff.kFF);
  m_grabber_wrist_PIDController.SetOutputRange(m_grabber_wrist_Coeff.kMinOutput, m_grabber_wrist_Coeff.kMaxOutput);
}

