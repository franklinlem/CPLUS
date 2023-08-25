#include <iostream>
using namespace std;
#define pi 3.1415;
#define curtir cout << "Curta o canal e se inscreva!\n";

void inscrever(){
        cout << "Inscreva-se no canal!" << endl;
    }
int somar(int x, int y){
    int s;
    s = x + y;
    return s;
}
int main(){
    inscrever();
    inscrever();
    inscrever();
    int a = 5, b = 8;
    cout << "A soma e "<< somar(a,b) << endl;
    cout << pi;
    curtir;
    curtir;
    curtir;
    return 0;
}