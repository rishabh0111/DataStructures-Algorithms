#include <iostream>
#include <list>
using namespace std;

bool compare_function( string& s1 , string& s2 ) {
  return ( s1.length() > s2.length() );
}

int main() {
    list<int> l1 = {1, 2, 3};
	list<int>::iterator it = l1.begin();
	l1.push_back(11);
	l1.push_back(11);
	l1.insert(++it, 100); //insert 100 before 2 position // -> {1, 100, 2, 3}

	std::list<int> l2 = {10, 20, 30, 40};
	l2.insert(l2.begin(),l1.begin(),l1.end()); //insert elements from beginning of list l1 to end of list l1 before 1st position in list l2. // -> {10, 20, 30, 40, 1, 100, 2, 3}

	l1.insert(l1.begin(),3,10); // insert 10 before beginning 3 times // -> {10, 10, 10, 1, 100, 2, 3}

	l1.push_back(11);
	l1.push_back(12);
	// -> {10, 10, 10, 1, 100, 2, 3, 11, 12}

	l1.push_front(13);
	l1.push_front(14);
	// -> {14, 13, 10, 10, 10, 1, 100, 2, 3, 11, 12}

	l1.pop_back(); //{14, 13, 10, 10, 10, 1, 100, 2, 3, 11}
	l1.pop_front();//{13, 10, 10, 10, 1, 100, 2, 3, 11}

	if(l1.empty())
		cout << "Empty List" << endl;
	else
		cout << "Not Empty" << endl;

	cout << l1.size(); //returns the number of elements present in the list.
	cout << l1.front(); // first element
	cout << l1.back(); // last element

	l1.swap(l2);

	l2.reverse(); // -> {3, 2, 100, 1, 40, 30, 20, 10}

	l2.sort(); // -> {1, 2, 3, 10, 20, 30, 40, 100}
	list<string> l3 = {"h", "hhh", "hh"};
	l3.sort(compare_function); // -> {"h", "hh", "hhh"} //Its very helpful for the elements that are not numeric.

	list<int> list4 = {1,2,3,4};
    list<int> list5 = {5,6,7,8};

	it = list4.begin();
	++it; //pointing to second position

	list4.splice(it, list5); // transfer all elements of list5 at position 2 in list4 // -> list4{1, 5, 6, 7, 8, 2, 3, 4} & list5 is empty

	list5.splice(list5.begin(), list4, it); // transfer element pointed by it in list4 to the beginning of list5 // -> list4{1, 6, 7, 8, 2, 3, 4} & list5 -> {5}

	list<int> list6 = {1, 3, 5, 7, 9};
	list<int> list7 = {2, 4, 6, 8, 10};
	// both the lists are sorted. In case they are not, first they should be sorted by sort function()
	list6.merge(list7);
	// list6 -> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	cout << list6.size() << endl;

	return 0;
}

/*
Since lists are collection of elements, thus they do not have a standard value of their own. Thus in order to compare list or vectors we compare their elements in their lexicographical order.

For example, let list1 = { 1 , 2 , 3} and list2 = { 1 , 3 , 2 }, now if we want to check if the list1 is greater than list2 or not, we just check the element of each list in the order they appear in the lists. Since 1 in list1 is equal to 1 in list2, we proceed further, now 2 in list1 is smaller then 3 in list2, thus list2 is lexicographically greater than list1.

Operators == , > , < , <= , >= can be used to compare lists lexicographically.
*/