#include "template.h"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("130.in");
    ofstream fout ("out.txt");
    
    string s;
    
    int res = 0;
    while (true) {
        int ax, ay, bx, by, x, y;

        fin >> ax >> ay;
        if (ax == -1) {
            fout << res << "\n";
            return 0;
        }
        fin >> bx >> by;
        fin >> x >> y;

        int cheapest = 1000;
        for (int i=0; i<101; i++) {
            for (int j=0; j<101; j++) {
                if (i*ax + j*bx == x && i*ay + j*by == y) {
                    smin(cheapest, 3*i + j);
                }
            }
        }


        if (cheapest != 1000)
            res += cheapest;
    }


    return 0;
}
