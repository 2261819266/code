#include <bits/stdc++.h>
#define node(x,y,z) (node){x,y,z}
using namespace std;
const int N=310,K=620;
int T,n,m,k,a[N];
void dd(int &v)
{
	v=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		v=v*10+ch-48;
		ch=getchar();
	}
}
int pos[K],cao[N][2];
struct node
{
	int op,x,y;
};
void work_one()
{
	queue<int> dui;
	queue<node> ansd;
	dd(n);
	dd(m);
	dd(k);
	for(int i=1;i<n;++i)
	dui.push(i);
	for(int i=1,x;i<=m;++i)
	{
		dd(x);
		//cout<<pos[x]<<endl;
		if(!pos[x])
		{
			int t=dui.front();
			pos[x]=t;
			//printf("1 %d\n",pos[x]);
			ansd.push(node(1,pos[x],0));
			if(cao[t][0])
			{
				cao[t][1]=x;
				dui.pop();
			}
			else
			{
				cao[t][0]=x;
			}
		}
		else
		{
			if(cao[pos[x]][1]==x)
			{
				//printf("1 %d\n",pos[x]);
				ansd.push(node(1,pos[x],0));
				cao[pos[x]][1]=0;
				dui.push(pos[x]);
				pos[x]=0;
			}
			else
			{
				//printf("1 %d\n",n);
				//printf("2 %d %d\n",pos[x],n);
				ansd.push(node(1,n,0));
				ansd.push(node(2,pos[x],n));
				cao[pos[x]][0]=0;
				if(cao[pos[x]][1])
				swap(cao[pos[x]][0],cao[pos[x]][1]);
				dui.push(pos[x]);	
				pos[x]=0;		
			}
		}
	}
	printf("%d\n",ansd.size());
	while(!ansd.empty())
	{
		node t=ansd.front();
		if(t.op==1)
		{
			printf("1 %d\n",t.x);
		}
		else
		{
			printf("2 %d %d\n",t.x,t.y);
		}
		ansd.pop();
	}
}
void xun(int v,int &x,int &y)
{
	x=y=0;
	for(int j=1;j<=2;++j)
	for(int k=0;k<=1;++k)
	if(cao[j][k]==a[v])
	{
		x=j;
		y=k;
	}
}
void work_two()
{
	queue<node> ansd;
	dd(n);
	dd(m);
	dd(k);
	for(int i=1;i<=m;++i)
	dd(a[i]);
	for(int i=1;i<=m;++i)
	{
		int x=0,y=0;
		xun(a[i],x,y);
		if(x&&y)
		{
			if(y==1)
			{
				ansd.push(node(1,x,0));
				cao[x][y]=0;
				continue ;
			}
			ansd.push(node(1,2-x,0));
			ansd.push(node(2,1,2));
			//cao[]
			continue ;
		}
		xun(a[i+1],x,y);
		
		
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	dd(T);
	if(T%1000==1)
	{
		while(T--)
		{
			work_one();
		}
		return 0;
	}
	if(T%1000==2)
	{
		while(T--)
		{
			work_two();
		}
		return 0;
	}
	while(T--)
	work_one();
}
//freopen("meow.in","r",stdout) never g.....
/*
1001
3 6 4
1 2 3 2 3 1
8
1 1
1 1
1 2
1 1
1 3
2 2 3
1 3
2 1 3
4 10 6
1 2 3 6 2 3 1 6 5 5
14
1 1
1 1
1 2
1 2
1 1
1 4
2 2 4
1 4
2 1 4
1 4
2 2 4
1 3
1 4
2 3 4

*/









