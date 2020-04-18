package TamanhoImpressao;

public class Teste {
	public static void main(String[] args) {
		Vetor v1 = new Vetor(10);
		v1.adiciona("1");
		v1.adiciona("2");
		v1.adiciona("3");
		
		System.out.println("Tamanho atual do vetor: "+v1.MostraTamanho());
		System.out.println("Dentro do Vetor:"+v1.mostraTodosElementos());
	}
}
