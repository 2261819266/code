#include<bits/stdc++.h>
using namespace std;
const int MAX=2e6+10;
bool fi;
int T,t,n,m,k;
int a[MAX];
int st[310][100010],tot[310];
int cao[MAX<<2][3],cnt;
bool se;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48; ch=getchar();}
	return x*f;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
//    cerr<<(&se-&fi)/1024.0/1024.0;
	T=read();
	t=T;
	while(T--){
		for(register int i=1; i<=300; i++)
		    for(register int j=0; j<=tot[i]; j++)
		        st[i][j]=0;
		memset(tot,0,sizeof(tot));
		cnt=0;
		n=read(),m=read(),k=read();
		for(register int i=1; i<=m; i++)
		    a[i]=read();
		for(register int i=1; i<=m; i++){
			int x=a[i]/2;
			if(a[i]&1)
			    x++;
			if(st[x][tot[x]]==a[i]){
				cao[++cnt][0]=1,cao[cnt][1]=x;
				st[x][tot[x]]=0;
				tot[x]--;
				continue;
			}
			if(st[x][tot[x]]!=a[i]&&st[x][1]==a[i]){
				st[x][1]=0;
				st[x][1]=st[x][tot[x]];
				tot[x]--;
				cao[++cnt][0]=1,cao[cnt][1]=n;
				cao[++cnt][0]=2,cao[cnt][1]=x,cao[cnt][2]=n;
				continue;
			}
			cao[++cnt][0]=1,cao[cnt][1]=x;
			st[x][++tot[x]]=a[i];
		}
		printf("%d\n",cnt);
		for(register int i=1; i<=cnt; i++){
			if(cao[i][0]==1)
			    printf("1 %d\n",cao[i][1]);
			else
			    printf("2 %d %d\n",cao[i][1],cao[i][2]);
		}
	}
	return 0;
}
/*

*/
