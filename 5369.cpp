//
// Created by 서준혁 on 2/6/24.
//
#include<iostream>
using namespace std;
int arr[10001];
int n;
int idx;
void solve(int st, int en)
{
    if(st>=en) return;
    if(st==en-1)
    {
        cout<<arr[st]<<'\n';
        return;
    }
    int i = st+1;
    while(i<en)
    {
        if(arr[st]<arr[i]) break;i++;
    }

    solve(st+1, i);
    solve(i, en);
    cout<<arr[st]<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    idx=0;
    while(cin>>n)
    {
        arr[idx++]= n;

    }
    solve(0, idx);


}