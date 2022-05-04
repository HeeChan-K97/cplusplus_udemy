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
    //여기까지만 하면, 이 함수를 통해서 출력되는 것은 child thread인 t1에 의한 출력창이 된다. And we have two thread running which are the main thread and the child thread, t1.
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
=============================================================================================

If the thread is neither joined nor detached?
: if a thread object is destroyed before join or detach then the program will terminate
So we need to make a decision whether we join the thread or detach the thread before the thread object gone out of scope

#include <iostream>
#include <thread>
using namespace std;

void function_1(){
    std::cout << "Beauty us only skin-deep" << std::endl;
}

int main(){
    std::thread t1(function_1);

    //====Alternative method (Wrapper method)====
    //Alternatively USING RAII
    //the destructor of the wrapper will automatically join the thread when the 'w' go out of scope
    //whenever the 'w' go out of scope automatically calls the t1.join to join the thread
    Wrapper w(t1);
    //===========================================

    <the thread can be constructed not only by regular function but class or lambda functions>
    For ex)
    class Fctor{
        public:
            void operator()(string msg){
                cout << "t1 says: " << msg << endl;
            }
    };

    Fctor fct; //이렇게 되면 두 thread가 동시에 출력을 하면서 정돈되지 않은 출력창을 표시하게 된다.
    std::thread t1(fct);//creating a thread that passing a fct to the function
    std::thread t1((Fctor()));//creating a fctor and passing it as a parameter to the constructor of t1
    
    string s = "where is HeeChan";
    //way to pass the string to the thread is taking s as aditional parameter to the constructor 
    std::thread t1((Fctor()), s);

    //with or without an exception the thread will always be joined using try and catch method
    std::try {
            std::cout<< "from main: " << i << endl;
    } catch (...){
        t1.join();
        throw;
    }

    t1.join();
    return 0;
}
=============================================================================================
Example 2: 
#include <iostream>
#include <thread>
using namespace std;

void function_1(){
    std::cout << "Beauty us only skin-deep" << std::endl;
}
class Fctor{
        public:
            void operator()(string msg){
                cout << "t1 says: " << msg << endl;
            }
};

int main(){

    string s = "where is HeeChan";
    //way to pass the string to the thread is taking s as aditional parameter to the constructor 
    std::thread t1((Fctor()), s);

    //with or without an exception the thread will always be joined using try and catch method
    try {
            cout<< "from main: " << s << endl;
    } catch (...){
        t1.join();
        throw;
    }

    t1.join();
    return 0;
}

//Result
from main: where is HeeChan
t1 says: where is HeeChan
===================================================================================
Parameter to a thread is ALWAYS passed by its value
if we want to pass the thread by its reference we have to std::ref()

Example 3: 
#include <iostream>
#include <thread>
using namespace std;
class Fctor{
        public:
            void operator()(string& msg){
                cout << "t1 says: " << msg << endl;
                msg = "How we pass the string by reference";
            }
};

int main(){

    string s = "where is HeeChan";
    std::thread t1((Fctor()), std::ref(s));//passing the string by its reference
    std::thread t1((Fctor()), std::move(s));//this will move the s from the main thread to the child thread. This method is safe and efficient
    t1.join(); // to make sure t1 has finished their job
            cout<< "from main: " << s << endl;

    return 0;
}

RESULT:
t1 says: where is HeeChan
from main: How we pass the string by reference
===================================================================================
** The thread object can only be moved not copy.
    eg) std::thread t2 = t1; // compile error
        std::thread t2 = std::move(t1);

        then now we need to join t2.join(); since the t1 is empty now

===Printing out the parent thread's ID===
-> std::cout << std::this_thread::get_id() << std::endl;
//if we put this commend inside the child thread 'this' becomes the child and prints out the child thread's ID

===Printing out the child thread's ID===
-> std::cout << t1.get_id() << std::endl;

===To avoid "Oversubscription" we can check how many threads can run concurrently===
-> std::thread::hardware_concurrency(); //Indication
===================================================================================
Example 4:

#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork(){
    using namespace std::literals::chrono_literals;

    while(!s_Finished){
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main() {
    std::thread worker(DoWork);

    std::cin.get();//wait until ENTER pressed by the user
    s_Finished = true;
    
    worker.join();
    std::cout << "Finished." << std::endl;

    std::cin.get();
}