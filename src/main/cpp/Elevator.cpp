#include <iostream>
#include "Elevator.h"

void Elevator::Up() 
{
    m_motor_elevator_left.Set(1.0);
    m_motor_elevator_right.Follow(m_motor_elevator_left);
    
}

void Elevator::Down()
{
    m_motor_elevator_left.Set(-1.0);
    m_motor_elevator_right.Follow(m_motor_elevator_left);

}

void Elevator::Stop()
{
    m_motor_elevator_left.Set(0);
    m_motor_elevator_right.Follow(m_motor_elevator_left);
}