#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <numeric>

int main(){
    std::cout<<"Additional iterator " <<std::endl;
    std::list<int> nameLis{1,2,3,4};
    std::list<int> list1,list2;
    std::copy(nameLis.begin(),nameLis.end(),std::front_inserter(list1));// list1 contain 4,3,2,1
    std::cout<<"Copy value , and apply front inserter \t:[";
    for (auto &i : list1)
    {
        std::cout<<i<<"|";
    }
    std::cout<<std::endl;

    std::cout<<"Iterator inserter \t:[";
    std::copy(nameLis.begin() , nameLis.end(), std::inserter(list2,list2.begin()));
    for (auto &i : list2)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]" <<std::endl;

    
    std::cout<<"Test back inserter\t:[";
    std::vector<int> smallNum{13,12,4,132};
    std::vector<int> small ;
    std::copy(smallNum.begin() , smallNum.end() , std::back_inserter(small));
    for (auto &i : small)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]" <<std::endl;

    std::cout<<"iterator stream" <<std::endl;
    std::ifstream in("michael.txt");
    std::istream_iterator<std::string> str_it(in); //istream iterator for traversing element 
    auto x=0;
    std::cout<<"read from input stream\t:[";
    while (x<8)
    {
        std::cout<<*str_it <<" | ";
        ++str_it;
        x++;
    }
    std::cout<<"]" <<std::endl;   
    in.close();      
/*
    std::cout<<"Implementing an iterator";
    std::istream_iterator<int> in_iter(std::cin) , eof; // the prsent of eof iterator is to tell end of file reading
    std::vector<int> vec(in_iter , eof);
    std::cout<<"Resul isstream_iterator \t:[" ;
    for (auto &i : vec)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]" <<std::endl;
*/
    std::cout<<"Using stream iterator and algorithm \t: "; 
    std::istream_iterator<int> inF(std::cin) , endF; 
    std::cout<<"Accumulate them \t:[" << std::accumulate(inF,endF,0)<<"]" <<std::endl;
    



}