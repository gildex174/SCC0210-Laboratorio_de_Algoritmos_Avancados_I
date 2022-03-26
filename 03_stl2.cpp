#include<iostream>
#include<queue>

using namespace std;

struct job{
	int name;
	int priority;
};

void drag(int ini, int n, job queue[]){
	job aux[101];

	for(int i=ini;i<n-1;i++){
		aux[i].name = queue[i+1].name;
		aux[i].priority = queue[i+1].priority;
	}

	aux[n-1].name = queue[ini].name;
	aux[n-1].priority = queue[ini].priority;

	for(int i=ini;i<n;i++){
		queue[i].name = aux[i].name;
		queue[i].priority = aux[i].priority;
	}

}

void sort(int n, job queue[], priority_queue<int> priorities){
	int i=0;
	while(i!=n){
		if(queue[i].priority==priorities.top()){
			priorities.pop();
			i++;
		}
		else{
			drag(i,n, queue);
		}
	}
}

int time(int n, int m, job queue[]){
	for(int i=0;i<n;i++){
		if(queue[i].name==m){
			return i+1;
		}
	}
	return 0;
}

int main(){

	int t;
	cin >> t;

	for(int z=0;z<t;z++){
		priority_queue<int> priorities;
		int n,m;
		job queue[101];
		//n is the number of jobs in the queue (1 ≤ n ≤ 100)
		//and m is the position of your job 
		cin >> n >> m;
		for(int i=0;i<n;i++){
			queue[i].name = i;
			cin >> queue[i].priority;
			priorities.push(queue[i].priority);
		}

		sort(n,queue,priorities);

		cout << time(n,m,queue) << "\n";
	}
	
	return 0;
}