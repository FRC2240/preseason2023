  #include <Grabber.h>

/* 
void Grabber::Up(){


if (m_Grabber.ende

}


void Grabber::Down(){

if (m_Grabber.)

}
*/


void Grabber::In(){

//this function spins backward in one way so the B button spin backwards in order to grab an object//

//Grabber Spining In//
m_motor_grabber_spin.Set(-0.5);


// the limit switch is for the wires to be energized or de-energized
// the limit switch is for the wheels to turn on when it is responded to the b button and press the b button again to turn off
// if you press the x button while the b button is still on then the wheels will start to spin foward 
}

void Grabber::Out(){

//this function spins forward out in the other way so the X button spins forwards in order to release an object//

//Grabber Spining Out//
m_motor_grabber_spin.Set(0.5);


// the limit switch is for the wires to be energized or de-energized
// the limit swicht is for the wheels to turn on when it is responed to the x button and press the x button again to turn off 
// if you press the b button while the x button is still on then the wheels will start to spin backwards


}

