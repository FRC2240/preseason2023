// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
 
#include "Robot.h"
 
 
#include <fmt/core.h>
 
#include <frc/smartdashboard/SmartDashboard.h>
 
void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}
 
/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}
 
/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);
 
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}
 
void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}
 
void Robot::TeleopInit() {
 
}
 
void Robot::TeleopPeriodic() {
 
 
 
  m_drive.drivetrain.ArcadeDrive(BUTTON::THROTTLE_AXIS(), BUTTON::TURN_AXIS());
 
  if (BUTTON::ELEVATOR_AXIS() > 0.1) {
    //std::cout << "here" << "\n";
 
    m_elevator.Up(-0.2 );
  }
 
  else if (BUTTON::ELEVATOR_AXIS() < -0.1) {
    m_elevator.Down(0.4 );
  }

  // else if (BUTTON::ELEVATOR_AXIS() < 0.1 && BUTTON::ELEVATOR_AXIS() > -0.1) {
  //   m_elevator.m_left_elevatorPIDController.SetReference(m_elevator.m_encoder.GetPosition(), rev::ControlType::kPosition);
  // }
 
  else {
    m_elevator.Stop();
  }
 
 
if ( BUTTON::CLIMBER_UP() )
{
  m_climber.Up();
}
 
else if ( BUTTON::CLIMBER_DOWN() )
{
  m_climber.Down();
}
 
else {
  m_climber.Stop();
}
 
 
 
 
 
/*  if (BUTTON::INTAKE_IN() )
  {
    m_grabber.In();
  }
  else if (BUTTON::INTAKE_OUT() )
  {
    m_grabber.Out();
  }
*/
  m_grabber.Logic(BUTTON::GRABBER_INTAKE(), BUTTON::GRABBER_EXTAKE(), BUTTON::GRABBER_STORE(), BUTTON::GRBBER_IGNORE());
 
 
}
 
void Robot::DisabledInit() {}
 
void Robot::DisabledPeriodic() {}
 
void Robot::TestInit() {}
 
void Robot::TestPeriodic() {
    m_climber.Test();
}
 
void Robot::SimulationInit() {}
 
void Robot::SimulationPeriodic() {}
 
#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
