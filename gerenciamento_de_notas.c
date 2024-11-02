#include <stdio.h>

float notasAlunos[30][2];
    
int registrarAlunos() // Yanko
{
    int i, j, id = 0;
    float nota = 0, soma;
    
    // Título da aplicação no console
    printf("\t\t\t\t -----------------------------------\n");
    printf("\t\t\t\t | Gerenciador de Notas dos alunos |\n");
    printf("\t\t\t\t -----------------------------------\n");
    
    printf("\t\tEscreva o Id e 3 notas para cada aluno, no final o relatorio sera mostrado. \n\n");
    
    // Laço de repetição para cadastro de até 30 alunos
    for (i = 0; i < 30; i++) {
        printf("\nEscreva o id do aluno: (Digite um numero negativo pra encerrar)\n");
        scanf("%d", &id);
    
        if(id < 1){ // Verifica se a condição de encerramento foi cumprida
            printf("Cadastro encerrado!");
            return -1; // Encerra o programa (poderia ser return 0 tmb)
        }  else {
            soma = 0; // Zera o valor de soma para não acumular os valores
            
            for (j = 0; j < 3; j++) { // Laço de repetição para as 3 notas
                printf("\nEscreva a %d nota: ", j + 1);
                scanf("%f", &nota);
                
                soma += nota;
            }

            notasAlunos[i][0] = id; // Atribuindo o id a primeira linha do vetor
            notasAlunos[i][1] = soma; // Atribuindo a soma a segunda linha do vetor
            // Não realizei a média diretamente pra facilitar na hora de calcular a individual e geral
        }  
    }
}

float calcularMedia() 
{ // Diogo Henrique

    float medias[30][2], media, id; //Declarei as variáveis 
    
     for (int i =0; i < 30; i++) 
    { //Laço para Verificar ID,Dividir,Guardar media e ID
    
        if ( notasAlunos[i][0] !=0 )
        {
            media = notasAlunos[i][1] / 3.0; // Dividindo pra obter a media
            id = notasAlunos[i][0]; // Assoçiando o id a outra matriz
            medias[i][1] = media; // Esta atribuindo media em uma posiçao da matriz
            medias[i][0] = id; // Esta atribuindo ID em uma posiçao da matriz
        }
    }
}
int Exibir_Nota() // Kayo Winicius
{
    float Maior_Nota, Menor_Nota, nota; // Declaração das variáveis. 

    for(int i = 0; i < 30; i++) // Laço para encontrar a maior e a menor nota.
    {
        if(notasAlunos[i][0] != 0) // Verifica se o ID é valido 
        {
            float medias = notasAlunos[i][1] / 3.0; 

            if(medias > Maior_Nota){ // Verifica se a média atual é maior que o valor atualmente armazenado em Maior_Nota]
                Maior_Nota = medias; // Atualiza a maior nota.

            if(medias < Menor_Nota){ // Mesma coisa que o primeiro if, mas agora verifica se a média atual é menor que o valor armazenado.
                Menor_Nota = medias; // Atualiza menor nota.

         }
    }
}

        printf("A maior nota eh: %.2f\n", Maior_Nota);
        printf("A menor nota eh: %2.f\n", Menor_Nota);
    }
}
int main()
{
   registrarAlunos();
   calcularMedia();
}
