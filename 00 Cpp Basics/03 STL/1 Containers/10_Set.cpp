#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

/*
Set (set<int> s) is the implementation of Binary Search Trees.
Unordered set (unordered_set<int> S) is the implementation of Hash Table.
Multiset (multiset<int> S) is implementation of Red-Black trees.
*/

int main() {
    //begin(), end(), rbegin(), rend(), crbegin, crend(), cbegin(), cend() are same as in all containers.
	//size(), max_size(), empty() also same

	set<int> s1;
	s1.insert(40); // used to add element element in set
	s1.insert(30);
	s1.insert(60);
	s1.insert(20);
	s1.insert(50);
	s1.insert(50); // only one 50 will be added to the set

	set<int>::iterator itr;

	cout << "The set s1 is : ";
	for (itr = s1.begin(); itr!=s1.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	set<int> s2;
	//Function to insert one set to another all elements from where 40 is to end is inserted to set2
	s2.insert(s1.find(40), s1.end()); // here find() returns an iterator to the element'40' in the set if found, else returns the iterator to end
	cout << "The set s2 is: ";
    for (auto it = s2.begin(); it != s2.end(); it++)
      cout << *it << " ";
	cout << endl;

	// assigning the elements from s1 to s3
	set<int> s3(s1.begin(), s1.end());

	s3.erase(50); // remove element with value 50 in s3
	cout << "s3.erase(50) " << " removed" << endl;
	s3.erase(s3.begin());
	cout << "s3.erase(s3.begin()) " << " removed" << endl;
	cout << "The set s3 is: ";
	s3.erase(s3.begin(),s3.end());
	for (itr = s3.begin(); itr!=s3.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	cout << "*s1.lower_bound(40) : " << *s1.lower_bound(40) << endl; //Returns an iterator to the first element that is equivalent to ‘40’ or definitely will not go before the element ‘40’ in the set.
	cout << "*s1.upper_bound(40) : " << *s1.upper_bound(40) << endl; //Returns an iterator to the first element that will go after the element ‘g’ in the set.

	s2.clear(); //clears all elements
	cout << s1.count(20) << endl; // Returns 1 or 0 based on the element ‘20’ is present in the set or not.

	s2.emplace(2);
	s2.emplace(6);
	s2.emplace(8);
	s2.emplace(9);
	cout << "The set s2 is: ";
	for (auto it = s2.begin(); it != s2.end(); it++)
		cout << *it << " ";
	cout << endl;

	//emplace() vs insert:
	//When we use insert, we create an object and then insert it into the multiset. With emplace(), the object is constructed in-place.

	unordered_set<int> ust;
	//average time complextity is O(1) but worst case is linear in nature, O(set_size)
	ust.insert(3);
	ust.insert(3);
	ust.insert(1);
	ust.insert(1);
	ust.insert(2);
	ust.insert(4);
	// -> {3, 1, 2, 4}


	multiset <int> ms; // sorted but not unique

	ms.insert(3);
	ms.insert(3);
	ms.insert(1);
	ms.insert(2);
	ms.insert(2);
	// ms -> {1, 2, 2, 3, 3}

	ms.erase(2); // all the instances will be erased

	auto it = ms.find(2);// returns an iterator pointing to first instance of 2

	cout << ms.count(3) << endl;
	return 0;
}

/*
Function   | Time Complexity | Space Complexity
-----------------------------------------------
s.find( )  | O(log n)        | O(1)
s.insert(x) | O(log n)        | O(1)
s.erase(x)  | O(log n)        | O(1)
s.size()   | O(1)            | O(1)
s.empty( ) | O(1)            | O(1)

*/