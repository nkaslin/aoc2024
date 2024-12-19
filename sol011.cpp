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

    
    multiset<int> ms;
    for (int i=0; i<v1.size(); i++) {
    	ms.insert(v2[i]);
    }

    ll res = 0;
    for (int i=0; i<v1.size(); i++) {
    	res += v1[i] * ms.count(v1[i]);
    }

    fout << res << "\n";



    return 0;
}
