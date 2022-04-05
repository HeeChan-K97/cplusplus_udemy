// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() //one without parameter
{
  // do stuff...
}

void bar(int x) //one with a parameter
{
  // do stuff...
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo() //foo is the function that we give to the thread
  std::thread second (bar,0);  // spawn new thread that calls bar(0)//this is how we define a function with a parameter and its syntax

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}