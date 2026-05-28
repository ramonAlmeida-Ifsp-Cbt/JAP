#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


	/* Jogo: Solicita-se um número dentro de um intervalo
	*
	* 1) um jogador neutro: "Informe um número entre 1 e 100.
	* 2) fazer um tratamento p/ garantir que o jogador neutro digite um valor dentro do intervalo.
	*/	

	
int main(int argc, char** argv)
{
	
	int oculto = 0;
	int limiteInferior;
	int limiteSuperior;
	int vez;
	int palpite;
	//----------------//
	
	 srand (time(NULL));
	 oculto = rand() % 100;  	
	//---- Consistência -> GARANTIR DIGITAÇÃO DE NÚMERO ENTRE 1 E 100 -----//
	do
	{
		cout<<"Jogador neutro, informe um numero entre 1 e 100: ";
		cin>>oculto;
	}
	while(oculto<=1 || oculto>=100);

	//começo do jogo
	
	
	
	return 0;
}