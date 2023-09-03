/*The truth is with you!*/
# include <bits/stdc++.h>
# define MAX (250009)
# define ll long long
# define inf (0x3f3f3f3f)
int lg[MAX];
int max(int a,int b){
	return a>b?a:b;
}
struct ST{
	int a[20][MAX];
	void init(int n){
		int i,j;
		for(i = 1;i <= lg[n];i++){
			for(j = 1;j+(1<<i)-1 <= n;j++){
				a[i][j]=max(a[i-1][j],a[i-1][j+(1<<(i-1))]);
			}
		}
	}
	int query(int l,int r){
		return max(a[lg[r-l+1]][l],a[lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
	}
}ra,rb;
int n,a[MAX],b[MAX];
unsigned ll ans;
int read(){
	int f=1,x=0;
	char ch=0;
	while('0'>ch||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main(){
	
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	read();
	n=read();
	int i,j,l,r;
	for(i = 1;i <= n;i++){
		ra.a[0][i]=read();
	}
	for(i = 1;i <= n;i++){
		rb.a[0][i]=read();
	}
	for(i = 2,lg[1]=0;i <= n;i++)lg[i]=lg[i>>1]+1;
	ra.init(n),rb.init(n);
	int q=read();
	while(q--){
		l=read();
		r=read();
		ans=0;
		for(i = l;i <= r;i++){
			for(j = i;j <= r;j++){
				ans+=1ull*ra.query(i,j)*rb.query(i,j);
			}
		}
		printf("%llu\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
