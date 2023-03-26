#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void Limpar(){
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

typedef struct lista
{
   int ra;
   int presenca;
   float nota1;
   float nota2;
   int status;
}lista;

lista alunos[MAX];
lista alunos_aprovados[MAX];
lista alunos_recuperacao[MAX];
lista alunos_reprovados[MAX];
int quant_aprovados = 0, quant_recuperacao = 0, quant_reprovados = 0, quant_total = 0;
int i = 0;//para todos as vezes que precisar de um laço "for"

int checar_status(lista exemplo){
    float nota_total, media;
    nota_total = exemplo.nota1 + exemplo.nota2;
    media = nota_total/2;
    if(media>=6 && exemplo.presenca>=38){
        exemplo.status = 2;
    }else if(media<6 && media>3 && exemplo.presenca>=38){
        exemplo.status = 1;
    }else{
        exemplo.status = 0;
    }
    return exemplo.status;
}

void incluir_aluno(){
    printf("Qual a RA do aluno?\n>>>");
    fflush(stdin);
    scanf("%d", &alunos[quant_total].ra);
    printf("Quanto o aluno tirou no 1 bimestre\n>>>");
    fflush(stdin);
    scanf("%f", &alunos[quant_total].nota1);
    printf("Quanto o aluno tirou no 2 bimestre?\n>>>");
    fflush(stdin);
    scanf("%f", &alunos[quant_total].nota2);
    printf("Quantas aulas o aluno compareceu?\n>>>");
    fflush(stdin);
    scanf("%d", &alunos[quant_total].presenca);
    alunos[quant_total].status = checar_status(alunos[quant_total]);
    if(alunos[quant_total].status == 2){
            alunos_aprovados[quant_aprovados] = alunos[quant_total];
            quant_aprovados+=1;
    }else if(alunos[quant_total].status == 1){
            alunos_recuperacao[quant_recuperacao] = alunos[quant_total];
            quant_recuperacao+=1;
    }else if(alunos[quant_total].status == 0){
            alunos_reprovados[quant_reprovados] = alunos[quant_total];
            quant_reprovados+=1;
    }
    quant_total+=1;
}

void alterar_dados(int alteracao){
    printf("Quanto o aluno tirou no 1 bimestre\n>>>");
    fflush(stdin);
    scanf("%f", &alunos[alteracao].nota1);
    printf("Quanto o aluno tirou no 2 bimestre?\n>>>");
    fflush(stdin);
    scanf("%f", &alunos[alteracao].nota2);
    printf("Quantas aulas o aluno compareceu?\n>>>");
    fflush(stdin);
    scanf("%d", &alunos[alteracao].presenca);
    alunos[alteracao].status = checar_status(alunos[alteracao]);
}

void listar_alunos(lista exemplo){
        printf("-=-=-=-=-=\n");
        printf("RA: %d\n", exemplo.ra);
        printf("Nota1: %.2f\n", exemplo.nota1);
        printf("Nota2: %.2f\n", exemplo.nota2);
        printf("Presenca: %d\n", exemplo.presenca);
        printf("Status: %d\n", exemplo.status);
}

void menu(){
    int opcao_menu = 0; // opçao pra escolher menu
    int codigo = 0; //usado para alterar aluno ou excluir aluno
    printf("\n\t\t\tGerenciamento de Dados\n\t\t\t======================\n");
    printf("\n\t\t\t1. Listar todos os alunos.\n\n\t\t\t2. Listar os alunos aprovados.\n\n\t\t\t3. Listar os alunos em recuperacao.");
    printf("\n\n\t\t\t4. Listar os alunos reprovados.\n\n\t\t\t5. Incluir aluno.");
    printf("\n\n\t\t\t6. Alterar dados.\n\n\t\t\t7. Excluir aluno.\n\n\t\t\t8. Sair do programa.\n\t\t\t\t");
    fflush(stdin);
    scanf("%d", &opcao_menu);
     switch(opcao_menu){
        case 1:
            for(i=0; i<quant_total;i++){
                listar_alunos(alunos[i]);
            }
            menu();
            break;
        case 2:
            for(i=0; i<quant_aprovados;i++){
                listar_alunos(alunos_aprovados[i]);
            }
            menu();
            break;
        case 3:
            for(i=0; i<quant_recuperacao;i++){
                listar_alunos(alunos_recuperacao[i]);
            }
            menu();
            break;
        case 4:
            for(i=0; i<quant_reprovados;i++){
                listar_alunos(alunos_reprovados[i]);
            }
            menu();
            break;
        case 5:
            if(quant_total < MAX){
                incluir_aluno();
            }else{
                printf("Quantidade maxima de alunos alcancada.\n");
            }
            menu();
            break;
        case 6:
            printf("Qual o RA do aluno que voce gostaria de mudar os dados?\n>>>");
            scanf("%d", &codigo);
            for(i=0;i<quant_total;i++){
                if(alunos[i].ra == codigo){
                    alterar_dados(i);
                    //Essa lista de "for"s são usadas para ver em qual categoria os dados novos do aluno se encaixam
                    for(int j = 0; j < quant_aprovados; j++){
                        if(alunos_aprovados[j].ra == codigo){
                            alunos_aprovados[j] = alunos[i];
                        }
                    }
                    for(int j = 0; j < quant_recuperacao; j++){
                        if(alunos_recuperacao[j].ra == codigo){
                            alunos_recuperacao[j] = alunos[i];
                        }
                    }
                    for(int j = 0; j < quant_reprovados; j++){
                        if(alunos_reprovados[j].ra == codigo){
                            alunos_reprovados[j] = alunos[i];
                        }
                    }
                    menu();
                    break;
                }
            }
            printf("RA nao encontrado, tente outro RA.\n");
            menu();
            break;
        case 7:
            //excluir_aluno(); break;
        case 8:
            //exit(0); break;
        default:
            Limpar();
            printf("Opcao Invalida.\n");
            system("pause");
            menu();
    }
}

int main(){
    for(i=0;i<3;i++){
        incluir_aluno();
    }
    menu();
    return 0;
}
