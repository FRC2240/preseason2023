class Drive{

public
   void Forward();
   void Backward();
   void Right();
   void Left();
private
//Needs four motors
    WPI_TalonFX m_motor_front_left{1};
    WPI_TalonFX m_motor_front_right{2};
    WPI_TalonFX m_motor_back_left{3};
    WPI_TalonFX m_motor_back_right{4};
};
