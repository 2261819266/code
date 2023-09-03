#include<bits/stdc++.h>
using namespace std;
int read()
{
	int c=0;
	char ch=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9')
	{
		c=(c<<3)+(c<<1)+(ch-'0');
		ch=getchar();
	}
	return c;
}
const int N=250088;
int T,n,q,a[N],b[N],ql,qr,tra[N<<2],trb[N<<2];
unsigned long long int ans[88],sc[88],cnt=0;
void Builda(int id,int L,int R)
{
	if(L==R)
	{
		tra[id]=a[R];
		return ;
	}
	int mid=(L+R)>>1;
	Builda(id*2,L,mid);
	Builda(id*2+1,mid+1,R);
	tra[id]=max(tra[id*2],tra[id*2+1]);
}
void Buildb(int id,int L,int R)
{
	if(L==R)
	{
		trb[id]=b[R];
		return ;
	}
	int mid=(L+R)>>1;
	Buildb(id*2,L,mid);
	Buildb(id*2+1,mid+1,R);
	trb[id]=max(trb[id*2],trb[id*2+1]);
}
int Querya(int id,int L,int R,int qL,int qR)
{
	if(qL<=L && R<=qR) return tra[id];
	int mid=(L+R)>>1,resa=0;
	if(qL<=mid) resa=Querya(id*2,L,mid,qL,qR);
	if(qR>mid) resa=max(resa,Querya(id*2+1,mid+1,R,qL,qR));
	return resa;
}
int Queryb(int id,int L,int R,int qL,int qR)
{
	if(qL<=L && R<=qR) return trb[id];
	int mid=(L+R)>>1,resb=0;
	if(qL<=mid) resb=Queryb(id*2,L,mid,qL,qR);
	if(qR>mid) resb=max(resb,Queryb(id*2+1,mid+1,R,qL,qR));
	return resb;
}
unsigned long long int fz,p;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	Builda(1,1,n);
	Buildb(1,1,n);
	q=read();
	while(q--)
	{
		ql=read(),qr=read();
		for(int i=0;i<=64;i++) ans[i]=0,sc[i]=0;
		for(int i=ql;i<=qr;i++)
		{
			for(int j=i;j<=qr;j++)
			{
				int k1=Querya(1,1,n,i,j);
				int k2=Queryb(1,1,n,i,j);
				long long int res=k1*k2;
				int tot=0,now=0;
				while(res)
				{
					if(res&1)
					{
						ans[tot]++;
						now=tot;
						while(ans[now]>1)
						{
							ans[now+1]+=ans[now]/2;
							ans[now]%=2;
							now++;
							if(now>=64) ans[now]=0;
						}
					}
					tot++;
					res>>=1;
				}
			}
		}
		cnt=1,fz=1;
		p=1;
		if(ans[0]) sc[1]=1;
		for(int i=1;i<=63;i++)
		{
			fz*=2;
			if(ans[i])
			{
				p=1;
				if(sc[p]+fz>100000)
				{
					sc[p+1]+=(sc[p]+fz)/100000;
					sc[p]=(sc[p]+fz)%100000;
					p++;
				}
				else sc[p]+=fz;
				while(sc[p]>100000)
				{
					sc[p+1]+=(sc[p])/100000;
					sc[p]=(sc[p])%100000;
					p++;
				}
				cnt=max(cnt,p);
			}
		}
		printf("%llu",sc[cnt]);
		for(int i=cnt-1;i>=1;i--)
		{
			if(sc[i]>9999) printf("%llu",sc[i]);
			else
			{
				if(sc[i]>999) printf("0%llu",sc[i]);
				else
				{
					if(sc[i]>99) printf("00%llu",sc[i]);
					else
					{
						if(sc[i]>9) printf("000%llu",sc[i]);
						else printf("0000%llu",sc[i]);
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}
