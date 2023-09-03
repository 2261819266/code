#include<bits/stdc++.h>
using namespace std;
const int M=2e6+10;
const int N=610;
int T,n,m,k,a[M],op;
int x[N],y[N],s[3][M];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		op=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++) scanf("%d",&a[i]);
		for(int i=1;i<=k;i++) x[i]=y[i]=0;
		for(int i=1;i<=m;i++){
			if(a[i]>(n-1)){
				if(!x[a[i]-n+1]){
					op++;
					s[0][op]=1;
					s[1][op]=a[i]-n+1;
					x[a[i]-n+1]=a[i];
				}
				else{
					if(y[a[i]-n+1]==a[i]){
						op++;
						s[0][op]=1;
						s[1][op]=a[i]-n+1;
						y[a[i]-n+1]=0;
					}
					else{
						if(x[a[i]-n+1]==a[i]){
							op++;
							s[0][op]=1;
							s[1][op]=n;
							op++;
							s[0][op]=2;
							s[1][op]=a[i]-n+1;
							s[2][op]=n;
							x[a[i]-n+1]=y[a[i]-n+1];
						}
						else{
							op++;
							s[0][op]=1;
							s[1][op]=a[i]-n+1;
							y[a[i]-n+1]=a[i];
						}
					}
				}
			}
			else{
				if(!x[a[i]]){
					op++;
					s[0][op]=1;
					s[1][op]=a[i];
					x[a[i]]=a[i];
				}
				else{
					if(y[a[i]]==a[i]){
						op++;
						s[0][op]=1;
						s[1][op]=a[i];
						y[a[i]]=0;
					}
					else{
						if(x[a[i]]==a[i]){
							op++;
							s[0][op]=1;
							s[1][op]=n;
							op++;
							s[0][op]=2;
							s[1][op]=a[i];
							s[2][op]=n;
							x[a[i]]=y[a[i]];
						}
						else{
							op++;
							s[0][op]=1;
							s[1][op]=a[i];
							y[a[i]]=a[i];
						}
					}
				}
			}
		}
		printf("%d\n",op);
		for(int i=1;i<=op;i++){
			printf("%d ",s[0][i]);
			printf("%d ",s[1][i]);
			if(s[0][i]==2) printf("%d",s[2][i]);
			puts("");
		}
	}
	return 0;
}
