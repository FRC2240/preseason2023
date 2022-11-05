#include "ctre/Phoenix.h"
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"
#include <Constants.h>


class Drive{        

public:
   Drive();
  void ArcadeDrive(double throttle, double turn);

  
private:
//Needs four motors
    rev::CANSparkMax m_front_left_motor{CONSTANTS::DRIVE::front_Left,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_front_right_motor{CONSTANTS::DRIVE::front_Right,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_back_left_motor{CONSTANTS::DRIVE::back_Left,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_back_right_motor{CONSTANTS::DRIVE::back_Right,rev::CANSparkMax::MotorType::kBrushless};


    frc::MotorControllerGroup m_left_drive{m_front_left_motor, m_back_left_motor};
    frc::MotorControllerGroup m_right_drive{m_front_right_motor, m_back_right_motor};

    frc::DifferentialDrive drivetrain {m_left_drive, m_right_drive};

};
