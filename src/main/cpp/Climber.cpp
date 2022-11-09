#include <iostream>
#include <Climber.h>





void Climber::Up(double speed) 
{
    if (m_ClimberEncoder.GetDistance() >= CONSTANTS::CLIMBER::MAX_CLIMBER_UP) {
        Stop();
    }
    else { 
        m_motor.Set(speed);
    }
}


void Climber::Down(double speed)
{
    if (m_ClimberEncoder.GetDistance() <= CONSTANTS::CLIMBER::MAX_CLIMBER_DOWN) {
        Stop();    
    } 
    else {
        m_motor.Set(speed);
    }
}

void Climber::Stop()
{
    m_motor.Set(0);
}
