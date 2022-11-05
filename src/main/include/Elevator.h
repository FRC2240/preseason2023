#include <ctre/Phoenix.h> 
#include <frc/Encoder.h>
#include "Constants.h"

class Elevator {
 
public:
    Elevator();
    void Up(double speed);
    void Down(double speed);
    void Stop();
    /* void SoftLimits(); */
    double test(double speed);
private:
    frc::Encoder m_encoder{CONSTANTS::ELEVATOR::ENCODER_A, CONSTANTS::ELEVATOR::ENCODER_B};


    double max_up = CONSTANTS::ELEVATOR::MAX_ELEVATOR_UP, max_down = CONSTANTS::ELEVATOR::MAX_ELEVATOR_DOWN;
    
    //Needs two motors
    WPI_TalonFX m_motor_elevator_left{CONSTANTS::ELEVATOR::LEFT_MOTOR_ID};
    WPI_TalonFX m_motor_elevator_right{CONSTANTS::ELEVATOR::RIGHT_MOTOR_ID};


 };
