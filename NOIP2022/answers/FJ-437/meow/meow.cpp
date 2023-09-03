//30
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int p[2000010];
short opx[4000020][3];
int zhan[310][11451],l[310],r[310];
bool flag;
struct po1
{
	bool zai;
	int cs,zs;
}zh2[620];
int sum[310];
void dfs(int cs)
{
	if(cs==m)
	{
		for(int i=1;i<=n;i++)
		{
			if(l[i]!=r[i])
			{
				return; 
			}
		}
		flag=1;
		cout<<opx[0][0]<<endl;
		for(int i=1;i<=opx[0][0];i++)
		{
			cout<<opx[i][0];
			if(opx[i][0]==1)
			{
				cout<<' '<<opx[i][1];
			}
			else
			{
				if(opx[i][1]>opx[i][2])
				{
					swap(opx[i][1],opx[i][2]);
				}				
				cout<<' '<<opx[i][1]<<' '<<opx[i][2];
			}
			cout<<endl;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(r[i]>l[i]&&zhan[i][r[i]-1]==p[cs+1])
		{
			opx[++opx[0][0]][0]=1;
			opx[opx[0][0]][1]=i;			
			r[i]--;
			dfs(cs+1);
			r[i]++;			
		}
		else if(r[i]>l[i]&&zhan[i][l[i]]==p[cs+1])
		{
			int fr=0;
			for(int j=1;j<=n;j++)
			{
				if(l[j]==r[j])
				{
					fr=j;
					break;
				}
			}
			if(fr)
			{
				l[i]++;
				opx[++opx[0][0]][0]=1;
				opx[opx[0][0]][1]=fr;			
				opx[++opx[0][0]][0]=2;
				opx[opx[0][0]][1]=fr;
				opx[opx[0][0]][2]=i;				
				dfs(cs+1);
				opx[0][0]--;
				l[i]--;
			}
			else
			{
				opx[++opx[0][0]][0]=1;
				opx[opx[0][0]][1]=i;				
				zhan[i][r[i]++]=p[cs+1];
				dfs(cs+1);
				r[i]--;					
			}
		}
		else
		{
			opx[++opx[0][0]][0]=1;
			opx[opx[0][0]][1]=i;			
			zhan[i][r[i]++]=p[cs+1];
			dfs(cs+1);
			r[i]--;				
		}
		opx[0][0]--;
		if(flag)
		{
			return; 
		}
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	cin>>T;
	if(T%10>1)
	{
		while(T--)
		{
			cin>>n>>m>>k;
			for(int i=1;i<=m;i++)
			{
				cin>>p[i];
			}
			dfs(0);
		}		
		return 0;
	}
	if(T%10==1)
	{
		while(T--)
		{
			cin>>n>>m>>k;
			for(int i=1;i<=m;i++)
			{
				cin>>p[i];
			}
			queue<int>kf;
			for(int i=1;i<=n-1;i++)
			{
				kf.push(i);
				kf.push(i);
				sum[i]=2;
			}
			for(int i=1;i<=m;i++)
			{
				if(zh2[p[i]].zai)
				{
					if(zh2[p[i]].cs==1)
					{
						opx[++opx[0][0]][0]=1;
						opx[opx[0][0]][1]=n;
						opx[++opx[0][0]][0]=2;
						opx[opx[0][0]][1]=n;
						opx[opx[0][0]][2]=zh2[p[i]].zs;	
						kf.push(zh2[p[i]].zs);
						sum[zh2[p[i]].zs]++;
					}
					else
					{
						opx[++opx[0][0]][0]=1;
						opx[opx[0][0]][1]=zh2[p[i]].zs;
						kf.push(zh2[p[i]].zs);
						sum[zh2[p[i]].zs]++;		
					}		
				}
				else
				{
					int w=kf.front();
					zh2[p[i]].zai=1;
					zh2[p[i]].zs=w;
					zh2[p[i]].cs=3-sum[w];
					sum[w]--;
					kf.pop();
					opx[++opx[0][0]][0]=1;
					opx[opx[0][0]][1]=w;
				}
			}
			cout<<opx[0][0]<<endl;
			for(int i=1;i<=opx[0][0];i++)
			{
				cout<<opx[i][0];
				if(opx[i][0]==1)
				{
					cout<<' '<<opx[i][1];
				}
				else
				{
					if(opx[i][1]>opx[i][2])
					{
						swap(opx[i][1],opx[i][2]);
					}
					cout<<' '<<opx[i][1]<<' '<<opx[i][2];
				}
				cout<<endl;
			}			
		}		
	}
	return 0;
}
