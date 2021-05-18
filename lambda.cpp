#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <functional> //library bind function 
#include <fstream>
using std::placeholders::_1;
using std::placeholders::_2;

void fcn1();
void fcn2();
void fcn3();
void mutLamda();
void mutLamda2();
void transformData(std::vector<int> &trans);
void transformData2(std::vector<int> &trans);
void transformData3(std::vector<int> &trans);
bool checkSize(const std::string &s,std::string::size_type sz);
bool isShorter(const std::string &a, const std::string &b);
std::ostream &print(std::ostream &os,const std::string &s,char c);

int main(){
    std::cout<<"Capture list \t: lamda passing paramtere by value"<<std::endl;
    fcn1();
    fcn2();
    fcn3();
    mutLamda2();
    std::vector<int> data ={1,2,3,-1,-1,-31,-98,-87};
    transformData(data);
    std::vector<int> data2 ={1,2,3,-1,-1,-31,-98,-87};
    transformData2(data2);
    std::cout<<"Using trailing return"<<std::endl;
    std::vector<int> data3 ={1,2,3,-1,-1,-31,-98,-87};
    transformData3(data3);
    auto check6= std::bind(checkSize, _1,6);
    std::cout<<"using bind function "<<std::endl;
    std::string s ="hello";
    std::string::size_type sz;
    std::vector<std::string> words ={"mik", " tets"};
    bool b1=check6(s);
    std::cout<<"Size \t:[" << s.size() <<" ] item" <<std::endl;
    std::cout<<"Compare them \t: is string less than 6 " <<std::endl;
    std::cout<<"Check size , mix using callable object \t:[" <<b1<<"]" <<std::endl;
    auto wcTest = std::find_if(words.begin() ,  words.end(),std::bind(checkSize,_1,sz));
    std::cout<<"using to bind to reorder parameters " <<std::endl;
    std::vector<std::string> beforeSort ={"michael" ,"sipayung" ,"test","quick" ,"jump" ,"dum" ,"dash"};
    std::cout<<"Before sort \t:[";
    for (auto &i : beforeSort)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"  <<std::endl;
    std::cout<<"Sort ,  introduce bind argument " <<std::endl;
    std::sort(beforeSort.begin(),beforeSort.end(),std::bind(isShorter,_2,_1)); /// swap argument and it will reorder value 
    //std::sort(beforeSort.begin(),beforeSort.end(),std::bind(isShorter,_2,_1)); /// swap argument and it will reorder value 
    std::cout<<"After calling sort and  bind arguments \t:[";
    for (auto &i : beforeSort)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]" <<std::endl;
    std::vector<std::string> testWords1={"michael" ,"sipayung","name" ,"placeholder" ,"pass"};
    std::filebuf buf; // filebuf -> defined in fstream header 

    buf.open("test.txt" ,std::ios::app);
    std::ostream os(&buf);
    std::for_each(testWords1.begin(),testWords1.end(),std::bind(print,std::ref(os) ,  _1,'\n')); //print to output stream 
    buf.close();
    //noted std::ostream defined in header iostream 

}
void fcn1(){ //passing by reference
    size_t v1=42;
    auto f= [v1]{return v1;};
    v1=0;
    auto j = f(); //j store 42
    std::cout<<"passing by value \t:[ "<<j<<" ]"<<std::endl;
}
void fcn2(){
    size_t a=12;
    size_t &v1=a;
    a=012;
    auto f = [v1]{return v1;};
    auto j = f();
    std::cout<<"passing by reference \t:[ "<<j<<" ]"<<std::endl;
    std::vector<int>words ={1,23,1,12};
    std::string::size_type sz;

}
//test capture by reference 
void fcn3(){
    size_t v1=42;
    auto f2= [&v1]{return v1;};
    v1=0;
    auto j = f2();
    std::cout<<"Test capture by reference\t:["<<j<<" ]"<<std::endl;
    std::cout<<"implicit capture ";
    auto fx= [=] (const std::string &a) {return a;};
    std::string x="13";
    std::cout<<"implicit capture \t:["<<fx("213")<<"]"<<std::endl;
    std::cout<<" by default value in capture variable can't change , except we using mutable key "<<std::endl ;



}

void bigges(std::vector<std::string> &words,std::vector<std::string>::size_type sz,std::ostream &os=std::cout,char c=' '){
    std::for_each(words.begin(),words.end(),[&os,c](const std::string &s){os<<s<<c;});
}

//implicit capture 

void bigges2(std::vector<std::string> &words,std::vector<std::string>::size_type sz,std::ostream &os=std::cout,char c=' '){
    std::for_each(words.begin(),words.end(),[&,c](const std::string &s){os<<s<<c;});
}

void mutLamda(){
    size_t  v1=42;
    auto f =[v1] () mutable{return ++v1;}; 
    std::cout<<"original value \t:[" <<v1 <<" after change : "<< f()<<"]"<<std::endl;
}

void mutLamda2(){
    size_t  v1=42;
    auto f =[&v1] () mutable{return ++v1;}; 
    std::cout<<"original value \t:[" <<v1 <<" after change : "<< f()<<"]"<<std::endl;
    v1=78;
    std::cout<<"2.original value \t:[" <<v1 <<" after change : "<< f()<<"]"<<std::endl;

}
void transformData(std::vector<int> &trans){
    std::cout<<"Original value \t:[";
    for (auto &i : trans)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    std::transform(trans.begin(),trans.end(),trans.begin(),[](int i ){return  i<0? -i:i;});
    std::cout<<"After transform \t:[";
    for (auto &i : trans)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    

}
//transform algorithm using lamda and built in function
void transformData2(std::vector<int> &trans){
    std::cout<<"Original value \t:[";
    for (auto &i : trans)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;

    std::transform(trans.begin(),trans.end(),trans.begin(),[](int i ){return  abs(i);});

    std::cout<<"After transform \t:[";
    for (auto &i : trans)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;


}
void transformData3(std::vector<int> &trans){
    std::cout<<"Original value \t:[";
    for (auto &i : trans)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
    std::transform(trans.begin(),trans.end(),trans.begin(),[](int i )->int{if(i<0) return   -i;else return i;}); //using trailing return to make it return value
    std::cout<<"After transform \t:[";
    for (auto &i : trans)
    {
        std::cout<<i<<"|";
    }
    std::cout<<"]"<<std::endl;
}


bool checkSize(const std::string &s,std::string::size_type sz){
    return s.size()>=sz;
}

bool isShorter(const std::string &a, const std::string &b){
    return a.size()>b.size();
}


std::ostream &print(std::ostream &os,const std::string &s,char c){
    return os<<s<<c;
}
