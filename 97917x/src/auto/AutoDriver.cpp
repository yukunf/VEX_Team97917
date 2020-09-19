#include "../src/auto/auto.h"
static vex::thread AutoThread;//File Field (to create time interruption)
void bindAutonomous(void(*fp)()){
  autofp = fp;
}
void moniterFunc(){
  vex::timer time;
  time.reset();
  while(time.time(sec) <=15){
    vex::wait(100, msec);
  }
  AutoThread.interrupt();
}
//主代理
void autonomous(){
  AutoThread = autofp;//implicit object creation
  vex::thread monitor(moniterFunc);;
  monitor.detach();
  AutoThread.detach();
}
