#include <iostream>
using namespace std;
int main(){
    int tam=8;
    int vetor[tam];
    int i;
    vetor[0]=10;
    vetor[1]=20;
    vetor[2]=30;
    vetor[3]=40;
    vetor[4]=50;
    vetor[5]=60;
    vetor[6]=70;
    vetor[7]=80;
    for(i = 0; i < tam; i++){
        cout<<vetor[i]<<endl;
    }
    for(i = 0; i < sizeof(vetor) / 4; i++){ //outra forma
        cout<<vetor[i]<<endl;
    }
    return 0;
}