#include <stdio.h> // Biblioteca padrão para entrada e saída de dados
#include <locale.h> // Biblioteca que permite a inserção da função setlocale no programa, o que permitirá adaptar a linguagem para Português
#include <math.h> // Biblioteca contendo funções para operações matemáticas
void CalculaArea(float *area, float *comprimento, float *largura) // Função que irá calcular e retornar a área do cômodo baseada em sua largura e comprimento
{
 float c = *comprimento, l = * largura;
 *area = c * l;
}
float Lampadas(int tipo, float area) /* Função que irá determinar a potência por metro quadrado de área que será usada para o cálculo de número de lâmpadas
de acordo com o tipo do cômodo e a área do mesmo, ao final da função será retornado o número de lâmpadas de 60W de potência necessárias para o cômodo */
{
 // Variáveis da função "Lampadas"
 float x;
 int potencia;
 
 switch (tipo) // Estrutura de decisão "switch/case" que irá usar o valor que foi inserido na variável "tipo" para realizar os cálculos da função "Lampadas"
 {
 case 0:
 potencia = 12;
 break;
 
 case 1:
 potencia = 15;
 break;
 
 case 2:
 potencia = 18;
 break;
 
 case 3:
 potencia = 20;
 break;
 
 case 4:
 potencia = 22;
 break;
 
 default:
 potencia = 0; // Caso o tipo digitado esteja fora do intervalo especificado, a potência será de 0W, impossibilitando o cálculo
 }
 
 x = (area * potencia) / 60; // Cálculo para adquirir o número aproximado de lâmpadas de 60W
 return x;
}
int main() // Função principal
{
 setlocale(LC_ALL, "Portuguese"); /* Função que fará com que o programa seja adaptado ao idioma português, fazendo com que sejam aceitos caracteres especiais e acentuação
 nos comentários e nos códigos do programa. Para que a função funcione no Visual Studio Code, é necessário ir no canto inferior direito do programa, clicar em "UTF-8",
 em seguida em "Reabrir com codificação" e clicar em "Western (ISO 8859-
1)", feito isso, basta apertar Ctrl + Z caso necessário */
 struct
 {
 int tipo;
 float comprimento, largura;
 }comodo; // Struct de nome "comodo" que irá armazenar o tipo, a largura e o comprimento do cômodo
 
 float area; // Variável que receberá o valor retornado pela função "CalculaArea"
 float Numerodelampadas; // Variável que receberá o valor retornado pela função "Lampadas"
 
 printf("\nDigite o tipo de cômodo (0, 1, 2, 3 ou 4):"); // Tipo de cômodo que será digitado pelo usuário via teclado
 scanf_s("%i", &comodo.tipo);
 
 while (comodo.tipo != -1) // Estrutura de repetição "while" que será interrompida apenas quando o tipo de cômodo digitado pelo usuário for -1
 {
 // Largura e comprimento do cômodo que serão digitados pelo usuário via teclado
 printf("Digite o comprimento do cômodo em metros:");
 scanf_s("%f", &comodo.comprimento);
 
 printf("Digite a largura do cômodo em metros:");
 scanf_s("%f", &comodo.largura);
 
 
 CalculaArea(&area, &comodo.comprimento, &comodo.largura);
 Numerodelampadas = Lampadas(comodo.tipo, area);
 
 // Impressão da área do cômodo e da quantidade de lâmpadas necessárias, a quantidade será arredondada para cima através da função "ceil"
 printf("\nÁrea do cômodo:%0.2f metros quadrados\n", area);
 printf("De acordo com a área e o tipo do cômodo, serão necessárias %0.0f lâmpadas de 60W de potência\n", ceil(Numerodelampadas));
 
 printf("\nDigite o tipo de cômodo (0, 1, 2, 3 ou 4):");
 scanf_s("%i", &comodo.tipo);
 }
 return 0;
}