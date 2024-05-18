//
// Created by 서준혁 on 5/12/24.
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod= 1e9+7;
int m,n,x,y;
int arr[50001];
int cnt[50001];
ll factorialList[50001];

int t;
ll method;
ll mx;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    factorialList[0]=1;
    factorialList[1]=1;
    for(ll i =2; i<=50000; i++) factorialList[i]= (factorialList[i-1]*i)%mod;
    while(t--)
    {
        cin>>n>>m;
        memset(arr,0,sizeof(arr));
        memset(cnt,0,sizeof(cnt));
        for(int i =0; i<n; i++) cin>>arr[i];
        while(m--)
        {
            cin>>x>>y;
            cnt[x-1]++; cnt[y]--;

        }
        for(int i =1; i<=n; i++)
            cnt[i]+=cnt[i-1];
        sort(arr, arr+n);
        sort(cnt, cnt+n);
        mx=0;
        for(int i =0; i<n; i++)
            mx+=(ll)(arr[i]*cnt[i]);
        method =1;
        ll comp =1;
        int prevMx=cnt[0];
        for(int i =1; i<=n; i++)
        {
            if(cnt[i]==prevMx) comp++;
            else{
                method= (method*factorialList[comp])%mod;
                prevMx = cnt[i];
                comp=1;

            }
        }
        method= (method*factorialList[comp])%mod;
        cout<<mx<<" "<<method<<'\n';


    }


}
