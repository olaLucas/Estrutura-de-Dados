# Lista Duplamente Encadeada

## `inicializar()`
```c
// Função para inicializar os nós da lista
void inicializar()
{
    // Aloca memória para o primeiro nó da lista (chamado 'inicio').
    inicio = (ptr_node)malloc(sizeof(ptr_node));

    // Define o campo 'dado' do nó 'inicio' com o valor atual de 'counter'.
    inicio->dado = counter;

    // Configura o campo 'anterior' do nó 'inicio' como NULL, indicando que não há nó anterior a ele.
    inicio->anterior = NULL;

    // Configura o campo 'proximo' do nó 'inicio' como NULL, indicando que não há nó seguinte a ele.
    inicio->proximo = NULL;

    // Incrementa 'counter' para preparar o próximo valor a ser inserido.
    counter++;
}
```
 Esta função é responsável por criar o primeiro nó de uma lista ligada e configurá-lo com alguns valores iniciais.

- A função `inicializar` é utilizada para criar o primeiro nó da lista e configurá-lo.

- Ela começa alocando memória para o primeiro nó da lista através de `malloc`, garantindo que haja espaço para armazenar os campos do nó (como `dado`, `anterior` e `proximo`).

- Em seguida, ela define o campo `dado` do nó `inicio` com o valor atual de `counter`. Isso significa que o valor do primeiro nó será inicializado com o valor atual da variável `counter`.

- O campo `anterior` do nó `inicio` é configurado como `NULL`, indicando que este é o primeiro nó da lista e não há nó anterior a ele.

- O campo `proximo` do nó `inicio` também é configurado como `NULL`, indicando que, neste momento, não há nenhum nó seguinte a ele na lista.

- Por fim, a variável `counter` é incrementada, preparando o próximo valor a ser inserido na lista.

Essa função é geralmente chamada quando se deseja criar uma lista ligada vazia com um nó inicial contendo um valor específico. Ela estabelece as bases para adicionar mais nós à lista e estabelecer as conexões entre eles.


## `inserir()`
```c
// Função para inserir um novo nó com o valor 'counter' no final da lista.
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
```
Esta função tem como objetivo inserir um novo nó com o valor `counter` no final da lista ligada. Aqui está o funcionamento da função:

- Declara um ponteiro chamado `anterior` que será usado para rastrear o nó anterior durante a inserção.

- Verifica se a variável `counter` é igual a 1. Isso indica que a lista está vazia ou não inicializada. Se for o caso, chama a função `inicializar()` para configurar a lista.

- Se `counter` não for igual a 1, a função percorre a lista até encontrar o último nó. Ela faz isso usando um loop `while` que avança o ponteiro `inicio` até que o campo `proximo` do nó seja `NULL`. Enquanto faz isso, mantém o nó atual em `anterior`.

- Após encontrar o último nó, aloca memória para um novo nó utilizando `malloc` e move o ponteiro `anterior` para o último nó encontrado.

- Move o ponteiro `inicio` para o novo nó recém-criado.

- Configura o campo `dado` do novo nó com o valor `counter`.

- Configura o campo `anterior` do novo nó com o nó anterior (`anterior`).

- Incrementa `counter` para o próximo valor a ser inserido.

- Configura o campo `proximo` do novo nó como `NULL`, indicando o final da lista.

Essa função basicamente insere um novo elemento no final da lista.

## `excluir()` 
```c
// Função para excluir um nó com base no valor 'num' da lista.
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
```

A função `excluir` é usada para remover um nó da lista com base no valor `num`. Aqui está como a função funciona:

- Verifica se a variável `inicio` é igual a NULL. Isso indica que a lista está vazia. Se for o caso, limpa a tela, exibe uma mensagem informando que a lista está vazia e aguarda a entrada do usuário antes de retornar.

- Solicita ao usuário que insira o número que deseja excluir.

- Verifica se o número a ser excluído corresponde ao valor no primeiro nó da lista. Se for o caso:

  - Se `counter` for igual a 1, significa que há apenas um nó na lista. Nesse caso, decrementa `counter`, libera a memória do nó `inicio` e esvazia a lista.

  - Se houver mais de um nó na lista, decrementa `counter`, move o ponteiro `atual` para `inicio`, move o ponteiro `inicio` para o próximo nó na lista, copia o valor e o ponteiro do próximo nó para o nó `atual` e, em seguida, libera a memória do nó `inicio`.

- Se o número não estiver no primeiro nó, a função percorre a lista até encontrar o nó com o valor correspondente ou até chegar ao final da lista. Se o número não for encontrado, exibe uma mensagem informando que o número não foi encontrado.

- Se o número for encontrado na lista, a função ajusta os ponteiros para "pular" o nó a ser excluído e libera a memória desse nó. Também decrementa `counter`.

Em resumo, a função `excluir` permite ao usuário remover um nó específico da lista com base no valor fornecido. Se o valor a ser excluído estiver no primeiro nó, a função trata isso de forma especial para garantir que a lista seja ajustada corretamente.