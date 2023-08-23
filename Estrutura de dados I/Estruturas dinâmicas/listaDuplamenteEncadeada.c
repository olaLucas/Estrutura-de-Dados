#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int dado;
    struct node *proximo;
    struct node *anterior;
} * ptr_node;

ptr_node lista;
int counter = 0;

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
        exibir(lista);

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
            inserir(lista);
            break;

        case 2:
            excluir(lista);
            break;

        case 3:
            exibir(lista);
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
    // Declara um ponteiro 'anterior' para rastrear o nó anterior durante a inserção.
    ptr_node anterior;

    // Verifica se 'counter' é igual a 1, indicando que a lista está vazia ou não inicializada.
    if (counter == 1)
    {
        // Chama a função 'inicializar' para configurar a lista inicialmente.
        inicializar();
    }
    else
    {
        // Percorre a lista até encontrar o último nó.
        while (inicio->proximo != NULL)
        {
            // Armazena o nó atual em 'anterior' para acompanhar o nó anterior.
            anterior = inicio;

            // Move o ponteiro 'inicio' para o próximo nó na lista.
            inicio = inicio->proximo;
        }

        // Aloca memória para um novo nó e move o ponteiro 'anterior' para 'inicio'.
        inicio->proximo = (ptr_node)malloc(sizeof(ptr_node));
        anterior = inicio;

        // Move o ponteiro 'inicio' para o novo nó recém-criado.
        inicio = inicio->proximo;

        // Configura o campo 'dado' do novo nó com o valor 'counter'.
        inicio->dado = counter;

        // Configura o campo 'anterior' do novo nó com 'anterior'.
        inicio->anterior = anterior;
        
        // Incrementa 'counter' para o próximo valor a ser inserido.
        counter++;

        // Configura o campo 'proximo' do novo nó como NULL, indicando o final da lista.
        inicio->proximo = NULL;
    }
}

void excluir(ptr_node inicio)
{
    // Verifica se 'inicio' é igual a 1, indicando que a lista está vazia.
    if (inicio == NULL)
    {
        // Limpa a tela, exibe uma mensagem e aguarda a entrada do usuário.
        system("clear");
        printf("Lista vazia, não há dados para excluir. \n\n");
        cleanBuffer();
        getchar();
        return;
    }

    int num;
    ptr_node atual;

    // Solicita ao usuário que insira o número que deseja excluir.
    printf("Insira o número que deseja excluir: \n\n >>> ");
    scanf("%d", &num);

    // Verifica se o número a ser excluído corresponde ao valor no primeiro nó da lista.
    if (num == inicio->dado)
    {
        // Caso 'inicio' seja igual a NULL, significa que há apenas um nó na lista.
        if (inicio->proximo == NULL)
        {
            counter--;

            // Libera a memória do nó 'inicio', esvaziando a lista.
            free(inicio);
            lista = NULL; // retira o endereço do primeiro elemento
            return;
        }
        else
        {
            counter--;

            // Move o ponteiro 'atual' para 'inicio'.
            atual = inicio;

            // Move o ponteiro 'inicio' para o próximo nó na lista.
            inicio = inicio->proximo;

            // Copia o valor e o ponteiro do próximo nó para o nó 'atual'.
            atual->dado = inicio->dado;
            atual->proximo = inicio->proximo;

            // Libera a memória do nó 'inicio'.
            free(inicio);
            return;
        }
    }

    // Se o número não estiver no primeiro nó, percorre a lista até encontrá-lo ou chegar ao final.
    while (inicio->dado != num)
    {
        // Se 'proximo' for NULL, o número não foi encontrado na lista pois já chegamos ao final dela.
        if (inicio->proximo == NULL)
        {
            printf("Número não encontrado! \n\n");

            // Limpa o buffer e aguarda a entrada do usuário.
            cleanBuffer();
            getchar();
            break;
        }
        else
        {
            // Move o ponteiro 'atual' para 'inicio' e move 'inicio' para o próximo nó.
            atual = inicio;
            inicio = inicio->proximo;
        }
    }

    // Se o número for encontrado na lista, ajusta os ponteiros para "pular" o nó a ser excluído e libera sua memória.
    if (inicio->dado == num)
    {
        atual->proximo = inicio->proximo;
        counter--;

        // Libera a memória do nó a ser excluído.
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
        printf("(Anterior: %p | Dado: %d | Próximo: %p )", inicio->anterior, inicio->dado, inicio->proximo);
        inicio = inicio->proximo;
    }

    printf("(Anterior: %p | Dado: %d | Próximo: %p )", inicio->anterior, inicio->dado, inicio->proximo);
    printf("]");
}

void inicializar()
{
    lista = (ptr_node)malloc(sizeof(ptr_node));
    lista->dado = counter;
    lista->anterior = NULL;
    lista->proximo = NULL;
    counter++;
}

void cleanBuffer()
{
    int c;
    while ((c = getchar()) != '\n');
}