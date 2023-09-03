#include <bits/stdc++.h>
using namespace std;
stack<int> s;
queue<int> q[300];
int t,op,n,m,k,a;
int main(){
	//freopen("meow.in","r",stdin);
	//freopen("meow.out","w",stdout);
	cin >> t;
	for (int i=0;i<t;i++){
		scanf("%d%d%d",&n,&m,&k);
		for (int j=0;j<m;j++){
			scanf("%d",&a);
			s.push(a);
		}	
	}
	return 0;
}
