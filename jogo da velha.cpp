//Jogo da velha de W�lisson:

#include <stdio.h>
#include <locale.h>

	//Tutorial de como funciona uma matriz 3x3:
//	for(int i = 0; i < 3; i++){
//		for(int j = 0; j < 3; j++){
//			printf("I = %d J = %d\t", i, j);
//		}
//		printf("\n");
//	}

int main(){
	setlocale(0, "Portuguese");
	char matriz[3][3] = {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	};
	
	int jogada_Linha, jogada_Coluna, placarA, placarB, vencedor = 0;
	char jogador1[50], jogador2[50], contra, opcao;
	char continuar = 's';
	char simbolo = 'X';
	
	printf("Seja bem-vindo ao jogo da velha!\n");
	printf("---------------------------------\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("\t*", i, j);
		}
		printf("\n\n");
	}
	printf("---------------------------------\n");

	do{
		printf("O que voc� deseja fazer?\n");
		printf("1- Jogar;\n2- Ver Ranking;\n3- Cr�ditos;\n4- Sair.\n");
		scanf("%d", &opcao);
		getchar();
		switch (opcao){
			case 1:
				printf("Contra quem voc� deseja jogar? jogador:(p) m�quina:(m)\n");
				scanf("%c", &contra);
//				getchar();
				switch (contra){
					case 'p':
						//Pegando os nomes dos jogadores:
						printf("Digite o nome do 1� jogador (X):\n");
						scanf("%s", jogador1);
						printf("Digite o nome do 2� jogador: (O)\n");
						scanf("%s", jogador2);
						
						do{ //La�o de repeti��o que s� finaliza quando tiver um vencedor
							printf("Digite a posi��o na qual deseja jogar (ex: 0 2 [linha e coluna])");
							scanf("%d %d", &jogada_Linha, &jogada_Coluna);
							getchar();
							matriz[jogada_Linha][jogada_Coluna] = simbolo;
							if(simbolo == 'X'){
								simbolo = 'O';
							} else{
								simbolo = 'X';
							}
								for(int i = 0; i < 3; i++){
									for(int j = 0; j < 3; j++){
										if (matriz[i][j] == ' '){
											printf("\t*");
										}else{
											printf("\t%c", matriz[i][j]);
										}
									}
									printf("\n\n");
								}
								
							// Verifica linhas e colunas caso o jogador 1 tenha vencido
						    for (int i = 0; i < 3; i++) {
						        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != ' ') {
						             // Linha completa
						            if(matriz[i][0] == 'X'){
						            	vencedor = 1;
									}else if(matriz[i][0] == 'O'){
										vencedor = 2;
									}else{
										vencedor = 4;
									}
						            
						        }
						        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != ' ') {
						            // Coluna completa
						            if(matriz[0][i] == 'X'){
						            	vencedor = 1;
									}else if(matriz[0][i] == 'O'){
										vencedor = 2;
									}else{
										vencedor = 4;
									}
						        }
						    }
						
						    // Verifica diagonais
						    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != ' ') {
						        // Diagonal principal
						        if(matriz[0][0] == 'X'){
						        	vencedor = 1;
						        	placarA++;
								}else if(matriz[0][0] == 'O'){
									vencedor = 2;
									placarB++;
								}else{
									vencedor = 4;
								}
						    }
						    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != ' ') {
						        // Diagonal secund�ria
						        if(matriz[0][2] == 'X'){
						        	vencedor = 1;
						        	placarA++;
								}else if(matriz[0][2] == 'O'){
									vencedor = 2;
									placarB++;
								}else{
									vencedor = 4;
								}
						    }

						} while (vencedor == 0);
						break;
					case 'm':
						printf("Digite o seu nome, jogador:\n");
						scanf("%s", jogador1);
						break;
					default:
						printf("Valor inv�lido!\n");
				}
				break;
			case 2:
				//OPC��O DE VER RANKING
				//USAR AS VARI�VEIS: placarA e placarB para mostrar a pontua��o
				break;
			case 3:
				//OP��O DE CR�DITOS
				break;
			case 4:
				//OP��O DE SAIR
				printf("Obrigado por jogar, at� mais!\n");
				continuar = 'n';
				break;
			default:
				printf("Digite uma op��o v�lida");
		}
			
		getchar();
		
		
		switch (vencedor){
		case 1:
			printf("Parab�ns, %s. Voc� venceu!!\n", jogador1);
			break;
		case 2:
			printf("Parab�ns, %s. Voc� venceu!!\n", jogador2);
			break;
		case 3:
			printf("A m�quina venceu!\n");
			break;
		case 4:
			printf("Essa n�o, deu velha!\n");
			break;
		default:
			printf("Jogo finalizado.\n");
		}
		
		printf("Desja continuar? (s/n): ");
		scanf("%c", &continuar);
		
	} while (continuar == 's' || continuar == 'S');
		
	
}
