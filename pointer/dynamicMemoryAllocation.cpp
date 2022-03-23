// using new keywork to allocate storage
// using delete to deallocate storage
#include <iostream>
using namespace std;

int main()
{
    // create integer pointer
    // allocating dynamically at runtime from the heap
    //! SYNTAX: pointer_name = new data_type;
    int *int_ptr(nullptr);
    int_ptr = new int;
    cout << int_ptr << endl;
    delete int_ptr; // free up the space we allocated

    // allocate arry of double
    size_t size(0);
    double *temp_ptr(nullptr);
    cout << "How many temps? ";
    cin >> size;
    temp_ptr = new double[size]; // however the size of the data is the temp_ptr will show the first memory address location of the data
    cout << temp_ptr << endl;
    delete[] temp_ptr; // free up the space we allocated
}