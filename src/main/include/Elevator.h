#include <ctre/Phoenix.h> 
#include <frc/Encoder.h>


class Elevator {
 
public:
    void Up(double);
    void Down(double);
    void Stop();
    frc::Encoder m_encoder{5,6};


    double max_up = 1000.0, max_down = 0.0;
    
    //Needs two motors
    WPI_TalonFX m_motor_elevator_left{5};
    WPI_TalonFX m_motor_elevator_right{6};


 };
