#include<bits/stdc++.h>
using namespace std;

int T;
int n,m,K;
int stp[2000010];
int color[2000010];

void solve1()
{
	while(T--)
	{
		int t,cnt=0,op=0;
		int bot=-1,top=-1,size=0;
		cin>>n>>m>>K;
		for(int i=1;i<=m;i++)
		{
			cin>>t;
			if(top==t)
			{
				stp[cnt++]=1;
				op++;
				size--;
				top=(t-1)^1+1;
			}
			else if(bot==t)
			{
				stp[cnt++]=2;
				op+=2;
				size--;
				bot=(t-1)^1+1;
			}
			else{
				stp[cnt++]=1;
				op++;
				size++;
				if(size==1) bot=t;
				top=t;
			}
		}
		cout<<op<<endl;
		for(int i=0;i<cnt;i++)
		{
			if(stp[i]==1) cout<<"1 1"<<endl;
			if(stp[i]==2) cout<<"1 2"<<endl<<"2 1 2"<<endl;
		}
	}
}

struct Stp
{
	int type;
	int a,b;
};

int st1[2000010],head1,tail1;
int st2[2000010],head2,tail2;
int st3[2000010],head3,tail3;
Stp Stp2[2000010];
int op=0;
bool suc;

void dfs2(int k)
{
	if(k==m+1)
	{
		if(head1==tail1 && head2==tail2) suc=true;
		return;
	}
	if(head1!=tail1 && st1[tail1]==color[k]){
		Stp2[op++]=(Stp){1,1,0};
		tail1--;
		dfs2(k+1);
		if(suc) return;
		st1[++tail1]=color[k];
		op--;
	}
	else if(head2!=tail2 && st2[tail2]==color[k]){
		Stp2[op++]=(Stp){1,2,0};
		tail2--;
		dfs2(k+1);
		if(suc) return;
		st2[++tail2]=color[k];
		op--;
	}
	else if(head1!=tail1 && head2==tail2 && st1[head1+1]==color[k])
	{
		Stp2[op++]=(Stp){1,2,0};
		Stp2[op++]=(Stp){2,1,2};
		head1++;
		dfs2(k+1);
		if(suc) return;
		st1[head1--]=color[k];
		op-=2;
	}
	else if(head2!=tail2 && head1==tail1 && st2[head2+1]==color[k])
	{
		Stp2[op++]=(Stp){1,1,0};
		Stp2[op++]=(Stp){2,1,2};
		head2++;
		dfs2(k+1);
		if(suc) return;
		st2[head2--]=color[k];
		op-=2;
	}
	else
	{
		Stp2[op++]=(Stp){1,1,0};
		st1[++tail1]=color[k];
		dfs2(k+1);
		if(suc) return;
		tail1--;
		op--;
		
		Stp2[op++]=(Stp){1,2,0};
		st2[++tail2]=color[k];
		dfs2(k+1);
		if(suc) return;
		tail2--;
		op--;
	}
	return;
}

void solve2()
{
	while(T--)
	{
		cin>>n>>m>>K;
		for(int i=1;i<=m;i++) cin>>color[i];
		op=0;
		head1=head2=0;
		tail1=tail2=0;
		suc=false;
		dfs2(1);
		cout<<op<<endl;
		for(int i=0;i<op;i++)
		{
			if(Stp2[i].type==1) cout<<1<<" "<<Stp2[i].a<<endl;
			if(Stp2[i].type==2) cout<<2<<" "<<Stp2[i].a<<" "<<Stp2[i].b<<endl;
		}
	}
}

