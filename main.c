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
    scanf("%s", c.marca);
    printf("\nModelo: ");
    scanf("%s", c.modelo );
    printf("\nCor: ");
    scanf("%s", c.cor);
    printf("\nCombustível: ");
    scanf("%s", c.combustivel);
    printf("\nMatrícula: ");
    scanf("%s", c.matricula);
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

char menuAbrirficheiro() {    
    char op;
    printf("Carregar dados do ficheiro\n");
    printf("1 - Abrir Ficheiro\n");
    printf("2 - Não Ficheiro\n");
    printf("0 - Sair\n");
    printf("> ");
    fflush(stdin);
    scanf("%c", &op);
    return op;
} 

char menuQuererSalvar() {    
    char op;
    printf("Queres salvar os dados no ficheiro\n");
    printf("1 - Sim\n");
    printf("0 - Não\n");
    printf("> ");
    fflush(stdin);
    scanf("%c", &op);
    return op;
} 

char menuViaturas() {
    char op;
    printf(">>>>>>>>MENU GESTAO LISTA VIATURAS<<<<<<<<\n");
    printf(" 1 - Lista de viaturas\n");
    printf(" 2 - Adicionar viaturas\n");
    printf(" 0 - Sair\n");
    printf("> ");
    fflush(stdin);
    scanf("%c", &op);
    return op;
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
    if (lista_count > 0)
    {
        printf("| Marca           | Modelo          | Cor             | Combustível     | Matricula       |\n");
        printf("|-----------------|-----------------|-----------------|-----------------|-----------------|\n");
        for (int i = 0; i < lista_count; ++i)
        {
            t_carro carro = lista[i];
            printf("| %15s | %15s | %15s | %15s | %15s |\n", carro.marca, carro.modelo, carro.cor, carro.combustivel, carro.matricula);
        }
    }
    else
    {
        printf("Sem carros!\n");
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
        fprintf(arquivo, "%s#%s#%s#%s#%s#", carro.marca, carro.modelo, carro.cor, carro.combustivel, carro.matricula);
        if (i + 1 < lista_count) fprintf(arquivo, "\n");
    }
  
    fclose(arquivo);
    printf("Dados do carro salvos no arquivo 'cars.txt'.\n");
}

void clear_screen()
{
    #if defined(_WIN32)
        system("cls");
    #else
        system("clear");
    #endif
}

int main(void)
{
    #if defined(_WIN32)
        SetConsoleOutputCP(CP_UTF8);
    #endif

    t_carro lista[32];
    int lista_count = 0;

    char op = menuAbrirficheiro();

    if (op == '0')
    {
        return 0;
    }
    else if (op == '1')
    {
        lista_count = read_cars(lista);
    }

    do {
        clear_screen();
        op = menuViaturas();

        if (op == '1')
        {
            clear_screen();
            print_cars(lista, lista_count);
        }
        else if (op == '2')
        {
            clear_screen();
            t_carro car = lerCarro();
            lista[lista_count++] = car;
            printf("\nCarro foi adicionado!\n\n");
            impCarro(car);
        }
        else
        {
            clear_screen();
            op = menuQuererSalvar();
            if (op == '1')
            {
                write_cars(lista, lista_count);
            }
            return 0;
        }

        fflush(stdin);
        getchar();
    } while (1);

    return 0;
}