#include "ctre/Phoenix.h"

class Elevator {

public:
    void Up();
    void Down();
    void Stop();

private:

    int m_lowerLimit;
    int m_upperLimit;
//Needs two motors
    WPI_TalonFX m_motor_elevator_left{5};
    WPI_TalonFX m_motor_elevator_right{6};
    

};