#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
bool vis[N][N];
char a[N][N],pp;
int n,m, lngth=0,mx;
bool valid(int r,int c){
return r >=0&&r<m&&a[r][c]==pp;
}
int fix(int y) {
	if (y < 0) return n - 1;
	if (y >= n) return 0;
	return y;
}

int solve(int r,int c){


    if(valid(r,c)==false||vis[r][c]==true)return 0;
    vis[r][c]=true;
    lngth++;
        solve(r-1,fix(c));
        solve(r+1,fix(c));
        solve(r,fix(c+1));
        solve(r,fix(c-1));


return mx=max(mx,lngth);
}
int main()
{
    while(cin>>m>>n){
    char k;
    int ans=0,xx,yy;
    int mx1=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cin>>k;
           a[i][j]=k;
        }
    }
    cin>>xx>>yy;
    pp=a[xx][yy];

   solve(xx,yy);
   mx=0,lngth=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==pp&&vis[i][j]==false){
                    ans=solve(i,j);
                    mx1=max(mx1,ans);
                    mx=0;lngth=0;
           }
        }
    }
    cout<<mx1<<"\n";
    mx=0;memset(vis,0,sizeof vis);lngth=0;


    }
    return 0;
}
