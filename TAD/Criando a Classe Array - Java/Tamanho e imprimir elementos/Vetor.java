package TamanhoImpressao;

import java.util.Arrays;

//Adicionar elemento no final do vetor

public class Vetor {
	private String[] elementos;
	private int tamanho;

	public Vetor(int capacidade) {
		this.elementos = new String[capacidade];
		this.tamanho=0;
	}
	
	/* ineficiente
	public void adicionaElementoL(String elemento) {
		for(int i=0;i<this.elementos.length;i++) {
			if(this.elementos[i] == null) {
				this.elementos[i] = elemento;
				break;
			}
		}
	}
	
	// não necessário...
	public void adicionaElementoT(String elemento) throws Exception {
		if(this.tamanho < this.elementos.length) {
			this.tamanho++;
		}else {
			throw new Exception("Vetor cheio!");
		}
	}
	*/
	
	public boolean adiciona(String elemento) {
		if(this.tamanho < this.elementos.length) {
			this.elementos[this.tamanho] = elemento;
			this.tamanho++;
			return true;
		}
		return false;
	}
	
	
	public int MostraTamanho() {
		return this.tamanho;
	}
	
	public String mostraTodosElementos() {
		StringBuilder s = new StringBuilder();
		s.append("[");
		
		for(int i = 0 ; i <this.tamanho;i++) {
			s.append(this.elementos[i]);
			s.append(", ");
		}
		
		if(this.tamanho > 0) {
			s.append(this.elementos[this.tamanho-1]);
		}
		
		s.append("]");
		
		
		return s.toString();
	}
	
	
	
}
