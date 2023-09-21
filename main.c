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
} t_carro;

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
    printf("\nMatrícula: ");
    scanf( "%s",&c.matricula);
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

int read_cars(t_carro *lista)
{
    FILE *f = fopen("cars.txt", "r");

    int lista_count = 0;
    if (f != NULL)
    {
        char marca[15];
        char modelo[15];
        char cor[15];
        char combustivel[15];
        char matricula[15];
        while (fscanf(f, "%[^#]#%[^#]#%[^#]#%[^#]#%[^#]#", marca, modelo, cor, combustivel, matricula) != EOF)
        {
            strcpy(lista[lista_count].marca, marca);
            strcpy(lista[lista_count].modelo, modelo);
            strcpy(lista[lista_count].cor, cor);
            strcpy(lista[lista_count].combustivel, combustivel);
            strcpy(lista[lista_count].matricula, matricula);
            lista_count++;
        }
        fclose(f);
    }

    return lista_count;
}

void print_cars(t_carro *lista, int lista_count)
{
    printf("| Marca           | Modelo          | Cor             | Combustível     | Matricula       |\n");
    printf("|-----------------|-----------------|-----------------|-----------------|-----------------|\n");
    for (int i = 0; i < lista_count; ++i)
    {
        t_carro carro = lista[i];
        printf("| %15s | %15s | %15s | %15s | %15s |\n", carro.marca, carro.modelo, carro.cor, carro.combustivel, carro.matricula);
    }
}

void write_cars(t_carro *lista, int lista_count)
{
    FILE *arquivo = fopen("cars.txt", "w");
    
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo 'cars.txt'.\n");
        return;
    }
  
    for (int i = 0; i < lista_count; ++i)
    {
        t_carro carro = lista[i];
        fprintf(arquivo, "%s#%s#%s#%s#%s#\n", carro.marca, carro.modelo, carro.cor, carro.combustivel, carro.matricula);
    }
  
    fclose(arquivo);
    printf("Dados do carro salvos no arquivo 'cars.txt'.\n");
}

int main(void)
{
    #if defined(_WIN32)
        SetConsoleOutputCP(CP_UTF8);
    #endif
    return 0;
}