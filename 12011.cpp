//
// Created by 서준혁 on 5/12/24.
//
#include<iostream>
using namespace std;
int t;
int n;
int arr[1004], dp[1004];
int ans=-987654321;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;

    while(t--)
    {
        dp[0]=0;
        cin>>n;
        ans = -987654321;
        for(int i =1; i<=n; i++)
        {
            cin>>arr[i];

        }
        for(int i =1; i<=n; i++)
        {
            dp[i]= max(dp[i-1]+arr[i], arr[i]);
            ans= max(dp[i], ans);
        }
        cout<<ans<<'\n';
    }
}