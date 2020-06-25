#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void DesenhaForca(int vida);
void Cabecalho(void);

int main(){

    system("COLOR 2"); //muda a cor da fonte para verde
    setlocale(LC_ALL,"Portuguese"); //Deixa a linguegem em português

    char palavra[25], lacuna[25], letra,opcao=0,erro[7],dica[25];
    int i, tamanho, acertos=0, vida=6,acertou=0,contErro=0;
    
    do{
		vida=6;
		acertos=0;
		contErro=0;
    	opcao=0;
    	system("cls");
    	Cabecalho();
    	printf("\t\t\t\t1 - JOGAR\n\t\t\t\t2 - COMO JOGAR\n\t\t\t\t3 - CREDITOS\n\t\t\t\t4 - SAIR\n");
		scanf("%d",&opcao);
		
		while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4){
			Cabecalho();
			system("cls");
			printf("1 - JOGAR\n2 - COMO JOGAR\n3 - CREDITOS\n4 - SAIR\n");
			scanf("%d",&opcao);
		}
		
		switch(opcao){
			

			
			case 1:

				system("cls");
				Cabecalho();
			    for(i=0;i<7;i++){
			    	erro[i] = ' ';
				}
			
			    //Lê a palavra secreta
			    printf("Digite a palavra secreta: ");
			    scanf("%s",palavra); 
			    
			    printf("Digite uma dica: ");
			    scanf("%s",dica);
			
			    //armazena o tamanho da palavra digitada
			    tamanho = strlen(palavra);
			
			    //define os traços com o numero de letras da palavra
			    for(i=0;i<=tamanho;i++){
			
			        lacuna[i]='_';
			    }												
			
			    //inicia o laço de reptição do jogo
			    do{
			        system("cls");
			        
			        //imprime a quantidade de vidas restantes
			        printf("\t\t\t\t\t\t\t\t        Vidas:%d \n\n",vida);
			        
			        printf("\t\t\t\t");
			        for(i=0;i<strlen(dica);i++){
			        	printf("%c",dica[i]);
					}
					
			        printf("\n");
			        
					DesenhaForca(vida); //desenha a forca
			
			
			
			        //imprime os traços
			        printf("\t\t\t\t");
			        for(i=0;i<tamanho;i++){	
			            printf("%c ",lacuna[i]);
			        }
			
			
			        
			        //imprime as letras erradas já chutadas
			        printf("\n\n\t\t\tLetras já chutadas\n");
			        printf("\t\t\t");
			        for(i=0;i<7;i++){
			    		printf("%c ",erro[i]);
					}
			
			
					printf("\n\n");
			
			        //Lê a letra chutada pelo player
			        printf("\nDigite uma letra: ");
			        letra = getche(); 
			        getche();
			        acertou=0;
			
			
			
			
			        //testa se a letra digitada pertence à palavra
			        for(i=0;i<tamanho;i++){
			
			            if(letra==palavra[i]){
			
			                lacuna[i]=letra;
			                acertou++;
			            }
			        }
			
			
			
			        //verifica se o usuario acertou a tentativa
			        if(acertou==0){
			            vida--;
			            contErro++;
			            
			            //armazena as letras erradas
			            for(i=0;i<7;i++){
			            	erro[contErro-1] = letra;
						}
						
						printf("\n\nErrou!\n\n\n\n\n");
						system("Pause");
			            
			        }else{ 
			            acertos += acertou;
			        }
			
			
			
					
				    }while(vida > 0 && acertos < tamanho);
				    
				    system("cls");
				    
				    if(acertos >= tamanho){
				    	
				    	//imprime a mensagem de vitória caso o jogador tenha ganho o jogo
				    	printf("\n\n\n\t\t\tParabéns! Você ganhou!\n\n");
				    	printf("\n\t\t\t");
				    	for(i=0;i<tamanho;i++){
				    		printf("%c", palavra[i]);
						}
						
						getche();
					}else{
						
						//imprime a mensagem de derrota
						printf("Enforcado!\n\n");
						printf("A palavra era: ");
						
						for(i=0;i<tamanho;i++){
							printf("%c",palavra[i]);
						}
						
						printf("\n\n");
						DesenhaForca(vida);
						getche();
					}
					vida=6;
					acertou=0;
					contErro=0;
					break;
				
				case 2:
					system("cls");
					Cabecalho();
					printf("O jogo da forca é um jogo em que o jogador tem que \nacertar qual é a palavra proposta, tendo como dica o número de letras e o \ntema ligado à palavra. \nA cada letra errada, é desenhada uma parte do corpo do enforcado. \nO jogo termina ou com o acerto da palavra ou com o término do \npreenchimento das partes corpóreas do enforcado.");
					printf("\n\nDigite a palavra secreta sem que o outro jogador veja. Digite a dica para ajudá-lo a acertar a palavra durante o jogo.\n\n\n\n");
					system("pause");
					break;	
				
				case 3:
					system("cls");
					Cabecalho();
					printf("Jogo da forca");
					printf("\n\nDesenvolvido por Roberto Kubiak Junior\n\nTrabalho para disciplina de Algoritmos e Linguagem C \nsolicitado pela prof. Rosemari Rattmann\n\n\n");
					system("pause");
					break;
					
				case 4:
					system("cls");
					break;
		}	}

	while(opcao!=4);
    return 0;

}


void DesenhaForca(int vida){
	
		printf("\t\t\t\t  _______       \n");
		printf("\t\t\t\t |/      |      \n");
		printf("\t\t\t\t |       %c  \n", (vida<6?'0':' '));
		printf("\t\t\t\t |      %c%c%c   \n", (vida<4?'/':' '), (vida<5?'|':' '), (vida<3?'\\': ' '));
		printf("\t\t\t\t |       %c     \n", (vida<5?'|':' '));
		printf("\t\t\t\t |      %c %c   \n", (vida<2?'/':' '), (vida<1?'\\':' '));
		printf("\t\t\t\t |              \n");
		printf("\t\t\t\t_|___           \n");
		printf("\n\n");
	
}

void Cabecalho(void){
	
	printf("Algoritmos e linguagem C\t   JOGO DA FORCA\t   Roberto Kubiak Junior\n\n\n\n");
}




