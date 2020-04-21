
public class Teste {
	public static void main(String[] args) {
		Vetor v1 = new Vetor(10);
		v1.adiciona("1");
		v1.adiciona("2");
		v1.adiciona("3");
		
		System.out.println(v1.MostraPosicao(2));
		System.out.println(v1.buscaSequencial("1"));
		
		v1.adiciona(0, "30");
		System.out.println("mostra dados:"+v1.mostraTodosElementos());
	}
}
