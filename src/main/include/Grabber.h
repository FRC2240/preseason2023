   #include "ctre/Phonix.h"

  class Grabber {
    public:
       void Up();
       void Down();
       void In();
       void Out();
  private:
      bool m_raised;
      bool m_lowered; 
      WPI_TalonFX m_motor{7};

  }
