//
// Created by 서준혁 on 5/3/24.
//
#include<iostream>
#include<vector>

using namespace std;
vector<int> vol, len;
int d,p;
int dp[100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>d>>p;
    vol.resize(p);
    len.resize(p);
    for(int i =0; i<p; i++)
    {
        cin>>len[i]>>vol[i];

    }
    dp[0]=1;
    for(int i =0; i<p; i++)
    {
        for(int j=d; j>=len[i]; j--)
        {
            if(dp[j-len[i]])
            {
                if(j==len[i])
                {
                    dp[j]= max(dp[j],vol[i]);
                }
                else{
                    dp[j]= max(min(dp[j-len[i]],vol[i]),dp[j]);
                }
            }

        }
    }
    cout<<dp[d];
}