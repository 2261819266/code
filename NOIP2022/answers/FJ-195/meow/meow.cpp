#include<bits/stdc++.h>
using namespace std;
int T;
int a[7000000],pos[7000000],top[400][3],cnt,cn;
long long int n,m,k;
struct node{
	int x,y,z;
}c[14000000];
void solve1(){
	cout<<m<<endl;
	for(int i=1;i<=m;i++){
	cout<<"1"<<" "<<a[i]<<'\n';
	}
}
void add(int x1,int y1,int c1){
	c[++cn].x=x1;
	c[cn].y=y1;
	c[cn].z=c1;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		cnt=0;
		cn=0;
		memset(top,0,sizeof(top));
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		if(k==n-1){
			solve1();
		}
		else if(k==2*n-2){
			for(int i=1;i<=m;i++){
				int t=a[i]%(n-1)+1;
				if(pos[a[i]]==0){
					add(1,t,0);
					if(!top[t][1]){
						top[t][1]=a[i];
						pos[a[i]]=1;
					}
					else{
						top[t][2]=a[i];
						pos[a[i]]=2;
					}
				}
				else{
					if(pos[a[i]]==2){
						add(1,t,0);
						pos[a[i]]=0;
						top[t][2]=0;
					}
					else if(pos[a[i]]==1){
						add(1,n,0);
						add(2,t,n);
						cnt++; 
						pos[a[i]]=0;
						if(top[t][2]){
						pos[top[t][2]]=1;
						top[t][1]=top[t][2];
						top[t][2]=0;
						}
						else{
							top[t][1]=0;
						}
					}
				}
			}
			cout<<m+cnt<<'\n';
			for(int i=1;i<=cn;i++){
				cout<<c[i].x<<" "<<c[i].y<<" ";
				if(c[i].x==2){
					cout<<c[i].z;
				}
				cout<<'\n';
			}
		}
	}
	return 0;
}
