#include<bits/stdc++.h>
using namespace std;
const int Max=300009;
int T,n;
int a[Max],b[Max];
unsigned long long ans;
int ST_a[300009][100],ST_b[300009][100];
int po[10009][10009];
struct yue{
	int r_max;
	unsigned long long p;
}ttt[Max];
struct Que{
	int l,r;
	int xu;
	unsigned long long ans_end;
}qs[Max];
int Q;
void deal_a(){
	for(int i=1;i<=n;++i){
		ST_a[i][0]=a[i];
	}
	int k=log(n)/log(2)+1;
	for(int j=1;j<=k;++j){
		for(int i=1;i<=n;++i){
			ST_a[i][j]=ST_a[i][j-1]>ST_a[i+(1<<(j-1))][j-1]?ST_a[i][j-1]:ST_a[i+(1<<(j-1))][j-1];
		}
	}
	return;
}
int ask_a(int l,int r){
	int d=r-l+1;
	int k=log(d)/log(2);
	int ans_ask=0;
	ans_ask=ST_a[l][k]>ST_a[r-(1<<k)+1][k]?ST_a[l][k]:ST_a[r-(1<<k)+1][k];
	return ans_ask;
}
void deal_b(){
	for(int i=1;i<=n;++i){
		ST_b[i][0]=b[i];
	}
	int k=log(n)/log(2)+1;
	for(int j=1;j<=k;++j){
		for(int i=1;i<=n;++i){
			ST_b[i][j]=ST_b[i][j-1]>ST_b[i+(1<<(j-1))][j-1]?ST_b[i][j-1]:ST_b[i+(1<<(j-1))][j-1];
		}
	}
	return;
}
unsigned long long ask_b(int l,int r){
	int d=r-l+1;
	int k=log(d)/log(2);
	unsigned long long bns_bsk=0;
	bns_bsk=ST_b[l][k]>ST_b[r-(1<<k)+1][k]?ST_b[l][k]:ST_b[r-(1<<k)+1][k];
	return bns_bsk;
}
void print_ST_a(){
	int k=log(n)/log(2)+1;
	for(int j=0;j<=k;++j){
		int d=(1<<j);
		cout<<j<<endl;
		for(int i=1;i<=n-d+1;++i){
			cout<<ST_a[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}
bool cmp(Que ta,Que tb){
	return ta.r<tb.r;
}
unsigned long long get_ans(int l,int r){
	unsigned long long sum2=0;
//	cout<<"*************************\n";
 //   cout<<l<<" "<<r<<endl;
	for(int i=ttt[l].r_max+1;i<=r;++i){
		for(int j=i;j<=r;++j){
//			cout<<i<<" "<<j<<endl;
//			cout<<ask_a(i,j)*ask_b(i,j)<<endl;
			sum2+=ask_a(i,j)*ask_b(i,j);
		}
	}
	sum2+=ttt[l].p;
	for(int i=l;i<=ttt[l].r_max;++i){
		for(int j=ttt[l].r_max+1;j<=r;++j){
			sum2+=ask_a(i,j)*ask_b(i,j);
		}
	}
	ttt[l].r_max=r;
	ttt[l].p=sum2;
	return sum2;
} 
bool bmp(Que ta,Que tb){
	return ta.xu<tb.xu;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int j=1;j<=n;++j){
		cin>>b[j];
	}
	
	
	deal_a();
	deal_b();
	
	for(int i=1;i<=n;++i){
		ttt[i].r_max=i;
		ttt[i].p=(unsigned long long)a[i]*b[i];
	}
	cin>>Q;
	for(int i=1;i<=Q;++i){
		cin>>qs[i].l>>qs[i].r;
		qs[i].xu=i;
	} 
	sort(qs+1,qs+1+Q,cmp);
	for(int i=1;i<=Q;++i){
		qs[i].ans_end=get_ans(qs[i].l,qs[i].r);
	}
	sort(qs+1,qs+1+Q,bmp);
	for(int i=1;i<=Q;++i){
		cout<<qs[i].ans_end<<endl;
	}
	return 0;
}

