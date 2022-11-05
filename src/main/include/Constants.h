#ifndef CONSTANTS_H_
#define CONSTANTS_H_

namespace CONSTANTS
{
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
        constexpr int MOTOR_ID = 0;
        constexpr int ENCODER_A = 1, ENCODER_B = 0;
    }
    namespace ELEVATOR
    {
        constexpr double MAX_ELEVATOR_UP = 1000.0, MAX_ELEVATOR_DOWN = 0.0;
        constexpr int LEFT_MOTOR_ID = 1;
        constexpr int RIGHT_MOTOR_ID = 2;
        constexpr int ENCODER_A = 1, ENCODER_B = 2;

    }
}


#endif // CONSTANTS_H_
