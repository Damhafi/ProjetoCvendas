#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define ncliente 10
#define nproduto 20
#define nvenda 50

FILE *fp;

struct Clientes{
	char nome[40];
	char codigo[20];
	char CPF[13];
}cliente[ncliente];

struct Produtos{
	char codigo[20];
	char descricao[40];
	char valor[20];
	int opcao;
}produto[nproduto];

struct Vendas{
	char data[10];
	char Nome_Cliente[20];
	char Cod_Produto[20];
	char quantidade[100];
	char valor[100];
}venda[nvenda];
				
void Menu(){
	printf ("______MENU DE CADASTRO_____");
	printf("\n[1] - Cadastrar Cliente   |");
	printf("\n[2] - Listar Clientes     |");
	printf("\n[3] - Cadastrar Produto   |");
	printf("\n[4] - Listar Produtos     |");
	printf("\n[5] - Cadastrar Venda     |");
	printf("\n[6] - Listar Vendas       |");
	printf("\n[7] - Sair                |");
}

void Cadastrando_Clientes(){     //Criando Lista de Clientes
	char resp;
	struct Clientes Novo_Cliente; 	//Cadastranclientes
	setlocale(LC_ALL, "Portuguese");
	fp = fopen("Clientes.txt","a");   //Criando um arquivo de clientes
	setlocale(LC_ALL, "Portuguese");	// Comando para utilzar acentos gráficos
	do{
		printf ("______CADASTRANDO CLIENTE_____");
		printf("\n Nome: ");
		fflush(stdin);
		gets(Novo_Cliente.nome);

		printf("\n Código do Cliente: ");
		fflush(stdin);
		gets(Novo_Cliente.codigo);
		
		printf("\n C.P.F: ");
		fflush(stdin);
		gets(Novo_Cliente.CPF);
		
		printf ("\n\nContinuar? [s/n]");
		scanf ("%c", &resp);
		system("CLS");
		
		if (resp == 'n'){
			break;
		}		
	}while(1!=0);
	fwrite(&Novo_Cliente, sizeof(struct Clientes), 1, fp);
			fclose(fp);
}

void MostLista_Clientes(){         //Mostrando Lista de CLientes
	struct Clientes Novo_Cliente;		//Listando o cliente criado na lista 
		
	fp = fopen("Clientes.txt", "r");    
	
	system("cls");
	printf ("\t\t____LISTA DE CLEINTES____\n");
	while (fread(&Novo_Cliente, sizeof(struct Clientes), 1, fp)){	
		setlocale(LC_ALL, "Portuguese");	// Comando para utilzar acentos gráficos
		printf("\n Código do Cliente: %s\n",Novo_Cliente.codigo);
		printf("\n Nome: %s\n",Novo_Cliente.nome);
		printf("\n C.P.F: %s\n",Novo_Cliente.CPF);
		printf("___________________________\n");	
	}
	fclose(fp);
	printf("\n\tPrecione 'ENTER' para voltar ao menu");
	
	system("PAUSE>>null"); //Nao mostra a mensagem do System pause
	system("CLS");
}

void Cadastrando_Produtos(){ //Criando Lista de Produtos
	struct Produtos Novo_Produto;
	char resp;
	fp = fopen("Produtos.txt", "a"); 
		system("cls");	
		setlocale(LC_ALL, "Portuguese");	// Comando para utilzar acentos gráficos	
		do{
			printf("____CADASTRO DE PRODUTOS___");
			printf("\n Código do Produto: ");
			fflush(stdin);
			gets(Novo_Produto.codigo);
							
			printf("\n Descrição do Produto: ");
			fflush(stdin);
			gets(Novo_Produto.descricao);
				
			printf("\n Valor do Produto: ");
			fflush(stdin);
			gets(Novo_Produto.valor);
			fwrite(&Novo_Produto, sizeof(struct Produtos), 1, fp);
				
			printf ("\n\nContinuar?[s/n]");
			scanf("%c", &resp);
			system("CLS");
			if (resp =='n'){
				break;
			}				
		}while(1!=0);		
	fclose(fp);	
}

