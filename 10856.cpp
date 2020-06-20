#include <bits/stdc++.h>
using namespace std;
int n;
const int N=200005;
bool vis[N];
vector<pair<int,int>>p;
int main()
{
    int x,y;
    while(cin>>n,n!=0){
        for(int i=0;i<n;i++){
            cin>>x>>y;
            p.push_back({x,y});
        }
        int m=n/2,xx,yy;

        xx=p[m].first;
        yy=p[m].second;


        for(int i=0;i<p.size();i++){
           if(p[m]!=p[i]&&(p[i].first==xx||p[i].second==yy)){
            swap(p[i],p[p.size()-1]);
            p.pop_back();
           }
        }

        swap(p[m],p[p.size()-1]);
        p.pop_back();


        int st=0;
        int st1=0;
        for(int i=0;i<p.size();i++){
            if((p[i].first>xx&&p[i].second>yy)||(p[i].first<xx&&p[i].second<yy)){

                ++st;
            }
            else if((p[i].first>xx&&p[i].second<yy)||(p[i].first<xx&&p[i].second>yy)){
                st1++;
            }
        }
        cout<<st<<" "<<st1<<"\n";
        p.clear();
    }

    return 0;
}
