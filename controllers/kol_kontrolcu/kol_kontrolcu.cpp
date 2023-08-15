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
#include <webots/Keyboard.hpp>
/*  kod içerisinde hızlı değişim sağlamak amaçlı yapılan define tanımları */
#define TIME_STEP 64
/* alan adlarını kodun tümünde kullanmamak için yapılan tanımlamalar */
using namespace webots;
using namespace std;
/* main fonksiyonu */
int main(int argc, char **argv)
{
  /* Kütüphane yardımı ile robotun tanımlanması ve kod bloğu içerisinde robotun tanımlanacağı fonksiyonlar için isim ataması */
  Robot *robot = new Robot();
  /* Kütüphane ile motorların tanımlanması ve kod bloğu içerisinde motorların tanımlanacağı fonksiyonlar için isim ataması */
  Motor *motor[2];
  /* kütüphane ile klavyenin tanımlanması ve kod bloğu içerisinde klavyenin tanımlanacağı fonksiyonlar için isim ataması */
  Keyboard kb;
  /* klavye girdilerinin kontrol edilmesi */
  /* BU BÖLGEDEKİ KODUN YORUM SATIRLARI KAPATILACAK OLURSA KLAVYE GİRDİLERİ KONSOLDAKİ ÇIKTIYA GÖRE DÜZENLENEBİLİR */
  //  char w = 'W'; //87
  //  char s = 'S'; //83
  //  char d = 'D'; //65
  //  char a = 'A'; //68
  // cout << int(w) << endl;
  // cout << int(s) << endl;
  // cout << int(d) << endl;
  // cout << int(a) << endl;
/* Motorların kütüphane aracılığı ile tanıtılması*/
  motor[0] = robot->getMotor("ilk_motor");
  motor[1] = robot->getMotor("ikinci_motor");
  /* simülasyon zamanının entegre edilmesi*/
  int timeStep = (int)robot->getBasicTimeStep();
  /*klavyenin örnekleme periyodu tanımının yapılması */
  kb.enable(TIME_STEP);
  /* hız değişkenlerinin ayarlanması (simülasyonda rad/s cinsinden ifade ediliyor)*/
  double solSagHiz = 0.0;
  double yukariAsagiHiz = 0.0;
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
      solSagHiz = 1.0;
    }
    else if (key == 68)
    {
      yukariAsagiHiz = 0.0;
      solSagHiz = -1.0;
    }
    else
    {
      yukariAsagiHiz = 0.0;
      solSagHiz = 0.0;
    }
    /*motorların konum ve ivme verilerinin güncelenmesi*/
    motor[0]->setVelocity(yukariAsagiHiz);
    motor[1]->setVelocity(solSagHiz);
    motor[0]->setPosition(INFINITY);
    motor[1]->setPosition(INFINITY);


  }
/*simülasyon durdurulduğunda robotun ve kodun çalışmayı durdurması için gereken kodlar */
  delete robot;
  return 0;
}