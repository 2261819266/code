#include<bits/stdc++.h>
using namespace std;
long long z[1005][1005],z2[1005][1005],t2[1005],q[1005][1005],q2[1005][1005];
string num;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	long long T,id,n,m,c,f,t,ansc,ansf;
	scanf("%lld%lld",&T,&id);
	for(int ii=1;ii<=T;ii++){
		ansc=0;
		ansf=0;
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(int j=1;j<=m;j++){
			t2[j]=1;
		}
		memset(z,0,1000000);
		memset(z2,0,1000000);
		memset(q,0,1000000);
		memset(q2,0,1000000);
		for(int j=1;j<=n;j++){
			t=1;
			cin>>num;
			for(int k=1;k<=m;k++){
				if(num[k-1]=='0'){
					z[j][t]++;
					z2[t2[k]][k]++;
				}
				if(num[k-1]=='1'){
					while(z[j][t]>0){
						z[j][t+1]=z[j][t]-1;
						t++;
					}
					t++;
					while(z2[t2[k]][k]>0){
						z2[t2[k]+1][k]=z2[t2[k]][k]-1;
						t2[k]++;
					}
					t2[k]++;
				}
			}
			while(z[j][t]>0){
				z[j][t+1]=z[j][t]-1;
				t++;
			}
			t++;
		}
		for(int j=1;j<=m;j++){
			while(z2[t2[j]][j]>0){
				z2[t2[j]+1][j]=z2[t2[j]][j]-1;
				t2[j]++;
			}
			t2[j]++;
		}
		if(c==0){
			cout<<0<<' ';
		}
		else{
			for(int j=3;j<=n;j++){
				for(int k=1;k<=m;k++){
					if(z[j][k]>1)
						q[j][k]=q[j-1][k]+z[j][k]-1;
					else
						q[j][k]=q[j-1][k];
				}
			}
			for(int j=1;j<=m-1;j++){
				for(int k=1;k<=n-2;k++){
					if(z2[k][j]>=3){
						ansc=ansc+(((z[k][j]-1)*(q[k+z2[k][j]-1][j]-q[k+1][j]))%998244353);
						ansc=ansc%998244353;
					}
				}
			}
			cout<<ansc<<' ';
		}
		if(f==0){
			cout<<0;
		}
		else{
			for(int j=3;j<=n;j++){
				for(int k=1;k<=m;k++){
					if(z[j][k]>1&&z2[j][k]>1)
						q2[j][k]=q2[j-1][k]+(z[j][k]-1)*(z2[j][k]-1);
					else
						q2[j][k]=q2[j-1][k];
				}
			}
			for(int j=1;j<=m-1;j++){
				for(int k=1;k<=n-3;k++){
					if(z2[k][j]>=4){
						ansf=ansf+(((z[k][j]-1)*(q2[k+z2[k][j]-1][j]-q2[k+1][j]))%998244353);
						ansf=ansf%998244353;
					}
				}
			}
			cout<<ansf;
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

