#include<bits/stdc++.h>
#define spa putchar(' ')
#define ent putchar('\n')
using namespace std;
inline void read(int &x){
	char c=getchar();
	int f=1;x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	x*=f;
}
inline void write(int x){
	char F[65];
	int cnt=0;
	if(x<0){putchar('-');x=-x;}
	do{F[++cnt]=x%10+'0';x/=10;}while(x);
	while(cnt)putchar(F[cnt--]);
}
const int maxm=2e6+5,maxn=300+5;
int n,m,T,k,a[maxm],s[maxn][20],bl[maxn*2],tp[maxn],op,st[4][20];
bool vis[maxn][20],ff;
struct node{
	int id,s1,s2;
}cz[maxm*2];
void dfs(int nw){
	if(nw>m){
		op=0;
		int lft=m;
		for(int i=1;i<=3;i++){
			tp[i]=0;
			for(int j=1;j<=14;j++)vis[i][j]=0;
		}
		for(int i=1;i<=m;i++){
			cz[++op].id =1;
			cz[op].s1 =bl[i];
			s[bl[i]][++tp[bl[i]]]=a[i];
		}
		for(int i=1;i<=3;i++){
			for(int j=tp[i]-1;j>=1;j--){
				if(s[i][j]==s[i][j+1]&&vis[i][j]==0&&vis[i][j+1]==0){
					vis[i][j]=1;
					vis[i][j+1]=1;
					lft-=2;
				}
			}
		}
		int ntp[4]={0},lw[4],maxl=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=tp[i];j++){
				if(vis[i][j])continue;
				st[i][++ntp[i]]=s[i][j];
			}
			maxl=max(maxl,ntp[i]);
			if(ntp[i])lw[i]=1;
			else lw[i]=0;
		}
		for(int j=1;j<=maxl;j++){
			for(int i=1;i<=3;i++){
				int t=i+1;
				if(t==4)t=1;
				if(lw[i]<=ntp[i]&&lw[t]<=ntp[t]&&st[i][lw[i]]==st[t][lw[t]]){
					cz[++op].id =2;
					cz[op].s1=i;
					cz[op].s2 =t;
					lw[i]++;
					lw[t]++;
					lft-=2;
				}
			}
		}
		if(lft==0)ff=1;
		return;
	}
	for(int i=1;i<=3;i++){
		bl[nw]=i;
		dfs(nw+1);
		if(ff==1)return;
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	read(T);
	if((T%10)==1){
		while(T--){
			op=0;
			read(n);
			read(m);
			read(k);
			for(int i=1;i<=n;i++)tp[i]=0;
			for(int i=1;i<=k;i++)bl[i]=0;
			for(int i=1;i<=m;i++){
				read(a[i]);
				if(bl[a[i]]==0){
					cz[++op].id =1;
					cz[op].s1 =(a[i]+1)>>1;
					if(tp[(a[i]+1)>>1]==0)bl[a[i]]=1;
					else bl[a[i]]=2;
					tp[(a[i]+1)>>1]++;
					continue;
				}
				if(bl[a[i]]==1){
					cz[++op].id =1;
					cz[op].s1 =n;
					cz[++op].id =2;
					cz[op].s1 =(a[i]+1)>>1;
					cz[op].s2 =n;
					tp[(a[i]+1)>>1]--;
					bl[a[i]]=0;
					continue;
				}
				if(bl[a[i]]==2){
					cz[++op].id =1;
					cz[op].s1 =(a[i]+1)>>1;
					tp[(a[i]+1)>>1]--;
					bl[a[i]]=0;
				}
			}
			write(op);
			ent;
			for(int i=1;i<=op;i++){
				if(cz[i].id ==1){
					putchar('1');
					spa;
					write(cz[i].s1 );
					ent;
				}
				else{
					putchar('2');
					spa;
					write(cz[i].s1 );
					spa;
					write(cz[i].s2 );
					ent;
				}
			}
		}
		return 0;
	}
	if(T==3){
		while(T--){
			ff=0;
			read(n);
			read(m);
			read(k);
			for(int i=1;i<=m;i++)read(a[i]);
			dfs(1);
			write(op);
			ent;
			for(int i=1;i<=op;i++){
				if(cz[i].id ==1){
					putchar('1');
					spa;
					write(cz[i].s1 );
					ent;
				}
				else{
					putchar('2');
					spa;
					write(cz[i].s1 );
					spa;
					write(cz[i].s2 );
					ent;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
