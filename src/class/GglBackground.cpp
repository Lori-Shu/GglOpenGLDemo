#include"GglBackground.h"

namespace mystd{
    using namespace std;
    static float zmove=0.0f;
    mutex moveMtx;
    static bool endLoopFlag=false;
    GglBackground::GglBackground(GLFWwindow* wdow) {
        window=wdow;
    }
    GglBackground::~GglBackground(){
      endLoopFlag = true;
      changingThreadPtr->join();
    }
    void GglBackground::setMouseControlBkImageZ(float &z){
      glfwSetScrollCallback(
          window,
          [](GLFWwindow* window, double xoffset, double yoffset) -> void {
            moveMtx.lock();
            zmove = static_cast<float>(static_cast<int32_t>(yoffset) * 10);
            moveMtx.unlock();
          });

      changingThreadPtr = make_unique<thread>([&]() {
        for(;;){
            if(endLoopFlag){
                return;
            }
          if ((z + zmove) >= 0.0f && (z + zmove) <= 100.0f) {
            z = z + zmove;
            moveMtx.lock();
            zmove = 0;
            moveMtx.unlock();
            cout << "z==" << z << endl;
        }
        this_thread::sleep_for(chrono::duration<int32_t,ratio<1,1000>>(100));
        }
      });
    }
}