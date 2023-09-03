#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
template<class T>
void rd(T &x)
{
	char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar());
	for(x=0;ch<='9'&&ch>='0';ch=getchar())
		x=x*10+(ch^48);
}
typedef unsigned long long ull;
const int N=2.5e5+5;
typedef pair<int,int> pii;
int T;
struct Seg{ull S,H,ThA,ThB,ThI;int I,A,B,OA,OB,TgA,TgB;}a[N<<2];
#define S(i) a[i].S
#define H(i) a[i].H
#define I(i) a[i].I
#define A(i) a[i].A
#define B(i) a[i].B
#define OA(i) a[i].OA
#define OB(i) a[i].OB
#define TgA(i) a[i].TgA
#define TgB(i) a[i].TgB
#define ThA(i) a[i].ThA
#define ThB(i) a[i].ThB
#define ThI(i) a[i].ThI
#define lc (k<<1)
#define rc (k<<1|1)

ull GA(int k){return OA(k)?1ull*I(k)*A(k):A(k);}
ull GB(int k){return OB(k)?1ull*I(k)*B(k):B(k);}

void UPD(int k)
{
	H(k)=H(lc)+H(rc);
	S(k)=S(lc)+S(rc),I(k)=I(lc)+I(rc);
	OA(k)=(A(lc)==A(rc)&&OA(lc)&&OA(rc));
	A(k)=(OA(k)?A(lc):GA(lc)+GA(rc));
	OB(k)=(B(lc)==B(rc)&&OB(lc)&&OB(rc));
	B(k)=(OB(k)?B(lc):GB(lc)+GB(rc));
}

void CngA(int k,int v)
{
	H(k)+=v*GB(k)*T,ThB(k)+=1ull*v*T;
	ThI(k)+=1ull*v*T*TgB(k);
	A(k)+=v,S(k)+=v*GB(k),TgA(k)+=v;
}
void CngB(int k,int v)
{
	H(k)+=v*GA(k)*T,ThA(k)+=1ull*v*T;
	ThI(k)+=1ull*v*T*TgA(k);
	B(k)+=v,S(k)+=v*GA(k),TgB(k)+=v;
}
void Push(int k,int f)
{
	H(k)+=GA(k)*ThA(f)+GB(k)*ThB(f)+I(k)*ThI(f);
	ThA(k)+=ThA(f),ThB(k)+=ThB(f);
	ThI(k)+=ThI(f)+ThA(f)*TgA(k)+ThB(f)*TgB(k);
	if(TgA(f))A(k)+=TgA(f),S(k)+=TgA(f)*GB(k),TgA(k)+=TgA(f);
	if(TgB(f))B(k)+=TgB(f),S(k)+=TgB(f)*GA(k),TgB(k)+=TgB(f);
}
void PD(int k){Push(lc,k),Push(rc,k),TgA(k)=TgB(k)=0,ThA(k)=ThB(k)=ThI(k)=0;}

void Build(int k,int l,int r)
{
	if(l==r)return OA(k)=OB(k)=I(k)=1,void();
	int mid=(l+r)>>1;
	Build(lc,l,mid),Build(rc,mid+1,r);
}

void ChangeA(int k,int l,int r,int L,int R,int v)
{
	if(L<=l && r<=R && OA(k))return CngA(k,v-A(k));
	int mid=(l+r)>>1;PD(k);
	if(L<=mid)ChangeA(lc,l,mid,L,R,v);
	if(R>mid)ChangeA(rc,mid+1,r,L,R,v);
	UPD(k);
}

void ChangeB(int k,int l,int r,int L,int R,int v)
{
	if(L<=l && r<=R && OB(k))return CngB(k,v-B(k));
	int mid=(l+r)>>1;PD(k);
	if(L<=mid)ChangeB(lc,l,mid,L,R,v);
	if(R>mid)ChangeB(rc,mid+1,r,L,R,v);
	UPD(k);
}

ull Query(int k,int l,int r,int L,int R)
{
	if(L<=l && r<=R)return S(k)*T-H(k);
	int mid=(l+r)>>1;PD(k);ull s=0;
	if(L<=mid)s+=Query(lc,l,mid,L,R);
	if(R>mid)s+=Query(rc,mid+1,r,L,R);
	return s;
}

int Typ,n,Q,A[N],B[N],pra[N],prb[N];
int st[N],top;
vector<pii> Vec[N];
ull Ans[N];

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	rd(Typ),rd(n);
	for(int i=1;i<=n;++i)rd(A[i]);
	for(int i=1;i<=n;++i)rd(B[i]);
	rd(Q);
	for(int i=1,x,y;i<=Q;++i)
		rd(x),rd(y),Vec[y].push_back(pii(x,i));
	Build(1,1,n);
	top=0;
	for(int i=1;i<=n;++i)
	{
		while(top && A[st[top]]<A[i])top--;
		pra[i]=st[top]+1,st[++top]=i;
	}
	top=0;
	for(int i=1;i<=n;++i)
	{
		while(top && B[st[top]]<B[i])top--;
		prb[i]=st[top]+1,st[++top]=i;
	}
	for(int i=1;i<=n;++i)
	{
		ChangeA(1,1,n,pra[i],i,A[i]);
		ChangeB(1,1,n,prb[i],i,B[i]);
		++T;
		for(pii q:Vec[i])
			Ans[q.second]+=Query(1,1,n,q.first,i);
	}
	for(int i=1;i<=Q;++i)
		printf("%llu\n",Ans[i]);
	return 0;
}
