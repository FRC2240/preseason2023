#include "ctre/Phoenix.h"

class Drive{

public:
    void Forward();
    void Backward();
    void Left();
    void Right();
private:
//Needs four motors
    WPI_TalonFX m_motor_front_left{1};
    WPI_TalonFX m_motor_front_right{2};
    WPI_TalonFX m_motor_back_left{3};
    WPI_TalonFX m_motor_back_right{4};
};