#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main(int, char**) {
    std::cout << "Hello, algorithm library !\n";
    std::vector<int> num={1,2,3,5,43,4,5,6};
    auto number=4;
    auto findNum= std::find(num.cbegin(),num.cend(),number); //find function insert algorithm header
    std::cout<<"test find number 4 in vector \t: [" << *findNum<<std::endl;
    std::cout<<"Find in list "<<std::endl;
    std::list<int> listAge={11,22,34,12,54};
    auto findAge= std::find(listAge.cbegin(), listAge.cend(),22);
    std::cout<<"Find number 22 \t: [" <<*findAge <<"]"<<std::endl;
    


}
