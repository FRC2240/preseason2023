// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Buttons.h"
#include "Elevator.h"
#include "Climber.h"
#include "Grabber.h"

#include <string>
#include "Drive.h"
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/controller/PIDController.h>

//#include <frc/XboxController.h>


//frc::XboxController m_stick{0};

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;


private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  Grabber::STATES m_grabber_last_run = Grabber::STATES::NOTHING;

  Drive m_drive;
  Climber m_climber;
  Elevator m_elevator;
  Grabber m_grabber;
  frc2::PIDController m_motor_elevator_leftPIDController{0.0,0.0,0.0};
};
