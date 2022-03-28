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
