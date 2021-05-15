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
    std::string nameAdd("maddison street");
    std::list<std::string> nameStreets={"maddison street","aveneu"};
    auto findStreet=std::find(nameStreets.cbegin(),nameStreets.cend(),nameAdd);
    std::cout<<"Find Maddison street in container \t:[" <<*findStreet<<"]"<<std::endl;
    int ia[]={12,23,34,14,32,42};
    int val=32;
    auto findArr=std::find(std::begin(ia) , std::end(ia),val);
    std::cout<<"Result , find number 32 in array \t:[ "<<*findArr<<"]"<<std::endl;
    


}
