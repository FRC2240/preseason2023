#include "Grabber.h"

Grabber::STATES Grabber::Logic(
                               bool intake_button,
                               bool extake_button
                               )
  /// Returns the current state of the machine at the end of the cycle
{
  
  switch (state)
    {
      case 1:
        if (intake_button )
        {
          Down();
          In();
          state = 2;
        }

      break;
      
      case 2:

        if (extake_button)
        {
          state = 6;
        } 

        else if (!left_limit_switch.Get() || !right_limit_switch.Get())
        {
          m_grabber_timer.Reset();
          m_grabber_timer.Start();
          state = 3;
        }



      break;

      case 3:

        if ((m_grabber_timer.Get() > units::time::second_t(0.5) && m_grabber_timer.Get() < units::time::second_t(1)) && (!left_limit_switch.Get() || !right_limit_switch.Get()))
        {
          m_grabber_timer.Stop();
          Stop();
          state = 4;
        } 
        else if (m_grabber_timer.Get() > units::time::second_t(1))
        {
          m_grabber_timer.Stop();
          state = 2;
        }
      break;

      case 4:

        if (extake_button)
        {
          Out();
          m_grabber_timer.Reset();
          m_grabber_timer.Start();
          state = 5;
        } 
        else if(intake_button) 
        {
          In();
          state = 2;
        }

      break;

      case 5:

        if (m_grabber_timer.Get() > units::time::second_t(0.5))
        {
          Stop();
          Up();
          m_grabber_timer.Stop();
          state = 1;
        }
      
      break;

      case 6:

        m_grabber_timer.Reset();
        m_grabber_timer.Start();
        if (m_grabber_timer.Get() > units::time::second_t(0.5))
        {
          Stop();
          m_grabber_timer.Stop();
          state = 4;
        }
        
    }
}

void Grabber::Up()
{}

void Grabber::Down() 
{}


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

void Grabber::Stop()
{
  m_motor_grabber_spin.Set(0.0);
}

void Grabber::GrabberPIDInit() {
  m_grabber_wrist_PIDController.SetP(m_grabber_wrist_Coeff.kP);
  m_grabber_wrist_PIDController.SetI(m_grabber_wrist_Coeff.kI);
  m_grabber_wrist_PIDController.SetD(m_grabber_wrist_Coeff.kD);
  m_grabber_wrist_PIDController.SetIZone(m_grabber_wrist_Coeff.kIz);
  m_grabber_wrist_PIDController.SetFF(m_grabber_wrist_Coeff.kFF);
  m_grabber_wrist_PIDController.SetOutputRange(m_grabber_wrist_Coeff.kMinOutput, m_grabber_wrist_Coeff.kMaxOutput);
}

