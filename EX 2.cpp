/*Uma pesquisa ser� realizada com os alunos da UNAERP em rela��o � algumas
caracter�sticas f�sicas e de educa��o. O n�mero de alunos que ser�o entrevistados n�o foi
definido, e os dados a serem coletados ser�o: (1,00 ponto).
	- Turno: M (manh�), T (tarde) e N (noite)
	- �rea do curso: E (exatas), H (humanas) e B (biol�gicas)
	- Renda familiar
	- Quantas pessoas fazem parte de sua fam�lia (incluindo o entrevistado)
	- Idade do entrevistado
Deseja-se saber:
	a) Qual turno possui a menor e a maior m�dia de renda familiar.
	b) A quantidade e o percentual de entrevistados de cada �rea de curso, cuja idade est�
entre 18 e 22 anos, que possua fam�lia com 3 ou 4 pessoas e a renda familiar acima de
R$ 1.800,00.
	c) A quantidade de entrevistados por tamanho de fam�lia, considerando fam�lias de
tamanho: 1, 2, 3, 4, 5, 6 e maior que 6.*/

#include <iostream>
#include <locale.h>
#include <vector>
#include <conio.h>

using namespace std;

vector<int> aluno;
vector<char> turno;
vector<char> area_estudo; 
vector<float> renda;
vector<int> familia;
vector<int> idade;
int i = 1;

int main () {
	
	setlocale (LC_ALL,"");
	
	//while( ) {
		
		//LISTA ALUNO
		aluno.push_back(i);
		
		//LISTA DOS TURNOS
		cout << "DADOS DO " << i++ << "� ALUNO:\n\n";
		cout << "Digite o turno em que aluno estuda, M (manh�), T (tarde) ou N (noite): ";
		turno.push_back(getchar());
		cin.ignore();
		i--;
		while (turno[i] != 'M' && turno[i] != 'T' && turno[i] != 'N' && turno[i] != 'm' && turno[i] != 't' && turno[i] != 'n') {
			turno.pop_back();
			cout << "Valor invalido!!!\n\nDigite M (manh�), T (tarde) ou N (noite):";
			turno.push_back(getchar());
			cin.ignore();
		}
		i++;
		
		
		cout << "Digite a �rea de estudo do aluno, E (exatas), H (humanas) ou B (biol�gicas): ";
		area_estudo.push_back(getchar());
		cin.ignore();
		i--;
		while (area_estudo[i] != 'E' && area_estudo[i] != 'H' && area_estudo[i] != 'B' && area_estudo[i] != 'e' && area_estudo[i] != 'h' && area_estudo[i] != 'b') {
			area_estudo.pop_back();
			cout << "Valor invalido!!!\n\nDigite E (exatas), H (humanas) ou B (biol�gicas):";
			area_estudo.push_back(getchar());
			cin.ignore();
		}
		i++;
		
		
		
		
		
		
		
		
		
		
	//}
	
	
	
	
	
	
	
	
	
	
	
	
	system ("pause");
	
	return 0;
}
