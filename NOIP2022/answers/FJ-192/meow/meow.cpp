#include<bits/stdc++.h>
using namespace std;
int a[2000010]={0},ans1[4000010]={0},ans2[4000010]={0},ans3[4000010]={0};
map<int,int>mp1,mp2,mp3;//存栈顶,存栈底,用第i个栈将顶部移到底部 
map<int,int>::iterator it1,it2; 
bool b[310][2]={0};//记录哪些栈是空的,0为空 ,b[i][j]，0为底部,1为顶部 
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T,n,m,k,op;
	cin>>T;
//	if(T==1001)//最后一个栈用于处理栈底 
//	{
		while(T--)
		{
			op=0;
			cin>>n>>m>>k;
			for(int i=1;i<=m;i++)
				cin>>a[i];
			for(int i=1;i<=m;i++)//mp1为顶,mp2为底 
			{
//				for(it1=mp1.begin();it1!=mp1.end();it1++)
//					cout<<it1->first<<" "<<it1->second<<'\n';
//				for(it1=mp2.begin();it1!=mp2.end();it1++)
//					cout<<it1->first<<" "<<it1->second<<'\n';
				it1=mp1.find(a[i]);
				if(it1!=mp1.end())
				{
//					cout<<"1 "<<it1->second<<'\n';
					ans1[++op]=1;
					ans2[op]=it1->second;
					
					it2=mp3.find(it1->second);
					mp1.erase(it1);
					if(it2==mp3.end())
						cout<<"error"<<'\n';
					else
						mp3.erase(it2);
					b[it1->second][1]=0; 
				}
				else
				{
					it1=mp2.find(a[i]);
					if(it1!=mp2.end())
					{
//						cout<<"1 "<<n<<'\n';
//						cout<<"2 "<<it1->second<<" "<<n<<'\n';//先放再删 
						ans1[++op]=1;
						ans2[op]=n;
						ans1[++op]=2;
						ans2[op]=it1->second;
						ans3[op]=n;
						it2=mp3.find(it1->second);
						mp2.erase(it1);
						if(it2!=mp3.end())
						{
							mp2[it2->second]=it2->first;
							b[it1->second][1]=0;//顶部清空 
							it1=mp1.find(it2->second);
							mp1.erase(it1);
							mp3.erase(it2);
						}
						else//栈为空
							b[it1->second][0]=0;//底部清空 
					}
					else if(mp2.size()<n-1)
					{
						for(int j=1;j<n;j++)
							if(!b[j][0])
							{
								mp2[a[i]]=j;
								b[j][0]=1;
								ans1[++op]=1;
								ans2[op]=j;
								break;
							}
					}
					else
					{
						for(int j=1;j<n;j++)
							if(!b[j][1])
							{
								mp1[a[i]]=j;
								mp3[j]=a[i];
								b[j][1]=1;
								ans1[++op]=1;
								ans2[op]=j;
								break;
							}
					}
				}
			}
			cout<<op<<'\n';
			for(int i=1;i<=op;i++)
			{
				cout<<ans1[i]<<" ";
				if(ans1[i]==1)
					cout<<ans2[i]<<'\n';
				else if(ans1[i]==2)
					cout<<ans2[i]<<" "<<ans3[i]<<'\n';
			}
		}
//	}
	return 0;
}
