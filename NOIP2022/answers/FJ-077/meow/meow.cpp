#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,m,k,t,x,xx,minn,id;
bool pd;
int a[100001];
int ab[1001][1001];//位于栈底的a，前种类，后栈名 
int at[1001][1001];//位于栈顶的a，同上
int bjt[1001];
int bjb[1001]; 
int zba[1001];
int zto[1001];
int z[1001][1001];
int ans;
int anzl[100001];
int an[100001][2];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		memset(anzl,0,sizeof(anzl));
		memset(an,0,sizeof(an));
		memset(zto,0,sizeof(zto));
		memset(zba,0,sizeof(zba)); 
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=m; i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1; i<=m; i++)
		{
			pd=false;
			x=a[i];
			if(bjb[x]!=0)
			{
				for(int j=1; j<=n; j++)
				{
					if(zto[j]-zba[j]==0)
					{
						xx=ab[x][bjb[x]];
						ans++;
						anzl[ans]=1;
						an[ans][0]=j;
						ans++;
						anzl[ans]=2;
						an[ans][0]=j;
						an[ans][1]=ab[x][bjb[x]];
					//	printf("1 %d\n",j);
					//	printf("2 %d %d",ab[x][bjb[x]],j);
						//cout<<"1 "<<j<<endl;
						//cout<<"2 "<<ab[x][bjb[x]]<<" "<<j<<endl;
						zba[xx]++;
						bjb[x]--;
						if(zba[xx]<zto[xx])
						{
							bjb[z[xx][zba[xx]]]++;
							ab[z[xx][zba[xx]]][bjb[z[xx][zba[xx]]]]=xx;
						}
						else
						{
							for(int j=1; j<=bjt[z[xx][zba[xx]-1]]; j++)
							{
								if(at[z[xx][zba[xx]]-1][j]==xx)
								{
									swap(at[z[xx][zba[xx]]-1][j],at[z[xx][zba[xx]]-1][bjt[z[xx][zba[xx]-1]]]);
									break;
								}
							}
							bjt[z[xx][zba[xx]-1]]--;
						}
						pd=true;
						break;
					}
				}
			}
			if(pd==true)
			{
				continue;
			}
			if(bjt[x]!=0)
			{
				xx=at[x][bjt[x]];
				ans++;
				anzl[ans]=1;
				an[ans][0]=at[x][bjt[x]];
				//printf("1 %d\n",at[x][bjt[x]]);
				//cout<<"1 "<<at[x][bjt[x]]<<endl;
				zto[xx]--;
				bjt[x]--;
				if(zto[xx]>zba[xx])
				{
					bjt[z[xx][zto[xx]]]++;
					at[z[xx][zto[xx]]][bjt[z[xx][zto[xx]]]]=xx;
				}
				else
				{
					for(int j=1; j<=bjb[z[xx][zto[xx]+1]]; j++)
					{
						if(ab[z[xx][zto[xx]]+1][j]==xx)
						{
							swap(ab[z[xx][zto[xx]]+1][j],ab[z[xx][zto[xx]]+1][bjb[z[xx][zto[xx]+1]]]);
							break;
						}
					}
					bjb[z[xx][zto[xx]+1]]--;
				}
				pd=true;
			}
			if(pd==true)
			{
				continue;
			}
			else
			{
				minn=99999999;
				for(int j=1; j<=n; j++)
				{
					x=zto[j]-zba[j];
					if(x<minn)
					{
						minn=x;
						id=j;
					}
					if(minn==0)
					{
						break;
					}
				}
				zto[id]++;
				z[id][zto[id]]=a[i];
				bjt[a[i]]++;
				at[a[i]][bjt[a[i]]]=id;
				if(minn==0)
				{
				//	cout<<999;
					bjb[a[i]]++;
					ab[a[i]][bjb[a[i]]]=id;
				}
				else
				{
					for(int j=1; j<=bjt[z[id][zto[id]-1]]; j++)
					{
						if(at[z[id][zto[id]]-1][j]==id)
						{
							swap(at[z[id][zto[id]]-1][j],at[z[id][zto[id]]-1][bjt[z[id][zto[id]-1]]]);
							break;
						}
					}
					bjt[z[id][zto[id]-1]]--;
				} 
				ans++;
				anzl[ans]=1;
				an[ans][0]=id;
				//printf("1 %d\n",id);
				//cout<<"1 "<<id<<endl;
			}
		}
		printf("%d\n",ans);
		for(int i=1; i<=ans; i++)
		{
			printf("%d ",anzl[i]);
			if(anzl[i]==1)
			{
				printf("%d",an[i][0]);
			}
			else
			{
				printf("%d %d",an[i][0],an[i][1]);
			}
			printf("\n");
		}
	}
	return 0;
}
