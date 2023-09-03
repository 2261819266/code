#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=310,maxm=100010;
ll t,n,m,k,op;
int st[maxn],sd[maxn];
int stk[maxn][maxm];
struct node{
	int oi,s,s1,s2;
};
node ope[maxm*2];

void op1(int s){
	op++;			ope[op].oi=1;
	ope[op].s=s;
//	cout<<ope[op].oi<<" "<<ope[op].s<<"\n";
	return ;
}
void op2(int s1,int s2){
	op++;			ope[op].oi=2;
	ope[op].s1=s1;	ope[op].s2=s2;
//	cout<<ope[op].oi<<" "
//		<<ope[op].s1<<" "<<ope[op].s2<<"\n";
	return ;
}
void findop2(int i){
//	cout<<st[i]-sd[i]<<" ";
//	for(int i=sd[3]+1;i<=st[3];i++)
//		cout<<stk[3][i]<<" ";
	if(st[i]<=sd[i])
		return ;
	for(int j=1;j<=n;j++)
	{
		if(j!=i&&stk[j][sd[j]+1]==stk[i][sd[i]+1])
		{
			op2(i,j);
			sd[i]++,sd[j]++;
			findop2(i),findop2(j);
			return ;
		}
	}	
}
void putt(int x){
	for(int i=1;i<=n;i++)
		if(stk[i][st[i]]==x)
		{
			op1(i);
			st[i]--;
			return ;
		}
	for(int i=1;i<=n;i++)
		if(st[i]-sd[i]==0)
		{
			op1(i);
			stk[i][++st[i]]=x;
			findop2(i);
			return ;
		}
	op1(1);
	stk[1][++st[1]]=x;
	return ;
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);			 cout.tie(0);
	
	cin>>t;
	while(t--)
	{
		op=0;
		memset(st,0,sizeof(st));
		memset(sd,0,sizeof(sd));
		memset(stk,0,sizeof(stk));
		cin>>n>>m>>k;
		for(int i=1,a;i<=m;i++)
		{
			cin>>a;
			putt(a);
		}
		cout<<op<<"\n";
		for(int i=1;i<=op;i++)
		{
			cout<<ope[i].oi<<" ";
			if(ope[i].oi==1)
				cout<<ope[i].s<<"\n";
			else if(ope[i].oi==2)
				cout<<ope[i].s1<<" "<<ope[i].s2<<"\n";
		}
	}
	
	return 0;
}
