#include <stdio.h>

typedef struct {int Dia, Mes, Ano;} DATA;

typedef struct pessoa {
    char Nome[100];
    int Idade;
    float Salario;
    DATA Nasc;
} PESSOA;

void Ler (PESSOA *ptr){
    printf("Qual o Nome? "); gets((*ptr).Nome);
    printf("Qual a Idade? "); scanf("%d", &(*ptr).Idade);
    printf("Qual o salario? "); scanf("%f", &(*ptr).Salario);
    printf("Qual a Data de Nascimento? "); scanf("%d %d %d", &(*ptr).Nasc.Dia, &(*ptr).Nasc.Mes, &(*ptr).Nasc.Ano);
}

void Mostrar (struct pessoa x){
    printf("Nome: %s\n", x.Nome);
    printf("Idade: %d\n", x.Idade);
    printf("Salario: %.2f\n", x.Salario);
    printf("Data de Nascimento: %d/%d/%d\n", x.Nasc.Dia, x.Nasc.Mes, x.Nasc.Ano);
}

main(){
    struct pessoa p = {"Carlos", 23, 12345.67, {23, 5, 1954}};

    Mostrar (p);
    puts("\n");
    Ler(&p);
    puts("\n");
    Mostrar(p);    
}