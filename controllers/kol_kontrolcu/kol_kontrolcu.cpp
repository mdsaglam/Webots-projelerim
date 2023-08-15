// File:          skid_steer_kontrolcu.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <webots/Keyboard.hpp>
// All the webots classes are defined in the "webots" namespace
#define TIME_STEP 64
using namespace webots;
using namespace std;
// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
// ... (kodun başındaki kısımlar)
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();
  Motor *motor[2];
  Keyboard kb;
  char w = 'W';
  char s = 'S';
  char d = 'D';
  char a = 'A';
  cout << int(w) << endl;
  cout << int(s) << endl;
  cout << int(d) << endl;
  cout << int(a) << endl; 
 

    motor[0] = robot->getMotor("ilk_motor");
    motor[1] = robot->getMotor("ikinci_motor");
  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();
  
  kb.enable(TIME_STEP);
  double solSagHiz = 0.0;
  double yukariAsagiHiz = 0.0;
  
  while (robot->step(timeStep) != -1) {
    // Saniye sayacını artır

    int key=kb.getKey();
    if (key==87){
    yukariAsagiHiz = 5.0;
    solSagHiz = 0.0;
    } else if (key==83){
    yukariAsagiHiz = -5.0;
    solSagHiz = 0.0;
    }else if (key==65){
    yukariAsagiHiz = 0.0;
    solSagHiz = 1.0;
    }else if (key==68){
    yukariAsagiHiz = 0.0;
    solSagHiz = -1.0;
    }
    else {
    yukariAsagiHiz = 0.0;
    solSagHiz = 0.0;
    }   
    motor[0]->setVelocity(yukariAsagiHiz);
    motor[1]->setVelocity(solSagHiz);
    motor[0]->setPosition(INFINITY);
    motor[1]->setPosition(INFINITY);

    // Bekleme süresi
 // Örnek olarak 0.1 saniye bekletme
  }

  delete robot;
  return 0;
}