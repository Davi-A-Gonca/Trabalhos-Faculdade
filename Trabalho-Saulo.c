#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
   int ra;
   int presenca;
   float nota1;
   float nota2;
   int status;
}lista;

void menu(){
    int opcao_menu = 0; // opçao pra escolher menu
    printf("\n\t\t\tGerenciamento de Dados\n\t\t\t======================\n");
    printf("\n\t\t\t1. Listar todos os alunos.\n\n\t\t\t2. Listar os alunos aprovados.\n\n\t\t\t3. Listar os alunos em recuperacao.");
    printf("\n\n\t\t\t4. Listar os alunos reprovados.\n\n\t\t\t5. Incluir aluno.");
    printf("\n\n\t\t\t6. Alterar dados.\n\n\t\t\t7. Excluir aluno.\n\n\t\t\t8. Sair do programa.\n\t\t\t\t");
    fflush(stdin);
}

int main(){
    lista alunos[10];
    int i, resultado;
    for(i=0;i<10;i++){
        printf("Qual a RA do %d aluno?\n>>>", i+1);
        fflush(stdin);
        scanf("%d", &alunos[i].ra);
        printf("Quanto o aluno tirou no 1 bimestre\n>>>");
        fflush(stdin);
        scanf("%f", &alunos[i].nota1);
        printf("Quanto o aluno tirou no 2 bimestre?\n>>>");
        fflush(stdin);
        scanf("%f", &alunos[i].nota2);
        printf("Quantas aulas o aluno compareceu?\n>>>");
        fflush(stdin);
        scanf("%d", &alunos[i].presenca);
    }
    menu();

    return 0;
}
