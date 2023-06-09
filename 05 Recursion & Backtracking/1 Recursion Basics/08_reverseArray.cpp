#include <iostream>
using namespace std;

//two pointer approach
void reverse1(int a[], int l, int r) {
    if (l >= r) return;
    swap(a[l],a[r]);
    reverse1(a, l+1, r-1);
}

//one pointer approach
void reverse2(int a[], int i, int n) {
    if(i >= n/2) return;
    swap(a[i], a[n-i-1]);
    reverse2(a, i+1, n);
}

void print(int a[], int n){
    for(int i=0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {1,2,3,4,5,6};
    reverse1(arr1, 0, 5);
    print(arr1, 6);

    int arr2[] = {11, 44, 22, 77};
    reverse2(arr2, 0, 4);
    print(arr2, 4);
    
    return 0;
}