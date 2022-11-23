#include <iostream>
#include <string>

using namespace std;

inline int sprawdz(char znak)
{
	
	if(znak >= 'a' && znak <= 'z') return 0;
	
	if(znak >= 'A' && znak <= 'Z') return 1;
	
	return 2;
}

void szyfruj(int klucz, string &tab)
{		
	
	if(!(klucz >= -26 && klucz <= 26)) return;
	
	int pom;
	char a, z;
	
	for(int i = 0; i < tab.size(); i++)
	{
		pom = sprawdz(tab[i]);
	
		if(pom < 2)
		{
			if(pom == 0) 
				a = 'a', z = 'z';
			else
				a = 'A', z = 'Z';
	
			if(klucz >= 0)
					
				if(tab[i] + klucz <= z)
					tab[i] += klucz;
				else
					tab[i] = tab[i] + klucz - 26; 
			else
				if(tab[i] + klucz >= a)
					tab[i] += klucz;
				else
					tab[i] = tab[i] + klucz + 26;
		}
	}
}

int main()
{
	string tab; 
	
	int klucz;
	
	cout<<"Podaj zdanie do zaszyfrowania: ";
	getline(cin, tab);
	
	cout<<"Podaj klucz z przedziału [-26..26]: ";
	cin>>klucz;
	
	szyfruj(klucz,tab); 
	
	cout<<"Po zaszyfrowaniu: "<<tab<<endl;
	
	szyfruj(-klucz,tab); 
	
	cout<<"Po rozszyfrowaniu: "<<tab<<endl;

	return 0;
}