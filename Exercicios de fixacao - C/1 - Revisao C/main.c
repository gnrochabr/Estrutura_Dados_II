#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criando a estrutura do tipo aluno
typedef struct {
    int matricula;
    char nome[100];
    char endereco[200];
    char data_nasc[10];
} Aluno;

// Prototipos
void pesquisaAluno(Aluno *alunos[], int tamanho);
void excluiAluno(Aluno *alunos[], int *tamanho);
void imprimir(Aluno *alunos[], int tamanho);
void ordenarPorNome(Aluno *alunos[], int tamanho, char form);

int main() {
    int tamanho = 10;
    Aluno *alunos[tamanho];
    
    // Alocando memória e inicializando alunos
    for (int i = 0; i < tamanho; i++) {
        alunos[i] = (Aluno *)malloc(sizeof(Aluno));
        if (alunos[i] != NULL) {
            alunos[i]->matricula = i + 1;
            sprintf(alunos[i]->nome, "Exemplo %d", i + 1);
            strcpy(alunos[i]->endereco, "Padrao");
            strcpy(alunos[i]->data_nasc, "Padrao");
        } else {
            printf("Erro ao alocar memória para o aluno %d\n", i + 1);
        }
    }

    // Funções de pesquisa, ordenação e exclusão
    imprimir(alunos, tamanho);
    ordenarPorNome(alunos, tamanho, 'd'); // Ordenação decrescente
    imprimir(alunos, tamanho);
    ordenarPorNome(alunos, tamanho, 'c'); // Ordenação crescente
    pesquisaAluno(alunos, tamanho);
    excluiAluno(alunos, &tamanho);
    pesquisaAluno(alunos, tamanho);

    // Liberando memória
    for (int i = 0; i < tamanho; i++) {
        free(alunos[i]);
    }

    return 0;
}

// Realiza a pesquisa pelo aluno através de um ponteiro para o vetor alunos
void pesquisaAluno(Aluno *alunos[], int tamanho) {
    Aluno *encontrado = NULL;
    int matr;
    printf("Digite a matrícula: ");
    scanf("%d", &matr); // Capta a matrícula que o usuário deseja encontrar

    for (int j = 0; j < tamanho; j++) { // Faz a busca na matrícula
        if (alunos[j]->matricula == matr) {
            encontrado = alunos[j];
            break;
        }
    }

    // Aponta o resultado para o problema de busca
    if (encontrado != NULL) {
        printf("O aluno %s, matricula %d foi encontrado!\n", encontrado->nome, encontrado->matricula);
    } else {
        printf("Aluno não encontrado!\n");
    }
}

// Imprime a lista de alunos
void imprimir(Aluno *alunos[], int tamanho) {
    printf("Lista de alunos:\n");
    for (int j = 0; j < tamanho; j++) {
        printf("%d - %s\n", alunos[j]->matricula, alunos[j]->nome);
    }
}

// Ordena o vetor de alunos por nome, em ordem crescente ('c') ou decrescente ('d')
void ordenarPorNome(Aluno *alunos[], int tamanho, char form) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = tamanho-1; j >=0; j--) {
            int cmp_result = strcmp(alunos[i]->nome, alunos[j]->nome);
            if ((form == 'c' && cmp_result > 0) || (form == 'd' && cmp_result < 0)) {
                // Troca os ponteiros
                Aluno *temp = alunos[j];
                alunos[j] = alunos[i];
                alunos[i] = temp;
            }
        }
    }
}

// Exclui um aluno pelo número da matrícula
void excluiAluno(Aluno *alunos[], int *tamanho) {
    int search;
    printf("Digite a matrícula: ");
    scanf("%d", &search);
    int found = 0;

    for (int j = 0; j < *tamanho; j++) {
        // Se o elemento for encontrado, procedemos à exclusão
        if (alunos[j]->matricula == search) {
            free(alunos[j]); // Libera o valor da memória
            for (int k = j; k < *tamanho - 1; k++) { // Fazemos a realocação dos demais valores
                alunos[k] = alunos[k + 1]; // Altera a posição dos elementos do vetor
            }
            alunos[*tamanho - 1] = NULL; // Muda o último elemento para NULL para evitar inconsistência
            (*tamanho)--; // Reduz o tamanho em -1 elemento
            found = 1; // Sinaliza que foi realizada a operação de exclusão
            break; // Encerra o processo
        }
    }

    if (found) {
        printf("Aluno excluído!\n");
    } else {
        printf("Aluno não encontrado!\n");
    }
}
