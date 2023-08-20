#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int dado;
    struct node * proximo;
} * ptr_node;

ptr_node inicializar();
void inserir();
void exibir();
void excluir();
void menu();
void limparBuffer();

ptr_node inicializar(ptr_node elemento)
{
    elemento = (ptr_node)malloc(sizeof(ptr_node));
    elemento->dado = 0;
    elemento->proximo = NULL;

    return elemento;
}

void inserir(ptr_node * fila)
{
    int num = -1;
    while (num == -1)
    {
        printf("\nInforme o número que deseja inserir: (0 = Sair)");
        printf("\n\n>>> ");
        scanf("%d", &num);
        limparBuffer();

        if (num == 0)
        {
            return;
        }
    }

    ptr_node navegador = * fila;

    if (navegador == NULL)
    {
        *fila = inicializar(*fila);
        navegador = * fila;
        navegador->dado = num;
    }
    else
    {
        while (navegador->proximo != NULL)
        {
            navegador = navegador->proximo;
        }

        navegador->proximo = inicializar(*fila);
        navegador = navegador->proximo;
        navegador->dado = num;
    }
}

void exibir(ptr_node fila)
{
    printf("fila: [ ");
    if (fila != NULL)
    {
        printf("%d ", fila->dado);
        while (fila->proximo != NULL)
        {
            fila = fila->proximo;
            printf("%d ", fila->dado);
        }
    } 
    else 
    {
        printf("vazia ");
    }
    
    printf("]\n");
}

void excluir(ptr_node * fila)
{
    ptr_node navegador = *fila;

    if (*fila == NULL)
    {
        return;
    }
    else if (navegador->proximo == NULL)
    {
        *fila = NULL;
        free(*fila);
        return;
    }
    else if (navegador->proximo != NULL)
    {
        ptr_node atual = navegador;

        navegador = navegador->proximo;
        atual->dado = navegador->dado;
        atual->proximo = navegador->proximo;

        free(navegador);
    }
}

void menu(ptr_node fila)
{
    int seletor = -1;
    while (seletor != 0)
    {
        system("clear");
        printf("--------------| ELEMETOS |--------------\n");
        exibir(fila);
        
        printf("\nSelecione uma opção: \n\n");
        printf("0. Sair \n");
        printf("1. Inserir dados.\n");
        printf("2. Excluir dados.\n");
        
        printf("\n >>> ");
        scanf("%d", &seletor);
        limparBuffer();

        switch (seletor)
        {
        case 0:
            return;
            break;
        
        case 1:
            inserir(&fila);
            break;

        case 2:
            excluir(&fila);
            break;
        
        default:
            printf("Opção inválida! Tente novamente. \n\n");
            limparBuffer();
            getchar();
            break;
        }
    }
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}

int main(void)
{
    ptr_node fila = NULL;
    menu(fila);

    return 0;
}