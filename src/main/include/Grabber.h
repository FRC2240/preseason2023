#include <rev/CANSparkMax.h>
#include "frc/DigitalInput.h"
#include <frc/Timer.h>
#include "frc/smartdashboard/SmartDashboard.h"

class Grabber {
private:  enum STATES {STOWED, INTAKING, INTAKE_WAIT, INTAKE_STOP, EXTAKING, OVERIDE_WAIT};

public:

  void Up();
  void Down();
  void In();
  void Out();
  void Stop();
  void GrabberPIDInit();
  void GrabberDashboardInit();
  void GrabberReadDashboard();

  STATES Logic(bool intake_button, bool extake_button, bool store_button, bool ignore_button);

  frc::DigitalInput left_limit_switch{3};
  frc::DigitalInput right_limit_switch{2};
        
  private:

  int state = 1;


  //Needs 2 motor
 rev::CANSparkMax m_motor_grabber_spin{8, rev::CANSparkMax::MotorType::kBrushless};
 rev::CANSparkMax m_motor_grabber_wrist{7, rev::CANSparkMax::MotorType::kBrushless}; 

 frc::Timer m_grabber_timer;

  //PIDs
  rev::SparkMaxPIDController m_grabber_wrist_PIDController = m_motor_grabber_wrist.GetPIDController();

  struct pidCoeff
  {
    double kP, kI, kD, kIz, kFF, kMaxOutput, kMinOutput;
  };

  pidCoeff m_grabber_wrist_Coeff{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

};

