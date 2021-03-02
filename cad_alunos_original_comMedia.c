//declaração das bibliotecas necessárias
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declaração da estrutura com as variáveis
struct Aluno
{
    char nome[80];
    float nota[3];
    int media;
};

//declaração da estrutura para coleta de dados do usuário
struct Aluno leAluno()
{
    struct Aluno aluno;

    printf("Digite o Nome: ");
    fgets(aluno.nome, 80, stdin);
    printf("Digite a Nota 1: ");
    scanf("%f", &aluno.nota[0]);
    printf("Digite a Nota 2: ");
    scanf("%f", &aluno.nota[1]);
    printf("Digite a Nota 3: ");
    scanf("%f", &aluno.nota[2]);
    getchar();

    return aluno;
}

//função que cria arquivo de texto com as informações dos alunos
void imprimeAluno(struct Aluno a)
{
    printf("Dados de um aluno --- ");
    printf("Nome: %s. Média: %.2f\n", a.nome, a.nota);

    FILE *file;
    file = fopen("alunos.txt", "a");

    fprintf(file, "Dados de um aluno --- ");
    fprintf(file, "Nome: %s. Média: %.2f\n", a.nome, a.nota);

    fclose(file);

}

//função que lista as turmas com os alunos
void listarTurma(struct Aluno turma[], int n)
{
    
    int i;
    printf("Imprimindo a turma\n");
    for (i = 0; i < n; i++)
        imprimeAluno(turma[i]);

}

//função principal
int main(struct Aluno a, int argc, char  *argv[])
{
    struct Aluno *vetAlu;
    int n, i;
    printf("Numero de alunos: ");
    scanf("%d", &n);
    getchar();

    //calculando as médias
    int media_aluno[80][3];
    int linha, coluna;
    a.media = 0;
    for (int linha = 0; linha < 80; linha++)
    {
        for (int coluna = 0; coluna < n; coluna++)
        {
            a.media = media_aluno[linha][coluna]/3;

        }
        a.nota[linha] = a.media;
    }

    vetAlu = malloc(n * sizeof(struct Aluno)); 

    for (i = 0; i < n; i++)
        vetAlu[i] = leAluno();
    listarTurma(vetAlu, n);
    free(vetAlu); 
    return 0;
}