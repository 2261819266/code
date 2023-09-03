#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
const int N=2e6+10;
int T,n,m,k,a[N],op=0;
int ans[N][3];
int s1[N],s1h=0,s1e=0;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--)
	{
		op=0;
		n=read();m=read();k=read();
		for(int i=1;i<=m;++i)
		{
			a[i]=read();
		}
		int pai=1;
		while(++op)
		{
			if(pai==m+1)break; 
			if(s1h==s1e)
			{
				s1[s1h]=a[pai++];
				s1e++;
				ans[op][0]=1,ans[op][1]=1;
			}
			else
			{
				if(s1[s1h]==a[pai])
				{
					s1h++;
					pai++;
					ans[op][0]=1,ans[op][1]=1;
				}
				else if(s1[s1e-1]==a[pai])
				{
					ans[op][0]=1,ans[op][1]=2;
					op++;
					ans[op][0]=2,ans[op][1]=1,ans[op][2]=2;
					s1e--;
					pai++;
				}
				else
				{
					s1[--s1h]=a[pai];
					pai++;
					ans[op][0]=1,ans[op][1]=1;
				}
			}
		}
		cout<<--op<<endl;
		for(int i=1;i<=op;++i)
		{
			cout<<ans[i][0]<<' '<<ans[i][1];
			if(ans[i][0]==2)cout<<" "<<ans[i][2];
			cout<<endl;
		}
	}
	return 0;
 } 
