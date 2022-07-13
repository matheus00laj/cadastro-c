/* ETE Gin�sio Pernambucano
   Recife, 04 de Junho de 2022
   Desenvolvimento de Sistemas 1� M�dulo Turma A
   Desenvolvimento e Aplica��o Desktop
   Professor: Emmanuel
   Alunos: Ezequiel Leandro Jr
           Caio Daniel
           Matheus Jos�
           Nataly Carvalho
           Isabelly Souza
           
   Projeto de Cadastro de pessoas desaparecidas nas enchentes */

//inclus�o das bibliotecas   
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//cria��o do registro de cadastro
typedef struct{
	
	int id;
	char nome[30];
	int idade;
	char genero[3];
	int g;
	char data[10];
	char municipio[15];
	int m;
	char contato[15];
		
} REGISTRO;



//declara��o do ponteiro que armazenar� o endere�o de mem�ria do arquivo
FILE *pRegistro;

//declara��o do registro auxiliar e nulo
REGISTRO cadastro_aux, cadastro_nulo;


//cria��o do procedimento linha
void linha(){
	
	int i;
	
	for(i=1; i <= 120; i++){
		
		printf("_");
	}
	printf("\n");
} 



//cria��o do procedimento cabe�alho
void cabecalho(){
	
	system("cls");
	
	printf("CADASTRO DE PESSOAS DESAPARECIDAS\n");
	
	linha();
}



//procedimento para abrir ou criar arquivo
void abre_arquivo(){
	
	pRegistro = fopen("cadastro.dat", "r+b");
	
	if(pRegistro == NULL)
	{
		pRegistro = fopen("cadastro.dat", "w+b");
	}
}



//procedimento para inserir
void inserir(){
	
	int resp;
	
	do{
		cabecalho();
		
		printf("\n\nCADASTRAR NOVA PESSOA\n\n");
		
		printf("\nN�mero ID (at� 5 d�gitos): ");
		scanf("%d", &cadastro_aux.id);
		
		printf("\nNome e sobrenome (ex ''Ezequiel Magalh�es''): ");
		fflush(stdin);
		gets(cadastro_aux.nome);
		
		printf("\nIdade: ");
		scanf("%d", &cadastro_aux.idade);
		
		printf("\nG�nero <1-Masc 2-Fem>: ");
		scanf("%d", &cadastro_aux.g);
		
		printf("\nData do desaparecimento (exemplo: 17/08/22): ");
		fflush(stdin);
		gets(cadastro_aux.data);
		
		printf("\nMunic�pio:\n");
		printf("1.  Abreu e Lima\n");
		printf("2.  Ara�oiaba\n");
		printf("3.  Cabo de Santo Agostinho\n");
		printf("4.  Camaragibe\n");
		printf("5.  Igarassu\n");
		printf("6.  Ipojuca\n");
		printf("7.  Itamarac�\n");
		printf("8.  Itapissuma\n");
		printf("9.  Jaboat�o dos Guararapes\n");
		printf("10. Moreno\n");
		printf("11. Olinda\n");
		printf("12. Paulista\n");
		printf("13. Recife\n");
		printf("14. S�o Louren�o da Mata\n: ");
		scanf("%d", &cadastro_aux.m);
		
		printf("\nTelefone para contato(ex: 81997655428): ");
		fflush(stdin);
		gets(cadastro_aux.contato);
		
		//if-else para escrever o g�nero
		if(cadastro_aux.g == 1)
		{
			strcpy(cadastro_aux.genero, "Mas");
			
		} else if(cadastro_aux.g == 2)
		  {
		  	strcpy(cadastro_aux.genero, "Fem");
		  	
		  } else
		    {
		    	strcpy(cadastro_aux.genero, "XXX");
			}
		
		//switch para escrever o munic�pio
		switch(cadastro_aux.m){
			
			case 1: strcpy(cadastro_aux.municipio, "Abreu L"); break;
			case 2: strcpy(cadastro_aux.municipio, "Ara�oiaba"); break;
			case 3: strcpy(cadastro_aux.municipio, "Cabo"); break;
			case 4: strcpy(cadastro_aux.municipio, "Camaragibe"); break;
			case 5: strcpy(cadastro_aux.municipio, "Igarassu"); break;
			case 6: strcpy(cadastro_aux.municipio, "Ipojuca"); break;
			case 7: strcpy(cadastro_aux.municipio, "Itamarac�"); break;
			case 8: strcpy(cadastro_aux.municipio, "Itapissuma"); break;
			case 9: strcpy(cadastro_aux.municipio, "Jaboat�o"); break;
			case 10: strcpy(cadastro_aux.municipio, "Moreno"); break;
			case 11: strcpy(cadastro_aux.municipio, "Olinda"); break;
			case 12: strcpy(cadastro_aux.municipio, "Paulista"); break;
			case 13: strcpy(cadastro_aux.municipio, "Recife"); break;
			case 14: strcpy(cadastro_aux.municipio, "SL da Mata"); break;
			default: strcpy(cadastro_aux.municipio, "XXXXX"); break;
			
		}
		
		//comandos de exibi��o de cadastro
		system("cls");
		
		cabecalho();
		
		printf("\n\n");

        linha();
  
        printf("ID             NOME                              IDADE    GENERO    DATA          MUNICIPIO          CONTATO\n");
  
        linha();
  
        printf("%11d    %-30s    %3d    %3s    %10s    %15s    %15s\n", cadastro_aux.id, cadastro_aux.nome, cadastro_aux.idade, cadastro_aux.genero, cadastro_aux.data, cadastro_aux.municipio, cadastro_aux.contato);
  
        linha(); 
        
        printf("\n\nPessoa cadastrada com sucesso!\n\n");
        
        //comando para posicionar o leitor do arquivo
        fseek(pRegistro, 0, SEEK_END);
        
        //comando para gravar o cadastro no arquivo
        fwrite(&cadastro_aux, sizeof(REGISTRO), 1, pRegistro);
        
        //comando para testar a condi��o do/while
        printf("\nDeseja fazer novo cadastro <1-Sim 2-N�o>?: ");
        scanf("%d", &resp);	
		
	} while( resp == 1);
}




