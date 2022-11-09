#include "ctre/Phoenix.h"
#include <frc/Encoder.h>
#include "Constants.h"


class Climber {

public:
Climber();

void SoftLimits();
void Up();
void Down();

private:
frc::Encoder m_ClimberEncoder{CONSTANTS::CLIMBER::ENCODER_A, 
                                CONSTANTS::CLIMBER::ENCODER_B};


 WPI_TalonFX m_motor{CONSTANTS::CLIMBER::MOTOR_ID};

};