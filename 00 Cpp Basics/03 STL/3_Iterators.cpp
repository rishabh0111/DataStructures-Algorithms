#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//Defining Iterators:
		vector<int>::iterator i, z; // create an iterator named i to a vector of integers 
		
		vector<string>::iterator j; // create an iterator named j to a vector of strings 
		
		list<int>::iterator k; // create an iterator named k to a vector of integers 
		
		map<int, int>::iterator l; // create an iterator named l to a map  of integers

	//Traversing container using iterator:
		vector<int> v(5); //creates an vector v : 0,0,0,0,0
		for(i = v.begin(); i != v.end(); i++) // for loop
		{
			cout << *i << " ";
		}
		cout << endl;

		for(auto i : v) // for-each loop
		{
			cout << i << " ";
		}
		cout << endl;

	//advance() operation:
		//It will increment the iterator i by the value of the distance. If the value of distance is negative, then iterator will be decremented.
		i = v.begin();

		advance(i,5); // i now points to the fifth element form the beginning of the vector v

    advance(i,-1);
    // i  now points to the fourth element from the beginning of the vector

	//distance() Operation:
		//It will return the number of elements or we can say distance between two iterators
		i = v.begin();
		z = v.end()-1;

		cout << distance(i, z) << endl;

	//next() Operation:
		//It will return the nth iterator to i, i.e iterator pointing to the nth element from the element pointed by i.
		next(i,3);

	//prev() Operation:
		//It will return the nth predecessor to i, i.e iterator pointing to the nth predecessor element from the element pointed by i.
		prev(z,2);
	
	vector <int> vec = {1, 2, 3, 4, 5};

	//begin() – Returns an iterator pointing to the first element in the vector
	//end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
	cout << "Output of begin and end: ";
	for (auto i = vec.begin(); i != vec.end(); ++i)
		cout << *i << " ";

	//cbegin() – Returns a constant iterator pointing to the first element in the vector.
	//cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
	//const_iterator is used to iterate over elements in a container in a read-only manner.
	cout << "\nOutput of cbegin and cend: ";
	for (auto i = vec.cbegin(); i != vec.cend(); ++i)
			cout << *i << " ";

	//rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
	//rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
	cout << "\nOutput of rbegin and rend: ";
	for (auto ir = vec.rbegin(); ir != vec.rend(); ++ir)
			cout << *ir << " ";

	//crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
	//crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
	cout << "\nOutput of crbegin and crend : ";
	for (auto ir = vec.crbegin(); ir != vec.crend(); ++ir)
			cout << *ir << " ";
	cout << endl << endl;

	return 0;
}