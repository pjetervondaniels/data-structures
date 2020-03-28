typedef struct reserva r;

// cria reserva
r* criaReserva(int horaEntrada,int horaSaida);

// libera reserva
void liberaReserva(r* Reserva);

// Acessa os valores de entrada e saída de uma reserva
void acessaReserva (r* Reserva,int *horaEntrada,int *horaSaida);

// Atribui os valores de x e y a um ponto..
void atribuiReserva(r* Reserva,int horaEntrada,int horaSaida);

// Calcula o tempo da reserva
int calculaTempo(int horaEntrada,int horaSaida);