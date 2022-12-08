#include <iostream>
#include "Grabber.h"

Grabber::STATES Grabber::Logic(
                               bool intake_button,
                               bool extake_button,
                               bool store_button,
                               bool ignore_button
                               )
  /// Returns the current state of the machine at the end of the cycle
{

  if (store_button)
  {
    state = STOWED;
    std::cout << "stowed button\n";
  }
  
  switch (state)
    {
      case STOWED:
        std::cout << "stowed\n";

        Up();
        Stop();

        if (intake_button )
        {
          Down();
          In();
          state = INTAKING;
        }
        else if(extake_button)
        {
          Out();
          state = EXTAKING;
        }

      break;
      
      case INTAKING:
      std::cout << "intaking\n";

        Down();
        In();

        if (extake_button)
        {
          m_grabber_timer.Reset();
          m_grabber_timer.Start();
          state = OVERIDE_WAIT;
        } 

        else if ((!left_limit_switch.Get() || !right_limit_switch.Get()) && !ignore_button)
        {
          m_grabber_timer.Reset();
          m_grabber_timer.Start();
          state = INTAKE_WAIT;
        }

      break;

      case INTAKE_WAIT:
      std::cout << "intake wait\n";

        Down();
        In();

        if ((m_grabber_timer.Get() > units::time::second_t(0.5) && m_grabber_timer.Get() < units::time::second_t(1)) 
            && (!left_limit_switch.Get() || !right_limit_switch.Get()))

        {
          m_grabber_timer.Stop();
          Stop();
          state = INTAKE_STOP;
        } 
        else if (m_grabber_timer.Get() > units::time::second_t(1))
        {
          m_grabber_timer.Stop();
          state = INTAKING;
        }

      break;

      case INTAKE_STOP:
      std::cout << "intake stop\n";

        Down();
        Stop();

        if (extake_button)
        {
          Out();
          m_grabber_timer.Reset();
          m_grabber_timer.Start();
          state = EXTAKING;
        } 
        else if(intake_button) 
        {
          In();
          state = INTAKING;
        }

      break;

      case EXTAKING:
      std::cout << "extaking\n";

        Down();
        Out();

        if (m_grabber_timer.Get() > units::time::second_t(0.5))
        {
          Stop();
          Up();
          m_grabber_timer.Stop();
          state = STOWED;
        } 
      
      break;

      case OVERIDE_WAIT:
      std::cout << "overide wait\n";

        Down();
        In();

        if (m_grabber_timer.Get() > units::time::second_t(0.5))
        {
          Stop();
          m_grabber_timer.Stop();
          state = INTAKE_STOP;
        }

      break;
        
    }
}

void Grabber::Up()
{}

void Grabber::Down() 
{}


void Grabber::In()
{
  //Grabber Spining In//
  m_motor_grabber_spin.Set(0.5);
}

void Grabber::Out()
{
  //Grabber Spining Out//
  m_motor_grabber_spin.Set(-0.5);
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

