#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);
    cout << "The elements of the vector1 are: " << vector1.at(0) << ", " << vector1.at(1) << endl;
    cout << "The size of the vector1 is: " << vector1.size() << endl;
    cout << "===================================" << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    cout << "The elements of the vector2 are: " << vector2.at(0) << ", " << vector2.at(1) << endl;
    cout << "The size of the vector2 is: " << vector2.size() << endl;

    vector<vector<int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    cout << "===================================" << endl;
    cout << "Display the elements in the vector_2d" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;

    vector1.at(0) = 1000;

    cout << "===================================" << endl;
    cout << "Display the elements in the vector_2d" << endl;
    cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    cout << "===================================" << endl;

    cout << "The new vector elements of vector1 are: " << endl;
    cout << vector1.at(0) << " " << vector1.at(1) << endl;

    return 0;
}