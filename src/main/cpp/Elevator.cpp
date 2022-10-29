#include <iostream>
#include "Elevator.h"

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