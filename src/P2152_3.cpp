#include<bits/stdc++.h>
#define U(i,l,r) for(int i(l);i<=r;++i)
#define D(i,r,l) for(int i(r);i>=l;--i)
using namespace std;
typedef long long ll;
#define _int vector<ll>
#define BASE (1000000000ll)
_int rd()
{
	static char c[100005];
	_int t;scanf("%s",c);int l(strlen(c)-1);
	for(;l>=8;l-=9)
	{
		t.push_back(0);ll &x(t.back());
		U(i,l-8,l) x=x*10+(c[i]^48);
	}
	if(~l)
	{
		t.push_back(0);ll &x(t.back());
		U(i,0,l) x=x*10+(c[i]^48);
	}
	return t;
}
void pt(_int a)
{
	printf("%lld",a[a.size()-1]);
	D(i,(int)a.size()-2,0) printf("%09lld",a[i]);
}
_int operator*(_int a,int b)
{
	int temp(0);
	U(i,0,(int)a.size()-1)
		if((a[i]=a[i]*b+temp,temp=0,a[i])>=BASE)
		{
			if(i==a.size()-1) a.push_back(0);
			temp=a[i]/BASE,a[i]%=BASE;
		}
	return a;
}
_int operator-(_int a,_int b)
{//a>b
	U(i,0,b.size()-1)if((a[i]-=b[i])<0) a[i]+=BASE,--a[i+1];
	while(a.size()>1&&!a.back()) a.pop_back();
	return a;
}
_int operator/(_int a,int b)
{
	int temp(0);
	D(i,a.size()-1,0) a[i]+=temp*BASE,temp=a[i]%b,a[i]/=b;
	while(a.size()>1&&!a[a.size()-1]) a.pop_back();
	return a;
}
bool operator<(_int a,_int b)
{
	if(a.size()>b.size()) return false;
	if(a.size()<b.size()) return true;
	D(i,a.size()-1,0)
		if(a[i]>b[i]) return false;
		else if(a[i]<b[i]) return true;
	return false;
}
_int gcd(_int a,_int b)
{
	int tims(0);if(a<b) swap(a,b);
	while(!(a[0]&1)&&!(b[0]&1)) a=a/2,b=b/2,++tims;
	while(!(a==b))
	{
		int t1(a[0]&1),t2(b[0]&1);
		!t1?a=a/2:(!t2?b=b/2:a=a-b);
		if(a<b) swap(a,b);
	}
	while(tims--) a=a*2;
	return a;
}
signed main()
{ 
	return pt(gcd(rd(),rd())),0;
}