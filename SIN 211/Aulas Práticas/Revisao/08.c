/*
Altere o exercício anterior supondo agora que o usuário deseja armazenar 5 produtos.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct sProduto{
	int codigoIdentificacao;
	int quantidadeEstoque;
	float precoVenda;
	char nomeProduto[50];
}Produto;

void cadastraProduto(Produto *p){
	int i;
	for(i=0;i<10;i++){
		printf("\ncadastro do produto %d",i);
		printf("\n Codigo de produto: ");
		scanf("%d",&p[i].codigoIdentificacao);
		printf("\n Quantidade de estoque: ");
		scanf("%d",&p[i].quantidadeEstoque);
		printf("\n Preco de venda: ");
		scanf("%f",&p[i].precoVenda);
		fflush(stdin);
		printf("\n Nome de produto: ");
		scanf("%s",&p[i].nomeProduto);
		fflush(stdin);
	}
	printf("\n cadastro feito com sucesso!");
}

void procuraMaiorPreco(Produto *p){
	float maiorPreco=0;
	int guarda_posicao=0;
	for(int i=0;i<10;i++){
		if(maiorPreco<p[i].precoVenda){
			maiorPreco = p[i].precoVenda;
			guarda_posicao=i;
		}
	}
	printf("\n o produto da posicao %d, possui o maior preco, que eh de %f",guarda_posicao,maiorPreco);
}

void procuraMaiorQuantidade(Produto *p){
	int guarda_posicao=0,maiorQuantidade=0;
	for(int i=0;i<10;i++){
		if(maiorQuantidade<p[i].quantidadeEstoque){
			maiorQuantidade = p[i].quantidadeEstoque;
			guarda_posicao=i;
		}
	}
	printf("\n o produto da posicao %d, possui o maior quantidade em estoque, que eh de %d",guarda_posicao,maiorQuantidade);
}


int main(){
	Produto p*;
    p = (Produto*)malloc(sizeof(Produto));
	cadastraProduto(p);
	procuraMaiorPreco(p);
	procuraMaiorQuantidade(p);
	return 0;
}