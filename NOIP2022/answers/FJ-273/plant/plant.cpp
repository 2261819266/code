#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll M=998244353;
ll n,id,T,m,c,f;
string s[1005];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--){
		int a[n+5][m+5],b[n+5][m+5];
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		queue<int>p[m+5];
		ll ans1=0,ans2=0;
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++){
		 cin>>s[i];
		 a[i][m+1]=m+1;
			for(int j=m-1;j>=0;j--){
				if(s[i][j]=='0')a[i][j+1]=a[i][j+2];
		 		else {a[i][j+1]=j+1;p[j+1].push(i);}
		 	}
		}	
		for(int i=1;i<=m;i++)p[i].push(n+1);
		for(int i=1;i<=m;i++){
			int j=0;
			while(!p[i].empty()){
				int v=p[i].front();p[i].pop();
				for(int k=j+1;k<v;k++){
					for(int t=k+2;t<v;t++)
						if(a[k][i]>i+1&&a[t][i]>i+1){
							int u=(a[k][i]-i-1)*(a[t][i]-i-1)%M;
							ans1=(ans1+u)%M;
							if(t+1<v)ans2=(ans2+u)%M;
						}
				}
				j=v;
			}
		}
		cout<<c*ans1%M<<" "<<f*ans2%M<<endl;
	}
	return 0;
}
