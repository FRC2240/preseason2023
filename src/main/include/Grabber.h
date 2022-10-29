#include <rev/CANSparkMax.h>

class Grabber {
public:
       void Up();
       void Down();
       void In();
       void Out();
       states process(); 
       enum STATES {intaking,ejecting,nothing}
        
  private:
      bool fall;
      bool stown; 

//Needs 1 motor
    rev::CANSparkMax m_motor_grabber_spin{7, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_motor_grabber_wrist{8, rev::CANSparkMax::MotorType::kBrushless};

};

