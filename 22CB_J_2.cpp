#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[33],n;
ll dp[33][1<<3/*01,10,11是否出现过*/][2];
ll dfs(int pos,int sta,int ismx)
{
    if(pos==-1)
    {
        if(sta==7)return 1;//01,10,11都一定要出现 
        else return 0;
    }
    if(~dp[pos][sta][ismx])return dp[pos][sta][ismx];
    
    ll res=0;
    for(int i=0;i<=1;++i)
        for(int j=0;j<=1;++j)
        {
            if(ismx && i>a[pos])continue;//1.a<=n
            if((i==0&&j==1) && !(sta&(1<<1)))continue;//2.a>b
            if((i==0&&j==1) && !(sta&(1<<2)))continue;//3.a>c
            
            int bjsta=sta;
            if(i==0&&j==1)bjsta|=1;
            if(i==1&&j==0)bjsta|=2;
            if(i==1&&j==1)bjsta|=4;
            
            res+=dfs(pos-1,bjsta,ismx&&(i==a[pos]));
        }
    
    dp[pos][sta][ismx]=res;
    return res;
}
void SV()
{
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);
    int tt=33 , js=0 , nn=n;
    while(tt--)a[js++]=nn&1 , nn>>=1;
    printf("%lld\n",dfs(32,0,1)*3);//别忘了*3 
}

int main()
{
    int TTT;scanf("%d",&TTT);while(TTT--)SV();
    return 0;
}