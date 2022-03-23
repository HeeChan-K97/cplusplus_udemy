// Dereferencing a Pointer = access the data we are pointing to.
//  If 'score_ptr' is a pointer and has a valid address
// Then they can access the data at the address contained in the 'score_ptr'
// using the dereferencing operator (*).

//! EXAMPLE:
/* int socre {100};  initialize the score as 100
   int *score_ptr {&score};  initializing a score pointer, a pointer to a integer and initialize to the address of score.
                             score pointer가 포인팅하는 것은 즉, score의 주소와도 같다는 의미
*/
#include <iostream>
#include <vector>

int main()
{
    double high_temp{100.7};
    double low_temp{37.4};
    double *temp_ptr{&high_temp};

    std::cout << *temp_ptr << std::endl;

    temp_ptr = &low_temp; // DEREFERENCING

    std::cout << *temp_ptr << std::endl;
    std::cout << "------------------------------" << std::endl;

    // example with string
    std::string name{"Frank"};
    std::string *string_ptr{&name}; // pointing to the address of the name
    std::cout << *string_ptr << std::endl;

    name = "HeeChan"; // string pointer is still pointing the address of the name variable and the value of the name has been changed to "HeeChan"

    std::cout << *string_ptr << std::endl; // dereferencing the pointer = 포인터를 불러서 그 안에 있는 값을 출력한다
    std::cout << "------------------------------" << std::endl;

    std::vector<std::string> stooges{"Larry", "Moe", "HeeChan"};
    std::vector<std::string> *vector_ptr{nullptr};

    vector_ptr = &stooges;

    std::cout << "First stooge: " << (*vector_ptr).at(0) << std::endl; // goto vector_ptr and dereference it which give the vector that I am pointing to. same as stooge.at(0);

    std::cout << "Stooges: ";
    for (auto stooge : *vector_ptr) // range based for loop, every stooges that vector_ptr is pointing to, print it out
        std::cout << stooge << " ";
    std::cout << std::endl;

    // std::cout << std::endl;
    return 0;
}