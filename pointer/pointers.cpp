//! POINTERS: declaring pointers
// Always initialize pointers, to point 'nowhere'
// Uninitialized pointers contain garbage data and can point 'anywhere'
// Initializing to zero or nullptr represents address zero
//  만약 내가 포인터를 변수나 함수에 초기화 하지 않을 땐, 반드시 nullptr로 초기화 해주어야한다.
// check
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//! EXAMPLE:
int main()
{
    int score(10);
    double high_temp(100.7);

    int *score_ptr(nullptr); // score pointer is pointing nowhere, pointer to an integer but pointing nowhere

    score_ptr = &score;
    cout << "Value of score is: " << score << endl;
    cout << "Address of score is: " << &score << endl;
    cout << "Value of score_ptr is: " << score_ptr << endl;

    // score_ptr = &high_temp;
    //since the data type is different it show compile error
    return 0;
}