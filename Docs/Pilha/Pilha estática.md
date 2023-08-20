# Inserir

```c
/**
 * Função para inserir um número na fila.
 * 
 * Se a pilha estiver cheia, exibirá uma mensagem de erro.
 * Caso contrário, solicita ao usuário um número para inserção na pilha.
 * 
 * Parâmetros: Nenhum.
 * 
 * Retorna: Nenhum.
 */
void inserir()
{
    if (p1.fim == tamanho)
    {
        printf("\\nPilha cheia!\\n");
        cleanBuffer(); // Função que limpa o buffer do teclado.
        getchar();     // Aguarda um caractere do usuário para continuar.
        return;        // Sai da função sem realizar nenhuma inserção.
    }
    else
    {
        int num = 0;
        printf("\\nInforme um número: \\n >>> ");
        scanf("%d", &num); // Lê um número inteiro do usuário.

        p1.dados[p1.fim] = num; // Insere o número na pilha na posição indicada por 'fim'.
        p1.fim++;              // Incrementa o indicador de final da pilha.
        return;                // Sai da função após a inserção.
    }
}

```

## Explicação

- `**void** **inserir()**`
    
    Esta função é responsável por inserir um elemento na pilha. Aqui está o passo a passo do que ela faz:
    
    - Verifica se a pilha (`p1`) está cheia, comparando o valor de `p1.fim` com o tamanho máximo da pilha.
    - Se a pilha estiver cheia, exibe uma mensagem de erro ("Pilha cheia!") e limpa o buffer de entrada com `cleanBuffer()`. Em seguida, aguarda que o usuário pressione Enter com `getchar()` e retorna.
    - Caso a pilha não esteja cheia, a função pede ao usuário para inserir um número, lendo-o com `scanf()` e armazenando-o na posição atual da pilha (`p1.dados[p1.fim]`).
    - Incrementa o valor de `p1.fim` para apontar para a próxima posição livre da pilha, efetivamente adicionando um elemento à pilha.

# Excluir

```c
/**
 * Função para remover um número na fila.
 * 
 * Se a pilha estiver vazia, exibirá uma mensagem de erro.
 * Caso contrário, exclui o ultimo elemento da pilha.
 * 
 * Parâmetros: Nenhum.
 * 
 * Retorna: Nenhum.
 */
void excluir()
{
    if (p1.fim == p1.inicio)
    {
        printf("\\n\\nPilha vazia, não há dados para excluir. \\n");
        cleanBuffer(); // Função que limpa o buffer do teclado.
        getchar();     // Aguarda um caractere do usuário para continuar.
        return;        // Sai da função sem realizar nenhuma exclusão.
    }
    else
    {
        p1.dados[p1.fim-1] = 0; // Remove o elemento no topo da pilha, definindo-o como 0.
        p1.fim--;              // Decrementa o indicador de final da pilha.
    }
}

```

## Explicação

- **`void excluir()`**
    
    Esta função é responsável por excluir (ou remover) o elemento mais recente da pilha. Aqui está o passo a passo do que ela faz:
    
    - Verifica se a pilha (`p1`) está vazia, comparando o valor de `p1.fim` com o valor de `p1.inicio`. Se `p1.fim` for igual a `p1.inicio`, a pilha está vazia.
    - Se a pilha estiver vazia, exibe uma mensagem de erro ("Pilha vazia, não há dados para excluir.") e limpa o buffer de entrada com `cleanBuffer()`. Em seguida, aguarda que o usuário pressione Enter com `getchar()` e retorna.
    - Caso a pilha não esteja vazia, a função remove o elemento mais recente, definindo o valor correspondente a essa posição como 0 (`p1.dados[p1.fim-1] = 0`) e decrementa o valor de `p1.fim` para indicar que a pilha tem um elemento a menos.
