#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	while(isdigit(c))x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return x*f;
}
const int N=310,M=2e6+10;
int n,m,k,a[N];
int cnt,op[M],s1[M],s2[M];
int s[N][N*2],l[N],tp[N],flag;
void dfs(int x,int sum1,int sum2,int tot){
	if(flag)return;
	if(tot>m*2)return;
	if(!sum1&&!sum2){
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++){
			printf("%d ",op[i]);
			if(op[i]==1){
				printf("%d\n",s1[i]);
			}
			else {
				printf("%d %d\n",s1[i],s2[i]);
			}
		}
		flag=1;
		return;
	}
	for(int i=1;i<=n;i++){
		int tmp=s[i][tp[i]],tmp2=tp[i];
		s[i][++tp[i]]=a[x];int delta=0;
		if(s[i][tp[i]-1]==s[i][tp[i]])tp[i]-=2,delta=2;
		op[++cnt]=1,s1[cnt]=i;
		dfs(x+1,sum1-1,sum2+1-delta,tot+1);
		cnt--;
		s[i][tmp2]=tmp;
		tp[i]=tmp2;
	}
	if(s[1][l[1]]==s[2][l[2]]&&l[2]<=tp[2]&&l[1]<=tp[1]){
		op[++cnt]=2,s1[cnt]=1,s2[cnt]=2;
		l[1]++,l[2]++;
		dfs(x,sum1,sum2-2,tot+1);
		cnt--;
	}
	if(s[1][l[1]]==s[3][l[3]]&&n>2&&l[1]<=tp[1]&&l[3]<=tp[3]){
		op[++cnt]=2,s1[cnt]=1,s2[cnt]=3;
		l[1]++,l[3]++;
		dfs(x,sum1,sum2-2,tot+1);
		cnt--;
	}
	if(s[2][l[2]]==s[3][l[3]]&&n>2&&l[2]<=tp[2]&&l[3]<=tp[3]){
		op[++cnt]=2,s1[cnt]=2,s2[cnt]=3;
		l[2]++,l[3]++;
		dfs(x,sum1,sum2-2,tot+1);
		cnt--;
	}
}
void solve(){
	flag=0;
	cnt=0;
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)l[i]=1,tp[i]=0;
	for(int i=1;i<=m;i++)a[i]=read();
	dfs(1,m,0,0);
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--)solve();
	return 0;
}

