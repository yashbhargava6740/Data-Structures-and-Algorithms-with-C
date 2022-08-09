#include <iostream>
using namespace std;

void permutate(string st, string ans) {
    if(st.length() == 0) {
        cout << ans << endl;
        return;
    }
    for(int i = 0; i < st.length(); i++) {
        char ch = st[i];
        string ros = st.substr(0,i) + st.substr(i+1);
        permutate(ros, ans+ch);
    }
}
int main() {
    int n;
    string st;
    cin >> n >> st;
    permutate(st,"");
}