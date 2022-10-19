class Climber{

public:
    void Up();
    void Down();
    void Stop();

private: 
    int m_lowerLimit;
    int m_upperLimit;

  //Needs 1 motor
   WPI_Talon m_motor{0}

}