#include "Drive.h"

Drive::Drive()
{
    m_left_drive.SetInverted(true);
    m_back_right_motor.Follow(m_front_right_motor);
    m_back_left_motor.Follow(m_front_left_motor);
}

void Drive::ArcadeDrive(double throttle, double turn)
{
    drivetrain.ArcadeDrive(throttle, turn);  
}