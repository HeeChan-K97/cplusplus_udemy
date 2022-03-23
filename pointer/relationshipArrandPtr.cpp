#include <iostream>
using namespace std;
//various ways of pointer notation
int main()
{
    int score[]{100, 95, 89};
    int *score_ptr {score};
    cout << "Value of scores: " << score << endl;
    cout << "Value of scores_ptr: " << score_ptr << endl;

    cout << "\nArray subscript notation --------------------" << endl;
    cout << score[0] << endl;
    cout << score[1] << endl;
    cout << score[2] << endl;

    cout << "\nPointer subscript notation --------------------" << endl;
    cout << score_ptr[0] << endl;
    cout << score_ptr[1] << endl;
    cout << score_ptr[2] << endl;

    cout << "\nPointer offset notation --------------------" << endl;
    cout << *score_ptr << endl;
    cout << *(score_ptr + 1) << endl;
    cout << *(score_ptr + 2) << endl;

    cout << "\nArray offset notation --------------------" << endl;
    cout << *score << endl;
    cout << *(score + 1) << endl;
    cout << *(score + 2) << endl;

    cout << endl;
    return 0;
}