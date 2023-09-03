#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x(0),f(1);char c=getchar();
	while(c<'0'||c>'9')f=c=='-'?-1:1,c=getchar();
	while(c<='9'&&c>='0')x=x*10+c-48,c=getchar();
	return f*x;
}
const int N=2000010;
int a[N],n,m,k;
int q[N][3];
int sz[N],_0;
struct node{int opt,l,r;node(int OPT,int L,int R=0){opt=OPT,l=L,r=R;}};
vector<node>ans;
int qk[N],cnt;//0->wei cha ru;1->xia;2->shang;
void turn(int a,int qwq)
{
	if(a==0)return;
	if(qk[a]==0&&qwq!=0)cnt++;
	if(qk[a]!=0&&qwq==0)cnt--;
	if(!qk[a]||qwq==0)qk[a]=qwq;
}
void change(int t,int add)
{
	if(add==1&&t==_0)_0=-1;
	sz[t]+=add;
	if(sz[t]==0&&_0==-1)_0=t;
}
void push(int a,int t)
{
	if(!q[t][0])q[t][0]=a,turn(a,2*t),change(t,1);
	else if(!q[t][1])
	{
		if(q[t][0]==a)q[t][0]=0,turn(a,0),change(t,-1);
		else q[t][1]=a,turn(a,2*t+1),change(t,1);
	}
	else if(q[t][1]==a)q[t][1]=0,turn(a,0),change(t,-1);
	else q[t][2]=a,change(t,1);
}
int check()
{
	for(int i=1;i<=n;i++)if(i!=_0)
	if(sz[i]<=1)return i;
}
void pop(int x,int y)
{
	if(q[x][0]!=q[y][0])exit(1919810);
	turn(q[x][0],0);turn(q[x][1],0);turn(q[y][1],0);turn(q[x][2],0);turn(q[y][2],0);
	turn(q[x][1],x*2);turn(q[y][1],y*2);turn(q[x][2],x*2+1);turn(q[y][2],y*2+1);
	q[x][0]=q[x][1];q[y][0]=q[y][1];
	q[x][1]=q[x][2];q[y][1]=q[y][2];
	q[x][2]=q[y][2]=0;change(x,-1);change(y,-1);
}
//void debug()
//{
//	cerr<<"debug"<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		cerr<<sz[i]<<" "<<q[i][0]<<" "<<q[i][1]<<" "<<q[i][2]<<endl;
//	}
//	for(int i=1;i<=k;i++)cerr<<qk[i]<<" ";cerr<<endl;
//	cerr<<_0<<" "<<cnt<<endl;
//	cerr<<"done"<<endl;
//}
void print(int a,int opt,int l,int r=0)
{
//	cerr<<"print:"<<a<<" "<<opt<<" "<<l<<" "<<r<<endl;
	if(opt==1)push(a,l),ans.push_back(node(opt,l));
	else pop(l,r),ans.push_back(node(opt,l,r));
//	debug();
}
void out()
{
	printf("%d\n",ans.size());
	for(auto x:ans)
	{
		if(x.opt==1)printf("1 %d\n",x.l);
		else printf("2 %d %d\n",x.l,x.r);
	}
	ans.clear();
}
bool fd[N];
int main()
{
	freopen("meow.in","r",stdin);freopen("meow.out","w",stdout);
	int T=read();
	while(T--)
	{
		for(int i=1;i<=n;i++)q[i][0]=q[i][1]=q[i][2]=0,sz[i]=0;
		
		n=read(),m=read(),k=read();
		if(k==2*n-2)
		{
			for(int i=1;i<=m;i++)a[i]=read();
			for(int i=1;i<=m;i++)
			{
				int t=(a[i]+1)/2;
				if((!q[t][0])||(!q[t][1])||q[t][1]==a[i])print(a[i],1,t);
				else print(a[i],1,n),print(a[i],2,t,n);
			}
			out();
		}
		else
		{
			_0=n;
			for(int i=1;i<=m;i++)a[i]=read();
			for(int i=1;i<=m;i++)
			{
				if(cnt==k-1&&qk[a[i]]==0)
				{
					for(int j=i+1;j<=m;j++)
					if(qk[a[j]]%2==0)
					{
						if(fd[qk[a[j]]/2])print(a[i],1,_0);
						else print(a[i],1,qk[a[j]]/2);
						for(int k=j;k>=i+1;k--)fd[a[k]]=0;
						break;
					}
					else fd[qk[a[j]]/2]=1;
				}
				else
				{
					if(qk[a[i]]==0)print(a[i],1,check());
					else if(qk[a[i]]%2==0)
					{
						int nw=_0;print(a[i],1,nw),print(a[i],2,qk[a[i]]/2,nw);
					}
					else if(qk[a[i]]%2==1)print(a[i],1,qk[a[i]]/2);
				}
			}
			out();
		}
	}
	return 0;
}