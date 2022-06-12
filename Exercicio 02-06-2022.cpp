/*Uma pesquisa será realizada com os alunos da UNAERP em relação à algumas
características físicas e de educação. O número de alunos que serão entrevistados não foi
definido, e os dados a serem coletados serão: (1,00 ponto).
	- Turno: M (manhã), T (tarde) e N (noite)
	- Área do curso: E (exatas), H (humanas) e B (biológicas)
	- Renda familiar
	- Quantas pessoas fazem parte de sua família (incluindo o entrevistado)
	- Idade do entrevistado
Deseja-se saber:
	a) Qual turno possui a menor e a maior média de renda familiar.
	b) A quantidade e o percentual de entrevistados de cada área de curso, cuja idade está
entre 18 e 22 anos, que possua família com 3 ou 4 pessoas e a renda familiar acima de
R$ 1.800,00.
	c) A quantidade de entrevistados por tamanho de família, considerando famílias de
tamanho: 1, 2, 3, 4, 5, 6 e maior que 6.*/

#include <iostream>
#include <locale.h>
#include <vector>
#include <windows.h>

using namespace std;

vector<int> aluno;
vector<char> turno;
vector<char> area_estudo; 
vector<float> renda;
vector<int> familia;
vector<int> idade;
int n = 1; // n será a quantidade de alunos cadastrados

