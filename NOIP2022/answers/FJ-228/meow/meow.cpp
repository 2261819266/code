#include<bits/stdc++.h>
using namespace std;
ifstream fin("meow.in",ios::in);
ofstream fout("meow.out",ios::out);
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drp(i,r,l) for(int i=r;i>=l;i--)
#define int long long
#define MAX_N  400
int T,n,m,k;

inline int read() {
	int x=0,f=1;
	char c=fin.get();
	while(c<'0'||c>'9') {
		if(c=='-')f=-f;
		c=fin.get();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=fin.get();
	}
	return x*f;
}
int a2[MAX_N];
int l,r;
string ans;
int sum=0;
void s2() {

	sum=0;
	memset(a2,0,sizeof(a2));
	l=1,r=0;
	while(m--) {

		int x=read();

		if(l<=r&&a2[r]==x) {
//			printf("%d %d %d .\n",l,r,x);
			ans+="1 1\n";
			r--;
			sum++;
		} else if(l<=r&&a2[l]==x) {
			l++;
			ans+="1 2\n";
			ans+="2 1 2\n";
			sum+=2;
		} else {
			sum++;
			ans+="1 1\n";
			a2[++r]=x;
		}

	}
	fout<<sum<<'\n'<<ans;
}
int a[10000];
int d1[10000],d2[10000],l1,l2,r1,r2;

bool dsf3(int x,int s,string aans) {
	if(x>m) {
		if(r1<l1&&r2<l2) {
			
				fout<<s<<'\n'<<aans;
				return 1;
			

		}
		
		return 0;
	}
	int ss=s;
	if(l1<=r1&&a[x]==d1[r1])
	{
		aans+="1 1\n";
		r1--;ss++;
		dsf3(x+1,ss,aans);
		r1++;ss--;
	}
	else if(l1<=r1&&a[x]==d1[l1])
	{
		ans+=string("1 3\n");
		ans+=string("2 1 3\n");
		ss+=2;
		dsf3(x+1,ss,aans);
		ss-=2;
	}
	else if(l2<=r2&&a[x]==d2[r2])
	{
		ans+="1 2\n";
		ss++;
		r2--;
		dsf3(x+1,ss,aans);
		r2++;
		l2--;
	}
	else if(l2<=r2&&a[x]==d2[l2])
	{
		ans+="1 3\n";
		ans+="2 2 3\n";
		ss+=2;
		dsf3(x+1,ss,aans);
		ss-=2;
	}
	else
	{
		ss++;
		string temp=ans;
		temp+="1 1\n";
		d1[++r1]=a[x];
		dsf3(x+1,ss,temp);
		r1--;
		s--;
		
		ss++;
		temp=ans;
		temp+="1 2\n";
		d1[++r2]=a[x];
		dsf3(x+1,ss,temp);
		r2--;
		s--;
		
	}
	
	
}
void s3() {
	a[0]=0;
	rep(i,1,m)a[i]=read();
	sum=0;
	l1=0,l2=0,r1=0,r2=0;
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
	dsf3(1,0,string());

}
main() {
	
	T=read();
	while(T--) {
		n=read();
		m=read();
		k=read();
		if(n==2)s2();
		if(n==3)s3();
	}
}
