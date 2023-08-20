# Fila estática

# Código

## Inserir

```c
/**
 * Função para inserir um número na fila.
 * 
 * Se a fila estiver cheia, exibirá uma mensagem de erro.
 * Caso contrário, solicita ao usuário um número para inserção na fila.
 * 
 * Parâmetros: Nenhum.
 * 
 * Retorna: Nenhum.
 */
void inserir()
{   
    if (f1.fim == tamanho)
    {
        printf("\nFila cheia!\n");
        cleanBuffer(); // Função para limpar o buffer do teclado.
        getchar();     // Aguarda o usuário pressionar Enter.
        return;
    }
    else
    {
        int num = 0;
        printf("\nInforme um número: \n >>> ");
        scanf("%d", &num);

        f1.dados[f1.fim] = num; // Insere o número na posição final da fila.
        f1.fim++;              // Atualiza o índice de fim da fila.
        return;
    }
}
```

### Explicação

- **`void inserir()`**
    
    Esta função é usada para adicionar um elemento à fila. O funcionamento é o seguinte:
    
    - Primeiro, verifica se a fila está cheia, comparando `f1.fim` (a posição atual do final da fila) com o valor `tamanho` (que parece ser o tamanho máximo da fila).
    - Se a fila estiver cheia, ela exibe uma mensagem de erro e espera que o usuário pressione Enter.
    - Caso contrário, solicita ao usuário que insira um número, armazena esse número na posição corrente de `f1.dados` (a estrutura de dados que parece armazenar os elementos da fila) e incrementa `f1.fim` para apontar para a próxima posição vazia na fila.

## Excluir

```c
/**
 * Função para excluir um número da fila.
 * 
 * Se a fila estiver vazia, exibirá uma mensagem de erro.
 * Caso contrário, remove o número da posição inicial da fila e realiza uma realocação.
 * 
 * Parâmetros: Nenhum.
 * 
 * Retorna: Nenhum.
 */
void excluir()
{
    if (f1.fim == f1.inicio)
    {
        printf("\n\nFila vazia, não há dados para excluir. \n");
        cleanBuffer(); // Função para limpar o buffer do teclado.
        getchar();     // Aguarda o usuário pressionar Enter.
        return;
    }
    else
    {
        f1.dados[f1.inicio] = 0; // Remove o número da posição inicial da fila.
        realocar();              // Função para realizar a realocação dos elementos na fila.
        f1.fim--;                // Atualiza o índice de fim da fila.
    }
}
```

### Explicação

- **`void excluir()`**
    
    Esta função é usada para remover o elemento mais antigo da fila. O funcionamento é o seguinte:
    
    - Primeiro, verifica se a fila está vazia, comparando `f1.fim` com `f1.inicio`. Se eles forem iguais, a fila está vazia.
    - Se a fila estiver vazia, exibe uma mensagem de erro e espera que o usuário pressione Enter.
    - Caso contrário, ela define o elemento no início da fila (`f1.inicio`) como zero, simbolizando que o espaço está vazio.
    - Em seguida, chama a função `realocar()` para deslocar todos os elementos restantes na fila uma posição para frente.
    - Por fim, decrementa `f1.fim` para indicar que a fila está agora um elemento menor.

## Realocar

```c
/**
 * Função para realizar a realocação de elementos em uma fila após a remoção de um elemento.
 *
 * Se a fila estiver vazia, exibe uma mensagem de erro.
 * Caso contrário, desloca todos os elementos da fila uma posição para frente,
 * preenchendo a posição vazia no início com zero.
 *
 * Parâmetros: Nenhum.
 *
 * Retorna: Nenhum.
 */
void realocar()
{

    if (f1.fim == f1.inicio)
    {
        printf("\\nFila vazia, não há elementos para realocar!\\n");
        cleanBuffer(); // Função para limpar o buffer do teclado.
        getchar();     // Aguarda o usuário pressionar Enter.
        return;
    }
    else
    {
        for (int i = 0; i < f1.fim-1; i++)
        {
            f1.dados[i] = f1.dados[i+1]; // Desloca o elemento da posição (i+1) para a posição (i).
            f1.dados[i+1] = 0;           // Preenche a posição desocupada com zero.
        }
    }
}

```

### Explicação

- **`void realocar()`**
    
    Esta função é usada para realizar a realocação dos elementos na fila após a remoção de um elemento. O funcionamento é o seguinte:
    
    - Primeiro, verifica se a fila está vazia, da mesma forma que a função `excluir()`.
    - Se a fila estiver vazia, exibe uma mensagem de erro e espera que o usuário pressione Enter.
    - Caso contrário, ela entra em um loop que percorre a fila da primeira posição até a penúltima posição (`f1.fim-1`).
    - Dentro do loop, ela move o elemento da posição `(i+1)` para a posição `i`, efetivamente deslocando todos os elementos uma posição para frente.
    - Para garantir que o último elemento não seja duplicado no final da fila, ela define o elemento na última posição (`f1.dados[i+1]`) como zero.