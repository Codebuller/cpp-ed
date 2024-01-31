#ifndef TEST_TIME
#define TEST_TIME 

#include<chrono>
#include<iostream>
class TestTime
{
    std::chrono::_V2::system_clock::time_point start_time, end_time;
    
    
    
    public:
    TestTime(){};
    ~TestTime(){
       std::chrono::duration<float> duration = end_time - start_time;
       std::cout << "\n" <<"Process ended by " << duration.count() << " second." << "\n";
    }
    void start(){
        start_time = std::chrono::high_resolution_clock::now();
    }
    void end(){
        end_time = std::chrono::high_resolution_clock::now();
    }

};

#endif //TEST_TIME