#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct projeto{
	int codigo;
	char titulo[50];
	char descricao[100];
	int status, ano, quantidadeDeDesenvolvedores, quantidadeDeQA;
	char gerenteProjetos[100];
	float orcamento;
};

void MenuInicial(int *opcao){
	int opcaoAuxiliar;
	printf("\nOPÇÕES PROJETO\n");
	printf("1 - CADASTRAR PROJETO\n");
	printf("2 -TODOS OS PROJETOS\n");
	printf("3 -PROJETOS COM STATUS: A FAZER\n");
	printf("4 - PROJETOS COM STATUS: FAZENDO\n");
	printf("5 - PROJETOS COM STATUS: CONCLUÍDO\n");
	printf("ESCOLHA UMA OPÇÃO: ");
	scanf("%d", &opcaoAuxiliar);
	printf("\n");
	
	*opcao = opcaoAuxiliar;
}


int MenuOpcoesStatus(){
	int opcao;
	printf("\nDIGITE OS STATUS ABAIXO: \n");
	printf("1 - A FAZER\n");
	printf("2 - FAZENDO\n");
	printf("3 - CONCLUÍDO\n");
	printf("ESCOLHA UMA OPÇÃO: ");
	scanf("%d", &opcao);
	printf("\n");
	
	return opcao;
}

int ConferirStatus(){

	int statusAuxiliar = MenuOpcoesStatus();
	int status;
	
	if(statusAuxiliar == 1 || statusAuxiliar == 2 || statusAuxiliar == 3){
		return statusAuxiliar;
	}
	
	else{
		printf("\nDIGITE UMA OPÇÃO VÁLIDA\n");
		status = ConferirStatus();
		return status;		
	}

}

void CadastrarProjeto(int *i, struct projeto cadastro[200]){
	int codigo = 0;
	
	if(codigo <= 10){
		printf("\nCADASTRO DO PROJETO\n");
	
		cadastro[codigo].codigo = codigo + 1;
		printf("TITULO:\n");
		scanf("%s", &cadastro[codigo].titulo);
		printf("DESCRIÇÃO:\n");
		scanf("%s", &cadastro[codigo].descricao);
		printf("ANO:\n");
		scanf("%d", &cadastro[codigo].ano);
		printf("NOME DO GERENTE:\n");
		scanf("%s", &cadastro[codigo].gerenteProjetos);
	
		cadastro[codigo].status = ConferirStatus();
	}
	else{
		printf("NÚMERO MÁXIMO DE CADASTRO ATINGIDO.");
	}
	
	*i = codigo;
}


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	int i, opcao;
	struct projeto cadastro[200]; 
	
	printf("%d", i);
	printf("%s", cadastro[0].gerenteProjetos);
	printf("%d", cadastro[0].status);

	opcao = 0;
	while(opcao != 5){
		MenuInicial(&opcao);
		if(opcao == 1){
			CadastrarProjeto(&i, cadastro);	
		}
		else{
			if(opcao == 2){
				printf("IMPRIMIR");
			}
		}
		
		//TODO else printf("DIGITE UMA OPÇÃO VÁLIDA");
	}
	return 0;
}
