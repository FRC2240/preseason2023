#include <iostream>
#include <Climber.h>


Climber::Climber()
{
SoftLimits();

}



void Climber::SoftLimits()
{
    m_motor.ConfigForwardSoftLimitEnable(true);
    m_motor.ConfigReverseSoftLimitEnable(true);
    m_motor.ConfigForwardSoftLimitThreshold(CONSTANTS::CLIMBER::MAX_CLIMBER_UP);
    m_motor.ConfigReverseSoftLimitThreshold(CONSTANTS::CLIMBER::MAX_CLIMBER_DOWN);
}


void Climber::Up() 
{ 
    m_motor.Set(0.5);
}


void Climber::Down()
{
    m_motor.Set(-0.5);
}
