// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/controller/PIDController.h>
#include <frc/controller/SimpleMotorFeedforward.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>

#include "rev/CANSparkMax.h"
#include "AHRS.h"

/**
 * Represents a differential drive style drivetrain.
 */
class Drivetrain {
 public:
  Drivetrain(
      frc::MotorControllerGroup* leftGroup,
      frc::MotorControllerGroup* rightGroup,
      rev::SparkMaxRelativeEncoder* leftEncoder,
      rev::SparkMaxRelativeEncoder* rightEncoder
      ) :
  m_leftGroup(leftGroup),
  m_rightGroup(rightGroup),
  m_leftEncoder(leftEncoder),
  m_rightEncoder(rightEncoder)
  {
    // Set the distance per pulse for the drive encoders. We can simply use the
    // distance traveled for one rotation of the wheel divided by the encoder
    // resolution.
    m_leftEncoder->SetPositionConversionFactor(kDistancePerEncoderRotation);
    m_rightEncoder->SetPositionConversionFactor(kDistancePerEncoderRotation);
    m_leftEncoder->SetVelocityConversionFactor(kDistancePerEncoderRotation/60.0);
    m_rightEncoder->SetVelocityConversionFactor(kDistancePerEncoderRotation/60.0);

    m_leftEncoder->SetPosition(0.0);
    m_rightEncoder->SetPosition(0.0);

    m_leftGroup->SetInverted(true);

    // Instantiate gyro
    try {
			m_gyro = new AHRS(frc::SPI::Port::kMXP);
		} catch (std::exception& ex ) {
			std::string err_string = "Error instantiating navX MXP:  ";
			err_string += ex.what();
		}
    
    m_odometry = new frc::DifferentialDriveOdometry(m_gyro->GetRotation2d());
  }

  void SetSpeeds(const frc::DifferentialDriveWheelSpeeds& speeds);
  void Drive(units::meters_per_second_t xSpeed,
             units::radians_per_second_t rot);
  void UpdateOdometry();
  void ResetOdometry(const frc::Pose2d& pose);
  frc::Pose2d GetPose() const;
  units::angle::degree_t GetRotation();

 private:

  static constexpr double kP = 0.157; //2.77;                  // measured
  static constexpr auto   kS = 0.27_V;                         // measured
  static constexpr auto   kV = 1.53 * 1_V * 1_s / 1_m;         // measured
  static constexpr auto   kA = 0.254 * 1_V * 1_s * 1_s / 1_m;  // measured

  units::meter_t kTrackWidth = 0.657_m;                        // measured    
  double kDistancePerEncoderRotation = 0.0387;                 // measured (meters)  

  frc::MotorControllerGroup* m_leftGroup;
  frc::MotorControllerGroup* m_rightGroup;

  rev::SparkMaxRelativeEncoder* m_leftEncoder;
  rev::SparkMaxRelativeEncoder* m_rightEncoder;

  frc2::PIDController m_leftPIDController{kP, 0.0, 0.0};
  frc2::PIDController m_rightPIDController{kP, 0.0, 0.0};

  AHRS* m_gyro;

  frc::DifferentialDriveKinematics m_kinematics{kTrackWidth};
  frc::DifferentialDriveOdometry* m_odometry;

  // Gains are for example purposes only - must be determined for your own
  // robot!
  frc::SimpleMotorFeedforward<units::meters> m_feedforward{kS, kV, kA};
};