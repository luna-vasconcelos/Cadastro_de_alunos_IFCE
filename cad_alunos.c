#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declaração da estrutura com as variáveis
struct Aluno
{
    char nome[80];
    float nota[3][3];
    int media[3][3];
};

struct Aluno leAluno()
{
    struct Aluno aluno;

    printf("Digite o Nome: ");
    fgets(aluno.nome, 80, stdin);
    printf("Digite a 1º Nota: \n");
    scanf("%f", &aluno.nota[0]);
    getchar();
    printf("Digite a 2º Nota: \n");
    scanf("%f", &aluno.nota[1]);
    getchar(); 
    printf("Digite a 3º Nota: \n");
    scanf("%f", &aluno.nota[2]);
    getchar();

    aluno.media[0][0] = aluno.nota[0] + aluno.nota[1] + aluno.nota[2];    
    
    printf ("media %d\n", aluno.media[0][0] );
    

    return aluno;
}

//cria arquivo de texto com as informações dos alunos
void imprimeAluno(struct Aluno a)
{
    printf("Dados de um aluno --- ");
    printf("Nome: %s. Nota: %.2f\n", a.nome,a.nota);

    FILE *file;
    file = fopen("alunos.txt", "a");

    fprintf(file, "Dados de um aluno --- ");
    fprintf(file, "Nome: %s. Nota: %.2f\n", a.nome, a.nota);

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