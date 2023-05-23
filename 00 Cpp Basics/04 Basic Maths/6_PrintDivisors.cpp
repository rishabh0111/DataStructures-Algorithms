#include <iostream>
#include <math.h>
#include <set>
using namespace std;


void printDivisorsBruteForce(int n){
	cout << "The Divisors of "<< n << " are:" << endl;
	for(int i = 1; i <= n; i++)
		if(n % i == 0)
			cout << i << " ";
	cout << endl;
}
//Time Complexity: O(N)

void printDivisors(int n) {
    set<int> s;
    // for(int i = 1; i <= sqrt(n); i++){
    for(int i = 1; i*i <= n; i++){ // Efficient way of writing sqaure root, as no function call occures
		if(n % i == 0) {
			s.insert(i);
            if (n/i != i)
                s.insert(n/i);
        }
    }
    for(auto it: s)
        cout << it << " ";
    cout << endl;
}
//Time Complexity: O(sqrt(N))
	
int main(){
    int n;
    cin >> n;
	printDivisorsBruteForce(n);
	printDivisors(n);
    return 0;
}