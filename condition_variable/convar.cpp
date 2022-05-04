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
===============================================THREAD MANAGEMENT============================================================
int main(){

    //creating thread
    std::thread t1(function_1);
    std::thread t2(function_2);
    //wait for two threads to finish
    t1.join();
    t2.join();

    return 0;
}

Neither join nor detach thread will not execute. 
So we need to make a decision whether we want to join or detach the thread before a thread going out of scope

void function_1(){
    std::cout << "Beauty us only skin-deep" << std::endl;
}

int main(){
    std::thread t1(function_1); // t1 starts running

    //Alternatively USING RAII
    Wrapper w(t1);
    //the destructor of the wrapper will automatically join the thread when the 'w' go out of scope

    std::try {
        for (int i=0; i<100; i++)
            std::cout<< "from main: " << i << endl;
    } catch (...){
        t1.join();
        throw;
    }

    t1.join();
    return 0;
}
If the thread is neither joined nor detached?
: if a thread object is destroyed before join or detach then the program will terminate
So we need to make a decision whether we join the thread or detach the thread before the thread object gone out of scope
Parameter to a thread is always passed by its value
if we want to pass the thread by its reference we have to std::ref()


** std::move()
    eg) std::thread t2 = t1; // compile error
        std::thread t2 = std::move(t1); //correct way to copy the thread to another

** std::ref()

===Printing out the parent thread's ID===
-> std::cout << std::this_thread::get_id() << std::endl;
//if we put this commend inside the child thread 'this' becomes the child and prints out the child thread's ID

===Printing out the child thread's ID===
-> std::cout << t1.get_id() << std::endl;

===To avoid "Oversubscription" we can check how many threads can run concurrently===
-> std::thread::hardware_concurrency(); //Indication

========================================================================================================vv
RACE CONDITION AND MUTEX

* Race condition = one or more threads trying to execute using a common resource
* One of the way to solve this problem is using mutex to synchronize the access of the common resource
* 만약 cout에 관련된 문제로 oversubscription이 발생한다면 cout을 share할 수 있는 함수를 만들어주는 것이 해결책이 된다.
    Mutex of Synchronize the access of common resource among a group of threads
    참고: https://www.youtube.com/watch?v=3ZxZPeXPaM4&t=1s  (From 3:00)
*Sometimes we might face a exception that might lock the contents forever, in the case we use "lock_guard"
    eg) std::lock_guard<std::mutex> guard(mu);
*In order to protect the resource completely, the mutex must be bundled together with the resource it is protecting
    참고: https://www.youtube.com/watch?v=3ZxZPeXPaM4&t=1s (From 5:39)

===Avoiding Data Race===
1. Use mutex to synchronize data access
2. Never leak a handle of data to outside
3. Design interface appropriately