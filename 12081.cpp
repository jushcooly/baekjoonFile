#include<iostream>
#include<set>
#include <deque>
#include<map>
#include <vector>
#include <algorithm>
using namespace std;
const int dy[]= {1,0,-1,0};
const int dx[]= {0, -1,0, 1};
set<pair<int,int>> food;
bool gotFood(pair<int,int> &p)
{
    int sum= p.first+p.second;
    if(sum%2==0) return false;
    if(food.find(p)!=food.end()) return false;
    return true;
}
void eating(pair<int,int>&p)
{
    food.insert(p);
}
void solve()
{
    int Q,R,C;
    cin>>Q>>R>>C;
    deque<pair<int,int>> snake;
    food.clear();
    int dir=3;
    vector<pair<int,char>> lis;
    for(int i =0; i<Q; i++)
    {
        cin>>lis[i].first>>lis[i].second;

    }
    sort(lis.begin(),lis.end());
    map<pair<int,int>,int> visited;
    int tt =1; int idx =0;
    while(1)
    {
        if(tt>1e9)
        {
            cout<<snake.size()<<'\n';
            return;
        }
        pair<int,int> sp= snake.front();
        sp.first = (sp.first+dx[dir]+R)%R;
        sp.second = (sp.second+dy[dir]+C)%C;
        if(!gotFood(sp))
        {
            visited[snake.back()]--;
            if(!visited[snake.back()]) visited.erase(snake.back());
            visited[sp]++;
            if(visited[sp]>1){
                cout<<snake.size()<<'\n';
                return;
            }
            snake.push_front(sp);
            snake.pop_back();

        }
        else{
            eating(sp);
            visited[sp]++;
            if(visited[sp]>1){
                cout<<snake.size()<<'\n';
                return;
            }
            snake.push_front(sp);

        }
        if(idx<lis.size()&&lis[idx].first==tt)
        {
            if(lis[idx].second=='L') dir = (dir+3)%4;
            else if(lis[idx].second=='R') dir = (dir+1)%4;
            ++idx;

        }
        ++tt;
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i =1; i<=t; i++)
    {
        cout<<"Case #"<<i<<": ";solve();
    }
}