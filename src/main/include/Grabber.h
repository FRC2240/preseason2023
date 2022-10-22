#include "ctre/Phoenix.h"

class Grabber {
public:
       void Up();
       void Down();
       void In();
       void Out();
  private:
      bool m_raised;
      bool m_lowered; 

//Needs 1 motor
    WPI_TalonFX m_motor_grabber{7}; 
};

