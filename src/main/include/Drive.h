#include "ctre/Phoenix.h"
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"


class Drive{

public:
  Drive();
    frc::DifferentialDrive drivetrain {m_left_drive, m_right_drive};


private:
//Needs four motors
    rev::CANSparkMax m_front_left_motor{12,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_front_right_motor{11,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_back_left_motor{3,rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_back_right_motor{4,rev::CANSparkMax::MotorType::kBrushless};

    frc::MotorControllerGroup m_left_drive{m_front_left_motor, m_back_left_motor};
    frc::MotorControllerGroup m_right_drive{m_front_right_motor, m_back_right_motor};


};
