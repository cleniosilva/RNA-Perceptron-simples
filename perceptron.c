#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
/*RNA Perceptron simples
Author CLÊNIO EDUARDO DA SILVA*/
	
int main(){
	int i,j,cont;
	
	//constante de taxa de aprendizado
	double n = 0.5;
	
	//definindo o numero de epocas		
	int maxEpocas = 15;
		
	//matriz de entradas	
	int entradas[4][4] = {{1,0,0,0},{1,0,1,0},{1,1,0,0},{1,1,1,1}};
	//inicialização do vetor de pesos	
	double pesos[3] = {0.0};
		
	int nAmostras = 4;
	
	//iniciando o contandor de epocas
	int nEpocas = 0;
	
	//varicavel de erro	
	int erro;	
	//sinal de ativação
	double sinal;
	
	//linha da matriz
	int linha;
	
	//sinal de saida
	int y;

/*----------------------------iniciando algoritmo de treinamento--------------------------------------------*/	
	do
	{
		//setando a variavel de erros para inexistente
		erro = FALSE;
		cont = 0;
		linha = 0;
	
		
		while(cont < nAmostras)
		{
				sinal = 0;
				//soma ponderada dos pesos
				for(i=0;i < 3;i++){
					
					sinal = sinal + entradas[linha][i] * pesos[i];
					
				}					
				//função de ativação
				if(sinal <= 0)
				{
					y = 0;					
				}					
				else 
				{
				
					y = 1;
				} 
				
					
					//verifica a saida para atualização dos pesos
					if(y != entradas[linha][3])
					{
						
						for(j = 0;j < 3;j++)
						{
							pesos[j] = pesos[j] + n * (entradas[linha][3] - y)*entradas[linha][j];
							//printf("imprimindo o peso atualizado = %lf\n",pesos[j]);
							erro = TRUE;
						}
					}
					
					cont++;
				linha = cont;//incrementando a linha da matriz de entradas
		}
			nEpocas++;
			
			printf("Numero de epocas = %d\n",nEpocas);			
			//voltando a linha para a primeira linha de entradas
		
			if(linha == 3)
				linha = 0;
		
	}while(erro == TRUE && nEpocas <= maxEpocas );
	
	/*-------------------------------------------fim do algoritmo de treinamento----------------------------------------*/
	
	if(erro == FALSE)
	{	
		printf("\nRede Treinada com %d epocas\n",nEpocas);
		printf("Imprimindo os Pesos da rede ja treinada\n");
		
		for(i=0;i<3;i++)
			printf("%lf\n",pesos[i]);
		
		
		
	}
	else if(nEpocas >= maxEpocas)
		printf("\nEstouro do Numero de epocas! Rede nao treinou\n");
		
	
	
	return 0;
}