//fun��o para procurar um cadastro no arquivo
int procurar(int idP){
	
	int p = 0;
	
	//comando para botar o leitor no inicio do arquivo
	rewind(pRegistro);
	
	//comando para ler o primeiro cadastro do arquivo(o registro do arquivo � atribuido ao "cadastro_aux")
	fread(&cadastro_aux, sizeof(REGISTRO), 1, pRegistro);
	
	//while para retornar a posi��o do cadastro no arquivo
	while(feof(pRegistro) == 0){
		
		if(cadastro_aux.id == idP){
			
			return p;
			
		} else{
			
			fread(&cadastro_aux, sizeof(REGISTRO), 1, pRegistro);
			
			p++;
		}
	}
	
	return -1;
}




//procedimento para mostrar o registro escrito no arquivo, em forma de tabela
void mostrar(int pos){
	
	//comando para por o leitor do arquivo no ponto certo da leitura do cadastro selecionado
	fseek(pRegistro, pos*sizeof(REGISTRO), SEEK_SET);
	
	//comando para ler o cadastro do arquivo(o registro do arquivo � atribuido ao "cadastro_aux")
	fread(&cadastro_aux, sizeof(REGISTRO), 1, pRegistro);
	
	printf("\n\n");
	
	//comando para exibir o cadastro na tela
	linha();
  
    printf("ID             NOME                              IDADE    GENERO    DATA          MUNICIPIO          CONTATO\n");
  
    linha();
  
    printf("%11d    %-30s    %3d    %3s    %10s    %15s    %15s\n", cadastro_aux.id, cadastro_aux.nome, cadastro_aux.idade, cadastro_aux.genero, cadastro_aux.data, cadastro_aux.municipio, cadastro_aux.contato);
  
    linha(); 
	
	
}




//procedimento para consultar cadastro no arquivo
void consultar(){
	
	int resp, ipCon, posicao;
	
	do{
		cabecalho();
		
		printf("\n\nCONSULTAR CADASTRO\n\n\n");
		
		printf("ID: ");
		scanf("%d", &ipCon);
		
		posicao = procurar(ipCon);
		
		if(posicao == -1){
			
			printf("\n\nCadastro n�o encontrado!\n\n");
			
		} else{
			
			mostrar(posicao);
			
		}
		
		printf("\n\nDeseja consultar outro cadastro <1-Sim 2-N�o>?:  ");
		scanf("%d", &resp);
			
	}while(resp == 1);
}




