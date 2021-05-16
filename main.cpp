#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
#include <iterator>

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
    
    std::cout<<"Count object in vector "<<std::endl;
    std::vector<int> listNum={1,2,4,5,6,7,1,2,1,1};
    auto countOne= std::count(listNum.begin(),listNum.end(),1);
    std::cout<<"Show vector\t:[";
    for (auto &i : listNum)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    std::cout<<"Count how much one \t:"<<countOne<<std::endl;

    std::string birt("december");
    auto findStr=std::count(birt.begin(),birt.end(),'e');
    std::cout<<"Show Birt\t:[";
    for (auto &i : birt)
    {
        std::cout<<i<<"|";        
    }
    std::cout<<"]"<<std::endl;
    std::cout<<"HOw much character e appear \t:["<<findStr<<"]"<<std::endl;

    std::vector<int>  testSum={1,2,3,4,5,6,7,8,9};
    auto sum=std::accumulate(testSum.cbegin(),testSum.cend(),0);
    std::cout<<"Show number to sum\t:[";
    for (auto &i : testSum)
    {
        std::cout<<i<<"|";
    }
    
    std::cout<<"]"<<std::endl;
    std::cout<<"And their sum \t:"  <<sum<<std::endl;

    std::string accu = {'a','c','s','a'};
    auto acuStr=std::accumulate(accu.cbegin(),accu.cend(),std::string(""));
    std::cout<<"accumulate the all container\t:[";
    std::cout<<acuStr<<"]"<<std::endl;

    std::cout<<"Algorithm that compare element \t:[equal()]"<<std::endl;
    std::vector<std::string> strFir  ={"michael","jack","daniel"};
    std::vector<std::string> strSec  ={"michael","jack","daniel"};
    auto equalTest= std::equal(strFir.cbegin(),strFir.cend(),strSec.cbegin());
    std::cout<<"test equal \t:["<<equalTest<<"]"<<std::endl;

    std::vector<int> oriVec={1,2,3,4,5,6};
    std::cout<<"Before fill the number \t:[";
    for (auto &i : oriVec)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    
    std::fill(oriVec.begin(),oriVec.begin()+3,12);
    
    std::cout<<"After fill the number \t:[";
    for (auto &i : oriVec)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Fill_n()"<<std::endl;
    std::fill_n(oriVec.begin(),oriVec.size(),78); //fill all element with number :  78
    std::cout<<"After fill with n value \t:[";
    for (auto &i : oriVec)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Back inserter , assign a value to container  "<<std::endl;
    std::vector<int> back_inser;
    auto it=std::back_inserter(back_inser);
    *it=90;
    //similiar to push_back == back_inserter
    std::cout<<"After call back inserter \t:  [";
    for (auto &i : back_inser)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    for(auto i=1;i<10;++i){
        *it=(i+2);
        ++it;
    }
    std::cout<<"Then Call again \t: [";
    for (auto &i : back_inser)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    
    std::cout<<"Noted , back inserter have a purpose to make an iterator, in special case it's work well in algorithm"<<std::endl;
    std::vector<int> emptyVe;
    std::cout<<"Before call back inserter and fill_n .. size \t:["<<emptyVe.size()<<"]"<<std::endl;
    std::fill_n(std::back_inserter(emptyVe) , 10, 0);
    std::cout<<"After call back inserter and fill_n .. size \t:["<<emptyVe.size()<<"]"<<std::endl;
    
    std::cout<<"Copy Algorithm "<<std::endl;
    std::cout<<"Copy built-in array "<<std::endl;
    int aCop[]={1,2,3,4,5,6,7,8,9};
    int destCop[sizeof(aCop)/sizeof(*aCop)]; //int a[9] refers to this size
    std::copy(std::begin(aCop) , std::end(aCop), destCop);
    std::cout<<"After copt , destination hold \t: [";
    for(auto i=std::begin(destCop) ; i<=std::end(destCop);++i){
        std::cout<<*i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"std::replace"<<std::endl;
    std::list<int> listAgeP={1,2,3,42,1,1,2,3};
    std::cout<<"before replace value \t:[";
    for (auto &i : listAgeP)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"After replace\t:[";
    std::replace(listAgeP.begin(),listAgeP.end(),1,42); //replace instance 1 to 42

    for (auto &i : listAgeP)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Replace copy"<<std::endl;
    std::list<int> replaceCopy;
    std::replace_copy(listAgeP.begin() , listAgeP.end(),std::back_inserter(replaceCopy),42,100);
    std::cout<<"After call replace copy \t:[";
    for (auto &i : replaceCopy)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;


    


}