void dfs(int k)
{
	if(k==m+1)
	{
		if(head1==tail1 && head2==tail2 && head3==tail3) suc=true;
		return;
	}
	if(head1!=tail1 && st1[tail1]==color[k]){
		Stp2[op++]=(Stp){1,1,0};
		tail1--;
		dfs(k+1);
		if(suc) return;
		st1[++tail1]=color[k];
		op--;
	}
	else if(head2!=tail2 && st2[tail2]==color[k]){
		Stp2[op++]=(Stp){1,2,0};
		tail2--;
		dfs(k+1);
		if(suc) return;
		st2[++tail2]=color[k];
		op--;
	}
	else if(head3!=tail3 && st3[tail3]==color[k]){
		Stp2[op++]=(Stp){1,3,0};
		tail3--;
		dfs(k+1);
		if(suc) return;
		st3[++tail3]=color[k];
		op--;
	}
	else if(head1!=tail1 && st1[head1+1]==color[k])
	{
		if(head2==tail2)
		{
			Stp2[op++]=(Stp){1,2,0};
			Stp2[op++]=(Stp){2,1,2};
			head1++;
			dfs(k+1);
			if(suc) return;
			st1[head1--]=color[k];
			op-=2;
		}
		else if(head3==tail3)
		{
			Stp2[op++]=(Stp){1,3,0};
			Stp2[op++]=(Stp){2,1,3};
			head1++;
			dfs(k+1);
			if(suc) return;
			st1[head1--]=color[k];
			op-=2;
		}
	}
	else if(head2!=tail2 && st2[head2+1]==color[k])
	{
		if(head1==tail1)
		{
			Stp2[op++]=(Stp){1,1,0};
			Stp2[op++]=(Stp){2,1,2};
			head2++;
			dfs(k+1);
			if(suc) return;
			st2[head2--]=color[k];
			op-=2;
		}
		else if(head3==tail3)
		{
			Stp2[op++]=(Stp){1,3,0};
			Stp2[op++]=(Stp){2,2,3};
			head2++;
			dfs(k+1);
			if(suc) return;
			st2[head2--]=color[k];
			op-=2;
		}
	}
	else if(head3!=tail3 && st3[head3+1]==color[k])
	{
		if(head1==tail1)
		{
			Stp2[op++]=(Stp){1,1,0};
			Stp2[op++]=(Stp){2,1,3};
			head3++;
			dfs(k+1);
			if(suc) return;
			st3[head3--]=color[k];
			op-=2;;
		}
		else if(head2==tail2)
		{
			Stp2[op++]=(Stp){1,2,0};
			Stp2[op++]=(Stp){2,2,3};
			head3++;
			dfs(k+1);
			if(suc) return;
			st3[head3--]=color[k];
			op-=2;
		}
	}
	else
	{
		Stp2[op++]=(Stp){1,1,0};
		st1[++tail1]=color[k];
		dfs(k+1);
		if(suc) return;
		tail1--;
		op--;
		
		Stp2[op++]=(Stp){1,2,0};
		st2[++tail2]=color[k];
		dfs(k+1);
		if(suc) return;
		tail2--;
		op--;
		
		Stp2[op++]=(Stp){1,3,0};
		st3[++tail3]=color[k];
		dfs(k+1);
		if(suc) return;
		tail3--;
		op--;
	}
	return;
}

void solve3()
{
	while(T--)
	{
		cin>>n>>m>>K;
		for(int i=1;i<=m;i++) cin>>color[i];
		op=0;
		head1=head2=head3=0;
		tail1=tail2=tail3=0;
		suc=false;
		dfs(1);
		cout<<op<<endl;
		for(int i=0;i<op;i++)
		{
			if(Stp2[i].type==1) cout<<1<<" "<<Stp2[i].a<<endl;
			if(Stp2[i].type==2) cout<<2<<" "<<Stp2[i].a<<" "<<Stp2[i].b<<endl;
		}
	}
}

int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	if(T%10==1) solve1();
	else if(T%10==2) solve2();
	else if(T%10==3) solve3();
	else if(T%10==4) solve3();
	else if(T%10==5) cout<<"rp++"<<endl;
	
	return 0;
}
/*
rp++
让我拿35分吧  求求你了 
		by 吴含章 hispy 
		2022.11.26
*/
