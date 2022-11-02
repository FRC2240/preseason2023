#include "ctre/Phoenix.h"
#include <frc/Encoder.h>


class Climber {

public:
void Up(double);
void Down(double);
void Stop();
frc::Encoder m_ClimberEncoder{25,24};

double max_ClimberUp = 1000.0, max_CLimberDown = 0.0;

 WPI_TalonFX m_motor{0};

};
