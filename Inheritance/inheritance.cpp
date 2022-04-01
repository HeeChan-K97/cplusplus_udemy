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
즉, private를 base class가 아닌 다른 클래스에서 바꾸고 싶다면 그에 맞는 public 함수가 필요하다.

