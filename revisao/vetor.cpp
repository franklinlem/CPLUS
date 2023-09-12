#include <iostream>

using namespace std;

int main(){
    int vetor[10] = {0,1};
    vetor[5]=5;
    vetor[7]=7;

    for (int i=0; i<10; i++){
        cout << "[" << vetor[i] << "] ";
    }
    
    int x = sizeof(vetor);
    int y = sizeof(int);

    cout << endl << x << endl;
    cout << endl << y << endl;

    return 0;
}