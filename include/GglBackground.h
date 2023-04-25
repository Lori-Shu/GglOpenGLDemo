#pragma once
#include<GLFW/glfw3.h>
#include<iostream>
#include<thread>
#include<memory>
#include<chrono>
#include<mutex>
namespace mystd{
    class GglBackground{
        public:
         GglBackground(GLFWwindow* wdow);
         ~GglBackground();
        void setMouseControlBkImageZ(float& z);
        private:
         GLFWwindow* window;
         std::unique_ptr<std::thread> changingThreadPtr;
         
    };
}