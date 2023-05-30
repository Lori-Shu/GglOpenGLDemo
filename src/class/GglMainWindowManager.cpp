#include"GglMainWindowManager.h"

namespace mystd{
    using namespace std;
    GglMainWindowManager::GglMainWindowManager(GglNote * n){
        notePtr=n;
    }
    void GglMainWindowManager::switchToNote(){
        notePtr->show();
    }
}