int main () {
	
	setlocale (LC_ALL,"");
	
	while(1) {
		
		//LISTA DE ALUNOS
		aluno.push_back(n);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "\n\nDADOS DO " << n << "º ALUNO\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Informe os dados pedidos abaixo.\n\n";
		
		//LISTA DOS TURNOS
		{
		char valor;
		cout << "Turno de estudo ('M' manhã, 'T' tarde ou 'N' noite): ";
		cin >> valor;
		cin.ignore(200,'\n');
		while (valor != 'M' && valor != 'T' && valor != 'N' && valor != 'm' && valor != 't' && valor != 'n') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Valor invalido!!!, digite um dos caracteres M, T ou N\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "Turno de estudo ('M' manhã, 'T' tarde ou 'N' noite): ";
			cin >> valor;
			cin.ignore(200,'\n');
		}
		turno.push_back(valor);
		
		//LISTA DA ÁREA DE ESTUDO
		cout << "Área de estudo ('E' exatas, 'H' humanas ou 'B' biológicas): ";
		cin >> valor;
		cin.ignore(200,'\n');
		while (valor != 'E' && valor != 'H' && valor != 'B' && valor != 'e' && valor != 'h' && valor != 'b') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Valor invalido!!!, digite um dos caracteres E, H ou B\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "Área de estudo ('E' exatas, 'H' humanas ou 'B' biológicas): ";
			cin >> valor;
			cin.ignore(200,'\n');	
		}
		area_estudo.push_back(valor);
		}
		
		//LISTA DA RENDA FAMILIAR
		{
		float valor;
		cout << "Renda familiar: R$";
		cin >> valor;
		while (!cin) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Valor invalido!!!, digite um valor numérico.\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Digite a renda familiar do aluno: R$";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> valor;
		}
		renda.push_back(valor);
		
		
		//LISTA DA FAMILIA
		cout << "Quantas pessoas fazem parte da familia (incluindo o aluno): ";
		cin >> valor;
		int i = valor;
		while ( (!cin) || (valor != i) ) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Valor invalido!!!, digite um número inteiro maior que 0.\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Quantas pessoas fazem parte da familia (incluindo o aluno): ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> valor;
		}
		familia.push_back(valor);
		}
		
		//LISTA DAS IDADES
		{
		int valor;
		cout << "Idade do aluno: ";
		cin >> valor;
		while ( (!cin) || (valor < 0) ) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "Valor invalido!!!, digite um número maior que 0.\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "Digite a idade do aluno: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> valor;
		}
		idade.push_back(valor);
		}
		
		// CONTINUAR DIGITANDO? (sim ou nao)
		char valor;
		cout << "Continuar para o próximo aluno ('S' sim ou 'N' não): ";
		cin >> valor;
		cin.ignore(200,'\n');
		
		while (valor != 'S' && valor != 'N' && valor != 's' && valor != 'n') {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			cout << "Valor invalido!!!, digite um dos caracteres S ou N\n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			cout << "Continuar para o próximo aluno ('S' sim ou 'N' não): ";
			cin >> valor;
			cin.ignore(200,'\n');	
		}
		
		if ( (valor == 'S') || (valor == 's') )
			n++;
		else
			break;
	}
	
	cout << "\n\nRESULTADO DA PESQUISA\n\n";


	//CÁLCULO DA QUESTÃO A
	
	vector<float> manha, tarde, noite;
	float total_manha = 0, total_tarde = 0, total_noite = 0;
		
	for (int i = 0; i < n; i++) { // n é a quantidade de alunos cadastrados
		if ( (turno[i] == 'M') || (turno[i] == 'm') )
			manha.push_back(renda[i]);
		else if ( (turno[i] == 'T') || (turno[i] == 't') )
				tarde.push_back(renda[i]);	
			else if ( (turno[i] == 'N') || (turno[i] == 'n') )
					noite.push_back(renda[i]);
	}
	
	for (int i = 0; i < manha.size(); i++) {
		total_manha = total_manha + manha[i];
	}
	
	for (int i = 0; i < tarde.size(); i++) {
		total_tarde = total_tarde + tarde[i];
	}
	
	for (int i = 0; i < noite.size(); i++) {
		total_noite = total_noite + noite[i];
	}
	
	cout << "a) A média de renda do turno da manhã é R$" << total_manha / manha.size();
	cout << " , da tarde é R$" << total_tarde / tarde.size();
	cout << " e da noite é R$" << total_noite / noite.size() << endl << endl;
	
	
	//CÁLCULO DA QUESTÃO B
	int exatas = 0, humanas = 0, biologicas = 0;
	
	for (int i = 0; i < n; i++) {
		if ( (idade[i] >= 18) && (idade[i] < 22) && (renda[i] > 1800) )
			if ( (familia[i] == 3) || (familia[i] == 4) )
				if ( (area_estudo[i] == 'E') || (area_estudo[i] == 'e') )
					exatas++;
				else if ( (area_estudo[i] == 'H') || (area_estudo[i] == 'h') )
						humanas++;
					else if ( (area_estudo[i] == 'B') || (area_estudo[i] == 'b') )
							biologicas++;
	}
	
	cout << "b) A quantidade de entrevistados de cada área de curso, cuja idade está entre 18 e 22 anos, que possua família com 3 ou 4 pessoas e a renda familiar acima de R$ 1.800,00 é de:\n\n";
	cout << "para a área de exatas " << exatas << ", representando " << (( (float) exatas / n) * 100) << "% do total de alunos.\n";
	cout << "para a área de humanas " << humanas << ", representando " << (( (float) humanas / n) * 100) << "% do total de alunos.\n";
	cout << "para a área de biológicas " << biologicas << ", representando " << (( (float) biologicas / n) * 100) << "% do total de alunos.\n\n";
	
	
	//CÁLCULO DA QUESTÃO C
	
	int tamanho_familia [7];
	
	tamanho_familia [0] = 0; tamanho_familia [1] = 0; tamanho_familia [2] = 0;
	tamanho_familia [3] = 0; tamanho_familia [4] = 0; tamanho_familia [5] = 0; tamanho_familia [6] = 0;
	
	for (int i = 0; i < n; i++) {
		switch (familia[i]) {
			case 1: tamanho_familia[0] = tamanho_familia[0] + 1; break;
			case 2: tamanho_familia[1] = tamanho_familia[1] + 1; break;
			case 3: tamanho_familia[2] = tamanho_familia[2] + 1; break;
			case 4: tamanho_familia[3] = tamanho_familia[3] + 1; break;
			case 5: tamanho_familia[4] = tamanho_familia[4] + 1; break;
			case 6: tamanho_familia[5] = tamanho_familia[5] + 1; break;
			default: tamanho_familia[6] = tamanho_familia[6] + 1; break;		
		}
	}
	
	cout << "c) A quantidade de entrevistados por tamanho de familia foi de:\n\n";
	cout << "Familias de 1 pessoa: " << tamanho_familia[0] << endl;
	cout << "Familias de 2 pessoas: " << tamanho_familia[1] << endl;
	cout << "Familias de 3 pessoas: " << tamanho_familia[2] << endl;
	cout << "Familias de 4 pessoas: " << tamanho_familia[3] << endl;
	cout << "Familias de 5 pessoas: " << tamanho_familia[4] << endl;
	cout << "Familias de 6 pessoas: " << tamanho_familia[5] << endl;
	cout << "Familias de 6 ou mais pessoas: " << tamanho_familia[6] << endl;
	
	
	cout << endl << endl;
	
	system ("pause");
	
	return 0;
}