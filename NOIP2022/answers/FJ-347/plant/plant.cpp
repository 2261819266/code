#include<bits/stdc++.h>
using namespace std;
int n,m,temp,tt,d,f,c;
bool a[110][110];
char t;
int fc(int x,int y){
	int q=0,p=0,num=0,k=0;
	while(1){
		if(a[x][y+q]==0 || y+q>m){
			q--;
			break;
		}
		q++;
	}
	if(q<=0) return 0;
	while(1){
		if(a[x+p][y]==0 || x+p>n){
			p--;
			break;
		}
		p++;
	}
	if(p<=1) return 0;
	for(int i=x+2;i<=x+p;i++){
		k=1;
		while(1){
			if(a[i][y+k]==0 || y+k>m){
				k--;
				break;
			}
			k++;
		}
		if(i<x+p) temp=temp+k*q*(x+p-i);
		num=num+k*q;
	}
	
	return num;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
		cin>>tt>>d;
	while(tt){
		tt--;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>t;
			if(t=='0') a[i][j]=1;
			else a[i][j]=0;
		}
		
		int ansc=0,ansf=0;
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=m-1;j++){
				ansc+=fc(i,j);
				ansf+=temp;
				ansc%=998244353;
				ansf%=998244353;
				temp=0;
			}
		}
		
		cout<<ansc*c<<' '<<ansf*f<<endl;
		return 0;
	}
}
