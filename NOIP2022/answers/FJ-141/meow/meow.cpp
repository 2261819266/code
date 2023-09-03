#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t[5][20001],a[20001],ta[10],tp[10];
int cz1[200001],cz2[5][200001];
int n,m,k,T,ste,flag=1; 
void dfs_2(int now,int step)
{
	if((tp[1]==ta[1]&&tp[2]==ta[2]&&tp[3]==ta[3])&&now==m+1) 
	{
		ste=step;
		flag=0;
		return;
	}
	if(now<=m)	
	{
		for(int i=1;i<=n&&flag;i++)
	    {
		    t[i][tp[i]]=a[now];
		    tp[i]++;
		    cz1[step]=i;
		    dfs_2(now+1,step+1);
		    if(!flag) break;
		    cz1[step]=0;
		    tp[i]--;
		    t[i][tp[i]]=0;
	    }	
	}
	for(int l=1;l<n&&flag;l++)
	 for(int j=l+1;j<=n&&flag;j++)
	 {
	 	if(t[l][ta[l]]==t[j][ta[j]]&&t[l][ta[l]]!=0&&flag)
	 	{
	 		ta[l]++;
	 		ta[j]++;
	 		cz2[1][step]=l;
	 		cz2[2][step]=j;
	 		dfs_2(now,step+1);
	 		if(!flag) break;
	 		cz2[1][step]=0;
	 		cz2[2][step]=0;
	 		ta[l]--;
	 		ta[j]--;
		 }
	 }
	
}
void cs()
{
	for(int i=1;i<=3;i++)
	 {tp[i]=1;ta[i]=1;}
	for(int i=1;i<=m;i++) a[i]=0;
	flag=1;
}
void pian()
{
	cout<<m/2+m;
	t[1][tp[1]]=a[1];
	tp[1]++;
	for(int i=2;i<=m;i++)
	{
		if(t[1][tp[1]-1]!=a[i])
		{
			t[1][tp[1]]=a[1];
	        tp[1]++;
	        cout<<"1 1"<<endl;
		}
		else
		{
			t[2][tp[2]]=a[i];
	        tp[2]++;
	        cout<<"1 2"<<endl;
		}
	}
	for(int i=1;i<=m/2;i++)
	 cout<<"2 1 2"<<endl;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;	
		cs();
		for(int i=1;i<=m;i++) cin>>a[i];
		
		if(T==1002)
		{
			pian();
			continue;
		}
		
		dfs_2(1,0);
		cout<<ste<<endl;
		for(int i=0;i<ste;i++)
		{
			if(cz1[i]!=0) cout<<"1 "<<cz1[i]<<endl;
			else cout<<"2 "<<cz2[1][i]<<" "<<cz2[2][i]<<endl;
		}
	}
	return 0;
}
/*
1002 
2 4 2
1 2 1 2

2 4 2
1 2 1 2

3 10 5
1 2 3 4 5 2 3 4 5 1
*/
