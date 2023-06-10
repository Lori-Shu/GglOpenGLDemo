#pragma once
#define Windows

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>
#include <unistd.h>
#include<cassert>
#include<array>
#include<mutex>
void getProgramDir(std::string &path);

namespace mystd{
struct UserDetail {
  std::string id;
  std::string username;
};
extern UserDetail currentUserDetail;
}