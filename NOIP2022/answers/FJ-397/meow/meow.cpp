#include<bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define GC c=getchar()
#define IG isdigit(c)
using namespace std;
const int N=2e6+5;
template <class T=int>T qread(T x=0,char GC,bool f=1)
{
	for(;!IG;GC) f=c!='-';
	for(;IG;GC) x=x*10+(c^48);
	return f?x:-x;
}
int a[N],p[N][3];
bool b[N];
int n,m,k,T;
int down=1,num=0;
signed main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=qread();
	if(T%10==2)
	{
		while(T--)
		{
			n=qread(),m=qread(),k=qread();
			num=0,down=1;
			memset(b,false,m);
			f(i,1,m,1)
			{
				a[i]=qread();
				if(a[i]==p[down][1])
				{
					num++;
					p[num][2]=i;
					down++;
					while(b[down]==true) down++;
				}
				else
				{
					p[i-num][1]=i;
					if(a[i]==a[i-1]) 
					{
						b[i]=true;
						b[i-1]=true;
					}
				}
			}
			printf("%d\n",n+num*2);
			down=1;
			f(i,1,n+num,1)
			{
				if(i==p[down][2]) 
				{
					printf("1 2\n");
					printf("2 1 2\n");
					down++;
				}
				else printf("1 1\n");
			}
		}	
	}
	else
	{
		while(T--)
		{
			n=qread(),m=qread(),k=qread();
			printf("%d\n",m); 
			f(i,1,m,1) 
			{
				a[i]=qread();
				printf("1 1\n");
			}
		}
	}
	return 0;
}
