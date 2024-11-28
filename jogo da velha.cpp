//Jogo da velha:

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
	
	int jogada_Linha, jogada_Coluna, placarA, placarB = 0, vencedor = 0;
	char contra, opcao;
	char jogador1[50] = " ";
	char jogador2[50] = " ";
	char continuar = 's';
	char simbolo = 'X';
	srand(time(NULL));
	
	printf("Seja bem-vindo ao jogo da velha!\n");
	printf("---------------------------------\n");
	for(int i = 0; i < 3; i++){
//		printf("%d", i); //colunas
		for(int j = 0; j < 3; j++){
			printf("\t*");
		}
		printf("\n\n");
	}
	printf("---------------------------------\n");

	do{
		printf("O que você deseja fazer?\n");
		printf("1- Jogar;\n2- Ver Ranking;\n3- Créditos;\n4- Sair.\n");
		scanf("%d", &opcao);
		getchar();
		switch (opcao){
			case 1:
				printf("Contra quem você deseja jogar? jogador:(p) máquina:(m)\n");
				scanf("%c", &contra);
//				getchar();
				switch (contra){
					case 'p':
						//OPÇÃO DE JOGAR CONTRA OUTRO JOGADOR
						//Reiniciando a matriz (criar uma função para isso depois)
						for (int i = 0; i < 3; i++) {
					        for (int j = 0; j < 3; j++) {
					            matriz[i][j] = ' ';
					        }
					    }
					    vencedor = 0;
						
						if(strcmp(jogador1, " ") == 0 && strcmp(jogador2, " ") == 0){
							//Pegando os nomes dos jogadores:
							printf("Digite o nome do 1º jogador (X):\n");
							scanf("%s", jogador1);
							printf("Digite o nome do 2º jogador: (O)\n");
							scanf("%s", jogador2);
						}
						
						do{ //Laço de repetição que só finaliza quando tiver um vencedor
							printf("É a vez do jogador %c\n", simbolo);
							printf("Digite a posição na qual deseja jogar (ex: 0 2 [linha e coluna])");
							scanf("%d %d", &jogada_Linha, &jogada_Coluna);
							getchar();
							if(matriz[jogada_Linha][jogada_Coluna] != ' '){
								printf("Jogada inválida, tente novamente!\n");
								printf("---------------------------------\n");
							} else{
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
							}
							
							// Verifica linhas e colunas caso o jogador 1 tenha vencido
						    for (int i = 0; i < 3; i++) {
						        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != ' ') {
						             // Linha completa
						            if(matriz[i][0] == 'X'){
						            	vencedor = 1;
						            	placarA++;
									}else if(matriz[i][0] == 'O'){
										vencedor = 2;
										placarB++;
									}else{
										vencedor = 4;
									}
						            
						        }
						        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != ' ') {
						            // Coluna completa
						            if(matriz[0][i] == 'X'){
						            	vencedor = 1;
						            	placarA++;
									}else if(matriz[0][i] == 'O'){
										vencedor = 2;
										placarB++;
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
						        // Diagonal secundária
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
						//OPÇÃO DE JOGAR CONTRA A MÁQUINA (CPU)
						printf("Digite o seu nome, jogador:\n");
						scanf("%s", jogador1);
						strcpy(jogador2, "Máquina");
						for (int i = 0; i < 3; i++) {
					        for (int j = 0; j < 3; j++) {
					            matriz[i][j] = ' ';
					        }
					    }
						do{
							printf("É a vez do jogador %c\n", simbolo);
							printf("Digite a posição na qual deseja jogar (ex: 0 2 [linha e coluna])");
							scanf("%d %d", &jogada_Linha, &jogada_Coluna);
							getchar();
							if(matriz[jogada_Linha][jogada_Coluna] != ' '){
								printf("Este local já está preenchido, tente novamente!\n");
								printf("---------------------------------\n");
							} else{
								matriz[jogada_Linha][jogada_Coluna] = simbolo;
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
							}
							
							// Verifica linhas e colunas caso o jogador 1 tenha vencido
						    for (int i = 0; i < 3; i++) {
						        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != ' ') {
						             // Linha completa
						            if(matriz[i][0] == 'X'){
						            	vencedor = 1;
						            	placarA++;
									}else if(matriz[i][0] == 'O'){
										vencedor = 2;
										placarB++;
									}else{
										vencedor = 4;
									}
						            
						        }
						        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != ' ') {
						            // Coluna completa
						            if(matriz[0][i] == 'X'){
						            	vencedor = 1;
						            	placarA++;
									}else if(matriz[0][i] == 'O'){
										vencedor = 2;
										placarB++;
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
						        // Diagonal secundária
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
						    if(vencedor == 0){
						    	//JOGADA DA MÁQUINA
								do {
							        jogada_Linha = rand() % 3;  // Gera número entre 0 e 2
							        jogada_Coluna = rand() % 3;
							    } while (matriz[jogada_Linha][jogada_Coluna] != ' '); // Repete até encontrar um espaço vazio
								matriz[jogada_Linha][jogada_Coluna] = 'O'; // Máquina joga 'O'
								printf("A máquina jogou %d %d\n", jogada_Linha, jogada_Coluna);
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
							}
						} while (vencedor == 0);
						
						break;
					default:
						printf("Valor inválido!\n");
				}
				break;
			case 2:
				//OPCÇÃO DE VER RANKING
				printf("---------------------------------\n");
				printf("\t   Ranking:\n");
				printf("---------------------------------\n");
				if(strcmp(jogador1, " ") == 0){
					printf("Você ainda não jogou nenhuma partida\n\n");
					continue;
				} else if (strcmp(jogador2, " ") == 0 && strcmp(jogador1, " ") != 0){
					printf("%s: %d pontos\n", jogador1, placarA);
				} else{
					printf("%s: %d pontos\n", jogador1, placarA);
					printf("%s: %d pontos\n", jogador2, placarB);
				}
				break;
			case 3:
				//OPÇÃO DE CRÉDITOS
				    printf("===========================================\n");
				    printf("               DESENVOLVEDORES              \n");
				    printf("===========================================\n");
				    printf("               Wálisson Andrey             \n");
				    printf("               Gabriel Albino              \n");
				    printf("               Samuel David                \n");
				    printf("               Victor Gabriel              \n");
				    printf("===========================================\n");
				    printf("         Obrigado por jogar nosso jogo!     \n");
				    printf("===========================================\n");
				break;
			case 4:
				//OPÇÃO DE SAIR
				printf("Obrigado por jogar, até mais!\n");
				continuar = 'n';
				break;
			default:
				printf("Digite uma opção válida");
		}
			
//		getchar();
		
		switch (vencedor){
		case 1:
			printf("Parabéns, %s. Você venceu!!\n", jogador1);
			break;
		case 2:
			printf("Parabéns, %s. Você venceu!!\n", jogador2);
			break;
		case 3:
			printf("A máquina venceu!\n");
			break;
		case 4:
			printf("Essa não, deu velha!\n");
			break;
		default:
			printf("Jogo finalizado.\n");
		}
		
		printf("Desja continuar? (s/n): ");
		scanf("%c", &continuar);
		
	} while (continuar == 's' || continuar == 'S');
		
	
}
