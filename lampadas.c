#include <stdio.h> // Biblioteca padr�o para entrada e sa�da de dados
#include <locale.h> // Biblioteca que permite a inser��o da fun��o setlocale no programa, o que permitir� adaptar a linguagem para Portugu�s
#include <math.h> // Biblioteca contendo fun��es para opera��es matem�ticas
void CalculaArea(float *area, float *comprimento, float *largura) // Fun��o que ir� calcular e retornar a �rea do c�modo baseada em sua largura e comprimento
{
 float c = *comprimento, l = * largura;
 *area = c * l;
}
float Lampadas(int tipo, float area) /* Fun��o que ir� determinar a pot�ncia por metro quadrado de �rea que ser� usada para o c�lculo de n�mero de l�mpadas
de acordo com o tipo do c�modo e a �rea do mesmo, ao final da fun��o ser� retornado o n�mero de l�mpadas de 60W de pot�ncia necess�rias para o c�modo */
{
 // Vari�veis da fun��o "Lampadas"
 float x;
 int potencia;
 
 switch (tipo) // Estrutura de decis�o "switch/case" que ir� usar o valor que foi inserido na vari�vel "tipo" para realizar os c�lculos da fun��o "Lampadas"
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
 potencia = 0; // Caso o tipo digitado esteja fora do intervalo especificado, a pot�ncia ser� de 0W, impossibilitando o c�lculo
 }
 
 x = (area * potencia) / 60; // C�lculo para adquirir o n�mero aproximado de l�mpadas de 60W
 return x;
}
int main() // Fun��o principal
{
 setlocale(LC_ALL, "Portuguese"); /* Fun��o que far� com que o programa seja adaptado ao idioma portugu�s, fazendo com que sejam aceitos caracteres especiais e acentua��o
 nos coment�rios e nos c�digos do programa. Para que a fun��o funcione no Visual Studio Code, � necess�rio ir no canto inferior direito do programa, clicar em "UTF-8",
 em seguida em "Reabrir com codifica��o" e clicar em "Western (ISO 8859-
1)", feito isso, basta apertar Ctrl + Z caso necess�rio */
 struct
 {
 int tipo;
 float comprimento, largura;
 }comodo; // Struct de nome "comodo" que ir� armazenar o tipo, a largura e o comprimento do c�modo
 
 float area; // Vari�vel que receber� o valor retornado pela fun��o "CalculaArea"
 float Numerodelampadas; // Vari�vel que receber� o valor retornado pela fun��o "Lampadas"
 
 printf("\nDigite o tipo de c�modo (0, 1, 2, 3 ou 4):"); // Tipo de c�modo que ser� digitado pelo usu�rio via teclado
 scanf_s("%i", &comodo.tipo);
 
 while (comodo.tipo != -1) // Estrutura de repeti��o "while" que ser� interrompida apenas quando o tipo de c�modo digitado pelo usu�rio for -1
 {
 // Largura e comprimento do c�modo que ser�o digitados pelo usu�rio via teclado
 printf("Digite o comprimento do c�modo em metros:");
 scanf_s("%f", &comodo.comprimento);
 
 printf("Digite a largura do c�modo em metros:");
 scanf_s("%f", &comodo.largura);
 
 
 CalculaArea(&area, &comodo.comprimento, &comodo.largura);
 Numerodelampadas = Lampadas(comodo.tipo, area);
 
 // Impress�o da �rea do c�modo e da quantidade de l�mpadas necess�rias, a quantidade ser� arredondada para cima atrav�s da fun��o "ceil"
 printf("\n�rea do c�modo:%0.2f metros quadrados\n", area);
 printf("De acordo com a �rea e o tipo do c�modo, ser�o necess�rias %0.0f l�mpadas de 60W de pot�ncia\n", ceil(Numerodelampadas));
 
 printf("\nDigite o tipo de c�modo (0, 1, 2, 3 ou 4):");
 scanf_s("%i", &comodo.tipo);
 }
 return 0;
}