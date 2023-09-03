#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MOD=998244353;
int tg,id,n,m,v,f;
char c[1001][1001];

inline int rad(){
	int res=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res*w;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	tg=rad(),id=rad();
	for(int k=1;k<=tg;++k)
	{
		n=rad(),m=rad(),v=rad(),f=rad();
		bool flag1=false,flag2=false;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			cin>>c[i][j];
			if((j%3==0&&c[i][j]=='0')||(j%3!=0&&c[i][j]=='1'))
			flag1=true;
			if((i%4==0&&c[i][j]=='0')||(i%4!=0&&c[i][j]=='1'))
			flag2=true;
			
		}
		if(v==0&&f==0)
		{
			printf("%d %d\n",0%MOD,0%MOD);
			continue;
		 }
		if(n==3&&m==2)
		{
        if(c[1][1]=='0'&&c[1][2]=='0'&&c[2][1]=='0'&&c[3][1]=='0'&&c[3][2]=='0')
				printf("%d %d\n",1*v%MOD,0%MOD);
		    else printf("%d %d\n",0,0);
		    continue;
		}
		
		if(n==4&&m==2)
		{
			int s1=0,s2=0;
			if(c[1][1]=='0'&&c[1][2]=='0'&&c[2][1]=='0'&&c[3][1]=='0'&&c[3][2]=='0')
			s1++;
			if(c[1][1]=='0'&&c[1][2]=='0'&&c[2][1]=='0'&&c[3][1]=='0'&&c[4][1]=='0'&&c[4][2]=='0')
			s1++;
			if(c[2][1]=='0'&&c[2][2]=='0'&&c[3][1]=='0'&&c[4][1]=='0'&&c[4][2]=='0')
			s1++;
			if(c[1][1]=='0'&&c[1][2]=='0'&&c[2][1]=='0'&&c[3][1]=='0'&&c[4][1]=='0'&&c[3][2]=='0')
			s2++;
			printf("%d %d\n",s1*v%MOD,s2*f%MOD);
			continue;
		}
		if(m==2)
		{
			int s1=0,s2=0;
			for(int ii=1;ii<=n-2;++ii)
			{
				if(c[ii][1]=='0'&&c[ii][2]=='0')
				{
					for(int jj=ii+1;jj<=n;++jj)
					{
						if(c[jj][1]=='1')break;
						if(jj==ii+1)continue;
						if(c[jj][2]=='0')s1++;
					}
				}
			 }
			 for(int ii=1;ii<=n-3;++ii)
			{
				if(c[ii][1]=='0'&&c[ii][2]=='0')
				{
					for(int jj=ii+1;jj<n;++jj)
					{
						if(c[jj][1]=='1')break;
						if(jj==ii+1)continue;
						if(c[jj][2]=='0')
						{
							for(int kk=jj+1;kk<=n;++kk)
							if(c[kk][1]=='0')s2++;
						}
					}
				}
			 }
			 printf("%d %d\n",s1*v%MOD,s2*f%MOD);
			 continue;
		 } 
		if(flag1==false)
printf("%d %d\n",((m/3)*v*(n-1)*(n-2)/2)%MOD,((m/3)*f*(n-2)*(n-3)/2)%MOD);
		else if(flag2==false)
		{
			int s=0;
			for(int r=1;r<m;++r)
			s+=r*r;
        printf("%d %d\n",((n/4)*v*s)%MOD,((n/4)*f*0)%MOD);
			}	
		else
			{
				//cout<<"r";
				int s1=0,s2=0;
				for(int ii=1;ii<=n-2;++ii)
				for(int jj=1;jj<m;++jj)
				{
					if(c[ii][jj]=='1'||c[ii][jj+1]=='1')continue;
					int s3=0;
					for(int kk=jj+1;kk<=m;++kk)
					{
						if(c[ii][kk]=='1')break;
						s3++;
					}
					if(s3==0)continue;
					int s4=0,s5=0,s6=0;
					for(int kk=ii+1;kk<=n;++kk)
					{
						if(c[kk][jj]=='1')break;
						if(kk==ii+1)continue;
							if(c[kk][jj+1]=='1')continue;
							for(int rr=jj+1;rr<=m;++rr)
							{
								if(c[kk][rr]=='1')break;
								s4++;
								if(kk!=n)s6++;
							}
							if(s6==0||f==0)continue;
							for(int yy=kk+1;yy<=n;++yy)
							{
								if(c[yy][jj]=='1')break;
								s5++;
							}
						}
						s1+=s3*s4,s2+=s3*s6*s5;
				
				}
				printf("%d %d\n",s1*v%MOD,s2*f%MOD);
			 } 
	}
	
	return 0; 
} 

