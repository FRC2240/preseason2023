#include "ctre/Phoenix.h"

class Drive{

public:
    void Forward();
    void Backward();
    void Left();
    void Right();
private:
//Needs four motors
    WPI_TalonFX m_motor{1};
    WPI_TalonFX m_motor{2};
    WPI_TalonFX m_motor{3};
    WPI_TalonFX m_motor{4};
};