#include <rev/CANSparkMax.h>
#include "frc/DigitalInput.h"
#include <frc/Timer.h>

class Grabber {
private:  enum STATES {INTAKING, EJECTING, NOTHING};

public:

  void Up();
  void Down();
  void In();
  void Out();
  void Stop();
  void GrabberPIDInit();

  STATES Logic(bool intake_button, bool extake_button);

  frc::DigitalInput left_limit_switch{3};
  frc::DigitalInput right_limit_switch{2};
        
  private:

  bool full;
  bool stowed;
  int state = 1;

  STATES last_state = NOTHING;

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

