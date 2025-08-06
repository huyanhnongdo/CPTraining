#include <bits/stdc++.h>
#include <string>
#define LIMIT int(1e6)+5
using namespace std;

bitset<LIMIT> is_prime;
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
}

bool isDoiXung(string n){
    int length = n.size();
    int mid = length / 2;
    for(int i = 0;i < mid;i++){
        if(n[i] != n[length-i-1]){
            return false;
        }
    }
    return true;
}
void solve(){
    sieve();
    int T;cin >> T;
    while(T--){
        int t = 0;
        int l,r;cin >> l >> r;
        for(int i = l;i<=r;i++){
            if(is_prime[i]){
                if(isDoiXung(to_string(i))){
                    t+=i;
                }
            }
        }
        cout << t << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
