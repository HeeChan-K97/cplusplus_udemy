#include <chrono>
#include <iostream>
#include <mutex>
#include <deque>
#include <thread>
#include <condition_variable>

std::deque<int> q;
std::mutex mu;
std::condition_variable cond;

/*=======================STEPS==========================
    1. lock the mutex because the 'q' is shared memory between thread 1 and 2
    2. thread 2 is in 'busy' waiting state, it keeps checking ig the q is empty and if it is it unlock the locker and goto next loop immidiately
    3. Hence, we make the thread to take a nap(sleep_for) if the 'q' is empty and then go to the next loop
    4. how do we decide the time duration of sleep_for?
            -> we use convar
    5. in thread 1 after push in the data and unlock, we call convar and notify_one();
    6. rather than the if loop in thread 2 we only need to call convar and .wait(locker);
    7. convar can enforce that the thread 2 to fetch data only after thread1 push data into 'q'
    8. since we dont want to lock while sleeping, the thread 2 is unlock while sleep and whenever it is wake by thread 1 it locks
    9. since we need to repeat lock and unlock we need to use unique lock for convar, NOT lock_guard
=========================================================
*/

/*
    spurious wake, the thread can wake by itself
    we use LAMBDA function, which predicate that determines whether the condition is really met for the thread to keep running

    syntax) 
            cond.wait(locker, [](){return !q.empty();})

        If the thread 2 wakes up and found that the 'q' is empty then it go back to sleep again    
*/


void function_1(){//producer
    int count = 10;
    while (count > 0){
        std::unique_lock<std::mutex> locker(mu);
        q.push_front(count);//push the number into the q and sleep for a second(line 17)
        locker.unlock();
        cond.notify_one(); //wake another thread by notifying it use notify_all(); if there is more than one waiting
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count--;
    }

}void function_2(){//consumer
    int data = 0;
    while (data != 1){
        std::unique_lock<std::mutex> locker(mu);
        // if (!q.empty()){//while loop that keeps checking if the q is empty
            cond.wait(locker);//! IMPORTANT: putting thread 2 into sleep until it is notified by thread 1
            data = q.back();//if not empty, it pops off the data and print it out or go to the next loop
            q.pop_back();
            locker.unlock();
            std::cout<<"t2 got a value from t1: " << data << std::endl;
        // }   else{
        //     locker.unlock();
        // }
    }
}

int main(){

    //creating thread
    std::thread t1(function_1);
    std::thread t2(function_2);
    //wait for two threads to finish
    t1.join();
    t2.join();

    return 0;
}