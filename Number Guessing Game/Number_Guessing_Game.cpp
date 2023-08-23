#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    int num, guess;
    num = 1 + rand() % 100;

    cout << "_________Welcome to Number Guessing Game_________" << endl;
    cout << "The Number is Between 1 and 100, Try to Guess it...." << endl;

    do{
        cout << "Guess the number: ";
        cin >> guess;
        if(guess == num){
            cout << "Congratulations!! You Guessed the number successfully, the number is " << num << endl;
        }else if(guess >= num - 5 && guess <= num + 5){
            cout << "You are so so near from guessing the number!" << endl;
        }else if(guess >= num - 10 && guess <= num + 10){
            cout << "You are near from guessing the number!" << endl;
        }else{
            cout << "You are far from guessing the number!" << endl;
        }
    } while (guess != num);
}