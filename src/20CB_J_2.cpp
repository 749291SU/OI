#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll rd(){
    ll x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    return x*f;
}
const int maxn=1e3+5;
const ll mod=1e9+7;
ll ksm(ll a,ll b){ll ans=1;a%=mod;while(b){if(b&1)ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
const int M=1e3+5;
int pre[M],prime[M],ptot;
void init(){
    for (int i=2;i<M;i++){
        if (pre[i]==0)
            prime[++ptot]=pre[i]=i;
        for (int j=1;j<=ptot;j++){
            int t =i*prime[j];
            if (t>=M)
                break;
            pre[t]=prime[j];
            if (i%prime[j]==0)
                break;
        }
    }
}

int n,m,w,r1,c1,h1,r2,c2,h2;
ll dp[maxn][maxn],vis[maxn][maxn],jc[maxn<<1],inv[maxn<<1];
ll tmp[maxn<<1];
ll calc(int x,int y,int z){//从(1,1,1)出发到达(x,y,z)的方案数
    memset(tmp,0,sizeof(tmp));
    for (int i=0;i<=y;i++){
        for (int j=0;j<=z;j++){
            tmp[i+j]+=dp[y][i]*dp[z][j]%mod*jc[i+j]%mod*inv[i]%mod*inv[j]%mod;
            tmp[i+j]%=mod;
        }
    }//合并二三维
    ll ans=0;
    for (int i=0;i<=x;i++){
        for (int j=0;j<=y+z;j++){
            ans+=dp[x][i]*tmp[j]%mod*jc[i+j]%mod*inv[i]%mod*inv[j]%mod;
            ans%=mod;
        }
    }
    return ans;
}

int main() {
    init();//筛质数
    jc[0]=1;inv[0]=1;inv[1]=1;
    for (int i=1;i<=2000;i++)jc[i]=(jc[i-1]*i)%mod;//阶乘
    for (int i=2;i<=2000;i++)inv[i]=ksm(jc[i],mod-2);//阶乘逆元
    n=rd();m=rd();w=rd();
    r1=rd();c1=rd();h1=rd();
    r2=rd();c2=rd();h2=rd();
    dp[1][0]=1;vis[1][0]=1;
    int up=max(n,max(m,w)),now=0;
    for (int i=2;i<=up;i++){
        for (int j=0;j<=now;j++){
            for (int k=1;k<=ptot;k++){
                if (i-prime[k]<1)break;
                if (!vis[i-prime[k]][j])continue;
                dp[i][j+1]=(dp[i][j+1]+dp[i-prime[k]][j])%mod;
                vis[i][j+1]=1;
            }
        }
        if (vis[i][now+1])now++;
    }
    ll ans=calc(n,m,w);
    ans=(ans-(calc(r1,c1,h1)*calc(n-r1+1,m-c1+1,w-h1+1))%mod+mod)%mod;
    ans=(ans-(calc(r2,c2,h2)*calc(n-r2+1,m-c2+1,w-h2+1))%mod+mod)%mod;
    if (r1<=r2&&c1<=c2&&h1<=h2)ans=(ans+calc(r1,c1,h1)*calc(r2-r1+1,c2-c1+1,h2-h1+1)%mod*calc(n-r2+1,m-c2+1,w-h2+1)%mod)%mod;
    if (r2<=r1&&c2<=c1&&h2<=h1)ans=(ans+calc(r2,c2,h2)*calc(r1-r2+1,c1-c2+1,h1-h2+1)%mod*calc(n-r1+1,m-c1+1,w-h1+1)%mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
