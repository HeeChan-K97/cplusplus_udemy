Example 1:

#include <thread>
#include <iostream>
#include <string>
#include <mutex> // mutex STL
using namespace std;

std::mutex mu;//creating a mutex

// void shared_print(string msg, int id){//Synchronosing the access of the common resource with mutex mu.
//     mu.lock();//By locking the mutex, other thread won't print message
//     cout << msg << id << endl;
//     mu.unlock();//Letting other thread to print their message
// }

void shared_print(string msg, int id){//Synchronosing the access of the common resource with mutex mu.
    std::lock_guard<std::mutex> guard(mu);//unlock the mutex, mu when the guard goes out of scope, with and without any exceptions
    cout << msg << id << endl; 
}

void function_1(){
    for(int i = 0; i > -100; i--){
        shared_print(string("From t1: "), i);//instead of using cout both thread will call the string using the shared_print function
    }
}

int main(){
    std::thread t1(function_1);//making a thread called t1 with function_1

    for(int i = 0; i<100; i++){//counting from 0 to 99
        shared_print(string("From main: "), i);
    }
    t1.join();//wait for t1 to finish

    return 0;
}

//Result is very mess since there are two threads(Main and t1) 
//using the same resource in this code it "cout"
//This situation is called RACE CONDITION
/*
* Race condition = one or more threads trying to execute using a common resource
* One of the way to solve this problem is using MUTEX to synchronize the access of the common resource
* 만약 cout에 관련된 문제로 oversubscription이 발생한다면 cout을 share할 수 있는 함수를 만들어주는 것이 해결책이 된다.
*/

==============================================================================================================
Example 2:

#include <thread>
#include <iostream>
#include <string>
#include <mutex> // mutex STL
using namespace std;

class LogFile {
    std::mutex m_mutex;
    ofstream f;

public:
    Logfile() {
        f.open("log.txt");
    } //Need destructor to close file
    void shared_print(string id, int value){//Synchronosing the access of the common resource with mutex mu.
        std::lock_guard<mutex> locker(m_mutex);//unlock the mutex, mu when the guard goes out of scope, with and without any exceptions
        f << "From " << id <<": "<< value << endl; 
    }// now the f is under the total protection of mutex
    //never return f to the outside like ofstream& getStream() {return f;}
    //Never pass f as argument to user provided function
    /*
    void processf(void fun(ofstream&)) {
        fun(f);
    }
    */
};

void function_1(Logfile& log){
    for(int i = 0; i > -100; i--){
        log.shared_print(string("From t1: "), i);//instead of using cout both thread will call the string using the shared_print function
    }
}

int main(){
    std::thread t1(function_1);//making a thread called t1 with function_1

    for(int i = 0; i<100; i++){//counting from 0 to 99
        log.shared_print(string("From main: "), i);
    }
    t1.join();//wait for t1 to finish

    return 0;
}

===Avoiding Data Race===
1. Use mutex to synchronize data access
2. Never leak a handle of data to outside
3. Design interface appropriately
===================================================================================