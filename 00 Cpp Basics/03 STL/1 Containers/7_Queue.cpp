#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue <int> qu1;
	qu1.push(1);
	qu1.push(2);
	qu1.push(3);

	cout << qu1.front() << endl;
	cout << qu1.back() << endl;

	qu1.pop();
	cout << qu1.front() << endl;
	cout << qu1.back() << endl;

	//size(), empty(), swap() are same
}