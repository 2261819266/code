#include <bits/stdc++.h>
using namespace std;
int t,n,qq,l,r;
int a[3030],b[3030],f[3030][16][3],me[3030][3030][3];
int logg[3030]; 
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();} 
	return x;
}
void print(long long x)
{
	if(x>9) print(x/10);
	putchar('0'+(x%10));
}
int que(int p,int q,int op)
{
	if(me[p][q][op]) return me[p][q][op];
	int k=logg[q-p+1];
	me[p][q][op]=max(f[p][k][op],f[q-(1<<k)+1][k][op]);
	return me[p][q][op];
}
void stpre()
{
	logg[0]=-1;
	for(int i=1;i<=n;i++) logg[i]=logg[i>>1]+1;
	for(int i=1;i<=n;i++) f[i][0][1]=a[i],f[i][0][2]=b[i];
	for(int j=1;j<=logg[n];j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j][1]=max(f[i][j-1][1],f[i+(1<<(j-1))][j-1][1]),f[i][j][2]=max(f[i][j-1][2],f[i+(1<<(j-1))][j-1][2]);
	return;
}
void solve()
{
    long long ans=0;
	for(int p=l;p<=r;p++)
		for(int q=p;q<=r;q++)
			ans+=que(p,q,1)*que(p,q,2);
	print(ans);printf("\n");
	return;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read(),n=read();
	for(register int i=1;i<=n;i++) a[i]=read();
	for(register int i=1;i<=n;i++) b[i]=read();
	stpre();
	qq=read();
	while(qq--)
	{
		l=read(),r=read();
		solve();
	}
	fclose(stdin);
    fclose(stdout);
	//system("pause");
	return 0;
}
