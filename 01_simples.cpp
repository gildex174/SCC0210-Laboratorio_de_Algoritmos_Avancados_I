#include<iostream>
#include<map>
#include<string>

using namespace std;

string print(string n){
	string aux = "";
	int lenght = n.size();
	for(int i=0;i<lenght-1;i++){
		aux=aux+n[i];
	}

	return aux;
}

map<string, string> dici;
int main(){
	int n,m;

	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s1, s2;
		cin >> s1 >> s2;
	
		dici.insert(make_pair(s2,s1));
	}

	for(int j=0;j<m;j++){
		string s1, s2, aux;
		cin >> s1 >> s2;
	
		aux=print(s2);

	
	//atenção ao ponto e virgula no final
		cout << s1 << " "<< s2;
		cout << " #" << dici[aux] <<"\n";

	}
	


	return 0;
}