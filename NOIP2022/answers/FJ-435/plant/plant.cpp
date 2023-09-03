#include<bits/stdc++.h>
using namespace std;
int t,id,n,m,c,f,a[1010][1010],C,F;
char cc;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++){
			 	if(!i||!j||i>n||j>m)a[i][j]=1;
			 	else cin>>cc,a[i][j]=cc-'0';
			}
		if(!c&&!f){printf("0 0\n");continue;}
		for(int i=1;i<=n-2;i++)
			for(int j=1;j<m;j++){
				if(a[i][j]||a[i][j+1]||a[i+1][j]||a[i+2][j])continue;
				for(int k=j+1;!a[i][k];k++)
					for(int l=i+2;!a[l][j];l++)
						for(int p=j+1;!a[l][p];p++){
							C=(C+1)%998244353;if(f)for(int q=l+1;!a[q][j];q++,F=(F+1)%998244353);
						}
			}
		printf("%d %d\n",C,F);
	}
	return 0;
}