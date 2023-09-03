#include<bits/stdc++.h>
//#pragma GCC optimize(s)
//#pragma GCC optimize("Ofast")
using namespace std;
const int Maxn=4e6+8;
const int l=Maxn/2+1,r=Maxn/2;
int T,n,m,k,t,cnt=0,op=0;
int q[Maxn]={},p[Maxn]={},d[Maxn]={};
int tail_q=l,end_q=r,tail_p=l,end_p=r,tail_d=l,end_d=r;
struct Node{
	int book;
	int u,v;
}a[Maxn*2];
void PushUp_q(int x){
	q[--tail_q]=x;
}
void PushUp_p(int x){
	p[--tail_p]=x;
}
void PushUp_d(int x){
	d[--tail_d]=x;
}
void PopUp_q(){
	q[tail_q]=0;
	++tail_q;
}
void PopUp_p(){
	p[tail_p]=0;
	++tail_p;
}
void PopUp_d(){
	d[tail_d]=0;
	++tail_d;
}
void PopDown_q(){
	q[end_q]=0;
	--end_q;
}
void PopDown_p(){
	p[end_p]=0;
	--end_p;
}
void PopDown_d(){
	d[end_d]=0;
	--end_d;
}
bool empty_q(){
	return tail_q>end_q;
}
bool empty_p(){
	return tail_p>end_p;
}
bool empty_d(){
	return tail_d>end_d;
}
bool check(){
	return empty_q()&&empty_p();
}
void add(int X,int Y,int Z){
	a[++cnt].book=X;
	a[cnt].u=Y;
	a[cnt].v=Z;
}
void Clear(){
	while(tail_q<end_q){
		q[tail_q]=0;
		tail_q++;
	}
	while(tail_p<end_p){
		p[tail_p]=0;
		tail_p++;
	}
	while(tail_d<end_d){
		d[tail_d]=0;
		tail_d++;
	}
	tail_q=tail_p=tail_d=l;
	end_q=end_p=end_d=r;
	cnt=0;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	std::ios::sync_with_stdio(false);
	
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k;
		if(n==2){
			for(int i=1;i<=m;i++){
				cin>>t;
				if(empty_q()&&empty_p){
					PushUp_q(t);
					add(1,1,0);
					continue;
				}
				if(q[tail_q]==t){
					PopUp_q();
					add(1,1,0);
				}
				else if(p[tail_p]==t){
					PopUp_p();
					add(1,2,0);
				}
				else if(q[end_q]==t&&empty_p()){
					PopDown_q();
					add(1,2,0);
					add(2,1,2);
				}
				else if(p[end_p]==t&&empty_q()){
					PopDown_p();
					add(1,1,0);
					add(2,1,2);
				}
				else{
					PushUp_q(t);
					add(1,1,0);
				}
			}
		}
		else if(n==3){
			for(int i=1;i<=m;i++){
				cin>>t;
				if(empty_q()&&empty_p()&&empty_d()){
					PushUp_q(t);
					add(1,1,0);
					continue;
				}
				if(q[tail_q]==t){
					add(1,1,0);
					PopUp_q();
				}
				else if(p[tail_p]==t){
					add(1,2,0);
					PopUp_p();
				}
				else if(d[tail_d]==t){
					add(1,3,0);
					PopUp_d();
				}
				else if(q[end_q]==t&&(empty_p()||empty_d())){
					PopDown_q();
					if(empty_p())
						add(1,2,0),add(2,1,2);
					else	
						add(1,3,0),add(2,1,3);	
				}          
				else if(p[end_p]==t&&(empty_q()||empty_d())){
					PopDown_p();
					if(empty_q())
						add(1,1,0),add(2,1,2);
					else
						add(1,3,0),add(2,2,3);
				}
				else if(d[end_d]==t&&(empty_q()||empty_p())){
					PopDown_d();
					if(empty_q())
						add(1,1,0),add(2,1,3);
					else
						add(1,2,0),add(2,2,3);
				}
				else{
					PushUp_q(t);
					add(1,1,0);
				}
			}
		}
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++){
			cout<<a[i].book<<" "<<a[i].u;
			if(a[i].book==2)
				cout<<" "<<a[i].v;
			cout<<endl;
		}
		Clear();
	}
	
	return 0;
}