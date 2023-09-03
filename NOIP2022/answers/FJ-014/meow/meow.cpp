#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,s[305][2],x,xx,opt,siz[305],f,w,a[2000005];
vector<pair<int,int> > v;
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	while (t--)
		{scanf("%d%d%d",&n,&m,&k);
		 opt=w=0;
		 for (int i=0;i<m;i++) scanf("%d",&a[i]);
	     for (int i=0;i<m;i++)
	    	{x=a[i];
	    	 if (x>n) xx=x-n;
	    	 else xx=x;
	    	 if (s[xx][0]==0)
				{v.push_back(make_pair(xx,0));
				 s[xx][0]=x;
				 siz[xx]++;
				 w++;
				}
	    	 else if (s[xx][1]==0)
				{if (w==n+1)
					{int kkk=a[i+1];
					 if (kkk>n) kkk-=n;
					 if (kkk==xx)
						{for (int j=1;j<=n;j++)
							{if (siz[j]!=2&&j!=xx)
								{f=j;
								 break;
								}
							}
						 s[f][1]=x;
						 cout<<f<<endl;
						 v.push_back(make_pair(f,0));
						 siz[f]++;
						 w=0;
						 continue;
						}
					}
				 v.push_back(make_pair(xx,0));
				 if (s[xx][0]==x) s[xx][0]=0,siz[xx]--,w--;
				 else s[xx][1]=x,siz[xx]++,w++;
				}
			 else
				{if (s[xx][1]==x)
					{s[xx][1]=0;
					 siz[xx]--;
					 w--;
					 v.push_back(make_pair(xx,0));
					}
				 else
					{for (int j=1;j<=n;j++)
						if (siz[j]==0)
							{f=j;
							 break;
							}
					 v.push_back(make_pair(f,0));
					 v.push_back(make_pair(xx,f));
					 opt++;
					 siz[xx]--;
					 s[xx][0]=s[xx][1];
					 s[xx][1]=0;
					}
				}
			 opt++;
			}
		 printf("%d\n",opt);
		 for (int i=0;i<opt;i++)
			{if (v[i].second==0) printf("1 %d\n",v[i].first);
			 else printf("2 %d %d\n",v[i].first,v[i].second);
			}
		 v.clear();
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
