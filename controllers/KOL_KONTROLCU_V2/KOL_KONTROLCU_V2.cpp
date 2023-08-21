// File:          kol_kontrolcu.cpp
// Date:          21.08.2023
// Description:   2 eksen kol kontrolü
// Author:        Musa Davut SAĞLAM
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
#define TIME_STEP 64
using namespace std;
// All the webots classes are defined in the "webots" namespace
using namespace webots;

// This is the main program of your controller.
// It creates an instance of your Robot instance, launches its
// function(s) and destroys it at the end of the execution.
// Note that only one instance of Robot should be created in
// a controller program.
// The arguments of the main function can be specified by the
// "controllerArgs" field of the Robot node
int main(int argc, char **argv)
{
  /* Kütüphane yardımı ile robotun tanımlanması ve kod bloğu içerisinde robotun tanımlanacağı fonksiyonlar için isim ataması */
  Robot *robot = new Robot();
  /* Kütüphane ile motorların tanımlanması ve kod bloğu içerisinde motorların tanımlanacağı fonksiyonlar için isim ataması */
  Motor *motor[4];
  /* kütüphane ile klavyenin tanımlanması ve kod bloğu içerisinde klavyenin tanımlanacağı fonksiyonlar için isim ataması */
  Keyboard kb;
  /* klavye girdilerinin kontrol edilmesi */
  /* BU BÖLGEDEKİ KODUN YORUM SATIRLARI KAPATILACAK OLURSA KLAVYE GİRDİLERİ KONSOLDAKİ ÇIKTIYA GÖRE DÜZENLENEBİLİR */
  //  char w = 'W'; //87
  //  char s = 'S'; //83
char q = 'Q'; //65
char e = 'E'; //68
 cout << int(q) << endl;
 cout << int(e) << endl;
  // cout << int(d) << endl;
  // cout << int(a) << endl;
/* Motorların kütüphane aracılığı ile tanıtılması*/
  motor[0] = robot->getMotor("DIKEY_MOTOR");
  motor[1] = robot->getMotor("YATAY_MOTOR");
  motor[2] = robot->getMotor("TUTAMAC_SAG");
  motor[3] = robot->getMotor("TUTAMAC_SOL");
  /* simülasyon zamanının entegre edilmesi*/
  int timeStep = (int)robot->getBasicTimeStep();
  /*klavyenin örnekleme periyodu tanımının yapılması */
  kb.enable(TIME_STEP);
  /* hız değişkenlerinin ayarlanması (simülasyonda rad/s cinsinden ifade ediliyor)*/
  double solSagHiz = 0.0;
  double yukariAsagiHiz = 0.0;
  double ileriGeriHiz = 0.0;
/* kodun tekrarlı çalışmasını sağlayan while kodu*/
  while (robot->step(timeStep) != -1)
  {
/*klavye girdisi alınması*/
    int key = kb.getKey();
    /*klavye girdilerinin kıyaslanarak hız verilerinin güncellenmesi */
    if (key == 87)
    {
      yukariAsagiHiz = 5.0;
      solSagHiz = 0.0;
    }
    else if (key == 83)
    {
      yukariAsagiHiz = -5.0;
      solSagHiz = 0.0;
    }
    else if (key == 65)
    {
      yukariAsagiHiz = 0.0;
      solSagHiz = 5.0;
    }
    else if (key == 68)
    {
      yukariAsagiHiz = 0.0;
      solSagHiz = -5.0;
    }
    else if(key == 81)
    {
    ileriGeriHiz = -0.1;
    }
    else if(key == 69)
    {
    ileriGeriHiz = 0.1;
    }
    else
    {
      yukariAsagiHiz = 0.0;
      solSagHiz = 0.0;
      ileriGeriHiz = 0.0;
    }
    /*motorların konum ve ivme verilerinin güncelenmesi*/
    motor[0]->setPosition(INFINITY);
    motor[1]->setPosition(INFINITY);
    motor[2]->setPosition(INFINITY);
    motor[3]->setPosition(INFINITY);
    motor[0]->setVelocity(yukariAsagiHiz);
    motor[1]->setVelocity(solSagHiz);
    motor[2]->setVelocity(ileriGeriHiz);
    motor[3]->setVelocity(ileriGeriHiz);



  }
/*simülasyon durdurulduğunda robotun ve kodun çalışmayı durdurması için gereken kodlar */
  delete robot;
  return 0;
}