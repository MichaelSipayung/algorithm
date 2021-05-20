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
    /*
    std::cout<<"Using stream iterator and algorithm \t: "; 
    std::istream_iterator<int> inF(std::cin) , endF; 
    std::cout<<"Accumulate them \t:[" << std::accumulate(inF,endF,0)<<"]" <<std::endl;
    */ 

    std::vector<int> vec{1,2,3,4,5,6,7,8,9};
    std::cout<<"Using ostream iterator "<<std::endl;
    std::cout<<"ouput \t:[";
    std::ostream_iterator<int> out_iter(std::cout, " ");
    for(auto e :vec){
        *out_iter++=e; 
        //dereference and increment   the iterator tp traverse another element
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Revisited ostream iterator"<<std::endl;
    std::vector<int> testVe{1,2,4,4,1,1,2};
    std::ostream_iterator<int> iter_outr(std::cout," ");
    std::cout<<" Another way to write ,using ostream_iterator\t:[ " ;   
    std::copy(testVe.begin(),testVe.end() , iter_outr);
    std::cout<<"]" <<std::endl;

    std::cout<<"Reverse Iterators  \t:[";
    std::vector<std::string> name{"michael","sipayung"};
    for(auto i = name.crbegin();i!=name.crend();++i){
        std::cout<<*i <<"|";
    }
    std::cout<<"]"<<std::endl;

    std::vector<int> desc{1,2,3,4,5,6,7,8,9};
    std::sort(desc.rbegin(),desc.rend());
    std::cout<<"After sort by descending vector \t:[" ;
    for (auto &i : desc)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Print without coma\t:["  ;
    std::string mic ("michael,sipayung,test");
    auto coma = std::find(mic.begin(),mic.end(),',');
    std::cout<<std::string(mic.begin(),coma) <<"]" << std::endl;
    std::cout<<"using reverse operator  \t:[";
    auto revCom =std::find(mic.rbegin(),mic.rend(),',');
    std::cout<<std::string(mic.rbegin(),revCom)<<"]"<<std::endl;

    std::vector<int> listPeopAge{11,22,31,45,98};
    std::vector<int> listA;
    std::vector<int> donotChange;
   // std::copy(listPeopAge.begin(),listPeopAge.end() , listA.begin());
    std::reverse(listPeopAge.begin(),listPeopAge.end());
    std::cout<<" result after reverse element \t:[";
    for (auto &i : listPeopAge)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::list<int> listBl{1,2,3,21};
    std::list<int> bl(listBl.size());
    std::copy(listBl.begin(),listBl.end(),bl.begin());
    std::cout<<"After copy\t:[";
    for (auto &i : bl)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    std::cout<<"increasing the current value using std::iota \t:[";
    std::iota(bl.begin(),bl.end(),1);
    std::cout<<"Algorithm if version and copy"<<std::endl;
    std::vector<int> originalNum{1,2,3,4,5,6,7};
    std::vector<int> destOri (originalNum.size());
    for (auto &i : originalNum)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    std::remove_if(originalNum.begin(),originalNum.end(),[](int i) {return i%2;});
    std::cout<<"Apply if version , must include predicate\t:[";

    for (auto &i : originalNum)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Apply if and copy respectively version , must include destination and predicate\t:[";
    std::remove_copy_if(originalNum.begin(),originalNum.end(),std::back_inserter(destOri),[](int i) {return i%2;});
    for (auto &i : destOri)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Container Specific list \t:[";

    std::cout<<"merge a list "<<std::endl;
    std::list<int> numOn {1,2,3,4,5,6};
    std::list<int> numTwo {1,3,4,7,8,9,11};
    numTwo.merge(numOn);

    std::cout<<"After merge a lis t\t:[";
    for (auto &i : numTwo)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    


}