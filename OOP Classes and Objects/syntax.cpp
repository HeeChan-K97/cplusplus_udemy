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