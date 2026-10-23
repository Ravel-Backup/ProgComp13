// aplicado em: projetos -> ProgComp11 propriedades -> C/C++ -> linha de comando -> Opções adicionais: 
// O casório entre utf-8 do Visual Studio e IBM 850 do Prompt de Comando do Windows ->
// /source-charset:utf-8 /execution-charset:.850

#include <iostream>
#include <iomanip>
using namespace std;

// Registros e uniões e enumerações:

enum COR : short { NOME=1, NUMERO, CODIGO };
enum MES : short { JAN=1, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ };
enum SEMANA : short { DOM, SEG, TER, QUA, QUI, SEX, SAB };

	// Exercícios de Fixação:
union especCarro {
	char nome[20];
	int numero;
	char codigo[5];
};

struct Carro {
	char nomeModelo[20];
	int anoFabricacao;
	especCarro cor;
	int preco;
	int digito;
};

	// Atividades de Aprendizagem:
union Jogador {
	char nome[25]; // Nome do jogador.
	int numero;    // Número da camisa do jogador.
};

struct Gol {
	Jogador jog;   // Identificador do jogador.
	int hora, min; // Hora e minuto em que o gol foi marcado.
	int digito;    // Digito identificador para nome ou número da camisa.
};

struct Data {
	int dia;
	int mes;
	int ano;
};

struct Hora {
	int hora;
	int minuto;
};

struct Evento {
	char nome[18];
	Data data;
	Hora horario;
};

// Protótipos:

	// Exercícios de Fixação:
void modelosCarros();
ostream& operator<<(ostream&, const Carro&);

void datasMeses();
istream& operator>>(istream&, MES&);

	// Atividades de Aprendizagem:
void estatisticaJogadores();
istream& operator>>(istream&, Gol&);
ostream& operator<<(ostream&, const Gol&);

void eventoCidade();
istream& operator>>(istream&, Evento&);
ostream& operator<<(ostream&, const Evento&);

void exibirDias_daSemana();

// funções:

int main() {
	// Exercícios de Revisão:
	// Exercício 01:

	// Enunciado da questão se encontra em: https://github.com/JudsonSS/ProgComp/blob/master/Labs/Lab13/Lab13.pdf

	// Resposta: 
	// a) Vetor do tipo struct bola / vetor do tipo bola.                e) Campo do tipo enum direcao da variável do tipo bola
	// b) Variável do tipo bola.                                         f) Campo do tipo union identificador do tipo bola
	// c) Vetor de caracteres do tipo char da variável do tipo bola      g) Campo do tipo int pertencente ao tipo identificador que é um campo do tipo bola
	// d) Campo do tipo char da variável do tipo bola                    h) Campo do tipo float do tipo bola.
	
	// Exercícios de Fixação:
	// Exercício 01:

	modelosCarros();

	// Exercício 02:

	datasMeses();

	// Atividades de Aprendizagem:
	// Atividade 01:

	// Enunciado da questão se encontra em: https://github.com/JudsonSS/ProgComp/blob/master/Labs/Lab13/Lab13.pdf

	// i) Nada pois estatistica é um vetor do tipo gol.                                                n) Busca o ponteiro da variavel estatistica atual no vetor, acescenta 9, descopla o ponteiro e inicializa o campo enumerador local.
	// j) Nada pois estatitica[4] é uma variável do tipo gol.                                          m) Um float no campo velo do tipo float da variável de indice 2 do vetor de estatistica.
	// k) Nada pois estatitica[1].jog é um campo do tipo union jogador pertencente ao tipo gol.        o) Busca o poteiro da variavel estatistica no vetor, acescenta 1, descopla o ponteiro e inicializa o campo vetor nome de union jog que pertence ao campo da variavel estatistica do tipo gol.
	// l) Um número, pois nesse caso, o campo numero pertence a jogador que é um campo do tipo gol.    p) Um float no campo acel da variável de indice 6 do vetor de estatistica.
	
	// Atividade 02:

	estatisticaJogadores();

	// Atividade 03:

	eventoCidade();

	// Atividade 04:

	exibirDias_daSemana();
}


