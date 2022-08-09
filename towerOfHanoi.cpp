#include <iostream>
using namespace std;

void towerOfHanoi(int n, string src, string helper, string dest) {
    if(n == 1) {
        cout << "Moving " << n << " disk " << "from " << src << " to " << dest << endl;
        return;
    }
    towerOfHanoi(n-1, src, dest, helper);
    cout << "Moving " << n << " disk " << "from " << src << " to " << dest << endl;
    towerOfHanoi(n-1, helper, src, dest);
}
 
int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, "A", "B", "C");
}