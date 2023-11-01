#include <fstream>
#include <cstring>
#include <cstdio>
#define NMAX 100
#define LGMAX 200
using namespace std;
// fisiere citire/scriere
ifstream fin("plieri.in");
ofstream fout("plieri.out");
// variabile globale
int n, efinal[NMAX]; // efinal[i] = 1 <=> i este element final
char m[NMAX][LGMAX]; // m[i] = codificarea plierilor care ne conduc la elementul i
// functii ajutatoare
void pliaza(int, int);
// functia principala
int main()
{
	int i;
	fin >> n;
	fin.close();
	pliaza(1, n);
	for (i = 1; i <= n; i++)
	{
		if (efinal[i])
		{
			fout << i << ": " << m[i] << '\n';
		}
	}
	fout.close();
	return 0;
}
void pliaza(int p, int q)
{
	// pliaza un vector cu componente numerotate de la p la q
	int ls, ld, i;
	char ss[LGMAX], sd[LGMAX], aux[LGMAX];
	// ls, ld - pozitiile de pliere spre stanga, respectiv dreapta;
	// ss, sd - sirurile care se obtin din pozitiile de pliere
	if (p == q)
	{
		// vectorul contine un singur element
		efinal[p] = 1;
	}
	else
	{
		if ((q-p+1) % 2)
		{
			// vectorul are numar impar de elemente
			ls = (p+q)/2-1;
		}
		else
		{
			ls = (p+q)/2;
		}
		ld = (p+q)/2+1;
		pliaza(p, ls); // pliez prima jumatate
		sprintf(ss, "%d", ls);
		sprintf(sd, "%d", ld);
		// elementele finale din prima jumatate se obtin
		// printr-o pliere prealabila la stanga
		for (i = p; i <= ls; i++)
		{
			strcpy(aux, "S");
			strcat(aux, ss);
			strcat(aux, " ");
			strcat(aux, m[i]);
			strcpy(m[i], aux);
		}
		pliaza(ld, q);
		// elementele finale din cea de-a doua jumatate se obtin
		// printr-o pliere prealabila la dreapta
		for (i = ld; i <= q; i++)
		{
			strcpy(aux, "D");
			strcat(aux, sd);
			strcat(aux, " ");
			strcat(aux, m[i]);
			strcpy(m[i], aux);
		}
	}
}
// sol. oficiala
