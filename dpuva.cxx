#include <bits/stdc++.h>
using namespace std;
const int N=200009;
int n,q,d,m;
int a[N],tc=1;
long long dp[205][15][25];
vector<pair<int,int>>qu;
map<pair<int,int>,int>rem;
int mod1(long long a,long long b){
	return (((a%b)+b)%b);
}
long long solve(int i,int k,long long mod){
	if(k>m)return 0;
	if(i>=n){
		return mod==0&&k==m;
	}
	if(dp[i][k][mod]!=-1)return dp[i][k][mod];
	long long opt1=solve(i+1,k+1,mod1(mod+a[i],d));
	long long opt2=solve(i+1,k,mod);
	return dp[i][k][mod]=opt1+opt2;
}
int main(int argc, char **argv)
{
	//ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	while(cin>>n>>q,n!=0&&q!=0){
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ctr=1;bool key=false;
	for(int i=0;i<q;i++){
		cin>>d>>m;	
		qu.push_back({d,m});
	}
	cout<<"SET "<<tc++<<":"<<'\n';
	for(int i=0;i<q;i++){
		d=qu[i].first;m=qu[i].second;
		if(rem[{d,m}]!=0)cout<<"QUERY "<<ctr++<<": "<<rem[{d,m}]<<'\n';
		else{
			memset(dp,-1,sizeof dp);
			long long ans=solve(0,0,0);
			cout<<"QUERY "<<ctr++<<": "<<ans<<'\n';
		}
	}
	rem.clear();qu.clear();
}
	
	return 0;
}

