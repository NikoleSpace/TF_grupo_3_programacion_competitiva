#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

map<int,vector<int>> memorizar;
void conversor(vector<int> &numbit, int num, int numI) {
	if (num / 2 > 0) {

		conversor(numbit, num / 2, numI);
		numbit.push_back(num % 2);
		memorizar[numI].push_back(num % 2);	
	}
	else if (num / 2 == 0) {		
		numbit.push_back(num % 2);
		memorizar[numI].push_back(num);
	}	
}

int main() {
	int querys = 0, num;
	vector<int> numbit;
	string palabra;
	//do {
		//cout << "Cuantas consultas realizara: "; cin >> querys;
	//} while (querys < 0);

	//for (int i = 0; i < querys; i++)
	//{
		cout << "\nDigite la palabra a convertir: "; cin >> palabra; cin.ignore();
		for (int i = 0; i < palabra.length(); i++)
		{
			num = int(palabra[i]);
			if (memorizar.find(num) == memorizar.end()) {
				conversor(numbit, num, num);
				memorizar[num] = numbit;
				cout << "Letra "<<palabra[i]<<" || "<< num << " convertida: ";
				for (int i = 0; i < memorizar[num].size(); i++)
				{
					cout << memorizar[num].at(i);
				}
				numbit.clear();
				cout << endl;
			}
			else {
				cout << "Numero convertido: ";
				for (int i = 0; i < memorizar[num].size(); i++)
				{
					cout << memorizar[num].at(i);
				}
				cout << endl;
			}
		}
		
		
	//}

	system("pause");
	return 0;
}
