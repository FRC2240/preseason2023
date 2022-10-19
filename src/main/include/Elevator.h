#include <ctre/Phoenix.h> 

class Elevator {
 
public:
    void Up();
    void Down();
    void Stop();

private:
    int m_lowerLimit;
    int m_upperLimit;
    WPI_TalonFX M_motor{1};

}