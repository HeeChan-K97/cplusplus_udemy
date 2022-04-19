#include <iostream>
using namespace std;

1. How to call a function

void func(){//the function must be defined before the main function otherwise using forward declaration //void func();
    puts("this is func");
}

int main(){
    puts("this is main");
    func(); //calling a function
    return 0;
}
reference로 전달되지 않은 인자는 외부 함수에서 값을 변경 시켜도 메인 함수에서는 변경되지 않는다.
reference를 전달 해야지만 그 값이 변한다.
Internally, values are passed to and from a function on a small data structure called a stack. The stack is a relatively small space, 
and requires processing power to manage. Passing large values to a function requires copying larger amounts of data on the stack.

void func(int &i)
{
    i = 73;
    printf("in func() the value is &d\n", i);
}

int main()
{   
    i = 43;
    puts("this is main()");
    func(i);
    printf("after func() i is %d\n", i);
    return 0;
}

void func(const string & s){
    printf("the value is %s\n", s.c_str());
}
int main(){
    string s = "this is a string!";
    func(s);
    return 0;
}

2. /*Using Automatic and static variables
: Automatic storage is stored on the stack which is temporary and the value is not carried from one invocation to another.
: Static storage is not stored on the stack and it's persistent(집요한) for the life of the process.*/

const sting & func() {
    const static string s = "this is func()";
    return s;
}

int main(){
    ptus("this is main()");
    const string & s = func();
    printf("func() returns %s\n", s.c_str());
    return 0;
}
// Returning a value from a function is much like passing values to a function and that happens on the stack.

3. Using function pointer
void func(){
    puts("this is func");
}

int main(){
    void (*pfunc)() = func; //pointer named pfunc which points to the func //dereferencing the pointer
    puts("this is main");
    pfunc();
    return 0;
}

===========EXAMPLE============
#include <cstdio>
using namespace std;

const char * prompt();
int jump( const char * );

void fa() { puts("this is fa()"); }
void fb() { puts("this is fb()"); }
void fc() { puts("this is fc()"); }
void fd() { puts("this is fd()"); }
void fe() { puts("this is fe()"); }

void (*funcs[])() = { fa, fb, fc, fd, fe }; //array of function pointer

int main() {
// It simply calls prompt and passes that return value to jump and then says done. And it calls those in a while loop until jump returns false.
    while(jump(prompt())) ;//repeat over and over until the loop function is done
    puts("\nDone.");
    return 0;
}

const char * prompt() {
    puts("Choose an option:");
    puts("1. Function fa()");
    puts("2. Function fb()");
    puts("3. Function fc()");
    puts("4. Function fd()");
    puts("5. Function fe()");
    puts("Q. Quit.");
    printf(">> ");
    fflush(stdout);                 // flush after prompt
    
    const int buffsz = 16;          // constant for buffer size
    static char response[buffsz];   // static storage for response buffer
    fgets(response, buffsz, stdin); // get response from console
    
    return response;
}

int jump( const char * rs ) {
    char code = rs[0];
    if(code == 'q' || code == 'Q') return 0;
    
    // get the length of the funcs array
    int func_length = sizeof(funcs) / sizeof(funcs[0]);
    
    int i = (int) code - '0';   // convert ASCII numeral to int
    if( i < 1 || i > func_length ) {
        puts("invalid choice");
        return 1;
    } else {
        funcs[i - 1]();         // array is zero-based
        return 1;
    }
    
}
=============================================
4. Overloading function names
/*:  In C++, the function signature consists of the return type, the function name, and the list of argument types.
  :  The return type cannot be the only distinguishing factor, but the constness of the return type can be, and often is.
     And there are rules about how types are promoted to distinguish parameters, so it's a good idea to test your overload of functions thoroughly
  :  in C++, functions are distinguished by their signatures, so it's possible to have multiple functions with the same name, 
     that operate with different parameters, and with different return types, and this is called function overloading.
*/

#include <cstdio>
using namespace std;

// volume of a cube
double volume( double a ) {
    printf("cube of %.3lf\n", a);
    return a * a * a;
}

// volume of a cylinder
double volume( double r, double h ) {
    const static double _pi = 3.141592653589793;
    printf("cylinder of %.3lf x %.3lf\n", r, h);
    return _pi * r * r * h;
}

// volume of a cuboid
double volume( double a, double b, double c ) {
    printf("cuboid of %.3lf x %.3lf x %.3lf\n", a, b, c);
    return a * b * c;
}

int main() {
    printf("volume of a 2 x 2 x 2 cube: %.3lf\n", volume(2.0));
    printf("volume of a cylinder, radius 2, height 2: %.3lf\n", volume(2.0, 2.0));
    printf("volume of a 2 x 3 x 4 cuboid: %.3lf\n", volume(2.0, 3.0, 4.0));
    return 0;
}
=======================================================