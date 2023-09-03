#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

#define inf 0x3f3f3f3f3f3f3f3f
#define int unsigned long long

using namespace std;

struct node
{
	int l,r,summ;
	int tag1,tag2;
}p[300000];
struct bian
{
	int l,r,h;
	int a1,a2,id;
	bool tag;
}s[300000];
struct node2
{
	int l,r,id;
}ques[300000];

int ans[300000]={};
int lefa[300000],riga[300000],lefb[300000],rigb[300000],q[300000],top=0;
int a[300000],b[300000];
int n,m,len=0;

inline int rd()
{
	int s=0;char x='x';
	while(x<'0'||x>'9')x=getchar();
	while(x>='0'&&x<='9')s=s*10+(x^48),x=getchar();
	return s;
}

void build(int u,int l,int  r)
{
	p[u].l=l;p[u].r=r;p[u].tag1=p[u].tag2=1;
	if(l==r){p[u].summ=1;return;}
	build(u*2,l,(l+r)/2);build(u*2+1,(l+r)/2+1,r);
	p[u].summ=p[u*2].summ+p[u*2+1].summ; 
}

void push_down(int u)
{
	if(p[u].l==p[u].r)return;
	//p[u*2].tag1=p[u*2+1].tag1=p[u].tag1;
	p[u*2].tag1*=p[u].tag1;p[u*2+1].tag1*=p[u].tag1;
	p[u*2].tag2*=p[u].tag2;p[u*2+1].tag2*=p[u].tag2;
	//p[u*2].tag2=p[u*2+1].tag2=p[u].tag2;
	p[u*2].summ*=p[u].tag1;p[u*2+1].summ*=p[u].tag1;
	p[u*2].summ/=p[u].tag2;p[u*2+1].summ/=p[u].tag2;
	p[u].tag1=p[u].tag2=1;
}

void change1(int u,int l,int r,int s)
{
	if(l>p[u].r||r<p[u].l)return;
	if(l<=p[u].l&&p[u].r<=r){p[u].tag1*=s;p[u].summ*=s;return;}
	push_down(u);
	change1(u*2,l,r,s);change1(u*2+1,l,r,s);
	p[u].summ=p[u*2].summ+p[u*2+1].summ; 
}

void change2(int u,int l,int r,int s)
{
	if(l>p[u].r||r<p[u].l)return;
	if(l<=p[u].l&&p[u].r<=r){p[u].tag2*=s;p[u].summ/=s;return;}
	push_down(u);
	change2(u*2,l,r,s);change2(u*2+1,l,r,s);
	p[u].summ=p[u*2].summ+p[u*2+1].summ; 
}

int getsum(int u,int l,int r)
{
	if(l>p[u].r||r<p[u].l)return 0;
	if(l<=p[u].l&&p[u].r<=r)return p[u].summ;
	push_down(u);
	return (getsum(u*2,l,r)+getsum(u*2+1,l,r)); 
}

void readd()
{
	rd();n=rd();
	for(int i=1;i<=n;i++)
		a[i]=rd();
	for(int i=1;i<=n;i++)
		b[i]=rd();
	m=rd();
	for(int i=1;i<=m;i++)
	{
		ques[i].l=rd();
		ques[i].r=rd();
		ques[i].id=i;
	}
}

bool cmp1(bian x,bian y)
{
	return ((x.h==y.h)?x.id<y.id:x.h<y.h);
}

void awake()
{
	a[0]=a[n+1]=b[0]=b[n+1]=inf;
	 
	top=1;q[1]=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&a[q[top]]<a[i])top--;
		lefa[i]=q[top]+1;
		q[++top]=i; 
	}
	top=1;q[1]=0;
	for(int i=1;i<=n;i++)
	{
		while(top&&b[q[top]]<b[i])top--;
		lefb[i]=q[top]+1;
		q[++top]=i; 
	}
	top=1;q[1]=n+1;
	for(int i=n;i;i--)
	{
		while(top&&a[q[top]]<a[i])top--;
		riga[i]=q[top]-1;
		//cout<<i<<' '<<"top="<<q[top]<<endl; 
		q[++top]=i; 
	}
	top=1;q[1]=n+1;
	for(int i=n;i;i--)
	{
		while(top&&b[q[top]]<b[i])top--;
		rigb[i]=q[top]-1;
		q[++top]=i; 
	}
	
	for(int i=1;i<=n;i++)
	{
		//change1(1,lefa[i],i,a[i]);
		s[++len]={lefa[i],i,i,a[i],1,0,0};
		s[++len]={lefa[i],i,riga[i]+1,1,a[i],0,0};
		s[++len]={lefb[i],i,i,b[i],1,0,0};
		s[++len]={lefb[i],i,rigb[i]+1,1,b[i],0,0};
		//cout<<len<<endl;
	}
	//for(int i=1;i<=m;i++)
	//{
	//	s[++len]={ques[i].l,ques[i].r,ques[i].l-1,1,1,ques[i].id,0};
	//	s[++len]={ques[i].l,ques[i].r,ques[i].r,1,1,ques[i].id,1};
	//}
	
	sort(s+1,s+1+len,cmp1);
	//for(int i=1;i<=len;i++)
	//	cout<<s[i].h<<"!!!\n";
}

void working()
{
	//cout<<"m="<<m<<endl;
	for(int h=0,i=0;h<=n+10;h++)
	{
		//if(h%100==0)cout<<"h="<<h<<' '<<s[i+1].h<<endl;
		while(i<len&&s[i+1].h==h)
		{
			i++;
			//cout<<h<<':'<<s[i].l<<' '<<s[i].r<<' '<<s[i].id<<endl;
			if(s[i].id==0)
			{
				change1(1,s[i].l,s[i].r,s[i].a1);
				change2(1,s[i].l,s[i].r,s[i].a2);
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(ques[j].l<=h&&h<=ques[j].r)
			{
				ans[ques[j].id]+=getsum(1,ques[j].l,min(ques[j].r,h));
			}
		}
		//ans[ques[1].id]+=getsum(1,ques[1].l,min(ques[1].r,h));
		//cout<<"h="<<h<<':'<<getsum(1,1,min(ques[1].r,h))<<' '<<(ques[1].l<=h&&h<=ques[1].r)<<endl; 
		//cout<<ans[ques[1].id]<<endl;
	}
}

void print()
{
	/*for(int i=1;i<=n;i++)
	{
		cout<<i<<':'<<lefa[i]<<' '<<riga[i]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<i<<':'<<lefb[i]<<' '<<rigb[i]<<endl;
	}*/
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;
	}
}

signed main()
{
	//freopen("match1.in","r",stdin);
	//freopen("match2.in","r",stdin);
	freopen("mathch.in","r",stdin);
	freopen("match.out","w",stdout);
	
	readd(); 
	
	awake();
	
	build(1,0,n+1);
//	cout<<"!!!\n";
	working();
//	cout<<"!!!\n";
	print();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
