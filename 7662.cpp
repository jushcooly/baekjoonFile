//
// Created by 서준혁 on 2/6/24.
//
#include<iostream>
#include<queue>
#include<map>

using namespace std;
priority_queue<int> mxPQ;
priority_queue<int,vector<int>, greater<int>> mnPQ;
map<int,int> mp;
char commands;
int m, t, n;
void Init()
{
    while(mnPQ.size())
    {
        mnPQ.pop();

    }
    while(mxPQ.size()) mxPQ.pop();
    mp.clear();
}
void insert(int n)
{
    mnPQ.push(n);
    mxPQ.push(n);
    mp[n]++;

}
void erasing()
{
    if(n==1) {
        if(mxPQ.size())
        {
            mp[mxPQ.top()]--;
            mxPQ.pop();
        }
    }
    if(n==-1){
        if(mnPQ.size())
        {
            mp[mnPQ.top()]--;
            mnPQ.pop();
        }
    }
    while(mxPQ.size()&&mp[mxPQ.top()]==0)
    {
        mxPQ.pop();
    }
    while(mnPQ.size()&&mp[mnPQ.top()]==0)
    {
        mnPQ.pop();
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        Init();
        cin>>m;
        for(int i =0; i<m; i++)
        {
            cin>>commands;
            cin>>n;
            if(commands=='I') insert(n);
            if(commands=='D') erasing();


        }
        while(mxPQ.size()&&mp[mxPQ.top()]==0)
        {
            mxPQ.pop();
        }
        while(mnPQ.size()&&mp[mnPQ.top()]==0)
        {
            mnPQ.pop();
        }
        if(mnPQ.empty()||mxPQ.empty()) cout<<"EMPTY"<<'\n';
        else cout<<mxPQ.top()<<' '<<mnPQ.top()<<'\n';
    }

}