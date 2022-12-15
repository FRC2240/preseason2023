#include <iostream>
#include "Elevator.h"
 
Elevator::Elevator()
{
    Elevator::ElevatorPIDInit();
    Elevator::ElevatorDashboardInit();
    m_motor_elevator_left.RestoreFactoryDefaults();
    m_motor_elevator_right.RestoreFactoryDefaults();
    SoftLimits();
    m_motor_elevator_right.Follow(m_motor_elevator_left, true);
    //m_encoder.SetPosition(0.0);
}
void Elevator::Up(double speed)
{
        m_motor_elevator_left.Set(speed);
}
void Elevator::Down(double speed)
{
        m_motor_elevator_left.Set(speed);
 
}
void Elevator::Stop()
{
        m_motor_elevator_left.Set(0.0);
}
void Elevator::ElevatorPIDInit() {
 
    Elevator::ElevatorReadDashboard();
 
    m_left_elevatorPIDController.SetP(m_left_elevator_coeff.kP);
    m_left_elevatorPIDController.SetI(m_left_elevator_coeff.kI);
    m_left_elevatorPIDController.SetD(m_left_elevator_coeff.kD);
    m_left_elevatorPIDController.SetIZone(m_left_elevator_coeff.kIz);
    m_left_elevatorPIDController.SetFF(m_left_elevator_coeff.kFF);
    m_left_elevatorPIDController.SetOutputRange(m_left_elevator_coeff.kMinOutput, m_left_elevator_coeff.kMaxOutput);
 
}
void Elevator::SoftLimits()
{
    m_motor_elevator_left.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, true);
    m_motor_elevator_left.EnableSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, true);
    m_motor_elevator_left.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward, CONSTANTS::ELEVATOR::MAX_ELEVATOR_UP);
    m_motor_elevator_left.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse, CONSTANTS::ELEVATOR::MAX_ELEVATOR_DOWN);
 
}
 
void Elevator::ElevatorDashboardInit()
{
    frc::SmartDashboard::PutNumber("Left Elevator P Gain", m_left_elevator_coeff.kP);
    frc::SmartDashboard::PutNumber("Left Elevator I Gain", m_left_elevator_coeff.kI);
    frc::SmartDashboard::PutNumber("Left Elevator D Gain", m_left_elevator_coeff.kD);
    frc::SmartDashboard::PutNumber("Left Elevator FF Gain", m_left_elevator_coeff.kFF);
    frc::SmartDashboard::PutNumber("Left Elevator Max Output", m_left_elevator_coeff.kMaxOutput);
    frc::SmartDashboard::PutNumber("Left Elevator Min Output", m_left_elevator_coeff.kMinOutput);
 
}
 
void Elevator::ElevatorReadDashboard()
{
    m_left_elevator_coeff .kP = frc::SmartDashboard::GetNumber("Left Elevator P Gain", 0.0);
    m_left_elevator_coeff .kI = frc::SmartDashboard::GetNumber("Left Elevator I Gain", 0.0);
    m_left_elevator_coeff .kD = frc::SmartDashboard::GetNumber("Left Elevator D Gain", 0.0);
    m_left_elevator_coeff .kFF = frc::SmartDashboard::GetNumber("Left Elevator FF Gain", 0.0);
    m_left_elevator_coeff .kMinOutput = frc::SmartDashboard::GetNumber("Left Elevator Min Output", -1.0);
    m_left_elevator_coeff .kMaxOutput = frc::SmartDashboard::GetNumber("Left Elevator Mtput", 1.0);
 
}
 
void Elevator::test()
{
    //std::cout << "encoder: " << m_encoder.GetPosition() << "\n";
}