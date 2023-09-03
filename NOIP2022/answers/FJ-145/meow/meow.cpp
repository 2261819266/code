#include<bits/stdc++.h>
using namespace std;
int n,m,k,vec_t,tot,st_t,Test_num,Vec_t=0,ept;
int a[2000002],siz[302],to[602],typ[602],st[2000002],cnt[602],Vec[602];
int num[302][2];
struct info
{
	int o,x,y;
}vec[4000002];
inline void ins(int o,int x,int y)
{
	vec[++vec_t]=(info){o,x,y};
}
inline void clear()
{
	for(;Vec_t;--Vec_t)cnt[Vec[Vec_t]]=0;
}
inline void add(int x)
{
	if(!cnt[x])Vec[++Vec_t]=x;
	++cnt[x];
}
inline void Del(int x,int o)
{
	if(typ[x]==0)//buttom
	{
		if(o)ins(1,ept,0),ins(2,to[x],ept);
		num[to[x]][0]=num[to[x]][1],num[to[x]][1]=0;
		--siz[to[x]];
		if(siz[to[x]])typ[num[to[x]][0]]=0;
	}
	else//top
	{
		if(o)ins(1,to[x],0);
		--siz[to[x]];
	}
	if(siz[to[x]]==1 && to[x]!=ept)st[++st_t]=to[x];
	to[x]=0,--tot;
}
inline void Ins(int x)
{
	for(;st_t && siz[st[st_t]]==2;--st_t);
	assert(st_t);
	ins(1,st[st_t],0);
	to[x]=st[st_t];
	typ[x]=siz[st[st_t]];
	num[to[x]][typ[x]]=x;
	++siz[st[st_t]];
	if(siz[st[st_t]]==2)--st_t;
}
inline void Print()
{
	printf("  ept:%d vec_t:%d\n",ept,vec_t);
	printf("  (to,typ):");for(int i=1;i<=k;++i)printf("(%d,%d)%c",to[i],typ[i],i==k? '\n':' ');
	printf("  (num0,num1,siz):");for(int i=1;i<=n;++i)printf("(%d,%d,%d)%c",num[i][0],num[i][1],siz[i],i==n? '\n':' ');
}
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;
}
template<class T>void write(T x)
{
	if(x>9)write(x/10);
	putchar((x%10)^48);
}
inline void solve()
{
	read(n),read(m),read(k),vec_t=tot=st_t=0,ept=n;
	for(int i=1;i<=m;++i)read(a[i]);
	for(int i=1;i<=n;++i)siz[i]=num[i][0]=num[i][1]=0;
	for(int i=1;i<n;++i)st[++st_t]=i;
	for(int i=1;i<=k;++i)to[i]=typ[i]=0;
	for(int i=1,j;i<=m;++i)
	{
		//printf("i:%d\n",i);
		//Print();
		
		if(to[a[i]])Del(a[i],1);
		else
		{
			++tot;
			if(tot<=2*n-2)Ins(a[i]);
			else
			{
				for(j=i+1;j<=m;++j)
				{
					//printf("  j:%d\n",j);
					if(a[j]!=a[i] && typ[a[j]]==1)continue;
					clear();
					for(int k=i+1;k<j;++k)add(a[k]);
					if(a[j]==a[i])
					{
						//puts(" CS 3");
						ins(1,ept,0);
						for(int k=i+1;k<j;++k)ins(1,to[a[k]],0);
						for(int k=1;k<=Vec_t;++k)if(cnt[Vec[k]]&1)Del(Vec[k],0);
						ins(1,ept,0),--tot;
						break;
					}
					if(typ[a[j]]==0)
					{
						if(cnt[num[to[a[j]]][1]]&1)
						{
							//puts(" CS 1");
							ins(1,to[a[i]]=ept,0),st[++st_t]=ept,ept=to[a[j]];
							for(int k=i+1;k<j;++k)ins(1,to[a[k]],0);
							for(int k=1;k<=Vec_t;++k)if(cnt[Vec[k]]&1)Del(Vec[k],0);
							ins(1,to[a[j]],0),Del(a[j],0),num[to[a[i]]][0]=a[i],++siz[to[a[i]]],typ[a[i]]=0;
						}
						else
						{
							//puts(" CS 2");
							ins(1,to[a[i]]=to[a[j]],0);
							//printf("   vec_t:%d\n",vec_t);
							for(int k=i+1;k<j;++k)ins(1,to[a[k]],0);
							//printf("   vec_t:%d\n",vec_t);
							for(int k=1;k<=Vec_t;++k)if(cnt[Vec[k]]&1)Del(Vec[k],0);
							ins(1,ept,0),ins(2,to[a[j]],ept),Del(a[j],0),num[to[a[i]]][1]=a[i],++siz[to[a[i]]],typ[a[i]]=1;
						}
						break;
					}
				}
				assert(j<=m);
				i=j;
			}
		}
	}
	write(vec_t),putchar('\n');
	for(int i=1;i<=vec_t;++i)
	{
		if(vec[i].o==1)write(vec[i].o),putchar(' '),write(vec[i].x),putchar('\n');
		else write(vec[i].o),putchar(' '),write(vec[i].x),putchar(' '),write(vec[i].y),putchar('\n');
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&Test_num);
	for(;Test_num--;)solve();
	return 0;
}
