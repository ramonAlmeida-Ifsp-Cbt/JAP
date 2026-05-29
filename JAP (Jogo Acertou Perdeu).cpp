/* IFSP - Campus Cubatão/SP
* Curso: Técnico em Automação Industrial
* turma: CTA: 271 - noturmo / ano 2026
* Disciplina: CBTPROG - Programação
* Aluno: Ramon Matheus Costa Almeida (matrícula: cb3042847)
* #####################################################################################
*/

/* JOGO: "Acertou, perdeu"
*######################################################################################
*##Regras: ############################################################################
*##
*##
*## 1) Quantidade de jogadores: mínima 2, máxima 5.
*##
*## 2) Será fornecido um número oculto e aleatório, dentro dos limites: maior 1 e menor que 100; ou seja, 
*##		os jogadores não saberão qual número escolhido é esse.
*##
*## 3) O jogador que adivinhar qual é esse número, perde. E o jogo acaba.
*##
*## 4) No início do jogo, cada jogador em seu turno terá que "chutar" um valor/ adivinhar esse valor
*##		informando via teclado um número dentro do limite inicial (vide no item 2).
*##
*## 5) A cada valor informado, o limites máx e mín. serão alterados, tendendo ao valor oculto/ de modo a
*##		se aproximar do valor oculto.
*##
*## 6) Durante o turno do jogador, se o número informado por ele for igual ao valor oculto,
*##		(conforme o item 3) será retornado a mensagem "Você perdeu", e o jogo/ programa será encerrado.
*##
*## 7) O turno do jogador dura até o momento em que ele informa um número dentro do limite vigente.
*##		Assim que ele informa um número válido , o turno dele se encerrado e o turno do próximo
*##		jogador se inicia.
*## 
*## 8) Quando o turno de todos os jogadores terminar, enquanto nenhum deles acertar qual é o valor oculto,
*##		será repetido os turnos dos jogadores, começando novamente do primeiro ao último jogador,
*##		como um ciclo sem fim, até que um jogador acerte o valor oculto.
*##
*## 9) O valor oculto será gerado de forma randômica/ aleatória, via código. Conforme o item 2,
*##		os jogadores não devem saber qual número foi escolhido.
*## 
*## 10) Em cada turno, se o jogador informar um valor fora do limite:
*##		a. Na primeira vez, informe a mensagem "valor fora do limite, Digite novamente um número"...
*##		b. Na segunda vez seguida, informe a mensagem "Você digitou novamente um valor fora do limite, Digite novamente um número"...
*##		c. Na terceira vez seguida, informe a mensagem 
*###
*#####
*###################################################################################### 
*/


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv)
{
	// I - Declaração de variáveis
	string jogador[5]; //armazenará os nomes dos jogadores
	int qtde_jogadores = 0; // guardará a quantidade de jogadores
	int contador = 0;
	int oculto = 0;
	int vez = 0;
	
	//Colocando nomes genericos dentro do vetor de nomes
	for (int i = 0; i < 5; ++i)
	{
		 jogador[i] = "Jogador " + to_string(i + 1);
	}
//___________________________________________________________________________________			
	
	// II - solicita a quantidade de jogadores
	do
	{
		cout<<"Informe a quantidade de jogadores: ";
		cin>> qtde_jogadores;
		
		if(qtde_jogadores <2 || qtde_jogadores >5)
		{
			cout<<"Quantidade invalida.\n";
		}
	}
	while(qtde_jogadores <2 || qtde_jogadores >5);

	
	
		/* ******************************************************************************************
		//--------(codigo - Manutencao) verificando os nomes dos jogadores -------------
		
		cout<<"\\n#### Exibindo os nomes dos jogadores ####"<<endl;
		
		for (int i = 0; i < qtde_jogadores; i++)
		{
			 cout<<i + 1<<" - "<<jogador[i]<<endl;
		}
		********************************************************************************************
		*/
	
	// III - solicita a identificação/ nome dos jogadores


	int escolherNomes_temp = 0;
	
	cout << "\n---- Digite o numero da opcao desejada ----"<<endl;
	cout << "\nDeseja dar nome os jogadores? (1 - Sim/ 2 - Nao) -> ";
	cin >> escolherNomes_temp;
	
	if(escolherNomes_temp == 1)
	{
		do
		{
			cout<<"Nome do jogador "<< contador + 1 <<" -> ";
			cin>>jogador[contador];
			
			++contador;
		}
		while(contador < qtde_jogadores);
		
		contador = 0;
	}

	// IV - 
	
		 srand (time(NULL));
	 	 oculto = rand() % 100;

	
	// ####### Fim de Jogo ########
	cout <<" ###### Fim de Jogo ######.";
	
	return 0;
}