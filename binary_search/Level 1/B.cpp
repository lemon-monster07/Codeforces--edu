#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
const char newl='\n';
#define ll long long
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define debug(x) cout << (#x) << "'s value is " << (x) << newl
typedef long long int lld;
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name+".in").c_str(), "r", stdin); // see /general/io
        freopen((name+".out").c_str(), "w", stdout);
    }
}
bool isPrime(int x) {
    if(x<2){
        return false;
    }
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}
typedef unsigned long long int ulli;

vector<ulli> sieve(ulli n)
{
    vector<bool> prime(n+1,true);

    prime[0] = false;
    prime[1] = false;
    int m = sqrt(n);
    for (ulli p=2; p<=m; p++)
    {
        if (prime[p])
        {
            for (ulli i=p*2; i<=n; i += p)
            prime[i] = false;
        }
    }
    vector<ulli> ans;
    for (int i=0;i<n;i++)
        if (prime[i])
            ans.push_back(i);
    return ans;
}
bool isZero(ulli i)
{
    return i == 0;
}

vector<ulli> sieveRange(ulli start,ulli end)
{
    vector<ulli> s1 = sieve(start);
    vector<ulli> s2 = sieve(end);

    vector<ulli> ans(end-start);
    set_difference(s2.begin(), s2.end(), s1.begin(),
                             s2.end(), ans.begin());
    vector<ulli>::iterator itr =
                    remove_if(ans.begin(),ans.end(),isZero);
    ans.resize(itr-ans.begin());

    return ans;
}
int findpos(int arr[],int a,int n){
    for(int i = 0;i<n;i++){
        if(arr[i]==a){
            return i;
        }
    }
    return -1;
}
void arrxqc(int arr[], int le){
    for(int my_var = 0;my_var<le;my_var++){
        cout<<arr[my_var]<<" ";
    }
    cout<<newl;
}
// Main code starts here
int more(int a,int b,int c,int curr,int pieces){
    if(curr==0){
        return 1;
    }
    if(curr<0){
        ;
    }
    else{
        pieces = pieces+max(more(a,b,c,curr-a,pieces),max(more(a,b,c,curr-b,pieces),more(a,b,c,curr-c,pieces)));
    }
    return pieces;
}
const int N = 4e3 + 10;
void answer(int test){
   int n,k;
   cin>>n>>k;
   int arr[n];
   for(int i = 0;i<n;i++){
       cin>>arr[i];
   }
   for(int j = 0;j<k;j++){
       int query;
       cin>>query;
       int l = -1;
       int r = n;
       while(r>l+1){
           int m = (l+r)/2;
           if(arr[m]<=query){
               l = m;
           }
           else{
               r = m;
           }
       }
       cout<<l+1<<newl;
   }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    //cin>>test;
    int curr = 1;
    while(test--){
        answer(curr);
        curr++;
    }
}
        









