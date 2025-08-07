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
// 2 3 5 7
void solve(){
    sieve();
    int T;cin >> T;
    while(T--){
        int A,B;
        cin >> A >> B;
        int z = A+B;
        auto it = lower_bound(primes.begin(),primes.end(),z);
        int index = it - primes.begin();
        if(is_prime[z]){
            cout << primes[index+1] - z << '\n';
        } else {
            cout << primes[index] - z << '\n';
        }
    }
}

int main() {
    freopen("FINDNUM.INP","r",stdin);
    freopen("FINDNUM.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
