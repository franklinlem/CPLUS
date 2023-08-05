#include <iostream>
using namespace std;
int main(){
    int num1;
    int num2;
    cout << "Digite um numero " << endl;
    cin >> num1;
    cout << "Digite um numero " << endl;
    cin >> num2;
    if (num1 == num2)
    cout << num1 << "==" << num2 << endl;
    if (num1 != num2)
    cout << num1 << "!=" << num2 << endl;
    if (num1 >= num2)
    cout << num1 << ">=" << num2 << endl;
    if (num1 <= num2)
    cout << num1 << "<=" << num2 << endl;
    return 0;
}