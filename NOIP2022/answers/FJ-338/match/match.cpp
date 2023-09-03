#include <iostream>
using namespace std;
const int maxn=250011;
int a[maxn],b[maxn];
struct tree{
	int l,r,maxx;
}t1[maxn*4],t2[maxn*4];

inline int read(){
	char ch;
	bool flag=false;
	while((ch=getchar())&&(ch<'0'||ch>'9'))
		if(ch=='-') flag=true;
	int res=ch^48;
	while((ch=getchar())&&(ch>='0'&&ch<='9'))
		res=(res<<3)+(res<<1)+(ch^48);
	return flag?~res+1:res;
}

void build1(int k,int l,int r){
	t1[k].l=l;
	t1[k].r=r;
	if(l==r){
		t1[k].maxx=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build1(k<<1,l,mid);
	build1(k<<1|1,mid+1,r);
	t1[k].maxx=max(t1[k<<1].maxx,t1[k<<1|1].maxx);
}

void build2(int k,int l,int r){
	t2[k].l=l;
	t2[k].r=r;
	if(l==r){
		t2[k].maxx=b[l];
		return ;
	}
	int mid=(l+r)>>1;
	build2(k<<1,l,mid);
	build2(k<<1|1,mid+1,r);
	t2[k].maxx=max(t2[k<<1].maxx,t2[k<<1|1].maxx);
}

int query1(int k,int l,int r){
	if(t1[k].l==l&&t1[k].r==r) return t1[k].maxx;
	int mid=(t1[k].l+t1[k].r)>>1;
	if(r<=mid) return query1(k<<1,l,r);
	else if(l>mid) return query1(k<<1|1,l,r);
	else return max(query1(k<<1,l,mid),query1(k<<1|1,mid+1,r));
}

int query2(int k,int l,int r){
	if(t2[k].l==l&&t2[k].r==r) return t2[k].maxx;
	int mid=(t2[k].l+t2[k].r)>>1;
	if(r<=mid) return query2(k<<1,l,r);
	else if(l>mid) return query2(k<<1|1,l,r);
	else return max(query2(k<<1,l,mid),query2(k<<1|1,mid+1,r));
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n;
	t=read();
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	build1(1,1,n);
	build2(1,1,n);
	int q;
	q=read();
	int l,r;
	while(q--){
		l=read();
		r=read();
		unsigned long long sum=0;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				sum+=query1(1,i,j)*query2(1,i,j);
			}
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
