/*

Considere um cadastro de produtos de um estoque, com as
seguintes informações para cada produto:

- Código de identificação do produto: representado por um valor
inteiro
- Nome do produto: com ate 50 caracteres
- Quantidade disponível no estoque: representado por um número
inteiro
- Preço de venda: representado por um valor real

(a) Defina uma estrutura em C, denominada produto, que tenha os
campos apropriados para guardar as informações de um produto
(b) Crie um conjunto de 10 produtos e peça ao usuário para entrar
com as informações de cada produto
(c) Encontre o produto com o maior preço de venda
(d) Encontre o produto com a maior quantidade disponível no
estoque.

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
	Produto p[10];
	cadastraProduto(p);
	procuraMaiorPreco(p);
	procuraMaiorQuantidade(p);
	return 0;
}