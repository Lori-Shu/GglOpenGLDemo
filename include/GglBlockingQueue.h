#pragma once
#include"PreInclude.h"
#include<queue>
#include<mutex>

namespace mystd{
    /*自己实现push等待pop无元素抛出异常的阻塞队列*/
    template<typename T>
    class GglBlockingQueue{
        public:
         GglBlockingQueue(){

         }
         virtual ~GglBlockingQueue(){

         }
         void push(T item){
            std::unique_lock<std::mutex> lock{queMtx};
            rawQueue.push(item);
         }
         bool pop(){
            std::unique_lock<std::mutex> lock{queMtx};
            if(rawQueue.size()>0){
                rawQueue.pop();
                return true;
            }
            return false;
         }
         T front(){
            return rawQueue.front();
         }
         protected:
        std::queue<T> rawQueue;
        std::mutex queMtx;
    };
}