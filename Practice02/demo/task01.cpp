
#include<iostream>
using namespace std;
int main(){
int *p,var=101;
//Assigment
 p=&var;
 cout<<"Address of var: "<<&var<<endl;
 cout<<"Address of var: "<<p<<endl;
 cout<<"Address of p: "<<&p<<endl;
 cout<<"Address of var: "<<*p<<endl;
 return 0;
}
