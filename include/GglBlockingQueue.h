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
         void pop(){
            std::unique_lock<std::mutex> lock{queMtx};
            if(rawQueue.size()>0){
                rawQueue.pop();
                return;
            }
            throw std::runtime_error(" queue is empty can not pop ! ");
         }
         T front(){
            std::unique_lock<std::mutex> lock{queMtx};
            if(rawQueue.size()>0){
            return rawQueue.front();
            }
            std::cout<<"queue size=="<<rawQueue.size()<<std::endl;
            throw std::runtime_error("no item in this queue!");
         }
         int32_t size(){
            return rawQueue.size();
         }
         protected:
        std::queue<T> rawQueue;
        std::mutex queMtx;
    };
}