#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main(){
    char *nome;
    nome = (char *) malloc(sizeof(char) + 1);
    gets(nome);
    cout << nome << endl;
    return 0;
}