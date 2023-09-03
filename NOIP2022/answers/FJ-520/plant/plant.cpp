#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1010][1010];
int chang[1010][1010];
long long mod=998244353;
char ch[1010];
int main( ){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id;
	cin>>t>>id;
	
	for(int g=1;g<=t;g++){
		long long ansc=0,ansf=0;
		int n,m;
		long long c,f;
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		
		for(int i=1;i<=n;i++){
			scanf("%s",ch);
			for(int j=1;j<=m;j++){
				a[i][j]=ch[j-1]-48;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i][m]==0) chang[i][m]=m;
			else chang[i][m]=m-1;
			for(int j=m-1;j>=1;j--){
				if(a[i][j]==1) chang[i][j]=j-1;
				else chang[i][j]=chang[i][j+1];
				
			}
			//for(int j=1;j<=m;j++)
			
		}
		int q=1,z=1;
		long long shu=0;
		for(int j=1;j<=m;j++){
			q=1,z=1;
			while(z<=n){
				q=z;
			
				while(z<=n&&a[z][j]==0) z++;
				z--;
				//cout<<z<<" ";
				if(z-q+1>=3){
					shu=chang[z][j]-j;
					for(int i=z-2;i>=q;i--){
						ansc+=shu*(chang[i][j]-j)%mod;
						shu+=chang[i+1][j]-j;
						ansc%=mod,shu%=mod;
					}
				}
				if(z-q+1>=4){
					shu=chang[z-1][j]-j;
					for(int i=z-3;i>=q;i--){
						ansf+=shu*(chang[i][j]-j)%mod;
						shu+=(chang[i+1][j]-j)*(z-i-1)%mod;
						ansf%=mod,shu%=mod;
					}
				}
				z+=2;
			}
			//cout<<ansc<<endl;
		}
		printf("%lld %lld\n",c%mod*ansc%mod,f%mod*ansf%mod);
	}
	return 0;
}
