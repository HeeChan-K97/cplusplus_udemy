#include <iostream>
#include <vector>
using namespace std;

Arrays

1. Declaring,

    Element_type array_name [constant num of elements];

//cases where the arrays are not initialised
    eg) int test_scores[5]; //five integers
        int high_score_per_level[10]; //ten integers

//declares an array named high temperatures of 365 doubles
//since the array is declared in const the user knows its values
        const int days_in_year{365};
        double hi_temperatures[days_in_year];

        //initialized syntax
        int test_scores[5] {100, 95, 99, 53, 66};
        
        const int days_in_year{365};
        double hi_temperatures[days_in_year] {5}; //initialise all to zero

2. Accessing array elements

    array_name [element_index]
    eg) test_scores [1]
    eg02) int test_scores[5] {100, 95, 99, 53, 66};
          std::cout << "First element is: "<<test_scores[0]<<std::endl;
          std::cout << "Second element is: "<<test_scores[1]<<std::endl;

    //Getting values from user, syntax
    std::cin >> test_scores[0];
    std::cin >> test_scores[1];
    std::cin >> test_scores[2];
    std::cin >> test_scores[3];
    std::cin >> test_scores[4];
    //changing the array element
    test_scores[0] = 90;//putting the integer 90 to the first element of the array 'test_scores'

    eg03)만약 배열을 그냥 선언하게 되면 junk 메모리들로 가득하지만 대괄호를 마지막에 붙여주면 모든 원소들이 0으로 초기화되어서 나타난다.
        int test_scores[5]; //junk memories
        int test_scores[5] {}; //initialize all elements to zero

    eg04) the name of the array is the memory location of the array, the location of the fisrt element in the array

    std::cout << "The name of the array is: " << test_scores << std::endl;

3. Decalring multi dimensional arrays

        eg) int movie_rating [row][column];

4. Vectors, dynamic array
vectors can grow and shrink in size.
vector type is the part of the standard library;

    eg);
        vector<char> vowels;
        vector<int> test_scores;

        vector<char> vowels (5);//constructor initialization syntax which provides information inside parentheses
        vector<int> test_scores (10);//declaring a vector named test scores of 10 integers
        //the element auto initialize to zero
    eg02); 
          vector<char> vowels {'a', 'e', 'i', 'o', 'u'};
          vector<int> test_scores {100, 90, 80, 70, 60};
          vector<double>high_temperature (365, 80,0);
          vector<double>high_temperature (5); //5 element of vector high_temp initialized to zeros, like 0 0 0 0 0
          //뒤에 소괄호가 들어가면 첫번째 숫자는 벡터의 크기를 나타내고 두번째는 초기화할 값을 나타낸다.
          //즉, 365개의 double들을 80.0으로 모두 초기화 하는것

5. Accessing vector elements

    Same as accessing array syntax
    eg)    std::cout << "First element is: "<<test_scores[0]<<std::endl;

    eg) Vector syntax;

        vector<int> test_scores {100, 95, 99, 53, 66};
          std::cout << "First element is: "<<test_scores.at(0)<<std::endl;
          std::cout << "Second element is: "<<test_scores.at(1)<<std::endl;

* 벡터는 그 사이즈를 자유자재로 늘릴수 있는데 그 특성을 활용할 수 있는 함수중 하나가
  push_back이라는 함수이다.

  syntax)
        vector_name.push_back(element);

    vector size) vector_name.size() //shows how many elements are in the vector

    Changing the elements of the vector in vector syntax way

        std::cin >> test_scores.at(0);
        std::cin >> test_scores.at(1);
        std::cin >> test_scores.at(2);
        std::cin >> test_scores.at(3);
        std::cin >> test_scores.at(4);

6. Enter a test scores to add to the vector

    eg)
        int score_to_add {0};//reading an integer from the keyboard
        std::cin >> score_to_add;//putting the value into score_to_add
    
        test_scores.push_back(score_to_add);
        //telling test_scores to push that integer(scores_to_add) at the back of the vector
        즉, score_to_add라는 변수가 가지고 있는 정수를 test_scores라는 벡터의 원소들중 맨뒤로 push_back을 사용해서 넣는 작업.
        여기서 벡터의 크기가 늘어나야 한다면 컴퓨터가 알아서 크기를 늘려준다.

7. std::out of range

    벡터의 원소 선택 문장인,
    vector.at(0); 를 사용하여 정해진 크기의 벡터를 넘는 n번째 원소를 원하는 문장이 있을 때 나타나는 오류페이지이다.

8. Examples of 2D vectors

syntax and its example)
        vector<vector<int>> movie_ratings
        {
            {1,2,3,4},
            {1,2,4,4},
            {5,3,2,5}
        };

        std::cout<<"\nArray Syntax version:"<<std::endl;
        std::cout<<movie_ratings[0][0]<<std::endl;//row # 1
        std::cout<<movie_ratings[0][1]<<std::endl;//row # 1
        std::cout<<movie_ratings[0][2]<<std::endl;//row # 1
        std::cout<<movie_ratings[0][3]<<std::endl;//row # 1

        std::cout<<"\nVector Syntax version:"<<std::endl;
        std::cout<<movie_ratings.at(0).at(0)<<std::endl;//row # 1
        std::cout<<movie_ratings.at(0).at(1)<<std::endl;//row # 1
        std::cout<<movie_ratings.at(0).at(2)<<std::endl;//row # 1
        std::cout<<movie_ratings.at(0).at(3)<<std::endl;//row # 1
        
        std::cout<<std::endl;


