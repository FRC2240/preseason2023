#include <rev/CANSparkMax.h>

class Grabber {
public:
       void Up();
       void Down();
       void In();
       void Out();
  private:
      bool m_raised;
      bool m_lowered; 

//Needs 1 motor
    rev::CANSparkMax m_motor_grabber_spin{7, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_motor_grabber_wrist{8, rev::CANSparkMax::MotorType::kBrushless};

};

