#include "template.h"

int get_n_digits(ll x) {
    int res = 0;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ofstream fout ("out.txt");
    
    string s;
    // vll stones = {125, 17};
    vll stones = {77, 515, 6779622, 6, 91370, 959685, 0, 9861};

    cout << pow(10,0)<<endl;
    for (int i=0; i<5; i++) {
        vll next_stones;
        for (ll& s: stones) {
            int n_digits = get_n_digits(s);
            if (s == 0) {
                next_stones.pb(1);
            } else if (n_digits % 2 == 0) {
                int p = pow(10, n_digits / 2);
                // cout<<p<<" "<<n_digits<<endl;
                next_stones.pb(s / p);
                next_stones.pb(s % p);
            } else {
                next_stones.pb(s * 2024);
            }
        }
        stones = next_stones;
        next_stones.clear();
        cout << i << " " << stones.size() << endl;
        // vprint(stones);
    }

    fout << stones.size() << "\n";

    return 0;
}
