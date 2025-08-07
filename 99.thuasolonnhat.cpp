#include <bits/stdc++.h>
#define LIMIT int(1e6)+5
using namespace std;

bitset<LIMIT> is_prime;
vector<int> primes;
void sieve(){
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2;i * i < LIMIT;i++){
        if(is_prime[i]){
            for(int j = i * i; j < LIMIT; j+= i){
                is_prime[j] = 0;
            }
        }
    }
    for(int i = 2;i <= LIMIT;i++){
        if(is_prime[i])
            primes.push_back(i);
    }
}

void pt(int n){
    int i = 2;
    int s,m = 0;
    while(n>1){
        while(n%i==0){
            s=i;
            m+=1;
            n/=i;
        }
        i++;m=0;
    } cout << s << '\n';
}

// 2 3 5 7
void solve(){
    int T;cin >> T;
    while(T--){
        int n;
        cin >> n;
        pt(n);
    }
}

int main() {
    freopen("LARGESTFACTOR.INP","r",stdin);
    freopen("LARGESTFACTOR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
