#include <bits/stdc++.h>
using namespace std;
#define print(x) for(auto & it : x)cout<<it<<' '; cout<<endl;
#define printd(x) for(auto & it : x)cout<<it.first<<' '<<it.second<<endl;
#define all(x) x.begin(),x.end()
#define int long long 
const int MOD =  1e9+7;

vector<char>adj(26),v(26);

bool cycle( vector<char> &cpy, char a)
{
    char start = a;
    int cnt = 0;
    while( cpy[a-'a'] != a){
        if( cnt == 25)return false;
        if( cpy[a-'a'] == start)return true;
        a = cpy[a-'a'];
        cnt++;
    }
    return false;
}

bool hasCycleAfterMakingEdge(char a, int pos , string &s)
{
    //if( s[pos] == a)return true;
    vector<char>cpy = adj;
    cpy[a-'a'] = s[pos];
   // print(cpy)
    for(char a = 'a';a<='z';a++){
        if( cpy[a-'a'] != a){
            if( cycle(cpy,a)) return true;
        }
    }
    return false;
}

string ans;

bool already( int pos , string & s)
{
    for(char a = 'a'; a <= 'z'; a++){
        if( adj[a-'a'] != a){
            if( adj[a-'a'] == s[pos]){
                //cout<<ans<<endl;
                ans += a;
                return true;
            }
        }
    }
    return false;
}

bool canWeUse(char a, int pos, string &s)
{
    //cout<<a<<' '<<pos<<' '<<s<<endl;
   // cout<<(int)a<<endl;
    if( adj[a-'a'] == a){
        if( !hasCycleAfterMakingEdge(a,pos,s)){
            adj[a-'a'] = s[pos];
            v[a-'a'] = '$';
            ans += a;
            return true;
       }else return false;
    }else{
        return false;
    }
}

void solve()
{
    int n;cin>>n;
    string s; cin>>s;
    ans.clear();
    iota(all(v),'a');iota(all(adj),'a');
    
    int j = 0;
    while( j < (int)s.size()){
        if( already(j,s)){
            j++;
        }
        for(int i = 0;i<(int)v.size() and j < (int)s.size() ;i++){
            if(v[i] != '$' ){
               // cout<<v[i]<<endl;
               // print(v)
                if( s[j] == v[i]){
                    i++;
                   // break;
                }if( already(j,s)){
                   // cout<<"dfs"<<endl;
                    j++;
                    break;
                }else if( canWeUse(v[i],j,s)){
                    //cout<<(int)v[i]<<endl;
                    v[i] = '$';
                    j++;
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;
   // cout<<(int)ans[24]<<endl;

}

signed main()
{	
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)   
        solve();

    return 0;    
}