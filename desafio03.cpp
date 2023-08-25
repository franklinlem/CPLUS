#include <iostream>
using namespace std;
int fat(int x){
    int fatorial;
    for (int i=1; i<=x; i++){
        fatorial*=1;
    }
    return fatorial;
}
int main(){
    int n;
    while (true){
    cout << "Informa um  numero inteiro positivo: \n";
    cin >> n;
    if (n < 0){
        cout << "Numero informado invalido! Digite novamente!\n";
    } else {
        break;
    }
    }
    int valorfat = fat(n);
    cout << "O fatorial de " << n << " e: " << valorfat << endl;
    return 0;
}