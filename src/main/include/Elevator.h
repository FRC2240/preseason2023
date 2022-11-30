#include "rev/CANSparkMax.h"
#include <frc/Encoder.h>
#include "Constants.h"

class Elevator {
 
public:
    Elevator();
    void Up(double speed);
    void Down(double speed);
    void Stop();
    void SoftLimits();
    void test();
private:

    double max_up = CONSTANTS::ELEVATOR::MAX_ELEVATOR_UP, max_down = CONSTANTS::ELEVATOR::MAX_ELEVATOR_DOWN;
    
    //Needs two motors
    rev::CANSparkMax m_motor_elevator_left{CONSTANTS::ELEVATOR::LEFT_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_motor_elevator_right{CONSTANTS::ELEVATOR::RIGHT_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkMaxRelativeEncoder m_encoder = m_motor_elevator_left.GetEncoder();
};
