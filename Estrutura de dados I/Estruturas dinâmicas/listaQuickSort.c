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

void menu();
void inicializar_elemento(int num);
void inserir_ordenar();
void inserir_elemento(ptr_node inicio, int num);
void quicksort(int array[], int inicio, int fim);
int particiona_vetor(int array[], int inicio, int fim);
void excluir_elemento(ptr_node inicio);
void exibir_lista(ptr_node inicio);
void swap(int * x, int * y);
void cleanBuffer();

int main(void)
{    
    //inicializar();

    menu();
    return 0;
}

void menu()
{
    int seletor = 0;
    while (seletor != 4)
    {
        system("clear");
        exibir_lista(inicio);
        
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
            inserir_ordenar(inicio);
            break;

        case 2:
            excluir_elemento(inicio);
            break;

        case 3:
            exibir_lista(inicio);
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

void inserir_ordenar(ptr_node navegador)
{
    int num = 0;
    int inicioArr = 0, fimArr = counter - 1; 

    printf("Insira um numero: "); scanf("%d", &num);
    inserir_elemento(inicio, num);

    if (counter > 2)
    {
        int array[counter];

        int i = 0;
        while(navegador->proximo != NULL)
        {
            array[i] = navegador->dado;
            navegador = navegador->proximo;
            i++;
        }

        array[i] = navegador->dado; // pegando o valor do ultimo elemento da lista

        quicksort(array, inicioArr, fimArr);

        navegador = inicio; // voltando navegador para o começo da lista
        i = 0;

        while(navegador->proximo != NULL)
        {
            navegador->dado = array[i];
            navegador = navegador->proximo;
            i++;
        }

        navegador->dado = array[i]; 
    }
}

void inserir_elemento(ptr_node inicio, int num)
{
    if (counter == 1)
    {
        inicializar_elemento(num);
    }
    else
    {
        while (inicio->proximo != NULL)
        {
            inicio = inicio->proximo;
        }

        inicio->proximo = (ptr_node)malloc(sizeof(ptr_node));
        inicio = inicio->proximo;
        inicio->dado = num;
        inicio->proximo = NULL;

        counter++;
    }
}

void quicksort(int array[], int inicio, int fim)
{
    if (fim < inicio)
    {
        return;
    }

    int pivo = particiona_vetor(array, inicio, fim);
    quicksort(array, inicio, pivo - 1);
    quicksort(array, pivo + 1, fim);
}

int particiona_vetor(int array[], int inicio, int fim)
{
    int barraMenores = inicio, pivo = array[fim];
    for (int barraMaiores = inicio; barraMaiores < fim; barraMaiores++)
    {
        if (array[barraMaiores] < pivo)
        {
            swap(&array[barraMenores], &array[barraMaiores]);
            barraMenores++;
        }
    }

    swap(&array[barraMenores], &array[fim]);
    return barraMenores;
}

void excluir_elemento(ptr_node inicio)
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

void exibir_lista(ptr_node inicio)
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

void inicializar_elemento(int num)
{
    inicio = (ptr_node)malloc(sizeof(ptr_node));
    inicio->dado = num;
    inicio->proximo = NULL;
    counter++;
}

void swap(int * x, int * y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}