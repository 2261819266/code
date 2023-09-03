#include<bits/stdc++.h>
using namespace std;
int T,n,m,kk,a[2000001],op,h,t;
struct node{
	int fr,s[301],step,s1,s2,num;
	bool f,b;
	bool empty()
	{
		for(int i=0;i<n;i++)
			if(s[i])
				return 0;
		return num;
	}
	int ssize(int n)
	{
		int r=1;
		while(s[n]/r>9)r*=10;
		return r;
	}
	int stop(int n)
	{
		return s[n]/ssize(n);
	}
	void spush(int n,int a)
	{
		s[n]=s[n]*10+a;
		if(s[n]%10==(s[n]/10)%10)
			s[n]/=100;
	}
}q[40001];
void out(int h)
{
	if(h==0)
		return;
	out(q[h].fr);
	if(q[h].f)
		cout<<"1 "<<q[h].s1<<endl;
	else
		cout<<"2 "<<q[h].s1<<" "<<q[h].s2<<endl;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>kk;
		for(int i=0;i<m;i++)
			cin>>a[i];
		h=1;t=0;q[0].num=m;
		while(t<h)
		{
			if(q[t].step<=2*m&&q[t].num)
				for(int i=0;i<=n;i++)
				{
					if(i<n)
					{
						q[++h].fr=t;q[h].step=q[t].step+1,q[h].s1=i+1;
						q[h].spush(i,a[q[t].num--]);
						for(int k=0;k<n;k++)
							q[h].s[k]=q[t].s[k];
						if(q[h].empty())
						{
							out(h);
							t==h;
							break;
						}
					}
					else
					{
						for(int ss=0;ss<n;ss++)
						{
							if(q[t].s[ss])
							{
								for(int k=0;k<n;k++)
								{
									if(ss!=k&&q[t].s[k]&&q[t].stop(ss)==q[t].stop(k))
										q[++h].s[n]=q[t].s[n]-q[t].stop(ss)*q[t].ssize(ss),q[h].fr=t;q[h].step=q[t].step+1,q[h].s1=k+1,q[h].s2=ss+1;
								}
							}
						}
					}
				}
			t++;
		}
	}
}
