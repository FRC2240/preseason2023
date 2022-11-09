#include <rev/CANSparkMax.h>
#include "frc/DigitalInput.h"

class Grabber {
public:

  enum STATES {INTAKING, EJECTING, NOTHING};
  void Up();
  void Down();
  void In();
  void Out();

  void GrabberPIDInit();

  STATES Logic(bool intake_button,
               bool eject_button,
               STATES last_state = NOTHING );

  frc::DigitalInput left_limit_switch{9};
  frc::DigitalInput right_limit_switch{10};
        
  private:
      bool full;
      bool stowed;

//Needs 2 motor
    rev::CANSparkMax m_motor_grabber_spin{7, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_motor_grabber_wrist{8, rev::CANSparkMax::MotorType::kBrushless};

//PIDs
  rev::SparkMaxPIDController m_grabber_wrist_PIDController = m_motor_grabber_wrist.GetPIDController();
 
struct pidCoeff
  {
    double kP, kI, kD, kIz, kFF, kMaxOutput, kMinOutput;
};
 
pidCoeff m_grabber_wrist_Coeff{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

};
