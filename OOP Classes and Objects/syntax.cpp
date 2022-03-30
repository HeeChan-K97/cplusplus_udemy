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