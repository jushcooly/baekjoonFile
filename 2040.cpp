#include<iostream>
using namespace std;
int INF=987654321;
int dp[3004], arr[3004], n, res;
int solve(int turn)
{
    if(turn==0) return 0;
    if(dp[turn]!=INF) return dp[turn];
    int ans =INF;
    for(int i= turn; i>=1; i--)
    {
        ans = min(ans, arr[turn]-arr[i-1]-solve(i-1));

    }  return dp[turn]= ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int t=3;
    while(t--){
        for(int i =1; i<=n; i++)
        {
            cin>>arr[i];
            arr[i]+=arr[i-1];

        }
        for(int i =0; i<=3000; i++)
            dp[i]= INF;
        res= solve(n);
        if(res<0) cout<<"A\n";
        else if(res==0) cout<<"D\n";
        else cout<<"B\n";

    }

}