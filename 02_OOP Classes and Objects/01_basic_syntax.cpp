#include <cstdio>
using namespace std;
/*===========================1. Defining a class===============================*/
class C1
{
    int i = 0; // Data member
public:
    // void setvalue( int value ) { i = value; }//function members, method
    // return_type function_name (parameter) {definition}
    void setvalue(int value);
    int getvalue();
};

void C1::setvalue(int value)
{ // C1의 한 부분임을 나타내기 위해서 C1::을 반드시 넣어준다
    i = value;
}

int C1::getvalue()
{
    return i;
}

int main()
{
    int i = 47;
    C1 o1; // variable object name = o1

    o1.setvalue(i);
    printf("value is %d\n", o1.getvalue());
    return 0;
}

/*=====================================Data members===========================================*/

//struct는 data member들만 있을때 사용하지 좋고 class는 함수와 같이 있을때 사용하기 좋다.
#include <cstdio>
using namespace std;

struct A{
    int ia;
    int ib;
    int ic;
};

int main()
{
    A a = {1,2,3};
    printf("ia: %d, ib: %d, ic: %d", a.ia, a.ib, a.ic);
    return 0;
}

/*========================================Function members=========================================*/
//Using const and mutual declaration
class C1 {
    int i = 0;//Data member
public:
    void setvalue(int value);
    int getvalue()const;
    int getvalue();
};

void C1::setvalue(int value){ // C1의 한 부분임을 나타내기 위해서 C1::을 반드시 넣어준다, using namespace C1
    i = value;
}

int C1::getvalue() const {
    puts("const getvalue()");
    return i;
}

int C1::getvalue(){
    puts("mutable getvalue()");
    return ++i;
}

int main() {
    int i = 47;
    C1 o1;
    
    o1.setvalue(i); //setting a value by passing a parameter to the function called "setvalue"
    printf("value is %d\n", o1.getvalue());//getting the value we want and expected

    const C1 o2;
    printf("value is %d\n", o2.getvalue());//print value is 0 since the default value is 0 in class C1
    
    return 0;
}
