
#ifndef CONSTANTS_H_ 
#define CONSTANTS_H_

namespace CONSTANTS
{

     namespace GRABBER 
     {
         
         constexpr int SPIN_MOTOR_ID_WRIST = 7;
         constexpr int SPIN_MOTOR_ID_SPIN = 8;
     }

    namespace DRIVE
    {
        constexpr int front_Left = 1;
        constexpr int front_Right = 2;
        constexpr int back_Left = 3;
        constexpr int back_Right = 4;
    }
    namespace CLIMBER 
    {
        constexpr double MAX_CLIMBER_UP = 1000.0, MAX_CLIMBER_DOWN = 0.0;
        constexpr int MOTOR_ID = 7;
        constexpr int ENCODER_A = 1, ENCODER_B = 0;
    }
    namespace ELEVATOR
    {
        constexpr double MAX_ELEVATOR_UP = 10000.0, MAX_ELEVATOR_DOWN = 0.0;
        constexpr int LEFT_MOTOR_ID = 5;
        constexpr int RIGHT_MOTOR_ID = 6;
        constexpr int ENCODER_A = 2, ENCODER_B = 3;

    }
}


#endif // CONSTANTS_H_
