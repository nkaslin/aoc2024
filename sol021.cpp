#include "template.h"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    int res = 0;

    string line;
    while (getline(fin, line)) {
        stringstream ss(line);
        vi row;

        int x;
        while (ss >> x) {
            row.push_back(x);
        }

        int n = row.size();
        for (int rem=0; rem<n; rem++) {
            vi new_row;
            for (int i=0; i<n; i++) {
                if (i == rem)
                    continue;
                new_row.pb(row[i]);
            }
            bool neg = new_row[0] - new_row[1] < 0;
            bool is_safe = 1;
            int tol = 2;
            for (int i=0; i<new_row.size()-1; i++) {
                if (new_row[i] - new_row[i+1] == 0 
                    || abs(new_row[i] - new_row[i+1]) > 3
                    || (neg && (new_row[i] - new_row[i+1] > 0))
                    || (!neg && (new_row[i] - new_row[i+1] < 0))
                ) {
                is_safe = 0;
                break;
            }
            }
            if (is_safe) {
                res++;
                break;
            }
        }
    }

   

    fout << res << "\n";



    return 0;
}
