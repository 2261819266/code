#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return f*x;
}
int T,n,k,m;
int a[2000001],b[2000001],c[2000001],d[2000001],totb=0,totc=0,totd=0;
int s[4000001];
void ss2(int op,int shu)
{
	if(!(op>2*m+1))
	{
		if(totb!=0&&totc!=0)
		{
			if(b[1]==c[1])//Õ»µ× 
		{
			for(int i=2;i<=max(totb,totc);i++)
			{
				b[i-1]=b[i];
				c[i-1]=c[i];
			}
			totb--;
			totc--;
			ss2(op+1,shu);
		}
		}
		if(shu==m+1)
		{
			if(totb==totc==0)
			{
				cout<<op<<endl;
				for(int i=1;i<=op;i++)
				{
					if(s[i]==0) cout<<2<<" "<<1<<" "<<2<<endl; 
					else cout<<1<<" "<<s[i]<<endl;
					}
				}
				return ;
			}
			if(b[totb]==a[shu])//Õ»¶¥ 
			{
				int nb=b[totb];
				b[totb]=0;
				totb--;
				s[op]=1;
				ss2(op+1,shu+1);
			}
			if(c[totc]==a[shu])
			{
				int nb=c[totc];
				c[totc]=0;
				totc--;
				s[op]=2;
				ss2(op+1,shu+1);
			}
			totb++;
			b[totb]=a[shu];
			s[op]=1;
			ss2(op+1,shu+1);
			totc++;
			c[totc]=a[shu];
			s[op]=2;
			ss2(op+1,shu+1);
			}
}
int main()
{
	//freopen("meow.in","r",stdin);
	//freopen("meow.out","w",stdout);
	cin>>T;
	while(T--)
	{
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)
			a[i]=read();
		if(n==2) ss2(1,1);
		else
		{
		 	cout<<"I really like C++.However,I can not do it well because I have learnt it for 1 years.By chance,I want to show my love with C++.Dear Âå¹ÈÐ¡·ÛÍÃ"<<endl;
		 }
	}
	return 0;
}
