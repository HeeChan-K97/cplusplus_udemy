Inheritance

Terminology
* Inheritance
    Process of creating new classes from existing classes
    Reuse mechanism
* Single Inheritance
    A new class is created from another 'single' class
* Multiple Inheritance
    A new class is created from two or more other classes  

Base class = parent class, super class
    The class being extended or inherited from

Derived class = child class, sub class
    The class being created from the Base class
    Will inherit attributes and operations from Base class      

---------INHERITANCE IS TRANSITIVE---------
------------------------------------------------------------------------------------------
Inheritance and Composition
"is a" relationship VS "has a" relationship
------------------------------------------------------------------------------------------
Deriving classes from existing classes;

1. C++ derivation syntax

class Account {
    // Account class members. . .
};

class Savings_Account : public Account {
    //Savings_Account class members. . .
};

//Savings_Account is a Account.
2. C++ creating objects

*   Account account {};
    Account *p_account = new Account();
    account.deposit(1000.00);
    p_account->withdraw(200.0);

    delete p_account;

*   Savings_Account sav_account {};
    Savings_Account *p_sav_account = new Savings_Account();
    sav_account.deposit(1000.0);
    p_sav_account->withdraw(200.0);

    delete p_sav_account;
------------------------------------------------------------------------------------------

Access specifier, Protected:

    * Accessible from the Base class itself
    * Accessibile from classes Derived from Base
    * Not accessible by objects of Base or Derived

*** members which are protected in the Base class is also become a protected members of a Derived class
*** private members of the Base class is always private thata derived class can never get access
*** private inheritance makes the members of the derived class private
어떤 base class의 private 멤버의 값을 바꾸고 싶거나 정의하고 싶을때는 반드시 Base class에 주어진 getter and setter functions들을 통해서만 변경이 가능하다.
즉, private를 base class가 아닌 다른 클래스에서 바꾸고 싶다면 그에 맞는 public 함수가 필요하다.; Read the Abstraction below;

------------------------------------------------------------------------------------------

What is Abstraction?
: Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential 
    information about the data to the outside world, hiding the background details or implementation.

* Abstraction using Classes: We can implement Abstraction in C++ using classes. Class helps us to group data members and member functions
    using available access specifiers. A Class can decide which data member will be visible to outside world and which is not.

Advantages of Data Abstraction:

Helps the user to avoid writing the low level code
Avoids code duplication and increases reusability.
Can change internal implementation of class independently without affecting the user.
Helps to increase security of an application or program as only important details are provided to the user;

------------------------------------------------------------------------------------------
<Passing argument to base class constructors>
// class Base {
//     public:
//         Base();
//         Base(int);
//         . . .
// };

// Derived::Derived(int x)
//     : Base(x), {/"optional initializers for Derived"/} {
//         //code
//     }
<Constructor and class initialization;>

class Base {
    int value;
public:
    Base():value{0} {
        std::cout<<"Base no-args constructor"<<std::endl;
    }
    Base (int x):value{x} {
        std::cout<<"int Base constructor"<<std::endl;
    }
};

class Derived : public Base {
    int doubled_value;
public:
    Derived():Base{}, doubled_value{0} {
        std::cout<<"Derived no-args constructor"<<std::endl;
    }
    Derived(int x):Base{x}, doubled_value {x*2} {//overloaded constructor, expects the parameter
        std::cout<<"int Derived constructor"<<std::endl;
    }//this constructor also invokes the base class overloaded in its initializedr list.
    //and then it initializes its own doubled value attribute to 2 times x.
    //and finally, it displays int derived constructor
};

eg)
int main(){
    Derived d {1000};//
    return 0;
}
 *  해당 base class의 constructor를 거치기 때문에 int x를 인자롤 받는 컨스트럭터가 발동되고 'value'라는 변수를 1000으로 초기화 시킨다.
    그 후, derived class의 constructor로 들어와서 또 인자 int x를 받는 컨스트럭터를 발돌 시킨다.
    그럼 변수 'doubled_value'를 거치면서 그 값을 1000*2인 2000으로 만들어 준다.

 *  derived class에서 컨스트럭터를 만들면 해당 베이스 클래스에 같은 모양의 컨스터럭터를 거치고 derived class의 constructor를 거치게 된다. 
    그래서 항상 베이스 클래스에 있는 contructor가 먼저 출력되게 된다.

<Copy constructor>
sdqwd
