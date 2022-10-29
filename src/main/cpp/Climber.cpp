#include <iostream>
#include <Climber.h>





void Climber::Up(double speed) 
{
    if (m_ClimberEncoder.GetDistance() >= max_ClimberUp) {
        Stop();
    }
    else { 
        m_motor.Set(speed);
    }
}


void Climber::Down(double speed)
{
    if (m_ClimberEncoder.GetDistance() <= max_CLimberDown) {
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

