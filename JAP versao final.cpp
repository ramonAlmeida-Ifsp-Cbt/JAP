/* IFSP - Campus Cubatão/SP
 Curso: Técnico em Automação Industrial
 turma: CTA: 271 - noturmo / ano 2026
 Disciplina: CBTPROG - Programação
 Aluno: Ramon Matheus Costa Almeida (matrícula: cb3042847)
*/

/*## JOGO: "ACERTOU, PERDEU #########
 ####################################			
###
##
## REGRAS:
##
## 1) Quantidade de jogadores: mínima 2, máxima 5.
##______________________________________________________________________________________________________
## 2) Será fornecido um número oculto e aleatório, dentro dos limites: maior 1 e menor que 100; ou seja, 
##		os jogadores não saberão qual número escolhido é esse.
##______________________________________________________________________________________________________
## 3) O jogador que adivinhar qual é esse número, perde. E o jogo acaba.
##______________________________________________________________________________________________________
## 4) No início do jogo, cada jogador em seu turno terá que "chutar" um valor/ adivinhar esse valor
##		informando via teclado um número dentro do limite inicial (vide no item 2).
##______________________________________________________________________________________________________
## 5) A cada valor informado, o limites máx e mín. serão alterados, tendendo ao valor oculto/ de modo a
##		se aproximar do valor oculto.
##______________________________________________________________________________________________________
## 6) Durante o turno do jogador, se o número informado por ele for igual ao valor oculto,
##		(conforme o item 3) será retornado a mensagem "Você perdeu", e o jogo/ programa será encerrado.
##______________________________________________________________________________________________________
## 7) O turno do jogador dura até o momento em que ele informa um número dentro do limite vigente.
##		Assim que ele informa um número válido , o turno dele se encerrado e o turno do próximo
##		jogador se inicia.
##______________________________________________________________________________________________________ 
## 8) Quando o turno de todos os jogadores terminar, enquanto nenhum deles acertar qual é o valor oculto,
##		será repetido os turnos dos jogadores, começando novamente do primeiro ao último jogador,##		como um ciclo sem fim, até que um jogador acerte o valor oculto.
##______________________________________________________________________________________________________
## 9) O valor oculto será gerado de forma randômica/ aleatória, via código. Conforme o item 2,
##		os jogadores não devem saber qual número foi escolhido.
##______________________________________________________________________________________________________ 
## 10) Em cada turno, se o jogador informar um valor fora do limite:
##		a. Na primeira vez, informe a mensagem "valor fora do limite, Digite novamente um número"...
##		b. Na segunda vez seguida, informe a mensagem "Você digitou novamente um valor fora do limite, Digite novamente um número"...
###		c. Na terceira vez seguida, informe a mensagem 
#####
###################################################################################### 
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv)
{
	int oculto = 0;
	int li = 0; 
	int ls = 0; 
	int vez = 0; 
	int palpite = 0;
	int qtde = 0;
	
	int erro_palpites = 0; //usado p/ contar a qtde. de palpites fora dos limites.
	
//* (aluno) [I - GUARDAR NOMES DOS JOGADORES] **********************************	
	//Vetor jogador[] guardará os nomes dos jogadores
	//Iniciando vetor c/ nomes genéricos.
	string jogador[] 
	{
	"Jogador 1",
	"Jogador 2", 
	"Jogador 3", 
	"Jogador 4", 
	"Jogador 5"
	};
	
	int escolherNome = 2; //por definição 2, porque -> Opção 1: Definir nomes, opção 2: Sair.
	
	cout<<"### JOGO: ACERTOU, PERDEU ###\n";
	cout<<"\nLimite de Jogadores: \n* min. 2\n* max. 5"<<endl;
	
//##############################################################################			
		
	// Inicializa os limites e a vez
	li = 1;
    ls = 100;
    vez = 1;
    
	// [II - QUANTIDADE DE JOGADORES]
	do
	{
		cout<<"\nQuantos jogadores vao participar? (2..5): ";
		cin>> qtde; //recebe via teclado a quantidade de jogadores
		
		if(qtde <2 || qtde >5)
		{
			cout<<"\n<!> Quantidade invalida\n";
		}
	}
	while(qtde <2 || qtde >5);


//******************************************************************************	
	//(aluno)[III - IDENTIFICAÇÃO DOS JOGADORES].
	do
	{
		cout << "\nDeseja dar nome os jogadores? (1 - Sim/ 2 - Nao) -> ";
		cin >> escolherNome;
		
		//por definição -> Opção 1: Definir nomes, opção 2: Sair (fica os nomes genéricos).		
		if(escolherNome == 1)
		{
			do
			{
				cout<<"Nome do jogador "<< vez <<" -> ";
				cin>>jogador[(vez-1)]; //é feito o decremento temporário pois: vetor 'jogador[0-4]' e variável 'vez'(de 1 a 5)
				
				++vez; // Alterando do Jogador 1 ao 5
			}
			while(vez <= qtde);
			
			vez = 1; //volta a vez p/ o Jogador 1 antes de começar o jogo
		}
		else
		{
			if(escolherNome <1 || escolherNome > 2)
			{
				cout<<"\n<!> Opcao invalida.\n";
			}
			else
			{
				//Exibe os nomes dos jogadores 
				cout<<"\n[JOGADORES]\n__________\n";
				
				for (int i = 0; i < qtde; i++)
				{
					 cout<<jogador[i]<<endl;
				}
				
				cout<<"__________\n";
			}
		}

		//(Manutenção) Exibir conteúdo da variável 'escolherNome'.
		//cout<<"\n(Manutenção)Exibir *EscolherNome* = "<<escolherNome; 
		
		/* cout<<"\\n(Manutencao) Exibindo os nomes dos jogadores"<<endl;
		
		for (int i = 0; i < qtde; i++)
		{
			 cout<<i + 1<<" - "<<jogador[i]<<endl;
		}
		*/
	}
	while(escolherNome <1 || escolherNome > 2);
	
