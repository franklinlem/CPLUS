#include <iostream>
using namespace std;

int main(){
    float n1, n2, n3, medturma;
    cout << "Digita a nota 1: \n";
    cin >> n1;
    cout << "Digita a nota 2: \n";
    cin >> n2;
    cout << "Digita a nota 3: \n";
    cin >> n3;
    cout << "Digita a media da turma: \n";
    cin >> medturma;
    float mediaaluno=(n1+n2+n3)/3;
    cout << "A media do aluno e: "<< mediaaluno << endl;
    if (mediaaluno < medturma){
        cout << "O aluno esta abaixo da media!\n";
    } else if (mediaaluno == medturma){
        cout << "O aluno esta na media!\n";
    } else {
        cout << "O aluno esta acima da media!\n";
    }

    return 0;
}