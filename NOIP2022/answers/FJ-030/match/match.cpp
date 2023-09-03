#include"stdio.h"
#include"time.h"
#include"vector"
#include"algorithm"
#define reg register
#define getchar()(inBuf==lenBuf?lenBuf=(inBuf=Buf)+fread(Buf,1,1<<20,stdin):0,inBuf==lenBuf?EOF:*inBuf++)
char Buf[1<<20],*inBuf,*lenBuf;
template<class T>void read(T&x){reg char ch,f=x=0;while(ch=getchar(),ch<'0'||ch>'9');while(x=x*10+(ch&15),ch=getchar(),ch<='9'&&ch>='0');f?x=-x:0;}
int T,n,Q,a[250010],b[250010];
int stk[250010],L[250010],R[250010];
struct qd{int l,r,id;};std::vector<qd>q;
unsigned long long ans[250010];
int l[250010],t[250010],res[250010];
unsigned long long pre[250010],dp[250010];
void dc(int Lt,int mid,int Rt,std::vector<qd>q){
    if(Lt>Rt||!q.size())return;
    if(mid<Lt||mid>Rt)return;
    // printf("%d %d %d\n",Lt,mid,Rt);
    if(Lt==Rt){
        for(auto i:q)ans[i.id]+=1ull*a[Lt]*b[Lt];
        return;
    }
    for(reg int i=Lt;i<=Rt;++i)t[i]=b[i];
    for(reg int i=mid-1;i>=Lt;--i)t[i]<t[i+1]?t[i]=t[i+1]:0;
    for(reg int i=mid+1;i<=Rt;++i)t[i]<t[i-1]?t[i]=t[i-1]:0;
    pre[Lt-1]=0;for(reg int i=Lt;i<=Rt;++i)pre[i]=pre[i-1]+t[i];
    std::sort(q.begin(),q.end(),[](qd a,qd b){return a.l==b.l?a.id<b.id:a.l>b.l;});
    dp[mid+1]=0;for(reg int i=mid,j=0,k=mid;i>=Lt;--i){
        while(k<=Rt&&t[k]<=t[i])++k;--k;
    // if(Lt==19&&Rt==21)fprintf(stderr,"%d ",k);
        res[i]=k,dp[i]=dp[i+1];
        dp[i]+=1ull*(k-mid+1)*t[i];
        for(;j<q.size()&&q[j].l>=i;++j)if(q[j].l==i&&q[j].r>=mid){
            int pos=std::lower_bound(res+i,res+mid+1,q[j].r,[](int a,int b){return a>b;})-res;
            // if(q[j].id==1)fprintf(stderr,"%llu\n",pos);
            ans[q[j].id]+=a[mid]*(dp[pos]+(pre[pos-1]-pre[i-1])*(q[j].r-mid+1));
        }
    }
    std::sort(q.begin(),q.end(),[](qd a,qd b){return a.r==b.r?a.id<b.id:a.r<b.r;});
    dp[mid-1]=0;for(reg int i=mid,j=0,k=mid;i<=Rt;++i){
        if(k>mid)k=mid;while(k>=Lt&&t[k]<t[i])--k;++k;
        res[i]=k,dp[i]=dp[i-1];
        dp[i]+=1ull*(mid-k+1)*t[i];
        for(;j<q.size()&&q[j].r<=i;++j)if(q[j].r==i&&q[j].l<=mid){
            int pos=std::lower_bound(res+mid,res+i+1,q[j].l,[](int a,int b){return a>b;})-res;
            // for(reg int _=mid;_<=i;++_)printf("%d ",res[_]);puts("");
            // printf("%d %d\n",Lt,pos);
            ans[q[j].id]+=a[mid]*(dp[pos-1]+(pre[i]-pre[pos-1])*(mid-q[j].l+1));
        }
    }
    std::vector<qd>ls,rs;
    for(auto i:q){
        if(i.r<mid)ls.push_back(i);
        else if(i.l>mid)rs.push_back(i);
        else{
            if(i.l<mid)ls.push_back((qd){i.l,mid-1,i.id});
            if(mid<i.r) rs.push_back((qd){mid+1,i.r,i.id});
        }
    }
    {std::vector<qd>t;q.swap(t);}
    dc(Lt,L[mid],mid-1,ls),dc(mid+1,R[mid],Rt,rs);
}
main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    read(T);read(n);
    for(reg int i=1;i<=n;++i)read(a[i]);
    for(reg int i=1;i<=n;++i)read(b[i]);
    for(reg int i=1,tp=0;i<=n;R[stk[tp]]=i,stk[++tp]=i,++i)
        for(;tp&&a[stk[tp]]<a[i];L[i]=stk[tp--]);
    read(Q),q.resize(Q);for(reg int i=0;i<Q;++i)read(q[i].l),read(q[i].r),q[i].id=i+1;
    dc(1,stk[1],n,q);
    for(reg int i=1;i<=Q;++i)printf("%llu\n",ans[i]);
}
