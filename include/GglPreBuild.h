#pragma once
#include<string>
#include<unistd.h>
#include<iostream>
#include<memory>
#include<cstdlib>
#include<cstring>
#define Linux
static void getProgramDir(std::string &path) {
  char proDir[1024];
//   只在Linux环境有效
#ifdef Linux
  int32_t size = readlink("/proc/self/exe", proDir, 1024);
#endif
  std::string tp = std::string(proDir);
  int32_t lastIndex = tp.find_last_of('/');
  path = tp.substr(0, lastIndex + 1 - 0);
  std::cout << "proDir==" << path << std::endl;
}