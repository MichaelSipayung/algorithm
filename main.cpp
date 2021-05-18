#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
#include <iterator>
void Elimdups(std::vector<std::string> &words);
void Elimdups(std::vector<int> &words);
void Elimdups(std::vector<double> &words);
bool isShorter(const std::string &s1,const std::string &s2);
struct Sum{
    int sum{0};
    void operator ()(int n){sum+=n;}
};
void bigges(std::vector<std::string> &words,std::vector<std::string>::size_type sz);

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

    std::cout<<"Sort Algorithm"<<std::endl;
    std::cout<<"test std::unique"<<std::endl;
    std::vector<int> nameUni={1,2,3,41,1,2};
    std::sort(nameUni.begin(),nameUni.end());

    std::cout<<"Resul before call std::unique\t:[";
    for (auto &i : nameUni)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    auto uni=std::unique(nameUni.begin(),nameUni.end()); //point to unique element 

    std::cout<<"Resul after call std::unique\t:[";
    for (auto &i : nameUni)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    nameUni.erase(uni,nameUni.end());
    std::cout<<"After Erase element \t:[";
    for (auto &i : nameUni)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"call unique element"<<std::endl;
    std::vector<std::string> callUniq ={"i","stand","in","his","amazing","grace","i","stand"};
    std::cout<<"before call unique function , value \t:[";
    for (auto &i : callUniq)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    
    Elimdups(callUniq);
    std::cout<<"After call unique function \t:[";
    for (auto &i : callUniq)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Overloaded for list"<<std::endl;
    std::vector<int> loadData={1,2,33,1,2,1,23,1,1};
    std::cout<<"before call unique function , value \t:[";
    for (auto &i : loadData)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    
    Elimdups(loadData);
    std::cout<<"After call unique function \t:[";
    for (auto &i : loadData)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Custumizing algorithm "<<std::endl;
    std::vector<std::string> orThat={"fox","jumps","over","quick","red","slow","the","turtle","Over"};
    std::cout<<"Original Vector \t:[";
    for (auto &i : orThat)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    
    std::cout<<"After Custom Short\t:[";
    std::sort(orThat.begin(), orThat.end() , isShorter);// see the short word, compare each word 
    for (auto &i : orThat)
    {
        std::cout<<i<<"|";
    }
    
    std::cout<<"]"<<std::endl;
    std::vector<std::string> orThatV={"fox","jumps","over","quick","red","slow","the","turtle","Over"};
    
    std::cout<<"Call stable order, then what happen\t:[";
    Elimdups(orThatV);
    std::stable_sort(orThatV.begin(),orThatV.end(),isShorter);
    for (auto &i : orThatV)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    
    std::cout<<"Lambada Function \t:[";
    auto f = [] (int &a,int &b){
        auto temp=a;
        a=b;
        b=temp;
    };
    auto a=12,b=13;
    f(a,b);
    std::cout<<"Nilai a\t:"<<a<<"\nNilai b\t:"<<b<<std::endl;
    std::cout<<"Change is ordinary shorter function to lambada function\t: "<<std::endl;
    std::string aLam="michael";
    std::string bLam="Sipayung";
    auto testLamShort=[](const std::string &a,const std::string &b){
        return a.size()<b.size();
    };
    std::cout<<testLamShort(aLam,bLam)<<std::endl;
    std::vector<std::string> dataTest={"fox","jumps","over","quick","red","slow","the","turtle","over"};
    /*std::sort(dataTest.begin(),dataTest.end(),isShorter);
    std::cout<<"After sort , and implement predicate]\t:[";
    for (auto &i : dataTest)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    */
    Elimdups(dataTest);

    std::cout<<"before calling stable sort\t:[";
    for (auto &i : dataTest)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    
    std::cout<<"Test stable sort \t:[";

    std::stable_sort(dataTest.begin(),dataTest.end(),isShorter);
    for (const auto &i : dataTest)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Lambada Function\t:[";
    auto flam=[]{return 42;};
    std::cout<<flam()<<"]"<<std::endl;
    
    std::vector<std::string> applyLam={"fox","jumps","over","quick","red","slow","the","turtle","over"};
    std::stable_sort(applyLam.begin(),applyLam.end(),[](const std::string &a,const std::string &b ){return a.size()<b.size(); });
    std::cout<<"Show data after call predicates\t:[";
    for (auto &i : applyLam)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::cout<<"Using for each "<<std::endl;
    std::vector<int> nums{3,4,2,8,15,267};
    auto print=[] (const int &n){std::cout<<" "<<n;};
    std::cout<<"Before \t:[";
    std::for_each(nums.cbegin(),nums.cend(),print);
    std::cout<<"]"<<std::endl;
    std::cout<<"Sum them \t:[";
    auto cSum =std::accumulate(nums.cbegin(),nums.cend(),0);
    std::cout<<cSum<<"]"<<std::endl;   
    std::for_each(nums.begin(),nums.end(),[](int &n){n++;});
    Sum s= std::for_each(nums.begin(), nums.end(),Sum());
    std::cout<<"After \t:[";
    std::for_each(nums.cbegin(),nums.cend(),print);
    std::cout<<"]"<<std::endl;
    std::cout<<"And their sum \t: [";
    std::cout<<s.sum <<"]"<<std::endl;
    
    

    //auto testLamdaEx =[sz](int a,int b){return a  <sz;};
    
}
void Elimdups(std::vector<std::string> &words){
    std::sort(words.begin(),words.end());
    auto  end_unique = std::unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}
void Elimdups(std::vector<int> &words){
    std::sort(words.begin(),words.end());
    auto  end_unique = std::unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}

void Elimdups(std::vector<double> &words){
    std::sort(words.begin(),words.end());
    auto  end_unique = std::unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}
bool isShorter(const std::string &s1,const std::string &s2){
    return s1.size() <s2.size();
}

void bigges(std::vector<std::string> &words,std::vector<std::string>::size_type sz){
    Elimdups(words);
    std::stable_sort(words.begin(),words.end(),isShorter);

}

// void biggies(std::vector<std::string> &words,std::vector<std::string>::size_type sz)
// {
//  Elimdups(words); // put words in alphabetical order and removeduplicates
//  // sort words by size, but maintain alphabetical order for words of the same size
//  stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size();});
//  // get an iterator to the first element whose size() is >= sz
//  auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
//  // compute the number of elements with size >= sz
//  auto count = words.end() - wc; cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
//  // print words of the given size or longer, each one followed by a space
//  for_each(wc, words.end(), [](const string &s){cout << s << " ";}); cout << endl;
// }