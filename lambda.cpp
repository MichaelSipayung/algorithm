#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
void fcn1();
void fcn2();
void fcn3();

int main(){
    std::cout<<"Capture list \t: lamda passing paramtere by value"<<std::endl;
    fcn1();
    fcn2();
    fcn3();


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
 //   auto wc = std::find_if(words.begin(),words.end(),[=](const std::string &s){return s.size()>=sz;});





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

}

void bigges(std::vector<std::string> &words,std::vector<std::string>::size_type sz,std::ostream &os=std::cout,char c=' '){
    std::for_each(words.begin(),words.end(),[&os,c](const std::string &s){os<<s<<c;});
}

//implicit capture 

void bigges2(std::vector<std::string> &words,std::vector<std::string>::size_type sz,std::ostream &os=std::cout,char c=' '){
    std::for_each(words.begin(),words.end(),[&,c](const std::string &s){os<<s<<c;});
}