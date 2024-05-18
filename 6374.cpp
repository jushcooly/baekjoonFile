//
// Created by 서준혁 on 5/12/24.
//
#include<iostream>
using namespace std;
int n;
int arr[104][104], dp[104][104];
int ans = -987654321;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    dp[0][0]=0;
    for(int i=1; i<=n; i++ )
    {
        for(int j =1; j<=n; j++)
        {
            cin>>arr[i][j];
        }

    }
    for(int i =1; i<=n; i++)
    {
        for(int j =1; j<=n; j++)
        {
            dp[i][j]= dp[i-1][j]+dp[i][j-1]+arr[i][j]-dp[i-1][j-1];
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j =i; j<=n; j++)
        {
            for(int y =1; y<=n; y++)
            {
                for(int x=y; x<=n; x++)
                {
                   ans=  max(ans, dp[j][x]-dp[i-1][x]-dp[j][y-1]+dp[i-1][y-1]);
                }
            }
        }
    }
    cout<<ans;

}
