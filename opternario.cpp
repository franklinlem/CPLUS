#include <iostream>
using namespace std;
int main(){
    int n1, n2, nota;
    string res;
    cout << "Digite a primeira nota: "<< endl;
    cin >> n1;
    cout << "Digite a segunda nota: " << endl;
    cin >> n2;
    nota = (n1 + n2);
    (nota >= 60) ? res="ALUNO APROVADO!" : res="ALUNO REPROVADO!";
    //res=(nota >= 60) ? "ALUNO APROVADO!" : "ALUNO REPROVADO!";
     cout << "Situacao do Aluno: " << res << endl;

     int a, b;
     a=5;
     cout << "Digite um valor: " << endl;
     cin >> b;
     (b >= 10) ? a++ : a--;
     cout << "O valor de 'a' agora e: " << a << endl;
    return 0;
}