#include "template.h"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    vi v1, v2;
    int a, b;

    while (fin >> a >> b) {
    	v1.pb(a);
    	v2.pb(b);
    }

    sort(all(v1));
    sort(all(v2));

    ll res = 0;
    for (int i=0; i<v1.size(); i++) {
    	res += abs(v1[i] - v2[i]);
    } 

    fout << res << "\n";

    return 0;
}
