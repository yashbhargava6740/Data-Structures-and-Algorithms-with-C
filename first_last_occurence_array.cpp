#include <iostream>
using namespace std;

int firstOccurence(int *arr, int i, int n, int ele) {
    if(i == n)
        return -1;
    else if(arr[i] == ele)
        return i;
    else
        return firstOccurence(arr, i+1, n, ele);
}

int lastOccurence(int *arr, int n, int ele) {
    if(n == -1)
        return n;
    else if(arr[n] == ele) 
        return n;
    return lastOccurence(arr,n-1, ele);
}

int main() {
    int ele, n, first, last;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
        cin >> arr[i];
    cin >> ele;
    first = firstOccurence(arr, 0, n, ele);
    last = lastOccurence(arr, n-1, ele);
    cout << first << " " << last << endl;
    return 0;
}