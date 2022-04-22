//!EXAMPLE: ONE

#include<iostream>
using namespace std;
class B {
protected:
    int x, y;
public:
    virtual void Area() = 0; // Pure Virtual Function
};
class R:public B {
public:
    R(){x=1, y=2;}
    void Area() { cout << x*y << "\n"; }
};
class T:public B {
public:
    T(){x=1; y=2;}
    void Area() { cout << x*y/2 << "\n"; }
};
int main() {
    B *b;     R r;    T t;
    b = &r;  b->Area();
    b = &t;  b->Area();
}
//=================================================================================
//!EXAMPLE: TWO

#include<iostream>
using namespace std;
class CPoly{
protected:
    int w, h;
public:
    virtual int Area()=0;
};

class CRect: public CPoly{
public:
    CRect(int a, int b){w=a; h=b;}
    int Area(){return(w*h);}
};
class CTri: public CPoly{
public:
    CTri(int a, int b){w=a; h=b;}
    int Area(){return(w*h/2);}
};
int main(){
    CRect r(4,3);
    CTri t(4,3);
    CPoly* p=NULL;
    p=&r;    cout << p->Area() << endl;
    p=&t;    cout << p->Area() << endl;
}
//=================================================================================
//!EXAMPLE: THREE, Templete

#include <cstdio>
using namespace std;

template <typename T>
T maxof ( T a, T b ) {
    return ( a > b ? a : b );
}

int main( int argc, char ** argv ) {
    int m = maxof<int>( 7, 9 );
    printf("max is: %d\n", m);
    return 0;
}
//=================================================================================
//!EXAMPLE: FOUR, Templete

#include <iostream>
#include <string>
#include <exception>
using namespace std;

// simple exception class
class E : public std::exception {
    const char * msg;
    E(){};    // no default constructor
public:
    explicit E(const char * s) throw() : msg(s) { }
    const char * what() const throw() { return msg; }
};

// simple fixed-size LIFO stack template
template <typename T>
class bwstack {
private:
    static const int defaultsize = 10;
    static const int maxsize = 1000;
    int _size;
    int _top;
    T * _stkptr;
public:
    explicit bwstack(int s = defaultsize);
    ~bwstack() { delete[] _stkptr; }
    T & push( const T & );
    T & pop();
    bool isempty() const { return _top < 0; }
    bool isfull() const { return _top >= _size - 1; }
    int top() const { return _top; }
    int size() const { return _size; }
};

// Stack<T> constructor
template <typename T>
bwstack<T>::bwstack ( int s ) {
    if(s > maxsize || s < 1) throw E("invalid stack size");
    else _size = s;
    _stkptr = new T[_size];
    _top = -1;
}

template <typename T>
T & bwstack<T>::push ( const T & i ) {
    if(isfull()) throw E("stack full");
    return _stkptr[++_top] = i;
}

template <typename T>
T & bwstack<T>::pop () {
    if(isempty()) throw E("stack empty");
    return _stkptr[_top--];
}

int main( int argc, char ** argv ) {
    try {
        bwstack<int> si(5);
        
        cout << "si size: " << si.size() << endl;
        cout << "si top: " << si.top() << endl;
        
        for ( int i : { 1, 2, 3, 4, 5 } ) {
            si.push(i);
        }
        
        cout << "si top after pushes: " << si.top() << endl;
        cout << "si is " << ( si.isfull() ? "" : "not " ) << "full" << endl;
        
        while(!si.isempty()) {
            cout << "popped " << si.pop() << endl;
        }
    } catch (E & e) {
        cout << "Stack error: " << e.what() << endl;
    }
    
    try {
        bwstack<string> ss(5);
        
        cout << "ss size: " << ss.size() << endl;
        cout << "ss top: " << ss.top() << endl;
        
        for ( const char * s : { "one", "two", "three", "four", "five" } ) {
            ss.push(s);
        }
        
        cout << "ss top after pushes: " << ss.top() << endl;
        cout << "ss is " << ( ss.isfull() ? "" : "not " ) << "full" << endl;
        
        while(!ss.isempty()) {
            cout << "popped " << ss.pop() << endl;
        }
    } catch (E & e) {
        cout << "Stack error: " << e.what() << endl;
    }
    
    return 0;
}