void Mostrando_Produtos(){ // Mostrando lista de Produtos 
			struct Produtos Novo_Produto;	
			fp = fopen("Produtos.txt", "r");	
			system("cls");			
			printf("\n\t\t PRODUTOS CADASTRADOS \n");
			printf("\t\t --------------------\n\n");
			
			while (fread(&Novo_Produto, sizeof(struct Produtos), 1, fp)){			
				setlocale(LC_ALL, "Portuguese");	// Comando para utilzar acentos gráficos					
				printf("\n Produto : %s\n",Novo_Produto.descricao);
				printf("\n Código : %s\n",Novo_Produto.codigo);
				printf("\n Preço : %s\n",Novo_Produto.valor);
				printf("___________________________________\n");			
			}
			fclose(fp);
			printf("\n\tPrecione 'ENTER' para voltar ao menu");	
			system("PAUSE>>null"); //Nao mostra a mensagem do System pause
}

void Ficha_Vendas (){ //Realizando a Lista do Caixa
		struct Vendas Nova_Venda;
		fp = fopen("Vendas.txt","a+"); 
		setlocale(LC_ALL, "Portuguese");	// Comando para utilzar acentos gráficos
		system("cls");
		printf("\n\t\t  REGISTRANDO VENDA\n");
		printf("\t\t  ------------------\n\n");
		
		printf("\n Data: ");
		fflush(stdin);
		gets(Nova_Venda.data);
		
		printf("\n Nome do Cliente: ");
		fflush(stdin);
		gets(Nova_Venda.Nome_Cliente);
				
		printf("\n Código do produto: ");
		fflush(stdin);
		gets(Nova_Venda.Cod_Produto);
		
		printf("\n Quantidade: ");
		fflush(stdin);
		gets(Nova_Venda.quantidade);
		
		printf("\n Valor total: ");
		fflush(stdin);
		gets(Nova_Venda.valor);
		
		printf("\n\n\t\t");
		printf("\n\tPrecione 'ENTER' para voltar ao menu");
		system("PAUSE>>null"); //Nao mostra a mensagem do System pause
		system("cls");
		fwrite( &Nova_Venda, sizeof(struct Vendas), 1, fp);
		fclose(fp);			
}

void Mostrando_Vendas(){ // Mostrando lista do Caixa
	struct Vendas Nova_Venda;
	fp = fopen("Vendas.txt", "r");
	setlocale(LC_ALL, "Portuguese");	// Comando para utilzar acentos gráficos
		while (fread(&Nova_Venda, sizeof(struct Vendas), 1, fp)){
		system("cls");
		printf("\n\t\t LISTA DE VENDAS \n");
		printf("\t\t ----------------\n\n");
		printf(" Compra feita: %s\n",Nova_Venda.data);	
		printf("\n Nome do cliente : %s\n",Nova_Venda.Nome_Cliente);
		printf("\n Código do produto : %s\n",Nova_Venda.Cod_Produto);		
		printf("\n Quantidade : %s\n",Nova_Venda.quantidade);
		printf("\n Valor total : %s\n",Nova_Venda.valor);
		printf("-------------------------------\n\n");
		}
		close(fp);
		printf("\n\tPrecione 'ENTER' para voltar ao menu");	
		system("PAUSE>>null"); //Nao mostra a mensagem do System pause
}

int main() {
	int opcao;	
	while(opcao != 7){
		Menu();
		setlocale(LC_ALL, "Portuguese");
		printf("\nQual opção voce deseja acessar? ");
		scanf("%d",&opcao);
		system("CLS");	
			
		switch(opcao){
			case 1: Cadastrando_Clientes();break;
			case 2: MostLista_Clientes(); break;		
			case 3: Cadastrando_Produtos();break;		
			case 4: Mostrando_Produtos(); break;
			case 5:	Ficha_Vendas();break;
			case 6: Mostrando_Vendas(); break;
			case 7: exit(0); break;
			}
			fclose(fp);					
	}
	return 0;
}



