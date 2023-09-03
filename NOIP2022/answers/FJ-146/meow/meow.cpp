#include<cstdio>
#include<deque>
const int M=2e6+7;
bool opz[M+M];
int opx[M+M],opy[M+M],t;
void push(int x){opz[++t]=0;opx[t]=x;}
void comb(int x,int y){opz[++t]=1;opx[t]=x;opy[t]=y;}
void res()
{
	printf("%d\n",t);
	for(int i=1;i<=t;++i)
		if(opz[i])printf("2 %d %d\n",opx[i],opy[i]);
		else printf("1 %d\n",opx[i]);
}
void read(int&x)
{
	int ch;while((ch=getchar())>'9'||ch<'0');
	x=ch^48;while((ch=getchar())>='0'&&ch<='9')x=x*10+(ch^48);
}
int a[M],stk[307][27],tp[307];
void popup(int F){stk[F][tp[F]--]=0;}
void popdown(int F)
{
	stk[F][tp[F]-1]=stk[F][tp[F]];
	stk[F][tp[F]--]=0;
}
int Dm,Dn,p[17];
std::deque<int> dq[17];
bool dfs(int x)
{
	if(x==Dm+1)
	{
		t=0;for(int i=1;i<=Dn;++i)dq[i].clear();
		for(int i=1;i<=Dm;++i)
		{
			if(!dq[p[i]].empty()&&dq[p[i]].back()==a[i])dq[p[i]].pop_back();
			else dq[p[i]].push_back(a[i]);
			push(p[i]);
			bool flg=1;
			while(flg)
			{
				flg=0;
				if(!dq[1].empty()&&!dq[2].empty()&&dq[1].front()==dq[2].front())comb(1,2),dq[1].pop_front(),dq[2].pop_front(),flg=1;
				if(!dq[1].empty()&&!dq[3].empty()&&dq[1].front()==dq[3].front())comb(1,3),dq[1].pop_front(),dq[3].pop_front(),flg=1;
				if(!dq[3].empty()&&!dq[2].empty()&&dq[3].front()==dq[2].front())comb(3,2),dq[3].pop_front(),dq[2].pop_front(),flg=1;
			}
		}
		for(int i=1;i<=Dn;++i)if(!dq[i].empty())return 0;
		return 1;
	}
	for(int i=1;i<=3;++i){p[x]=i;if(dfs(x+1))return 1;}
	return 0;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int n,m,T,x;read(T);
	for(int cas=1;cas<=T;++cas)
	{
		read(n);read(m);
		read(t);t=0;
		if(T==1001)
		{
			for(int i=1;i<=m;++i)
			{
				read(x);int F=(x+1)>>1;
				if(stk[F][1]!=x)push(F),stk[F][++tp[F]]=x;
				else push(n),comb(F,n),popdown(F);
			}
			res();continue;
		}
		for(int i=1;i<=m;++i)read(a[i]);
		if(n==2)
		{
			for(int i=1;i<=m;++i)
			{
				x=a[i];
				if(stk[1][tp[1]]==x){push(1),popup(1);continue;}
				if(stk[2][tp[2]]==x){push(2),popup(2);continue;}
				if(!tp[2]&&stk[1][1]==x){push(2),comb(1,2),popdown(1);continue;}
				if(!tp[1]&&stk[2][1]==x){push(1),comb(1,2),popdown(2);continue;}
				if(tp[1]+tp[2]<2){push(1);stk[1][++tp[1]]=x;continue;}
				if(tp[1]==2)
				{
					if(a[i+1]==stk[1][2])push(2),push(1),stk[2][tp[2]=1]=x,popup(1);
					else push(1),push(2),comb(1,2),stk[1][1]=stk[1][2],stk[1][2]=x;
					++i;continue;
				}
				if(tp[2]==2)
				{
					if(a[i+1]==stk[2][2])push(1),push(2),stk[1][tp[1]=1]=x,popup(2);
					else push(2),push(1),comb(1,2),stk[2][1]=stk[2][2],stk[2][2]=x;
					++i;continue;
				}
				if(a[i+1]==stk[1][1])push(2),push(1),popup(1),stk[2][++tp[2]]=x;
				else push(1),push(2),popup(2),stk[1][++tp[1]]=x;
				++i;
			}
		}
		else Dm=m,Dn=n,p[1]=1,dfs(2);
		res();
	}
}
