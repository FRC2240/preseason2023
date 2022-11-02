#include "ctre/Phoenix.h"
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"

class Drive 
{
public:


void ArcadeDrive(double throttle, double turn)
{
  m_drivetrain.ArcadeDrive(throttle, turn)
}

  Drive();    


private:
//Needs four motors
    rev::CANSparkMax m_front_left_motor{12,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_front_right_motor{9,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_back_left_motor{13,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_back_right_motor{10,rev::CANSparkMax::MotorType::kBrushless};

    frc::MotorControllerGroup m_left_drive{m_front_left_motor, m_back_left_motor};
    frc::MotorControllerGroup m_right_drive{m_front_right_motor, m_back_right_motor};
    frc::DifferentialDrive m_drivetrain {m_left_drive, m_right_drive};


};