//procedimento para remover um cadastro do arquivo
void remover(){
	
	int idRem, conf, resp, posicao, campo;
	
	cadastro_nulo.idade = 0;
	cadastro_nulo.id = 0;
	
	do{
		cabecalho();
		
		printf("\n\nREMOVER CADASTRO\n\n\n");
		
		printf("ID: ");
		scanf("%d", &idRem);
		
		posicao = procurar(idRem);
		
		if(posicao == -1){
			
			printf("\n\nCadastro n�o encontrado!\a");
			
		}else{
			
			mostrar(posicao);
			
			printf("\n\nDeseja remover o cadastro <1-Sim 2-N�o>?: ");
			scanf("%d", &conf);
			
			if(conf == 1){
				
				fseek(pRegistro, posicao*sizeof(REGISTRO), SEEK_SET);
				
				fwrite(&cadastro_nulo, sizeof(REGISTRO), 1, pRegistro);
				
				printf("\n\nCadastro removido com sucesso!");
				
			} else{
				
				printf("\n\n\nRemo��o cancelada!");
			}
		}
		
		printf("\n\n\nDeseja remover outro cadastro <1-Sim 2-N�o>?: ");
		scanf("%d", &resp);
		
	}while(resp == 1);
}
	


	
	//procedimento para alterar os campos do cadastro
	void alterar(){
		
		int idAlt, conf, resp, posicao, campo;
		
		do{
			cabecalho();
			
			printf("\n\nALTERAR CADASTRO\n\n\n");
			
			printf("Digite o ID do cadastro: ");
			scanf("%d", &idAlt);
			
			posicao = procurar(idAlt);
			
			if(posicao == -1){
				
				printf("\nCadastro n�o encontrado!\a");
				
			}else{
				
				mostrar(posicao);
				
				printf("\n\nQual campo deseja alterar?\n");
				printf("1.ID\n");
				printf("2.Nome\n");
				printf("3.Idade\n");
				printf("4.G�nero\n");
				printf("5.Data do desaparecimento\n");
				printf("6.Munic�pio\n");
				printf("7.Contato\n: ");
				
				scanf("%d", &campo);
				
				switch(campo){
					
					case 1:
					       printf("\n\nDigite o novo ID (at� 5 d�gitos): ");
						   scanf("%d", &cadastro_aux.id);
						   break;
						   
					case 2:
					       printf("\n\nDigite o novo nome e sobrenome (ex ''Ezequiel Magalh�es''): ");
						   fflush(stdin);
						   gets(cadastro_aux.nome);
						   break;
						   
					case 3:
						   printf("\n\nDigite a nova idade: ");
						   scanf("%d", &cadastro_aux.idade);
						   break;
						   
					case 4:
						   printf("\n\nEscolha o novo g�nero <1-Mas 2-Fem>: ");
						   scanf("%d", &cadastro_aux.g);
						   
						   if(cadastro_aux.g == 1){
						   	
						   	     strcpy(cadastro_aux.genero, "Mas");
						   	     
						   } else if(cadastro_aux.g == 2){
						   	 
						   	     strcpy(cadastro_aux.genero, "Fem");
						   }
						   
						   break;
						   
					case 5:
						   printf("\n\nDigite a nova data do desaparecimento (exemplo: 17/08/22): ");
						   fflush(stdin);
						   gets(cadastro_aux.data);
						   break;
						   
					case 6:
						   printf("\n\nNovo munic�pio:\n");
						   printf("1.  Abreu e Lima\n");
	 	                   printf("2.  Ara�oiaba\n");
		                   printf("3.  Cabo de Santo Agostinho\n");
		                   printf("4.  Camaragibe\n");
		                   printf("5.  Igarassu\n");
		                   printf("6.  Ipojuca\n");
		                   printf("7.  Itamarac�\n");
		                   printf("8.  Itapissuma\n");
		                   printf("9.  Jaboat�o dos Guararapes\n");
		                   printf("10. Moreno\n");
		                   printf("11. Olinda\n");
		                   printf("12. Paulista\n");
		                   printf("13. Recife\n");
		                   printf("14. S�o Louren�o da Mata\n: ");
		                   scanf("%d", &cadastro_aux.m);
		                   
		                   switch(cadastro_aux.m){
			
			                 case 1: strcpy(cadastro_aux.municipio, "Abreu L"); break;
			                 case 2: strcpy(cadastro_aux.municipio, "Ara�oiaba"); break;
			                 case 3: strcpy(cadastro_aux.municipio, "Cabo"); break;
			                 case 4: strcpy(cadastro_aux.municipio, "Camaragibe"); break;
			                 case 5: strcpy(cadastro_aux.municipio, "Igarassu"); break;
			                 case 6: strcpy(cadastro_aux.municipio, "Ipojuca"); break;
			                 case 7: strcpy(cadastro_aux.municipio, "Itamarac�"); break;
			                 case 8: strcpy(cadastro_aux.municipio, "Itapissuma"); break;
			                 case 9: strcpy(cadastro_aux.municipio, "Jaboat�o"); break;
			                 case 10: strcpy(cadastro_aux.municipio, "Moreno"); break;
			                 case 11: strcpy(cadastro_aux.municipio, "Olinda"); break;
			                 case 12: strcpy(cadastro_aux.municipio, "Paulista"); break;
			                 case 13: strcpy(cadastro_aux.municipio, "Recife"); break;
			                 case 14: strcpy(cadastro_aux.municipio, "SL da Mata"); break;
			                 default: strcpy(cadastro_aux.municipio, "XXXXX"); break;		
	                     	} break;          
						   		
				}
	
			}
			
			printf("\n\nAltera��o realizada com sucesso!\n");
			
			fseek(pRegistro, posicao*sizeof(REGISTRO), SEEK_SET);
			
			fwrite(&cadastro_aux, sizeof(REGISTRO), 1, pRegistro);
			
			mostrar(posicao);
			
			printf("\n\nDeseja alterar outro cadastro <1-Sim 2-N�o>?: ");
			scanf("%d", &resp);
			
		}while(resp == 1);
		
	}
	
		
	
	//procedimento para listar todos os cadastros do arquivo
	void listagem(){
		
		cabecalho();
		
		printf("\n\nLISTAGEM GERAL\n\n\n");
		
		linha();
		
		printf("ID             NOME                              IDADE    GENERO    DATA          MUNICIPIO          CONTATO\n");
  
        linha();
        
        rewind(pRegistro);
        
        fread(&cadastro_aux, sizeof(REGISTRO), 1, pRegistro);
        
        while(feof(pRegistro) == 0){
        	
        	if(cadastro_aux.id != 0){
        		
        		printf("%11d    %-30s    %3d    %3s    %10s    %15s    %15s\n", cadastro_aux.id, cadastro_aux.nome, cadastro_aux.idade, cadastro_aux.genero, cadastro_aux.data, cadastro_aux.municipio, cadastro_aux.contato);
			}
			
			fread(&cadastro_aux, sizeof(REGISTRO), 1, pRegistro);
		}
		
		linha();
		
		printf("Tecle enter para voltar ao Menu...");
		
		getche();		
		
	}

	



//m�dulo principal
main(){
	
	int op;
	
	//comando para escrever em portugu�s
    setlocale(LC_ALL, "Portuguese");
	
	abre_arquivo();
	
	do{
		cabecalho();
		
		printf("\n\nMENU\n\n\n");
		
		printf("    1- Cadastrar nova pessoa\n\n");
		printf("    2- Remover cadastro\n\n");
		printf("    3- Consultar cadastro\n\n");
		printf("    4- Alterar cadastro\n\n");
		printf("    5- Listagem geral\n\n");
		printf("    0- Sair\n\n");
		
		linha();
		
		printf("\nInforme a op��o desejada: ");
		scanf("%d", &op);
		
		switch(op){
			
			case 1: inserir(); break;
			case 2: remover(); break;
			case 3: consultar(); break;
			case 4: alterar(); break;
			case 5: listagem(); break;
			case 0: fclose(pRegistro); break;
			default: printf("\n\nOp��o inv�lida!"); break;
	
		}
		
	}while(op != 0);
	
}

