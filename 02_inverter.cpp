#include<iostream>
#include<queue>
#include<stack>

using namespace std;

queue<int> inverter(queue<int> q){
	queue<int> aux;
	stack<int> aux1;
	while(q.size()!=0){

		aux1.push(q.front());
		q.pop();
	}

	while(aux1.size()!=0){
		aux.push(aux1.top());
		aux1.pop();

	}

	return aux;
}

void print(queue<int> q){
	while(q.size()!=0){
		cout << q.front()<< "\n";
		q.pop();
	}
}

int main(){

	int t;
	cin >> t;

	for(int z=0;z<t;z++){

		int n;
		queue<int> q;
		cin >> n;

		for(int i=0;i<n;i++){
			int aux;
			cin >> aux;

			q.push(aux);
		}

		q = inverter(q);
		print(q);
		
		if(z!=t-1) cout << "\n";
	}

	return 0;
}