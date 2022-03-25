#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string>stooges {"HeeChan", "YeChan", "JiWan"};

    for(auto str:stooges)
    str="the_Q";        //str is a COPY if the each vector element

    for(auto str:stooges)     //no changes
    cout<< str << endl;

    cout << "-------------------------" << endl;
    for(auto &str:stooges)//there is & sign, hence the str is a reference to each vector element
    str = "the_Q";

    for(auto const &str:stooges) //'const' this gives us the protection of making those elements read-only, but it also allows them not to be copied.

    cout << endl;
    return 0;
}