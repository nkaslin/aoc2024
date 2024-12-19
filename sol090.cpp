#include "template.h"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    string s;
    fin >> s;

    // cout<<('1'-'0') + 3<<endl;

    int n = s.length();
    int top = n - (int) (n % 2 == 0) - 1;
    int highest = (n + 3) / 2;
    int bottom = 0;
    int mult = 0;
    int left = 0;
    int res = 0;

    for (int i=0; i<n; i++) {
        int cur = (int) (s[i] - '0');
        if (i % 2 == 0) {
            while (cur--) {
                res += mult * bottom;
                mult++;
            }
            bottom++;
        } else {
            cout<<i<<" "<<highest<<endl;
            while (cur--) {
                cout<<left<<endl;
                if (left == 0) {
                    left = (int) (s[top] - '0');
                    // cout<<s[top]<<endl;
                    top -= 2;
                    highest--;
                }
                res += mult * highest;
                left--;
                mult++;
                // cout<<left<<endl;
            }
        }
        if (i > top)
            break;
    }




    

    fout << res << endl;

    return 0;
}
