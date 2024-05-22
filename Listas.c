// Atividade Avaliativa 1

#include <stdio.h>
#include <stdlib.h>

typedef struct nodulo {
    int valor;
    struct nodulo *proximoValor;
} Nodulo;

int tamanho;

Nodulo *alocar() {
    Nodulo *novo = (Nodulo *)malloc(sizeof(Nodulo));
    if (!novo) {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    return novo;
}

void inicia (Nodulo *LISTA) {
    LISTA -> proximoValor = NULL;
    tamanho = 0;
}

void liberarElementos (Nodulo *LISTA) {
    Nodulo *atual = LISTA -> proximoValor, *proximo;
    while (atual != NULL) {
        proximo = atual -> proximoValor;
        free (atual);
        atual = proximo;
    }
    inicia (LISTA);
}

void adicionarInicio (Nodulo *LISTA) {
    Nodulo *novo = alocar();

    novo -> proximoValor = LISTA->proximoValor;
    LISTA -> proximoValor = novo;
    printf ("Novo elemento --> ");
    scanf ("%d" , &novo->valor);
    
    tamanho++;
}

void adicionarFinal (Nodulo *LISTA) {
    Nodulo *novo = alocar ();

    novo -> proximoValor = NULL;
    if (LISTA -> proximoValor == NULL) {
        LISTA-> proximoValor = novo;
    }
    else {
        Nodulo *tmp = LISTA -> proximoValor;
        while (tmp -> proximoValor != NULL) {
            tmp = tmp -> proximoValor;
        }
        tmp -> proximoValor = novo;
    }
    printf ("Novo elemento --> ");
    scanf ("%d" , &novo->valor);

    tamanho++;
}

void adicionarEspecifico (Nodulo *LISTA, int posicao) {
    int count;

    if (posicao > 0 && posicao <= tamanho) {
        if (posicao == 1) {
            adicionarInicio(LISTA);
        }
        else {
            Nodulo *atual = LISTA -> proximoValor, *anterior = LISTA;
            Nodulo *novo = alocar ();
            for (count = 1; count < posicao; count ++) {
                anterior = atual; atual = atual-> proximoValor;
            }
            anterior -> proximoValor = novo;
            novo -> proximoValor = atual;
            printf ("Novo elemento --> ");
            scanf ("%d" , &novo->valor);
            tamanho++;
        }
    }
    else {
        printf ("Elemento Invalido! \n");
    }
}

void excluirInicio (Nodulo *LISTA) {
    if (LISTA -> proximoValor == NULL) {
        printf ("\nLista vazia!\n");
    }
    else {
        Nodulo *ultimo = LISTA-> proximoValor, *penultimo = LISTA;
        while (ultimo -> proximoValor != NULL) {
            penultimo = ultimo;
            ultimo = ultimo -> proximoValor;
            tamanho --;
        }
        penultimo -> proximoValor = NULL;
        printf ("No %d removido com sucesso!", ultimo->valor);
    }
    printf ("\n\n");
    system ("PAUSE");
}

void excluirFim (Nodulo *LISTA) {

    if (LISTA -> proximoValor == NULL) {
        printf ("\nLista vazia!\n");
    }
    else {
        Nodulo *ultimo = LISTA -> proximoValor, *penultimo = LISTA;
        while (ultimo -> proximoValor != NULL) {
            penultimo = ultimo;
            ultimo = ultimo -> proximoValor;
            tamanho --;
        }
        penultimo->proximoValor = NULL;
        printf ("No %d removido com sucesso!", ultimo->valor);
    }
    printf ("\n\n");
    system ("PAUSE");
}

void excluirEspecifico (Nodulo *LISTA, int posicao) {
    int count;

    if (posicao > 0 && posicao <= tamanho) {
        if (posicao == 1 || tamanho == 1) {
            excluirInicio(LISTA);
            tamanho --;
        } 
        else {
            Nodulo *atual = LISTA -> proximoValor, *anterior = LISTA;
            for (count = 1; count < posicao; count++) {
                anterior = atual;
                atual = atual -> proximoValor;
            }

            anterior -> proximoValor = atual -> proximoValor;
            tamanho--;
            printf ("Elemento %d removido com sucesso! ", atual->valor);
            free(atual); 
            system ("PAUSE");
        }
    } 
    else {
        printf ("Posicao invalida!\n");
        system("PAUSE");
    }
}

void listarElementos (Nodulo *LISTA) {
    if (LISTA ->proximoValor == NULL) {
        printf ("\nLista vazia!\n");
    }
    else {
        Nodulo *tmp;
        for (tmp = LISTA -> proximoValor; tmp != NULL; tmp = tmp-> proximoValor){
            printf ("%d\n" , tmp->valor);
        }
    }
    printf ("Tamanho da lista: %d\n", tamanho);
    printf ("\n\n");
    system ("PAUSE");
}

void listarEspecifico (Nodulo *LISTA, int posicao) {
    int count;

    if (posicao >0 && posicao <= tamanho) {
        Nodulo *atual = LISTA -> proximoValor, *anterior = LISTA;

        for (count = 1; count < posicao; count++) {
            anterior = atual;
            atual = atual -> proximoValor;
        }
        system ("CLS");
        printf ("\n\n");
        printf ("Valor do elemento %d e: %d\n", posicao, atual->valor);
        printf ("\n\n");
        system ("PAUSE");
    }
}

int main (void) {
    int opcao;
    int valorNodulo;
    Nodulo *LISTA = alocar ();
    inicia (LISTA);

    do {
        system ("CLS");
        printf ("====================================================\n");
        printf ("                   Menu de Opcoes                   \n");
        printf ("====================================================\n");
        printf ("[1] Adicionar no Inicio da Lista                    \n");
        printf ("[2] Adicionar no Final da Lista                     \n");
        printf ("[3] Adicionar em um ponto especifico da lista       \n");
        printf ("[4] Listar todos os elementos da lista              \n");
        printf ("[5] Listar um elemento especifico da lista          \n");
        printf ("[6] Excluir do inicio da lista                      \n");
        printf ("[7] Excluir do final da lista                       \n");
        printf ("[8] Excluir de um ponto especifico da lista         \n");
        printf ("[9] Liberar os elementos e mostrar a lista vazia    \n");
        printf ("[0] Terminar                                        \n");
        printf ("====================================================\n");
        printf ("Qual a sua opcao? ---> ");
        scanf ("%d", &opcao);
        system ("CLS");

        switch (opcao) {
            case 1: 
                adicionarInicio(LISTA);
                break;
            case 2:
                adicionarFinal(LISTA);
                break;
            case 3:
                if (LISTA -> proximoValor == NULL) {
                    printf ("\nLista vazia!\n");
                    system("PAUSE");
                    break;
                }
                printf ("Em qual posicao voce deseja inserir o valor? Escolha de [1 ate %d] --> " ,  tamanho);
                scanf ("%d" , &valorNodulo);
                adicionarEspecifico(LISTA, valorNodulo);
                break;
            case 4:
                listarElementos(LISTA);
                break;
            case 5:
                if (LISTA -> proximoValor == NULL) {
                    printf ("\nLista vazia!\n");
                    system("PAUSE");
                    break;
                }
                printf ("Qual elemento deseja consultar? Escolha de [1 ate %d] --> " ,  tamanho);
                scanf ("%d" , &valorNodulo);
                listarEspecifico(LISTA, valorNodulo);
                break;
            case 6:
                excluirInicio (LISTA);
                break;
            case 7:
                excluirFim (LISTA);
                break;
            case 8:
                if (LISTA -> proximoValor == NULL) {
                    printf ("\nLista vazia!\n");
                    system("PAUSE");
                    break;
                }
                printf ("Em qual posicao voce deseja excluir o valor? Escolha de [1 ate %d] --> " ,  tamanho);
                scanf ("%d" , &valorNodulo);
                excluirEspecifico(LISTA, valorNodulo);
                break;
            case 9:
                liberarElementos(LISTA);
                break;
            case 0:
                liberarElementos(LISTA);
                system ("PAUSE");
                printf ("Saindo do sistema...");
                break;
            default: 
                printf ("Comando Invalido\n\n");
        }   
    }
    while (opcao <= 9 && opcao != 0);
    liberarElementos (LISTA);
    return 0;
}
