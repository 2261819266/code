#include <bits/stdc++.h>

using namespace std;
int T,n,m,k;
int cards[2000005];
int stk[303][700005];
int ind[303];
bool mark[605];
int getes()
{
	for(int i = 1;i <= n;i++)
		if(ind[i]==0) return i;
	return -1;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	for(int t = 1;t <= T;t++)
	{
		cin>>n>>m>>k;
		for(int i =1;i <= m;i++)
			cin>>cards[i];
		if(n==2)
		{
			ind[0] = 0;
			ind[1] = 0;
			stk[0][0] = 0;
			stk[0][1] = 0;
			stk[1][0] = 0;
			stk[1][1] = 0;
			for(int i = 1;i <= m;i++)
			{
				int ca = cards[i];
				if(ind[0]==0 && ind[1]==0)	//均空 
				{
					cout<<"1 1"<<endl;
					stk[0][0] = ca;
					ind[0]++; 
					continue;
				}
				else
				{
					if(ind[1]!=0 && stk[1][ind[1]-1] == ca)	//消同 
					{
						cout<<"1 2"<<endl;
						stk[1][ind[1]-1] = 0;
						ind[1]--;
						continue;
					}
					else if(ind[0]!=0 && stk[0][ind[0]-1] == ca)	//消同 
					{
						cout<<"1 1"<<endl;
						stk[0][ind[0]-1] = 0;
						ind[0]--;
						continue;
					}
					//一二同
					if(i!=m)	//一定满足 
					{
						if(ca == cards[i+1])	//自消 
						{
							cout<<"1 1"<<endl;
							cout<<"1 1"<<endl;
							i++;
							continue;
						}
					}
					if(ind[0]==0&&stk[1][0]==ca)	//消底
					{
						cout<<"1 1"<<endl;
						cout<<"2 1 2"<<endl;
						stk[1][0] = stk[1][1];
						stk[1][1] = 0;
						ind[1]--;
						continue;
					}
					if(ind[1]==0&&stk[0][0]==ca)
					{
						cout<<"1 2"<<endl;
						cout<<"2 1 2"<<endl;
						stk[0][0] = stk[0][1];
						stk[0][1] = 0;
						ind[0]--;
						continue;
					}
					if(i!=m)	//1 2 + 3问题，看下一个 
					{
						if(cards[i+1]==stk[0][ind[0]-1])
						{
							cout<<"1 2"<<endl;
							stk[1][ind[1]] = ca;
							ind[1]++;
							continue;
						}
						else if(cards[i+1]==stk[1][ind[1]-1])
						{
							cout<<"1 1"<<endl;
							stk[0][ind[0]] = ca;
							ind[0]++;
							continue;
						}
						else	//1 () 2问题 
						{
							if(ind[0] == 0)
							{
								cout<<"1 1"<<endl;
								stk[0][0] = ca;
								ind[0]++;
							}
							else if(ind[1] == 0)
							{
								cout<<"1 2"<<endl;
								stk[1][0] = ca;
								ind[1]++;
							}
						}
					}
				}
			}
		}
		else
		{
			int ca = 0;
			int es = n;
			int j = 1;
			for(int i = 1;i <= 600;i++)
				mark[i] = false;
			for(int i = 1;i <= n;i++)
			{
				ind[i] = 0;
				memset(stk[i],0,m);
			}
			for(int i = 1;i <= m;i++)
			{
				j = 1;
				ca = cards[i];
				if(mark[ca]==false) //插入	
				{
					mark[ca] = true;
					if(es>1){
						j = getes();
						stk[j][0] = ca;
						es--;
						ind[j]++;
						//cout<<"Insert "<<ca<<" to empty stk"<<endl;
						cout<<"1 "<<j<<endl;
					}
					else
					{
						j = 1;
						while(ind[j]!=1) j++;
						stk[j][1] = ca;
						ind[j]++;
						//cout<<"Insert "<<ca<<" to size 1 stk"<<endl;
						cout<<"1 "<<j<<endl;
					}
				}
				else
				{
					mark[ca] = false;
					for(int q = 1;q <= n&&j!=-1;q++)
					{
						if(ind[q]!=0)
						{
							if(stk[q][ind[q]-1]==ca)
							{
								//cout<<"Insert "<<ca<<" to same top stk"<<endl;
								cout<<"1 "<<q<<endl;
								stk[q][ind[q]-1] = 0;
								ind[q]--;
								j = -1;
								if(ind[q]==0) es++;
							}
							else if(stk[q][0]==ca)
							{
								int c = getes();
								//cout<<"Insert "<<ca<<" to only empty stk"<<endl;
								cout<<"1 "<<c<<endl;
								cout<<"2 "<<c<<" "<<q<<endl;
								stk[q][0] = stk[q][1];
								stk[q][1] = 0;
								ind[q]--;
								if(ind[q]==0) es++;
							}		
						}
					}
				} 
			}
		}	
	}
	
	return 0;
}
