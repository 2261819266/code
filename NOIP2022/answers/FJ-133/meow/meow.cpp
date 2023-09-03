#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n,m,k,knh,az,last;
int a[N],b[N],c[N];
int ans[N],ans1[N];
int A[N][3];
int read()
{
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	while(T--)
	{
	n=read();m=read();read();
	for(int i=1;i<=m;i++)a[i]=read();
	queue<int>p1,p2;
	for(int i=1;i<n;i++)p1.push(i);
	int top1=n-1,top2=0;
	for(int i=1;i<=m;i++)
	{
		int x=a[i];
		if(!b[x]&&k+1<=2*n-2)
		{
			k++;
//			cout<<i<<" "<<top1<<" "<<top2<<endl;
			if(top2)
			A[p2.front()][2]=x,c[x]=p2.front(),p2.pop(),top2--;
			else 
			A[p1.front()][1]=x,c[x]=p1.front(),p1.pop(),p2.push(c[x]),top1--,top2++;
			b[x]=i;
		}
		else
		{
//			cout<<i<<" "<<k<<endl;
			if(b[x])
			{
				int x1=a[i+1],y=c[x1];
				if(A[y][2]==x1)
				{
					ans[b[x1]]=n;ans[i+1]=n;
					c[x]=c[x1];A[y][2]=x;
				}
				else
				{
					ans[b[x1]]=y;ans[i+1]=n;ans1[i+1]=y;
					c[x]=c[x1];A[y][1]=A[y][2];A[y][2]=x;
				}
				b[x]=0;k--;
				i++;
			}
			else
			{
				int y=c[x];
				if(A[y][2]==x)ans[b[x]]=y,ans[i]=y,p2.push(y),top2++,A[y][2]=0;
				else if(A[y][2]==0)ans[b[x]]=y,ans[i]=n,ans1[i]=y,top1++,p1.push(y),A[y][1]=0;
				else ans[b[x]]=y,ans[i]=n,ans1[i]=y,p2.push(y),A[y][1]=A[y][2];
			}
		}
	}
	for(int i=1;i<=m;i++)if(ans1[i])az++;
	cout<<az+m<<endl;
	for(int i=1;i<=m;i++)
	{if(ans[i]==0)ans[i]=1;
		printf("1 %d\n",ans[i]);
		if(ans1[i])
		printf("2 %d %d\n",ans1[i],ans[i]);
	}
}}

