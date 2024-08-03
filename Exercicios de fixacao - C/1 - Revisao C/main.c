#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando a estrutura do tipo aluno
typedef struct{
int matricula;
char nome[100];
char endereco[200];
char data_nasc[10];
} Aluno;

//prototipos
void pesquisaAluno(Aluno *alunos[],int tamanho);

int main(){
    int tamanho = 10;
    Aluno *alunos[tamanho];
    //Aluno novoAluno;

    for(int i = 0; i<10; i++){
        alunos[i] = (Aluno *)malloc(sizeof(Aluno));
        alunos[i]->matricula = i+1;
        sprintf(alunos[i]->nome,"Exemplo %d",i+1);
        strcpy(alunos[i]->endereco,"Padrao");
        strcpy(alunos[i]->data_nasc,"Padrao");
    }

    for(int j = 0; j<10; j++){
        printf("%i - %s\n",alunos[j]->matricula,alunos[j]->nome);
    }
    pesquisaAluno(alunos,tamanho);
    free(alunos);
    return 0;
}

void pesquisaAluno(Aluno *alunos[],int tamanho){
 
 int matr, ind = -1;
 printf("Digite a matrícula: ");
 scanf("%d",&matr);
for(int j = 0; j<tamanho;j++){
        if(alunos[j]->matricula == matr){
            ind = j;
            break;
        }
}
if(ind >= 0)
{
    printf("O aluno %s, matricula %d foi encontrado!",alunos[ind]->nome,alunos[ind]->matricula);
}
else
{
    printf("Aluno não encontrado!");
}

}
