#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Digite um numero positivo: ";
    cin >> n;
    int soma=0;
    int cont=1;
    while (cont<=n){
        soma+=cont;
        cont++;
    }
    cout << "A soma dos numero de 0 ate " << n << " e " << soma << endl;
    for (int j=1; j<=n; j++){
        soma+=j;
        cout << "A soma e " << soma << endl;
    }
    return 0;
}