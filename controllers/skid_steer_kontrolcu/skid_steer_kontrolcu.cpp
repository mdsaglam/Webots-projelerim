// File:          skid_steer_kontrolcu.cpp
// Date:          15.08.2023
// Description:   skid steer araç kontrolü
// Author:        Musa Davut SAĞLAM
// Modifications:

/* include ile kütüphane tanımları */
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <iostream>
#include <chrono>
#include <thread>
/* alan adlarını kodun tümünde kullanmamak için yapılan tanımlamalar */
using namespace webots;


/* main fonksiyonu */
int main(int argc, char **argv) {
  /* Kütüphane yardımı ile robotun tanımlanması ve kod bloğu içerisinde robotun tanımlanacağı fonksiyonlar için isim ataması */
  Robot *robot = new Robot();
  /* Kütüphane ile motorların tanımlanması */
  Motor *wheels[8];
  /* salınım hareketi için kontrolü sağlayacak sayacın tanımlanamsı */
  int sayac = 0;
/* kod bloğu içerisinde motorların tanımlanacağı fonksiyonlar için isim ataması ve kütüphane aracılığı ile tanımlanması */
  char wheelsNames[8][8] = {"motor1", "motor2", "motor3", "motor4", "motor5", "motor6", "motor7", "motor8"};
  for (int i = 0; i <= 7; i++) {
    wheels[i] = robot->getMotor(wheelsNames[i]);
  }
  /* simülasyon zamanının entegre edilmesi*/
  int timeStep = (int)robot->getBasicTimeStep();
/* kodun tekrarlı çalışmasını sağlayan while kodu*/
  while (robot->step(timeStep) != -1) {
    /* simülasyon zamanının bir değişkene çekilmesi */
   int simTime = robot->getTime();
    /* simülasyon zamanının tek veya çift olması durumunun kıyaslanarak sayaç verisinin güncellenmesi (bu sayede saniyede bir kontrol edilebilen bloklar tasarlanmış olur) */
   if(simTime % 2 == 0)
   {
    /* sayaç değişkeninin zamanın çift anlarında 2ye eşitlenmesi sağlayan blok */
   std::cout << "sayaç çift" << std::endl;
   sayac = 2;
   std::cout << sayac << std::endl;
   }
   else 
   {
    /* sayaç değişkeninin zamanın tek anlarında 2ye eşitlenmesi sağlayan blok */
   std::cout << "sayaç tek" << std::endl;
   sayac = 1;
   std::cout << sayac << std::endl;
   }      
    
/* sayacın aldığı değere göre motorları bir yöne çalıştıran bloklar*/
    if (sayac % 2 == 0) {
      double speed = -10; // rad/s
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
      double speed = -10; // rad/s
      for (int i = 0; i <= 3; i++) {
        wheels[i]->setPosition(INFINITY);
        wheels[i]->setVelocity(0.001);
      }
      for (int i = 4; i <= 7; i++) {
        wheels[i]->setPosition(INFINITY);
        wheels[i]->setVelocity(speed);
      }
    }

  }
/*simülasyon durdurulduğunda robotun ve kodun çalışmayı durdurması için gereken kodlar */
  delete robot;
  return 0;
}