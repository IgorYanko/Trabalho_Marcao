#include <stdio.h>

int registrarAlunos() // Yanko
{
    int i, id = 0, notasAlunos[30], nota = 0, soma;
    
    // Título da aplicação no console
    printf("\t\t\t\t -----------------------------------\n");
    printf("\t\t\t\t | Gerenciador de Notas dos alunos |\n");
    printf("\t\t\t\t -----------------------------------\n");
    
    printf("\t\tEscreva o Id e 3 notas para cada aluno, no final o relatorio sera mostrado. \n\n");
    
    // Laço de repetição para cadastro de até 30 alunos
    for (i = 0; i < 30; i++) {
        printf("Escreva o id do aluno: (Digite um numero negativo pra encerrar)\n");
        scanf("%d", &id);
        
        soma = 0; // Zera o valor de soma para não acumular os valores
    
        if(id < 1){ // Verifica se a condição de encerramento foi cumprida
            printf("Cadastro encerrado!");
            printf("\n%d\n", notasAlunos[4]);
            return -1; // Encerra o programa (poderia ser return 0 tmb)
        }  else {
            for (i = 0; i < 3; i++) { // Laço de repetição para as 3 notas
                printf("\nEscreva a nota: ");
                scanf("%d", &nota);
                
                soma += nota;
            }
            
            notasAlunos[i] = soma; // Atribuindo a soma a uma posição do vetor
            // Não realizei a média diretamente pra facilitar na hora de calcular a individual e geral
        }  
    }
}

int main()
{
   registrarAlunos(); 
}