//##############################################################################
	
// [IV - GERANDO VALOR OCULTO]
	srand (time(NULL)); // "semeando" um valor aleatório com base na data e hora atual.
	oculto = rand() % 100;// gerando um valor aleatório.
	
	//(Manutenção) cout<<"\n oculto: "<<oculto<<endl;
	
	// [V - INÍCIO DO JOGO]	
	cout<<"\n[INICIO DO JOGO]\n";

	 // Representa o LOOPING principal do programa
	 
    do
    {
    	// Entra com o palpite
		do
	    { 
   	        cout << jogador[vez-1]<< ", informe numero entre " << li << " e " << ls << ": ";
 	        cin >> palpite;
 	        
 	        //[VI - ERRO DE PALPITE]
 	        
 	        //(aluno) Avisa ao jogador que o palpite está errado/ fora dos limites
			 if (palpite <= li || palpite >= ls)
			 {
			 	++erro_palpites;// conta a qtde de erros de palpite
			 	
			 	switch(erro_palpites)
			 	{
					   case 1:
					   	cout<<"\n<!> Palpite invalido.\n";
					   	break;
					   case 2:
					   	cout<<"\n<!> Palpite continua invalido. Preste atencao no intervalo.\n";
					   	break;
					   case 3:
					   	cout<<"\n<!> Sem condicao. Voce nao tem condicao de continuar participando. Voce perdeu!\n";
					   	//atribuído o valor de oculto ao 'palpite' p/ sair do looping,...
					   	//... e exibir a mensagem de que esse jogador perdeu.
						   palpite = oculto; 
					   	break;
					   default:
					   	cout<<"\n<!> Erro. O jogo será encerrado.\n";
					   	palpite = oculto;// foi colocado dessa forma p/ sair do looping...
					   	break;
				}
			 } 
     	}
     	while (palpite <= li || palpite >= ls);
//******************************************************************************
//(aluno) [VII - RESET NO CONTADOR DE ERROS DO PALPITE

     	//Se ainda há como continuar o  jogo (palpite não é igual ao oculto)...
     	//...zera o contador de erros;
     	if (palpite != oculto)
		 {
     		erro_palpites = 0;
		 }
//##############################################################################
     	
     	// Verifica o palpite e ajusta os limites / Fim de jogo
     	if (palpite < oculto)
		 {
		 	// Ajusta Limite inferior
		 	li = palpite;
		 }
		 else
		 {
			 if (palpite > oculto)
			 {
			 	// Ajusta Limite superior
			 	ls = palpite;
			 }
			 else
			 {
  		 	     // Informa que perdeu			 	
				 cout << "\n-> Parabens " << jogador[vez-1]<< ", voce perdeu!!!" << endl;
			 }
		 }
		 
       vez = vez + 1;
       if (vez > qtde)
	   {
	   	vez = 1;
	   }
	   
	}
	while (palpite != oculto);
	
	// ####### Fim de Jogo ########
	cout <<"\n###### Fim de Jogo ######\n";
	
	return 0;
}