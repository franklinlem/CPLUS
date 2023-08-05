#include <iostream>
using namespace std;
int main(){
    int num1;
    int num2;
    cout << "Digite um numero: ";
    cin >> num1;
    cout << "Digite um numero: ";
    cin >> num2;

    int sum = num1 + num2;
    int sub = num1 - num2;
    int mult = num1 * num2;
    int divint = num1 / num2;
    float divreal = (float)num1 / (float)num2;
    int res = num1 % num2;

    cout << "A soma e " << sum << endl;
    cout << "A diferenca e " << sub << endl;
    cout << "O produto e " << mult << endl;
    cout << "A divisao inteira  " << divint << endl;
    cout << "A divisao real e " << divreal << endl;
    cout << "O resto da divisao e " << res << endl;

    return 0;
}