===================STL Based syntax========================
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cout << "Vector from initializer list: " << endl;
    vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    cout << "size: " << vi1.size() << endl;
    cout << "front: " << vi1.front() << endl;
    cout << "back: " << vi1.back() << endl;
    
    // iterator
    cout << endl << "Iterator:" << endl;
    vector<int>::iterator itbegin = vi1.begin();
    //auto itbegin = vi1.begin();
    vector<int>::iterator itend = vi1.end();
    //auto itend = vi1.end();
    for (auto it = itbegin; it < itend; ++it) {
        cout << *it << ' ';
    }
    cout << endl;
    
    cout << endl << "Index:" << endl;
    cout << "element at 5: " << vi1[5] << endl;//indexing the vector
    cout << "element at 5: " << vi1.at(5) << endl;//using at function
    
    //range based for loop
    cout << endl << "Range-based for loop:" << endl;
    for (int & i : vi1) {
        cout << i << ' ';
    }
    cout << endl;
    
    cout << endl << "Insert 42 at begin + 5: " << endl;
    vi1.insert(vi1.begin() + 5, 42);//5번째 원소에 42 집어넣기
    cout << "size: " << vi1.size() << endl;
    cout << "vi1[5]: " << vi1[5] << endl;
    
    cout << "Erase at begin + 5: " << endl;
    vi1.erase(vi1.begin() + 5);
    cout << "size: " << vi1.size() << endl;
    cout << "vi1[5]: " << vi1[5] << endl;
    
    cout << "push_back 47: " << endl;
    vi1.push_back(47);
    cout << "size: " << vi1.size() << endl;
    cout << "vi1.back() " << vi1.back() << endl;
    
    cout << "Range-based for loop: " << endl;
    for(int & v : vi1) {
        cout << v << ' ';
    }
    cout << endl << endl;
    
    // from C-array
    const static size_t size = 10;
    int ia[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << endl << "Vector from C-array: " << endl;
    vector<int> vi2(ia, ia + size);
    for( int & i : vi2 ) {
        cout << i << ' ';
    }
    cout << endl << endl;
    
    // vector of strings
    cout << "Vector of strings:" << endl;
    vector<string> vs = { "one", "two", "three", "four", "five" };
    for(string & v : vs) {
        cout << v << endl;
    }
    
    return 0;
}

출력값: 

Vector from initializer list: 
size: 10
front: 1
back: 10

Iterator:
1 2 3 4 5 6 7 8 9 10 

Index:
element at 5: 6
element at 5: 6

Range-based for loop:
1 2 3 4 5 6 7 8 9 10 

Insert 42 at begin + 5: 
size: 11
vi1[5]: 42
Erase at begin + 5: 
size: 10
vi1[5]: 6
push_back 47: 
size: 11
vi1.back() 47
Range-based for loop: 
1 2 3 4 5 6 7 8 9 10 47 


Vector from C-array: 
1 2 3 4 5 6 7 8 9 10 

Vector of strings:
one
two
three
four
five

===========================================iostream-formatting====================================================


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    // cout and cin to get a string
    string istr;
    cout << "Prompt: ";
    cin >> istr;    // one word at a time
    cout << "Input: " << istr << endl;
    
    // integer formatting
    cout << "Integer formatting:" << endl;
    int i1 = 42;
    int i2 = 127;
    int i3 = 5555;
    cout << "default: " << i1 << ' ' << i2 << ' ' << i3 << endl;
    cout << "hex: " << hex << i1 << ' ' << i2 << ' ' << i3 << endl;
    cout << "hex with showbase: " << showbase << hex << i1 << ' ' << i2 << ' ' << i3 << endl;
    cout << "octal with showbase: " << oct << i1 << ' ' << i2 << ' ' << i3 << endl;
    cout << "default: " << noshowbase << dec << i1 << ' ' << i2 << ' ' << i3 << endl;
    
    // floating point formatting options
    cout << endl << "Floating point formatting:" << endl;
    double d1, d2, d3;
    d1 = 3.1415926534;
    d2 = 1234.5;
    d3 = 4.2e-10;
    cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    cout << "fixed: " << fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    cout << "scientific: " << scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    cout << "fixed (3): " << setprecision(3) << fixed << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    cout << "scientific (7): " << setprecision(7) << scientific << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    cout.unsetf(ios_base::floatfield);
    cout << "default: " << d1 << ' ' << d2 << ' ' << d3 << ' ' << endl;
    
    // string formatting options
    cout << endl << "String formatting:" << endl;
    string s1 = "This is a string.";
    string s2 = "This is a much longer string.";
    string s3 = "Today's news: Big Light in Sky Slated to Appear in East";
    
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    
    cout << setw(64) << right << s1 << endl;
    cout << setw(64) << right << s2 << endl;
    cout << setw(64) << right << s3 << endl;
    
    cout << setfill('-') << setw(64) << right << s1 << endl;
    cout << setfill(' ') << setw(64) << right << s1 << endl;
    cout << left << s1 << endl;
    
    return 0;
}