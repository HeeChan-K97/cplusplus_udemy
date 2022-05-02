<What is multi-preocessing and Multi-threading>
Multi-processing: Two or more process communicates using interprocess communication system
Multi-threading: Where one process contains two or more threads and all the thread communicates each other through shared memory

<Pros and Cons for Multi-threading>
Pro:
Fast to start
Low overhead
Cons:
Difficult to implement
Cannot run on distributed system

=============================================================================================
Example 1:
#include <iostream>
#include <thread>

void function_1(){
    std::cout << "Beauty us only skin-deep" << std::endl;
}

int main(){

    //creating thread
    std::thread t1(function_1);//thread object t1 is constructed with a function_1 parameter
                               //t1 start running
    t1.join();//which means the main thread(메인함수) waits for t1 to finish
    //여기까지만 하면, 이 함수를 통해서 출력되는 것은 child thread인 t1에 의한 출력창이 된다. And we have thwo thread running which are the main thread and the child thread, t1.
    t1.detach(); //with the thread detached, t1 will run freely on its own which is called DAEMON PROCESS.
                //the main thread is no longer connected to child thread so the C++ runtime library will be responsible to reclaim the resource of t1.
                //Some Daemon process will run until the program shut down

    ** 이렇게 하다보면 t1이라는 thread가 실행되기도 전에 메인 함수가 끝나버리는 경우가 발생할 수 있다. 
       이것이 Concurrent programming의 전형적인 특징이다. 두 thread가 independently하게 실행되다 보면
       어떤 thread가 먼저 실행될지 예상하기 힘들어진다. 그렇게 되면 우리는 싱크로나이징 기술이 필요하게 된다.
    ** 결과적으로 thread가 리소스를 쉐어링하고 있는 상황에서 메인함수는 다른 함수 thread가 리소스에 접근할 수 있는 만큼의 시간동안 exist해야한다.
    ** We can only join or detach once.
    ** To check whether my thread is joinable we can use
                => t1.joinable()

    return 0;
}
