#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node
{
    int dado;
    struct node *proximo;
} *ptr_node;

ptr_node inicio;
int counter = 1;

void inicializar();
void inserir(ptr_node inicio);
void excluir(ptr_node inicio);
void exibir(ptr_node inicio);
void menu();
void cleanBuffer();

int main(void)
{    
    inicializar();

    menu();
    return 0;
}

void menu()
{
    int seletor = 0;
    while (seletor != 4)
    {
        system("clear");
        exibir(inicio);
        
        printf("\nSelecione uma opção: \n\n");
        printf("1. Inserir dados.\n");
        printf("2. Excluir dados.\n");
        printf("3. Exibir dados.\n");
        printf("4. Sair.\n");
        
        printf("\n >>> ");
        scanf("%d", &seletor);

        switch (seletor)
        {
        case 1:
            inserir(inicio);
            break;

        case 2:
            excluir(inicio);
            break;

        case 3:
            exibir(inicio);
            break;

        case 4:
            return;
            break;
        
        default:
            printf("Opção inválida! Tente novamente. \n\n");
            cleanBuffer();
            getchar();
            break;
        }
    }
}

void inserir(ptr_node inicio)
{
    if (counter == 1)
    {
        inicializar();
    }
    else
    {
        while (inicio->proximo != NULL)
        {
            inicio = inicio->proximo;
        }

        inicio->proximo = (ptr_node)malloc(sizeof(ptr_node));
        inicio = inicio->proximo;
        inicio->dado = counter;
        counter++;
        inicio->proximo = NULL;
    }
}

void excluir(ptr_node inicio)
{
    if (counter == 1)
    {
        system("clear");
        printf("Lista vazia, não há dados para excluir. \n\n");
        cleanBuffer();
        getchar();
        return;
    }

    int num;
    ptr_node atual;
    printf("Insira o número que deseja excluir: \n\n >>> ");
    scanf("%d", &num);

    if (num == inicio->dado)
    {
        if (counter == 2)
        {
            counter--;
            free(inicio);
            return;
        }
        else
        {
            counter--;
            atual = inicio;
            inicio = inicio->proximo;
            atual->dado = inicio->dado;
            atual->proximo = inicio->proximo;
            free(inicio);
            return;
        }
    }
    

    while (inicio->dado != num)
    {   
        if (inicio->proximo == NULL)
        {
            printf("Número não encontrado! \n\n");
            cleanBuffer();
            getchar();
            break;
        }
        else
        {
            atual = inicio;
            inicio = inicio->proximo;
        }
    }

    if (inicio->dado == num)
    {
        atual->proximo = inicio->proximo;
        counter--;
        free(inicio);
    }
}

void exibir(ptr_node inicio)
{   
    if (counter == 1)
    {
        printf("Pilha vazia, não há dados para exibir. \n\n");
        return;
    }
    
    printf("[ ");
    while (inicio->proximo != NULL)
    {
        printf("(Dado: %d | Próximo: %p )", inicio->dado, inicio->proximo);
        inicio = inicio->proximo;
    }

    printf("(Dado: %d | Próximo: %p )", inicio->dado, inicio->proximo);
    printf("]");
}

void inicializar()
{
    inicio = (ptr_node)malloc(sizeof(ptr_node));
    inicio->dado = counter;
    inicio->proximo = NULL;
    counter++;
}

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}