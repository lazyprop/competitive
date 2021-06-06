#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define sc second
 
const int INF = INT_MAX;
const int maxn = pow(10,5)+10;
pair<int,int> seg[4*maxn] = {};
int ele[maxn] = {};
int n,m;
 
pair<int,int> combine(pair<int,int> a, pair<int,int> b){
    if(a.fr < b.fr) return a;
    if(a.fr > b.fr) return b;
    
    return {a.fr,a.sc+b.sc};
}
 
void make_seg(int k , int tl , int tr){
 
    if(tl == tr){
        seg[k].fr = ele[tl];
        seg[k].sc = 1;
        return;
    }
 
    int tm = (tl+tr)/2;
    make_seg(2*k,tl,tm);
    make_seg(2*k+1,tm+1,tr);
 
    seg[k] = combine(seg[2*k],seg[2*k+1]);
}
 
void update(int k , int tl , int tr , int pos , int new_val){
 
    if(tl == tr){
        seg[k].fr = new_val;
        seg[k].sc = 1;
        return;
    }
 
    int tm = (tl+tr)/2;
    if(pos <= tm) update(2*k, tl, tm, pos, new_val);
    else update(2*k+1, tm+1, tr, pos, new_val);
 
    seg[k] = combine(seg[2*k],seg[2*k+1]);
}
 
pair<int,int> get_min(int k, int tl , int tr , int l, int r){
 
    if(l > r) return {INF,1};
    
    if(l == tl and r == tr){
        return seg[k];
    }
 
    int tm = (tl+tr)/2;
 
    auto a = get_min(2*k, tl, tm, l, min(r,tm));
    auto b = get_min(2*k+1, tm+1, tr, max(l,tm+1), r);
    return combine(a,b);
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
 
    cin>>n>>m;
 
    for(int i = 1; i <= n; i++) cin>>ele[i];
 
    make_seg(1,1,n);
 
    while(m--){
 
        int type,l,r; cin>>type>>l>>r;
 
        if(type == 1){
            update(1,1,n,l+1,r);
        }
        else{
            auto ans = get_min(1,1,n,l+1,r);
            cout<<ans.fr<<" "<<ans.sc<<"\n";
        }
    }
}