void modelosCarros() {
	// Designated Initializers colocado apartir do C++ 20, permite usar {nomeVariavel = valor} na inicialização entre colchetes
	// de uma variável e vetor caracteres do tipo criado struct.
	
	Carro carro[10] = { {"Vectra", 2009, {.nome = "Azul"}, 58'000, COR::NOME},{"Polo",2008, {.nome = "Preto"}, 45'000, COR::NOME} };
	
	cout << "Atualmente temos em nosso banco de dados, as informações sobre 2 carros."
		<< "\nEntre com dados do próximo carro: ";
	cout << "\nNome do modelo: "; cin.getline(carro[2].nomeModelo, 20);
	cout << "\nAno de fabricação: "; cin >> carro[2].anoFabricacao;
	cout << "\n Digite os respectivos números para Cor [1], Numero [2], ou Código do modelo [3]: "; 
	cin >> carro->digito;
	if (carro->digito == COR::NOME) {
		cout << "\nNome da cor: ";
		cin.get();
		cin.getline(carro[2].cor.nome, 20);
	}
	else if (carro->digito == COR::NUMERO) {
		cout << "\nNumero do modelo: ";
		cin >> carro[2].cor.numero;
	}
	else if (carro->digito == COR::CODIGO) {
		cout << "\nCódigo do modelo: ";
		cin.get();
		cin.getline(carro[2].cor.codigo, 5);
	}
	cout << "\nPreço do carro: "; cin >> carro[2].preco;

	cout << "Carros presentes: "
		<< "\n1: " << carro[0]
		<< "\n2: " << carro[1]
		<< "\n3: " << carro[2] << "\n\n";
}

ostream& operator<<(ostream& os, const Carro& entrada) {
	os << "\nNome do modelo: " << entrada.nomeModelo;
	os << "\nAno de fabricação: " << entrada.anoFabricacao;
	if (entrada.digito == COR::NOME) {
		cout << "\nNome da cor: " << entrada.cor.nome;
	}
	else if (entrada.digito == COR::NUMERO) {
		cout << "\nNumero do modelo: " << entrada.cor.numero;

	}
	else if (entrada.digito == COR::CODIGO) {
		cout << "\nCódigo do modelo: " << entrada.cor.codigo;
	}
	os << "\nPreço: R$" << entrada.preco;
	return os;
}

void datasMeses() {
	MES inicio, fim;

	inicio = MAR;
	fim = JUN;

	cout << "Digite o número do mês atual: ";
	MES atual;
	cin >> atual;

	if (atual >= inicio && atual <= fim) {
		cout << "\nVocê está em período de aulas.\n\n";
	}
	else {
		cout << "\nFérias!\n\n";
	}
}

istream& operator>>(istream& is, MES& entrada) {
	int temp;
	is >> temp;
	entrada = (MES) temp;
	return is;
}


void estatisticaJogadores() {
	cout << "Digite os dados do 3 últimos gols: ";
	Gol estatistica[3];
	for (int i = 0; i < 3; ++i) {
		cin >> estatistica[i];
	}
	for (int i = 0; i < 3; ++i) {
		cout << estatistica[i] << "\n\n";
	}
}

ostream& operator<<(ostream& os, const Gol& entrada) {
	os << "\nGol: ";
	if (entrada.digito == 1) {
		os << entrada.jog.nome << " ";
	}
	else if (entrada.digito == 2) {
		os << entrada.jog.numero << " ";
	}
	os << setfill('0') << setw(2) << entrada.hora << ":" << setfill('0') << setw(2) << entrada.min;
	return os;
}

istream& operator>>(istream& is, Gol& entrada) {
	cout << "\nDigite [1] para nome ou [2] para número da camisa: "; 
	is >> entrada.digito;
	cin.get();
	cout << "\nGol: ";
	if (entrada.digito == 1) {
		is >> entrada.jog.nome;
	}
	else if (entrada.digito == 2) {
		is >> entrada.jog.numero;
	}
	is >> entrada.hora;
	is.get();
	is >> entrada.min;
	return is;
}


void eventoCidade() {
	const int tamanho{ 2 };
	cout << "Entre com " << tamanho << " eventos: ";
	Evento recebe[tamanho];
	int count{0};
	for (int i = 0; i < tamanho; ++i) {
		count = i;
		cout << "\n#" << count +1;
		cin >> recebe[i];
	}
	for (int i = 0; i < tamanho; ++i) {
		cout << "\n" << recebe[i];
	}
	cout << "\n\n";

}
istream& operator>>(istream& is, Evento& entrada) {
	cout << "\nData: "; is >> entrada.data.dia; is.get(); is >> entrada.data.mes; is.get(); is >> entrada.data.ano;
	cout << "\nHora: "; is >> entrada.horario.hora; is.get(); is >> entrada.horario.minuto;
	cout << "\nDescrição: "; is.get(); is.getline(entrada.nome, 18);
	return is;
}
ostream& operator<<(ostream& os, const Evento& entrada) {
	os << setfill('0') << setw(2) << entrada.data.dia << "/" << setfill('0') << setw(2) << entrada.data.mes << "/" << entrada.data.ano;
	os << " " << setfill('0') << setw(0) << entrada.horario.hora << ":" << setfill('0') << setw(2) << entrada.horario.minuto;
	os << " " << entrada.nome;
	return os;
}

void exibirDias_daSemana() {
	char semana[7][15] ={
		"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"
	};
	for (SEMANA ind = DOM; ind <= SAB; ind = SEMANA(ind + 1)) {
		cout << semana[ind] << endl;
	}
}