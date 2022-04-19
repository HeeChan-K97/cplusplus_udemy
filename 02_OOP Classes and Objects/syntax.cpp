Accessing Class Members

1. Using the dot operator
선언문은 오른쪽에서 왼쪽으로 읽는 것, 그렇게 되면 더 이해하기 쉽다.
eg) Account frank_account; //라는 클래스에 frank_account라는 오브젝트를 선언.

  i.  frank_account.balance; //right to left.   balance method is called on the specific object 'frank_account'
  ii.  frank_account.deposit(1000.00); //read from right to left. =  depositing 1000.00 to frank-account

2. Using a pointer to an object
먼저 사용할 object를 dereference한 후에 dot operator를 사용한다.
eg) Account *frank_account = new Account();

    i. (*frank_account).balance;
    ii. (*frank_account).deposit(1000.00);

또는 화살표를 사용해서 표현할 수 있다.
Account *frank_account = new Account();

    i. frank_account->balance;
    ii. frank_account->deposit(1000.00);

-------------------------------------------------------------------------------------------------

1. Implementing Member Methods - Inside the class declaration

class Account {
    private:
        double balance;
    public:
        void set_balance(double bal){
            balance = bal;
        }

        //since the member 'balance' is the private member of the class Account, we need a "METHOD" to 
        //access the private member. And this method can be declared inside or outside of the class declaration.
        double get_balance(){
            return balance;
        }
};

2. Implementing Member Methods - Outside the class declaration

class Account {
    private:
        double balance;
    public:
        void set_balance(double bal);
        double get_balance();
};

void Account::set_balance(double bal) {//use scope resolution operator
    balance = bal;
}
double Account::get_balance() {
    return balance;
}

3. When we are making a cpp file and need to include a hearder file of my own

    syntax) eg)  
                #include "Account.h"  //이런 식으로 만들면 된다.
                                    //이미 있는 헤더 파일은 기존에 선언하듯이 <>를 사용하여 넣어주면 된다.
------------------------------------------------------------------------------------------------------------
Constr uctor Initialization List_
 //! PREVIOUS:
 Player::Player(){
     name = "None";
     health =0;
     xp =0;
 }
 //! BETTER:
 Player::Player()
    : name{"None"}, health{0}, xp{0} {
    }//이렇게 되면 constructor의 메인 바디가 실행되기도 전에 member들이 초기화되게 된다.
    //Constr uctor Initialization List가 유용한 이유는 이런 형식으로 선언을 하게 되면 초음부터 초기화가 가능하기 때문이다
    //보통 방식으로 하게되면 초기화가 아니라 assigning이 되기 때문에 inefficient하다.
------------------------------------------------------------------------------------------------------------    
Delegating Constructors

1. Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
    }
2. Player::Player()
    : Player {"None",0 ,0}{//this is delegation of constructor
    }
3. Player::Player()
    : Player {name_val, 0, 0}{
    } 
------------------------------------------------------------------------------------------------------------
Default Constructor Parameters

class Player
{
    private:
        std::string name;
        int health;
        int xp;
    public:
    //Constructor with default parameter values
    Player(std::string name_val = "None",
           int health_val = 0,
           int xp_val = 0);
};//default constructor parameter is declared inside the constructor delcaration in the class 

====================================================================================================
1. move semantic
WHEN IS IT USEFUL?
-> Sometimes copy constructors are called many times automatically due to the copy semantics of C++
-> Copy constructors doing deep copying can have a significant performance bottleneck좁은[번잡한] 도로
-> C++11 introduced move semantics and the move constructor
-> Move constructor moves an object rather than copy in
-> Optional but recommended when you have a raw pointer
-> Copy elision -C++ may optimize copying away completely (RVO-Return Value Optimization)

2. r-value references

/*  L-values = An l-value is an object that occupies a location in memory and is addressable.
    values that have names and are addressable
    modifiable if they are not constants;

    R-value - anything that's not an l-value is an r-value.
    Usually, r-values on the right-hand side of an assignment expression;
*/

int x {100} //integer x initialized to 100 and x is l-value
    int &l_ref = x; //l-valeu reference
    l_ref = 10;     // change x to 10

    int &&r_ref = 200;  // r-value ref
    r_ref = 300;        //change r_ref to 300

    int &&x_ref = x;    //compile error, since we are trying to assign L-value to R-value reference

3. l-value reference parameters

    int x {100};//integer x initialized to 100 and x is l-value

    void func (int &num);   //A, the func demands l-value reference

    func(x);    //calls A-x is an l-value
    func(200);  //ERROR -200 is an r-value

4. r-value reference parameters

    int x {100};//integer x initialized to 100 and x is l-value

    void func (int &&num);   //B, the func demands r-value reference

    func(200);    //calls B - 200 is an r-value
    func(x);  //ERROR - x is an l-value
