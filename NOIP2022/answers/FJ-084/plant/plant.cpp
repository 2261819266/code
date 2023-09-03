#include<bits/stdc++.h>
#define ll long long 
#define P 998244353
#define N 1010
#define GC getchar()
using namespace std;
ll re(){
	ll s=0,b=1; char c=GC;
	while(c>'9'||c<'0'){if(c=='-')b=-b; c=GC;}
	while(c<='9'&&c>='0'){s=(s<<1)+(s<<3)+(c^48); c=GC;}
	return s*b;
}
void ks(ll s){
	if(s<0){s=-s; putchar('-');} 
	if(s>=10)ks(s/10); 
	putchar((s%10)|48);
}
int n,m,T,x;
ll xsc,xsf,cfa[N][N],anc,anf,lx[N][N],ffa[N][N];
char a[N][N];
int main(){
	freopen("plant.in","r",stdin); 
	freopen("plant.out","w",stdout); 
	T=re(),x=re();
	while(T--){
		n=re(),m=re(); xsc=re(),xsf=re(); 
		for(int i=1; i<=n; i++)cin>>(a[i]+1);
		if(n==1||m==1){
			ks(0),putchar(' '),ks(0),putchar('\n'); continue; 
		} anc=anf=0;
		cfa[1][m]=0;
		if(a[1][m]=='0')lx[1][m]=1;
		 else lx[1][m]=0;
		for(int i=m-1; i>=1; i--){
			if(a[1][i]=='0'){
				lx[1][i]=lx[1][i+1]+1;
				cfa[1][i]=lx[1][i]-1;
			} else lx[1][i]=cfa[1][i]=0;
			 
		}
		if(a[2][m]=='0')lx[2][m]=1;
		 else lx[2][m]=0;
		for(int i=m-1; i>=1; i--){
			if(a[2][i]=='0'){
				lx[2][i]=lx[2][i+1]+1;
				cfa[2][i]=cfa[1][i]+lx[2][i]-1;
			} else lx[2][i]=cfa[2][i]=0;
		}
		for(int i=3; i<=n; i++){
			cfa[i][m]=0; ffa[i][m]=0;
			if(a[i][m]=='0')lx[i][m]=1;
			 else lx[i][m]=0;
			for(int j=m-1; j>=1; j--){
				if(a[i][j]=='1')lx[i][j]=cfa[i][j]=ffa[i][j]=0;
				 else{
				 	lx[i][j]=lx[i][j+1]+1; ll S=0; 
				 	if(a[i-1][j]=='0')S=(lx[i][j]-1)*cfa[i-2][j]%P;
					anc=(anc+S)%P; anf=(anf+ffa[i-1][j])%P;
				 	cfa[i][j]=(cfa[i-1][j]+lx[i][j]-1)%P;
					ffa[i][j]=(S+ffa[i-1][j])%P;
				 }
			}
		} 
		anc=anc*xsc%P; anf=anf*xsf%P;
		ks(anc),putchar(' '),ks(anf),putchar('\n');
	}
} 
