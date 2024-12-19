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

        bool neg = row[0] - row[1] < 0;
        bool is_safe = 1;
        cout << neg<< endl;
        for (int i=0; i<row.size()-1; i++) {
        	if (row[i] - row[i+1] == 0 
        		|| abs(row[i] - row[i+1]) > 3
        		|| (neg && (row[i] - row[i+1] > 0))
        		|| (!neg && (row[i] - row[i+1] < 0))
        	) {
        		is_safe = 0;
        		break;
        	}
        }
        res += is_safe;
    }

   

    fout << res << "\n";



    return 0;
}
