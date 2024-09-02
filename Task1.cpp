#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

double randm(){
    double num;
    srand(time(0));
    num = rand() % 101; //generates a random number from 1 to 100
    return num;
}
int main(){
    double numi,num; //declaration of variable
    num = randm();//calls the fuction and stores the return value
    cout<<"Welcome to guess-masters."<<endl;
    cout<<"Guess *THE* number between 1 to 100 !"<<endl;
    while(1){
    cout<<"Don't like playing ? Just type 101"<<endl;
    cin>>numi;//stores user guessed number
        if(numi==101){
            cout<<"Until we meet next time, Goodbye Friend!";
            break;
        }
        else if (numi == num)
        {
            cout<<"Yay! You guessed right number "<<endl;
            break;
        }else if (numi>num)
        {
            cout<<"Oops! Try again lower than that"<<endl;
        }
        else
        {
            cout<<"Oops! Try again higher than that"<<endl;
        }
    }
    return 0;
}