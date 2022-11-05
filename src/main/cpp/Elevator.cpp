#include <iostream>
#include "Elevator.h"

Elevator::Elevator()
{
  //  Elevator::SoftLimits();
} 
void Elevator::Up(double speed) 
{
    if (m_encoder.GetDistance() >= max_up) {
        Stop();
    }
    else { 
        m_motor_elevator_left.Set(speed);
        m_motor_elevator_right.Follow(m_motor_elevator_left);
    }
}

void Elevator::Down(double speed)
{
    if (m_encoder.GetDistance() <= max_down) {
        Stop();    
    } 
    else {
        m_motor_elevator_left.Set(speed);
        m_motor_elevator_right.Follow(m_motor_elevator_left);
    }
}

void Elevator::Stop()
{
    m_motor_elevator_left.Set(0);
    m_motor_elevator_right.Follow(m_motor_elevator_left);
}
/* void Elevator::SoftLimits() {

m_motor_elevator_left.ConfigForwardSoftLimitEnable(true);
m_motor_elevator_left.ConfigReverseSoftLimitEnable(true);

m_motor_elevator_left.ConfigForwardSoftLimitThreshold(1000);
m_motor_elevator_left.ConfigReverseSoftLimitEnable(10);
} */
double Elevator::test(double speed) {
    m_motor_elevator_left.Set(speed);
    m_motor_elevator_right.Follow(m_motor_elevator_left);
    return m_encoder.Get();
}
