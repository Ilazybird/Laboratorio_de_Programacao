#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAMANHO 5

int main()
{
    int matricula [TAMANHO], opcao;
    float bimestre1 [TAMANHO], soma, media;
    int indice = 0; //start
    int i;
    printf("MENU DE OPCOES:\n");
    printf("1: Cadastrar o aluno:\n");
    printf("2: Alunos acima da media:\n");
    printf("3: Pesquisar / Exibir os Dados de um aluno por matricula (xxx):\n");
    printf("4: Exibir os dados ordenados por Matrícula:\n");
    printf("5: Pesquisar (binário) / Exibir os dados de um aluno por Matrícula:\n");
    printf("0: Sair do programa.\n");
    do {
        printf("Sua opcao: "); scanf("%i", &opcao);
        if (opcao == 0) printf("Fim do Programa\n");
        else if ( opcao < 0 || opcao > 5)
            printf("Erro: Escolha de novo\n");
        else if ( opcao == 1) {
            //Relatório de Cadastro
            if ( indice == TAMANHO ) printf("Turma Lotada!\n");
            else {
                printf("Dados do Aluno %i:\n ", indice + 1);
                printf("Matricula(XXX): "); scanf("%i", &matricula[indice]);
                printf("Nota (0.0 a 10.0): "); scanf("%f", &bimestre1[indice]);
                if (matricula[indice] < 100 || matricula[indice] > 999) printf("Erro: Digite a Matricula novamente\n");
                else if (bimestre1[indice] < 0 || bimestre1[indice] > 10) printf("Erro: Digite a nota novamente\n");
                else {
                    printf("Aluno cadastrado com sucesso!\n");
                    indice++; //step
                };
            };
        }
        if (opcao == 2) {
            //Relatorio dos Alunos acima da media
            if (indice == 0) printf("Turma vazia!\n");
            else {
            soma = 0;
            for ( i = 0; i < indice ; i++)
                soma = soma + bimestre1[i];
            media = soma / indice;
            printf("Relatorio 2: Lista de Alunos acima da media (%.1f):\n", media);
            for (i = 0; i < indice ; i++) {
                if (bimestre1[i] > media)
                    printf("Aluno %i[Matricula: %i]: %.1f\n", i + 1, matricula[i], bimestre1[i]);

            };
            }
        }
    }while (opcao != 0);
    return 0;
}
