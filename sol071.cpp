#include "template.h"

vll rec(int i, vll& values) {
    if (i == values.size() - 1)
        return {values.back()};

    vll res;
    for (ll& x: rec(i+1, values)) {
        ll fact = 1;
        ll tmp = values[i];
        while (tmp) {
            fact *= 10;
            tmp /= 10;
        }
        res.pb(values[i] + x);
        res.pb(values[i] * x);
        res.pb(values[i] + x * fact);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    string line;
    
    
    ll res = 0;

    while (getline(fin, line)) {

        ll target, val;
        char delim;
        vll values;

        stringstream ss(line);
        ss >> target >> delim;

        // cout<<target<<endl;

        while (ss >> val) { 
            values.pb(val);
        }
        reverse(all(values));

        for (ll& x: rec(0, values)) {
            // cout<<"    "<<x<<endl;
            if (x == target) {
                res += x;
                break;
            }
        }


    }

    fout << res << endl;

    return 0;
}
