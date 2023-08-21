#include <iostream>
using namespace std;
int main(){
    int contador;
    cout << "Digite um valor para contagem : \n";
    cin >> contador;
    do {
        cout << contador << " - ";
        contador++;
    } while (contador<=100);
    cout <<"\n\n ***Fim da contagem!*** \n\n";
    return 0;
}