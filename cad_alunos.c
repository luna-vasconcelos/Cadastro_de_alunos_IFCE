#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200 //constante definindo o máximo de alunos e alinhando os dados

//declaração da estrutura com as variáveis
struct Aluno
{
    char nome[MAX][50];
    float nota[MAX][3];
    int media[MAX][3];
};

//declaração da estrutura para coleta de dados do usuário
struct Aluno leAluno()
{
    struct Aluno aluno;
    printf("Digite o Nome: \n");
    fgets(aluno.nome, 40, stdin);
    printf("Digite a 1º Nota da matéria 1: \n");
    scanf("%f", &aluno.nota[0][0]);
    getchar();
    printf("Digite a 2º Nota da matéria 1: \n");
    scanf("%f", &aluno.nota[0][1]);
    getchar(); 
    printf("Digite a 3º Nota da matéria 1: \n");
    scanf("%f", &aluno.nota[0][2]);
    getchar();
};

    /*
for (int i=0; i < aluno.quant; i++)
{
    for (int j=0; j < aluno.quant; j++)
    {
        aluno.media[i][j] = aluno.nota[0][0] + aluno.nota[0][1] + aluno.nota[0][2];
    }
}
    
printf ("media 1º aluno = %d\n", aluno.media[0][0] );
    
return aluno;
}
*/
//cria arquivo de texto com as informações dos alunos
void imprimeAluno(struct Aluno a)
{
    printf("Dados de um aluno --- ");
    printf("Nome: %s. Nota: %.2f\n", a.nome);

    FILE *file;
    file = fopen("alunos.txt", "cad_aluno");

    fprintf(file, "Dados de um aluno --- ");
    fprintf(file, "Nome: %s. Nota: %.2f\n", a.nome);

    fclose(file);

}

void listarTurma(struct Aluno turma[], int n)
{
    
    int i;
    printf("Imprimindo a turma\n");
    for (i = 0; i < n; i++)
        imprimeAluno(turma[i]);

}
int main(int argc, char  *argv[])
{
    struct Aluno *vetAlu;
    int n, i;
    printf("Numero de alunos: ");
    scanf("%d", &n);
    getchar();

    vetAlu = malloc(n * sizeof(struct Aluno)); 

    for (i = 0; i < n; i++)
        vetAlu[i] = leAluno();
    listarTurma(vetAlu, n);
    free(vetAlu); 
    return 0;
}