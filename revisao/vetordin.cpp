#include <iostream>

using namespace std;

int main(){

    int tamanho;
    cout << "Qual tamanho do vetor?"<< endl;
    cin >> tamanho;
    int *vetor = new int[tamanho];
    
    for (int i=0; i<tamanho; i++){
        cout << "Digite um valor a ser inseido na posicao " << i+1 << endl;
        cin >> vetor[i];
    }
    for (int i=0; i<tamanho; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;

    delete [] vetor;

    return 0;
}