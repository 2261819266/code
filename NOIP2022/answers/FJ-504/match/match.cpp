#include<bits/stdc++.h>
using namespace std;

vector<int> a,b;
int temp,T,n,Q,l,r;
unsigned long long ans;
map<int,map<int,unsigned long long> > MAX;

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	a.push_back(0),b.push_back(0);
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=1;i<=n;i++){
		cin>>temp;
		b.push_back(temp);
	}
	cin>>Q;
	while(Q--){
		cin>>l>>r;
		ans=0;
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				if(!MAX[p][q]){
					int max_a=INT_MIN,max_b=INT_MIN;
					for(int i=p;i<=q;i++){
						max_a=max(max_a,a[i]);
						max_b=max(max_b,b[i]);
					}
					MAX[p][q]=(unsigned long long)max_a*max_b;
				}
				ans+=MAX[p][q];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

//Spider Tree!!!
//***!!!
/*
#include<bits/stdc++.h>
using namespace std;

struct Tree{
	int l,r,Max;
}tr_a[1000001],tr_b[1000001];

int a[250001],b[250001];
int temp,T,n,Q,l,r;
unsigned long long ans;

inline void build_a(int pos,int l,int r){
	tr_a[pos].l=l;
	tr_a[pos].r=r;
	if(l==r){
		tr_a[pos].Max=a[l];
	}
	else{
		int mid=(l+r)>>1;
		build_a(pos<<1,l,mid);
		build_a(pos<<1|1,mid+1,r);
		tr_a[pos].Max=max(tr_a[pos<<1].Max,tr_b[pos<<1].Max);
	}
}

inline unsigned long long max_a(int pos,int l,int r){
	if(tr_a[pos].l==l&&r==tr_a[pos].r){/////
		return tr_a[pos].Max;
	}
	else{
		int mid=(l+r)>>1;
		return max(max_a(pos<<1,l,mid),max_a(pos<<1|1,mid+1,r));
	}
}

inline void build_b(int pos,int l,int r){
	tr_b[pos].l=l;
	tr_b[pos].r=r;
	if(l==r){
		tr_b[pos].Max=b[l];
	}
	else{
		int mid=(l+r)>>1;
		build_b(pos<<1,l,mid);
		build_b(pos<<1|1,mid+1,r);
		tr_b[pos].Max=max(tr_b[pos<<1].Max,tr_b[pos<<1].Max);
	}
}

inline unsigned long long max_b(int pos,int l,int r){
	if(tr_b[pos].l==l&&tr_b[pos].r==r){
		return tr_b[pos].Max;
	}
	else{
		int mid=(l+r)>>1;
		return max(max_b(pos<<1,l,mid),max_b(pos<<1|1,mid+1,r));
	}
}

int main(){
	freopen("match1.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	build_a(1,1,n),build_b(1,1,n);
	cin>>Q;
	while(Q--){
		cin>>l>>r;
		ans=0;
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				ans+=max_a(1,p,q)*max_b(1,p,q);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
*/