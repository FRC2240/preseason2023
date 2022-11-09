#include <iostream>
#include "Elevator.h"

Elevator::Elevator()
{
    m_motor_elevator_left.RestoreFactoryDefaults();
    m_motor_elevator_right.RestoreFactoryDefaults();
    SoftLimits();
    m_motor_elevator_right.Follow(m_motor_elevator_left, true);
} 
void Elevator::Up(double speed) 
{
        m_motor_elevator_left.Set(speed);
}
void Elevator::Down(double speed)
{
        m_motor_elevator_left.Set(speed);
  
}
void Elevator::SoftLimits() 
{
    m_motor_elevator_left.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, true);
    m_motor_elevator_left.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, true);
    m_motor_elevator_left.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, 0.0);
    m_motor_elevator_left.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, 0.0);
} 
void Elevator::test() 
{
    std::cout << "encoder: " << m_encoder.GetPosition() << "\n";
}
