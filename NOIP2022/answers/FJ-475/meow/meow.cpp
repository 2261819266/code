#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
vector<int>s[310];
int ssize[310];
int a[2000010];
int topsum[1010],undersum[1010];
int nxt[2000010];
int lst[2000010];
int ans;
void delete_top(int S){
//	cout<<"*";
	topsum[s[S][ssize[S]-1]]=0;
	if(ssize[S]==1)undersum[s[S][0]]=0;
	if(ssize[S]>0)topsum[s[S][ssize[S]-1]]=S;
	s[S].erase(s[S].begin()+ssize[S]-1);
	ssize[S]--;
//	cout<<"!";
}
void delete_under(int S){
//	cout<<"&";
	undersum[s[S][0]]=0;
	if(ssize[S]==1)topsum[s[S][0]]=0;
	ssize[S]--;
	s[S].erase(s[S].begin());
	if(ssize[S]>0)undersum[s[S][0]]=S;
//	cout<<"!";
}
void add_top(int S,int p){
//	cout<<"^";
	if(ssize[S]>0)topsum[s[S][ssize[S]-1]]=0;
	if(ssize[S]==0)undersum[p]=S;
	topsum[p]=S;
	ssize[S]++;
	s[S].push_back(p);
//	cout<<"!";
}
void push_up(int S,int flag=1){
	while(ssize[S]){
		int x1=undersum[s[S][0]];
		if(x1!=0){
			if(flag){
				cout<<"2 "<<x1<<" "<<S<<endl;
			}else{
				ans++;
			}
			delete_under(x1);
//			s[S].erase(s[S].begin());
//			ssize[S]--;
		}else{
			break;
		}
	}
	undersum[s[S][0]]=S;
}
//topsum每种卡在顶端的位置 undersum每种卡在栈底的位置 
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
/*
1
2 4 2
1 2 1 2 
*/
	cin>>t;
	while(t--){
		ans=0;
		memset(topsum,0,sizeof(topsum));
		memset(undersum,0,sizeof(undersum));
		memset(ssize,0,sizeof(ssize));
		memset(nxt,0,sizeof(nxt));
		memset(lst,0,sizeof(lst));
		for(int i=1;i<=300;i++){
			s[i].clear();
		}
		cin>>n>>m>>k;
		for(int i=m;i>=1;i--){
			cin>>a[i];
		}
		for(int i=m;i>=1;i--){
			nxt[lst[a[i]]]=i;
			lst[a[i]]=i;
		}
		int tp=m;
		while(tp){
			int flag=0;
			int x1=undersum[a[tp]],x2=topsum[a[tp]];
			if(x1!=0){
				ans+=2;
				s[n].push_back(a[tp]);
				push_up(x1,0);
				tp--;
				continue;
			}
			if(x2!=0){
				ans++;
				delete_top(x2);
				tp--;
				continue;
			}
			for(int i=1;i<n;i++){
				if(ssize[i]<=1){
					flag=i;
				}
			}
			if(flag>0){
				if(ssize[flag]>0)topsum[s[flag][ssize[flag]-1]]=0;
				add_top(flag,a[tp]);
				ans++;
				tp--;
			}else{
				if(a[tp-1]==a[tp]){
					tp-=2;
					ans+=2;
				}else{
					bool f[1010]={0};
					flag=0;
					for(int i=tp-1;i>nxt[tp];i--){
						if(a[i]==a[i-1]){
							i--;
							continue;
						}
						int x3=undersum[i];
						if(x3!=0&&f[s[x3][ssize[x3-1]]]!=0){
							flag=x3;
							break;
						}
						if(x3!=0){
							flag=-1;
							break;
						}
						
					}
					if(flag==-1){
						add_top(n,a[tp]);
						ans++;
						tp--;
					}else{
						add_top(flag,a[tp]);
						ans++;
						tp--;
					}
					
				}
			}
		}
		cout<<ans<<endl;
		tp=m;
		for(int i=1;i<=300;i++){
			s[i].clear();
		}
		memset(topsum,0,sizeof(topsum));
		memset(undersum,0,sizeof(undersum));
		memset(ssize,0,sizeof(ssize));
		while(tp){
			int flag=0;
			int x1=undersum[a[tp]],x2=topsum[a[tp]];
			if(x1!=0){
				cout<<"1 "<<n<<endl;
				cout<<"2 "<<x1<<" "<<n<<endl;
				ans+=2;
				s[n].push_back(a[tp]);
				push_up(x1);
				tp--;
				continue;
			}
			if(x2!=0){
				cout<<"1 "<<x2<<endl;
				ans++;
				delete_top(x2);
				tp--;
				continue;
			}
			for(int i=1;i<n;i++){
				if(ssize[i]<=1){
					flag=i;
				}
			}
			if(flag>0){
				if(ssize[flag]>0)topsum[s[flag][ssize[flag]-1]]=0;
				add_top(flag,a[tp]);
				cout<<"1 "<<flag<<endl;
				ans++;
				tp--;
			}else{
				if(a[tp-1]==a[tp]){
					cout<<"1 "<<n<<endl;
					cout<<"1 "<<n<<endl;
					tp-=2;
					ans+=2;
				}else{
					bool f[1010]={0};
					flag=0;
					for(int i=tp-1;i>nxt[tp];i--){
						if(a[i]==a[i-1]){
							i--;
							continue;
						}
						int x3=undersum[i];
						if(x3!=0&&f[s[x3][ssize[x3-1]]]!=0){
							flag=x3;
							break;
						}
						if(x3!=0){
							flag=-1;
							break;
						}
						
					}
					if(flag==-1){
						cout<<"1 "<<n<<endl;
						add_top(n,a[tp]);
						ans++;
						tp--;
					}else{
						cout<<"1 "<<flag<<endl;
						add_top(flag,a[tp]);
						ans++;
						tp--;
					}
					
				}
			}
		}
	}
	return 0;
}
/*
  
4   3
3 1 5

1 2 3
*/
