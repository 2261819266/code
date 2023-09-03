#include<bits/stdc++.h>
using namespace std;

int city[500010][2];

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out,","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++) {
		cin>>city[i][0]>>city[i][1];
	}
	return 0;
}
