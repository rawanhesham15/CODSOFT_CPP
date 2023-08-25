#include <bits/stdc++.h>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;
    cout << "______________Welcome to My Simple Calculator______________" << endl;
    cout << "You can perform many operations here (multiplication, subtraction, addition, division)!" << endl;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "enter the operation you want to perform (+, -, *, /): ";
    cin >> operation;

    if(operation == '+'){
        result = num1 + num2;
    }else if(operation == '-'){
        result = num1 - num2;
    }else if(operation == '/'){
        if(num2 == 0){
            cout << "INVALID DIVISION BY ZERO!";
            return 0;
        }
        result = num1 / num2;
    }else if(operation == '*'){
        result = num1 * num2;
    }else{
        cout << "INVALID OPERATION!";
        return 0;
    }
    cout << num1 << " " << operation << " " << num2 << " = " << result;
}
