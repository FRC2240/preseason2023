
#include "ctre/Phoenix.h"
class Climber {

public:
    void Up();
    void Down();
    void Stop();

private: 
    int m_lowerLimit;
    int m_upperLimit;
    
    WPI_TalonFX m_motor_climber{0};
};
