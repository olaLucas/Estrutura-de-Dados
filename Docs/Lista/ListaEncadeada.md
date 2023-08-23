# Lista Encadeada

## `inserir()`

```c
// Função para inserir um novo nó com o valor 'counter' no final da lista.
void inserir(ptr_node inicio)
{
    // Verifica se 'counter' é igual a 1, indicando que a lista está vazia ou não inicializada.
    if (inicio == NULL)
    {
        // Chama a função 'inicializar' para configurar a lista inicialmente.
        inicializar();
    }
    else
    {
        // Percorre a lista até encontrar o último nó.
        while (inicio->proximo != NULL)
        {
            inicio = inicio->proximo;
        }

        // Aloca memória para um novo nó e move o ponteiro 'inicio' para esse nó.
        inicio->proximo = (ptr_node)malloc(sizeof(ptr_node));
        inicio = inicio->proximo;

        // Configura o campo 'dado' do novo nó com o valor 'counter'.
        inicio->dado = counter;

        // Incrementa 'counter' para o próximo valor a ser inserido.
        counter++;

        // Configura o campo 'proximo' do novo nó como NULL, indicando o final da lista.
        inicio->proximo = NULL;
    }
}
```

A função `inserir` tem a responsabilidade de adicionar um novo nó com um valor à lista ligada. Aqui está uma explicação passo a passo do que ela faz:

1. Verifica se a variável `inicio` é igual a NULL. Se for igual a NULL, isso significa que a lista está vazia.

2. Se `inicio` for igual a NULL, chama a função `inicializar()`. Essa função é responsável por configurar a lista inicialmente.

3. Caso contrário, percorre a lista até encontrar o último nó. Isso é feito com um loop `while` que verifica se o campo `proximo` do nó atual não é `NULL`. Isso significa que estamos indo do início da lista até o último nó.

4. Após encontrar o último nó, aloca memória para um novo nó utilizando `malloc` e configura o campo `proximo` do último nó para apontar para o novo nó.

5. Move o ponteiro `inicio` para o novo nó.

6. Configura o campo `dado` do novo nó com o valor `counter`.

7. Incrementa `counter`.

8. Configura o campo `proximo` do novo nó como `NULL`, indicando o final da lista.

Essencialmente, esta função insere um novo elemento no final da lista.

## `excluir()`
```c
// Função para excluir um nó com base no valor 'num' da lista.
// Função para excluir um nó com base no valor 'num' da lista.
void excluir(ptr_node inicio)
{
    // Verifica se a lista é igual a NULL, indicando que a lista está vazia.
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
        // Caso o segundo elemento da lista seja igual a NULL, significa que há apenas um nó na lista.
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
        // Se 'proximo' for NULL, o número não foi encontrado na lista.
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
```

A função `excluir` é usada para remover um nó específico da lista com base no valor que o usuário deseja excluir. Aqui está uma explicação passo a passo do que ela faz:

1. Verifica se a variável `inicio` é igual a NULL. Se for igual, isso significa que a lista está vazia, e a função informa ao usuário que não há dados para excluir.

2. Solicita ao usuário que insira o número que deseja excluir.

3. Verifica se o número que o usuário deseja excluir é igual ao valor no primeiro nó (`inicio->dado`). Se for igual:

   - Se o primeiro elemento aponta para outro elemento, se não, isso significa que há apenas um nó na lista. Nesse caso, decrementa `counter` e libera a memória do nó `inicio`, esvaziando a lista.

   - Se houver mais de um nó na lista, decrementa `counter`, copia o valor e o ponteiro do próximo nó para o nó `inicio`, e então libera a memória do próximo nó.

4. Se o número não corresponder ao primeiro nó, a função percorre a lista com um loop `while` até encontrar o nó que corresponde ao número ou até chegar ao final da lista. Se o número não for encontrado, informa ao usuário que o número não foi encontrado.

5. Se o número for encontrado na lista, a função ajusta os ponteiros para "pular" o nó a ser excluído e libera a memória desse nó. Também decrementa `counter`.

Em resumo, a função `excluir` permite ao usuário remover um nó específico da lista com base no valor fornecido. Se o valor a ser excluído estiver no primeiro nó, a função trata isso de forma especial para garantir que a lista seja ajustada corretamente.