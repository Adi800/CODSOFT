#include<iostream>

using namespace std;


float Calc(float a, float b,char ch){
    float ans;
    switch (ch)
    {
    case '+':
        ans=a+b;
        break;
    case '-':
        ans=a-b;
        break;
    case '*':
        ans=a*b;
        break;
    case '/':
        ans=a/b;
        break;
    default:
        cout<<"Oops! TRy again"<<endl;
        break;
    }
    return ans;
}
int main(){
    char ch;
    float a,b; //declaration of variable
    // num = randm();//calls the fuction and stores the return value
    cout<<"Welcome to CalC."<<endl;
    while(1){
    cout<<"Input two numbers for arithmetic ops."<<endl;
    cin>>a>>b;//stores user input
    cout<<"what operation to perform? Enter the symbol (i.e. +,-,*,/)"<<endl;
    cin>>ch;
    float ans=Calc(a,b,ch);
    cout<<"Your answer is "<<ans<<endl; //cals the function
    }
    return 0;
}