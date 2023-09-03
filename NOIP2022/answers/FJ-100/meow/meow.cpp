#include<bits/stdc++.h>
using namespace std;//GCH bless me

#define ll long long
ll read()
{
	char c=getchar(); ll res=0, f=1;
	while(!isdigit(c)) {if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) {res=(res<<3)+(res<<1)+(c^48); c=getchar();}
	return res*f;
}
void write(ll x)
{
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int M=2e6+5,N=600;

int n,m,K,card[M],pre[M],nxt[M];

struct func {int s1,s2;};
func ans[M<<2]; int tot;

int sit[N],num[N],f1[N],f2[N];
set<int> unused;
struct data
{
	int val,id;
	bool operator < (const data &y) const {
		return val<y.val;
	}
};
set<data> pd;

void cls()
{
	tot=0;
	memset(sit,0,sizeof sit);
	memset(num,0,sizeof num);
	memset(f1,0,sizeof f1);
	memset(f2,0,sizeof f2);
	unused.clear(); pd.clear();
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	for(int subtask=1,T=read(); subtask<=T; ++subtask,cls())
	{
		n=read(), m=read(), K=read();
		for(int i=1;i<=m;++i) card[i]=read(), pre[i]=0, nxt[i]=0x3f;
		for(int i=1;i<=m;++i)
		{
			int x=card[i];
			nxt[pre[x]]=i, pre[x]=i;
		}
		for(int i=1;i<=n;++i) unused.insert(i);
		for(int i=1;i<=m;++i)
		{
			int col=card[i], id=sit[col];
			if(id && id<=n)
			{
				if(num[id]==1)
				{
					ans[++tot]=(func){id,0};
					pd.erase(pd.lower_bound((data){nxt[f1[id]],0}));
					f1[id]=num[id]=0; sit[col]=0;
					unused.insert(id);
				}
				else if(!unused.empty())
				{
					int tmp=*unused.begin();
					ans[++tot]=(func){tmp,0};
					ans[++tot]=(func){tmp,id};
					f1[id]=f2[id]; f2[id]=0; num[id]--;
					sit[card[f1[id]]]-=n; sit[col]=0;
					pd.insert((data){nxt[f1[id]],id});
				}
			}
			else if(id>n)
			{
				id-=n;
				ans[++tot]=(func){id,0};
				f2[id]=0; num[id]--; sit[col]=0;
				pd.insert((data){nxt[f1[id]],id});
			}
			else
			{
				if(!unused.empty())
				{
					int tmp=*unused.begin();
					ans[++tot]=(func){tmp,0};
					pd.insert((data){nxt[i],tmp});
					f1[tmp]=i; num[tmp]=1; sit[col]=tmp;
					unused.erase(unused.begin());
				}
				else
				{
					set<data>::iterator it=pd.begin();
					++it;
					if(it!=pd.end())
					{
						ans[++tot]=(func){it->id,0};
						num[it->id]=2; f2[it->id]=i; sit[col]=it->id + n;
						pd.erase(it);
					}
				}
			}
//			printf("!!!%d:\n",col);
//			for(int j=1;j<=n;++j)
//			{
//				printf("%d : %d %d %d\n",j,num[j],f1[j],f2[j]);
//			}
		}
		write(tot); putchar('\n');
		for(int i=1;i<=tot;++i)
		{
			printf("%d ",ans[i].s2 ? 2:1);
			if(ans[i].s2) write(ans[i].s1), putchar(' '), write(ans[i].s2), putchar('\n');
			else write(ans[i].s1), putchar('\n');
		}
	}
}
/*
4
2 4 2
1 2 1 2

2 8 3
1 2 3 3 3 2 1 3

3 10 5
1 2 3 4 5 2 3 1 5 4

3 10 5
1 2 3 4 5 2 3 4 5 1
*/
