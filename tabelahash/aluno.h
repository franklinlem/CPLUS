#include <iostream>
using namespace std;
class Aluno {
    private:
        int ra;
        int nome;
    public:
        Aluno();
        Aluno(int r, int n);
        int obterRa();
        string obterNome();   
};