#include<iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include "../helpers/test_time.cpp"
std::mutex mtx;

void Print()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    std::lock_guard<std::mutex> guard(mtx);
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout<<std::this_thread::get_id()<<"\n";
    guard.~lock_guard();
    
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
int main(){
    TestTime test;
    test.start();
    
    std::thread th1(Print);
    std::thread th2(Print);
    th1.join();
    th2.join();

    test.end();
   return 0;
}