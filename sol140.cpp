#include "template.h"

int N = 101; // 101 11
int M = 103; // 103 7

int steps = 100;

void vvprint(vvi& grid) {
    for (int i=0; i<grid.size(); i++) {
        vprint(grid[i]);
    }
    cout << "\n";
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("140.in");
    ofstream fout ("out.txt");
    
    string s;
    vi px, py, vx, vy;


    while (getline(fin, s)) {
        int pxVal, pyVal, vxVal, vyVal;

        istringstream lineStream(s);
        lineStream >> pxVal >> pyVal >> vxVal >> vyVal;

        px.pb(pxVal);
        py.pb(pyVal);
        vx.pb((vxVal + N) % N);
        vy.pb((vyVal + M) % M);
    }

    vvi grid(M, vi(N, 0));

    for (int i=0; i<px.size(); i++) {
        grid[(py[i]+(steps * vy[i])) % M][(px[i]+(steps * vx[i])) % N]++;
    }

    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    // vvprint(grid);

    for (int x=0; x<N/2; x++) {
        for (int y=0; y<M/2; y++) {
            // cout << x << " "<<y<<endl;
            q1 += grid[y][x];
            q2 += grid[y][N-x-1];
            q3 += grid[M-y-1][x];
            q4 += grid[M-y-1][N-x-1];
        }
    }

    cout << q1 << " "<< q2 << " "<< q3 << " "<< q4 << endl;

    ll res = q1 * q2 * q3 * q4;
    fout << res << "\n";

    return 0;
}
