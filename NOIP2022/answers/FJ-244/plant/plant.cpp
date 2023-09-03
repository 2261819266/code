#include<bits/stdc++.h>
using namespace std;
long long yl[1001][1001],xl[1001][1001],s[1001][1001],n,m,id,T,a[1001][1001],f,c;
const long long mod1=998244353;
long long ansf=0,ansc=0;
char lll[1001];
int main(){
//	freopen("plant.in","r",stdin);
//	freopen("plant.out","w",stdout);
	cin>>T>>id;
	if(id==1){
		for(int i=1;i<=T;i++)
			cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=T;i++){
		long long sum=0;
		cin>>n>>m>>f>>c;
		for(int j=1;j<=n;j++){
			scanf("%s",lll);			
			for(int k=1;k<=m;k++){
				if(lll[k-1]=='0') a[j][k]=0;
				else a[j][k]=1;
			}
		}
		for(int j=1;j<=n;j++)
			for(int k=m;k>=1;k--){
				if(a[j][k]) sum=0;
				xl[j][k]=sum;
				if(!a[j][k]) sum++;
			}
		sum=0;
		for(int k=1;k<=m;k++)		
			for(int j=n;j>=1;j--){
				if(a[j][k]) sum=0;
				yl[j][k]=sum;
				if(!a[j][k]) sum++;
			}
		for(int k=1;k<=m;k++){
			sum=0;
			for(int j=1;j<=n;j++){
				if(a[j][k]) sum=0;
				s[i][j]=sum;
				if(!a[j][k]) sum+=xl[j][k];
 			}
		}
		for(int k=1;k<=m;k++)
			for(int j=1;j<=n;j++){			
				long long w=s[j-1][k]*xl[j][k];
				w%=mod1;
				ansc+=w;
				ansc%=mod1;
				w=w*yl[j][k];
				w%=mod1;
				ansf+=w;
				ansf%=mod1;
			}
		ansc*=c;
		ansf*=f;
		cout<<ansc<<" "<<ansf<<endl;
	}
	return 0;
}
