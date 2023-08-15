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
// All the webots classes are defined in the "webots" namespace
using namespace webots;


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
  Motor *wheels[8];
  int sayac = 0;
  char wheelsNames[8][8] = {"motor1", "motor2", "motor3", "motor4", "motor5", "motor6", "motor7", "motor8"};
  for (int i = 0; i <= 7; i++) {
    wheels[i] = robot->getMotor(wheelsNames[i]);
  }
  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();

  while (robot->step(timeStep) != -1) {
    // Saniye sayacını artır
   int simTime = robot->getTime();

   if(simTime % 2 == 0)
   {
   std::cout << "sayaç çift" << std::endl;
   sayac = 2;
   std::cout << sayac << std::endl;
   }
   else 
   {
   std::cout << "sayaç tek" << std::endl;
   sayac = 1;
   std::cout << sayac << std::endl;
   }      
    
    // Saniyede bir işlem yap
    if (sayac % 2 == 0) {
      double speed = -10; // [rad/s]
      for (int i = 0; i <= 3; i++) {
        wheels[i]->setPosition(INFINITY);
        wheels[i]->setVelocity(speed);
      }
      for (int i = 4; i <= 7; i++) {
        wheels[i]->setPosition(INFINITY);
        wheels[i]->setVelocity(0.001);
      }
    } 
    else {
      double speed = -10; // [rad/s]
      for (int i = 0; i <= 3; i++) {
        wheels[i]->setPosition(INFINITY);
        wheels[i]->setVelocity(0.001);
      }
      for (int i = 4; i <= 7; i++) {
        wheels[i]->setPosition(INFINITY);
        wheels[i]->setVelocity(speed);
      }
    }

    // Bekleme süresi
 // Örnek olarak 0.1 saniye bekletme
  }

  delete robot;
  return 0;
}