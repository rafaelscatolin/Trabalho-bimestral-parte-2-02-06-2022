/*Considere um pa�s chamado �Nova Terra�, com 5.000.000 de habitantes e uma taxa de
natalidade de 3% ao ano, e um pa�s chamado �Novos Montes� com 7.000.000 de habitantes
e uma taxa de natalidade de 2% ao ano. Escrever um programa em C que seja capaz de
calcular e mostrar o tempo (em anos) necess�rio para que a popula��o do pa�s �Nova Terra�
ultrapasse a popula��o do pa�s �Novos Montes�.*/

#include <iostream>
#include <locale.h>

using namespace std;

int nova_terra = 5000000;
int novos_montes = 7000000;
int anos = 0;

int main () {
	
	setlocale (LC_ALL,"");
	
	while (nova_terra <= novos_montes) {
		nova_terra = nova_terra * 1.03;
		novos_montes = novos_montes * 1.02;
		anos = anos + 1;	
	}
	
	cout << "A popula��o de Nova Terra ira levar " << anos << " anos para ultrapassar a popula��o de Novos Montes.\n\n";
	
	system ("pause");
	
	return 0;
}
