#include <ctre/Phoenix.h> 
#include <frc/Encoder.h>


class Elevator {
 
public:
    Elevator();
    void Up(double speed);
    void Down(double speed);
    void Stop();
    /* void SoftLimits(); */
    double test(double speed);
private:
    frc::Encoder m_encoder{1,2};


    double max_up = 1000.0, max_down = 0.0;
    
    //Needs two motors
    WPI_TalonFX m_motor_elevator_left{1};
    WPI_TalonFX m_motor_elevator_right{2};


 };
