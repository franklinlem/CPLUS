#include <iostream>

using namespace std;

int main(){
    float nota1, nota2;
    cout << "Informe a primeira nota: " << endl;
    cin >> nota1;
    cout << "Informe a segunda nota: " << endl;
    cin >> nota2;
    float media = (nota1 + nota2) / 2;
    cout << "A media foi: " << media << endl;
    if (media >= 5){
        cout << "O Aluno esta APROVADO!!!" << endl;
    } else if (media < 5 && media >= 2){
        cout << "O Aluno esta em RECUPERACAO!!!" << endl;
    } else {
        cout << "O Aluno esta REPROVADO!!!" << endl;
    }
    return 0;
}