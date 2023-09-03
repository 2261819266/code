#include<iostream>
#include<stack>
using namespace std;
stack<int> insk1;
stack<int> insk2;
int temp[1001];
ifstream fin("meow.in");
ofstream fout("meow.out");
int cnt;
void dfs(int x) {
	if(x==0) return;
	
}
int main() {
	int t,n,m,k;
	cin >> t;
	while(t--) {
		fin >> n >> m >> k;
		m1=m;
		int i;
		while(m--) {
			i = 0;
			fin >> temp[i];
			i++;
		}
	}
	insk1.push(temp[i]);
	insk2.push(temp[i-1]);
	dfs(m1);
	return 0;
}
