#include <stdio.h>
#include <string.h>

//Criando a estrutura do tipo aluno
typedef struct{
int matricula;
char nome[100];
char endereco[200];
char data_nasc[10];
} Aluno;

//prototipos
void pesquisaAluno(Aluno alunos[10]);


int main(){
    Aluno alunos[10];
    //Aluno novoAluno;

    for(int i = 0; i<10; i++){
        alunos[i].matricula = i+1;
        sprintf(alunos[i].nome,"Exemplo %d",i+1);
        strcpy(alunos[i].endereco,"Padrao");
        strcpy(alunos[i].data_nasc,"Padrao");
    }

    for(int j = 0; j<10; j++){
        printf("%i - %s\n",alunos[j].matricula,alunos[j].nome);
    }
    pesquisaAluno(alunos);
    return 0;
}

void pesquisaAluno(Aluno alunos[10]){
 Aluno encontrado;
 int matr;
 encontrado.matricula = (int) NULL;
 printf("Digite a matrícula: ");
 scanf("%d",&matr);
for(int j = 0; j<10; j++){
        if(alunos[j].matricula == matr){
            encontrado = alunos[j];
        }
}
if(encontrado.matricula!= (int) NULL)
{
    printf("O aluno %s, matricula %d foi encontrado!",encontrado.nome,encontrado.matricula);
}
else
{
    printf("Aluno não encontrado!");
}

}