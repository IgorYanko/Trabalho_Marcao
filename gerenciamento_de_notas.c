#include <stdio.h>
#include <limits.h> // lib para usar INT_MAX

float notasAlunos[30][2], medias[30][2], contagem;
    
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

    float media, id; //Declarei as variáveis 
    
     for (int i =0; i < 30; i++) 
    { //Laço para Verificar ID,Dividir,Guardar media e ID
    
        if ( notasAlunos[i][0] !=0 )
        {
            media = notasAlunos[i][1] / 3.0; // Dividindo pra obter a media
            id = notasAlunos[i][0]; // Assoçiando o id a outra matriz
            medias[i][1] = media; // Esta atribuindo media em uma posiçao da matriz
            medias[i][0] = id; // Esta atribuindo ID em uma posiçao da matriz
            contagem++; //Variável para saber quantos alunos foram cadastrados no final - Matheus
        }
    }

    return contagem;
}
int ExibirNota(float medias[30][2]) // Kayo Winicius.  
{
    float Maior_Nota = 0, Menor_Nota = INT_MAX; // Declaração das variáveis a serem usadas;

    for(int i = 0; i < 30; i++) // Laço para percorrer as médias;
    {
        if(medias[i][0] != 0){ // Verifica se o ID do aluno não é zero;
            float media = medias[i][1]; // A média do aluno é extraida da segunda coluna onde foram armazenada as médias;

            if(media > Maior_Nota){ // Para verificar se a média atual é maior do que a Maior_Nota armazenada. Se for, a variável é atualizada;
                Maior_Nota = media; // Faz a atualização da Maior_Nota;
            } 
            
            if(media < Menor_Nota){ // Verifica se a média atual é menor que a Menor_Nota armazenada. Se for, a variavél atual é atualizada;
                Menor_Nota = media; // Faz a atualização da Menor_Media
            }
        }
    }
    
        printf("\nA maior nota eh: %.2f\n", Maior_Nota);
        printf("A menor nota eh: %.2f\n", Menor_Nota);
        //Irá imprimir a Maior_Nota e Menor_Nota na tela.

}

float calcularMediaGeral(float alunos[30][2]) // Função para calcular media geral - Natham
{
    int soma = 0, media;
    
    for (int i = 0; i < contagem; i++) {
        soma += alunos[i][1];
    }
    
    media = (float)soma / contagem;
    
    return media;
}

void ExibirAcimaAbaixoMediaGeral(float medias[30][2])
{
    float mediaGeral = calcularMediaGeral(medias);  // Chama a função para calcular a média geral

    if (mediaGeral > 0) 
    {
        printf("\nA média geral das notas é: %.2f\n", mediaGeral);

        // Exibe alunos acima da média
        printf("\nAlunos acima da média:\n");
        for (int i = 0; i < 30; i++) {
            if (medias[i][0] != 0 && medias[i][1] > mediaGeral) {
                printf("Aluno ID: %.0f - Média: %.2f\n", medias[i][0], medias[i][1]);
            }
        }

        // Exibe alunos abaixo da média
        printf("\nAlunos abaixo da média:\n");
        for (int i = 0; i < 30; i++) {
            if (medias[i][0] != 0 && medias[i][1] < mediaGeral) {
                printf("Aluno ID: %.0f - Média: %.2f\n", medias[i][0], medias[i][1]);
            }
        }
    }
    else
    {
        printf("Nenhum aluno foi registrado.\n");
    }
}

int main()
{
   registrarAlunos();
   calcularMedia();
   ExibirNota(medias);
   ExibirAcimaAbaixoMediaGeral(medias);
}
