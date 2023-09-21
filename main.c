#include <stdlib.h>
#include <stdio.h>
#if defined(_WIN32)
#include "windows.h"
#endif


typedef struct 
{
    char marca[15];
    char modelo[15];
    char cor[15];
    char combustivel[15];
    char matricula[15];

}t_carro;

t_carro lerCarro()
{
    t_carro c;

    printf("### Dados do Carro ###");
    printf("\nMarca: ");
    scanf("%s", &c.marca);
    printf("\nModelo: ");
    scanf("%s",&c.modelo );
    printf("\nCor: ");
    scanf("%s",&c.cor);
    printf("\nCombustível: ");
    scanf( "%s",&c.combustivel);
    printf ("\nMatrícula: ");
    scanf ( "%s",&c.matricula);
    return c;
    }

void impCarro(t_carro c)
{
    
    printf("Dados do carro:\n");

    printf("Marca: %s",c.marca);
    printf("\nModelo:%s ",c.modelo);
    printf("\nCor: %s",c.cor);
    printf("\nCombustível: %s",c.combustivel);
    printf("\nMatrícula: %s",c.matricula);

}

void menuAbrirficheiro(){    
    
    int op1;
    printf("Carregar dados do ficheiro")
    printf("1 - Abrir Ficheiro ");
    printf("2 - Não Ficheiro");
    printf("0 - Sair")
    
    switch (op1)
    {
    case '1'

        break;
    case '2'
    
        break;
    }

} 

void menuViaturas(){
    int op2
    printf(">>>>>>>>MENU GESTAO LISTA VIATURAS<<<<<<<<"); 
    printf(" 1 - Lista de viaturas");
    printf(" 2 - Adicionar viaturas");
    printf(" 0 - Sair");

    case '1'

        break;
    case '2'

        break;
}



int main(void)
{
    #if defined(_WIN32)
        SetConsoleOutputCP(CP_UTF8);
    #endif
    

    return 0;
}