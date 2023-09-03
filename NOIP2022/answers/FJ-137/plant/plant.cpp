#include <bits/stdc++.h>

const int MaxN=1001,MaxM=1001,mod=998244353;

int row[MaxN][MaxM],con[MaxN][MaxM],C[MaxN][MaxM],F[MaxN][MaxM];
char a[MaxN][MaxM];

void __init__(){
	std::memset(a,0,sizeof(a));
	std::memset(row,-1,sizeof(row));
	std::memset(con,-1,sizeof(con));
	std::memset(C,0,sizeof(C));
	std::memset(F,0,sizeof(F));
}

void process_rc(int n,int m){
	for(int i=0;i<n;i++){
		for(int j=m-1;j>=0;j--){
			if(a[i][j]=='0'){
				row[i][j]=row[i][j+1]+1;
			}
		}
	}
	for(int j=0;j<m;j++){
		for(int i=n-1;i>=0;i--){
			if(a[i][j]=='0'){
				con[i][j]=con[i+1][j]+1;
			}
		}	
	}
}

int main() {
	std::freopen("plant.in","r",stdin);
	std::freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	while(T--){
		__init__();
		int n,m,c,f;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=0;i<n;i++){
			scanf("%s",&a[i]);
		}
		if(c==0&&f==0){
			printf("0 0\n");
			continue;
		}
		process_rc(n,m);
		
		int sumC=0,sumF=0;
		for(int j=0;j<m;j++){
			for(int i=0;i<n;i++){
				if(i>=n-2||con[i][j]==-1||
				con[i+1][j]==-1||con[i+2][j]==-1)continue;
				if(i==0||con[i-1][j]==-1){
					for(int k=i+2;k<n;k++){
						if(con[k][j]!=-1){
							C[i][j]+=row[k][j];
							C[i][j]%=mod;
							F[i][j]+=row[k][j]*con[k][j]%mod;
							F[i][j]%=mod;
						}
						else{
							break;
						}
					}
				}
				else{
					C[i][j]=(C[i-1][j]-row[i+1][j]+mod)%mod;
					F[i][j]=(F[i-1][j]-row[i+1][j]*con[i+1][j]%mod+mod)%mod;
				}
				sumC+=C[i][j]*row[i][j]%mod;
				sumC%=mod;
				sumF+=F[i][j]*row[i][j]%mod;
				sumF%=mod;
			}
		}
		printf("%d %d\n",sumC*c%mod,sumF*f%mod);
	}
	return 0;
}
