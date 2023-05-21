#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

	// max size of 10^7 -> int , double, char
	int arrr1[10000000];
	// max size of 10^8 -> bool
	int arrr2[100000000];

int main() {
	// max size of 10^6 -> int , double, char
	int arrr1[1000000];
	// max size of 10^7 -> bool
	int arrr2[100000000];

	array<int, 4> array1 = { 2, 4, 6, 8 };

	//at function:
		//This method returns value in the array at the given range. If the given range is greater than the array size, out_of_range exception is thrown.
		cout << array1.at(1) << endl; // prints 4 // = array1[1]
		cout << array1.at(3) << endl; // prints 8 // = array1[3]
		//cout << array1[5] << endl; // no error but still incorect
		//cout << array1.at(5) << endl; // throws error
		
	//front() function:
		//This method returns the first element in the array.
		cout << array1.front() << endl;
	//back() function:
		//This method returns the last element in the array. If the array is not completely filled, back() will return the rightmost element in the array.
		cout << array1.back() << endl;

	//fill() function:
		//This method assigns the given value to every element of the array
		array1.fill(1);

	//swap function:
		//This method swaps the content of two arrays of same type and same size.
		array<int,8> a = {1,2,3,4,5,6,7,8};
    array<int,8> b = {8,7,6,5,4,3,2,1};
    
    a.swap(b);  // swaps array a and b
    
    cout << "a is : ";
    for(int i=0; i < 8; i++) {
    cout << a[i] <<" ";
    }
    cout << endl;
    cout << "b is : ";
    for(int i=0; i < 8; i++) {
    cout << b[i] <<" ";
    }
		cout << endl;

	//operators ( == , != , > , < , >= , <= )
		//All these operators can be used to lexicographically compare values of two arrays.
		if(a==b)
		{
			cout<<"Equal"<<endl;
		}
		else
		{
			cout<<"Unequal"<<endl;
		}

	//empty function:
		if(array1.empty())
		{
			cout << "Empty" << endl;
		}
		else
		{
			cout << "Not Empty" << endl;
		}
	
	array<int, 5> array2;
	array2[1] = 10;
	array2[2] = 20;

	//size function:
		cout << array2.size() << endl; //returns total num of indexes
	//max_size function:
		cout << array2.max_size() << endl; //returns total num of indexes
	//sizeof() function:
		cout << sizeof(array2) << endl; // total size of array in bytes
	
	//begin function & endl function:
		//begin method returns the iterator pointing to the first element of the array
		//end method returns an iterator pointing to an element next to the last element in the array
		array<int,5> array3 = {22, 11, 33, 55, 44};
		cout << "Initial array3 : ";
		for (auto i : array3) //for-each loop
			cout << i << ' ';
	
		sort(array3.begin(), array3.end());
	
		cout << "Sorted array3 : ";
		for (auto i : array3)
			cout << i << ' ';
		cout << endl;

return 0;
}

/*
array<int, 3> arr1; // -> {?,?,?}
array<int, 5> arr2 = {1, 5 , 6}; // -> {1, 5 , 6, 0, 0}
array<int, 5> arr3 = {1}; // -> {1, 0 , 0, 0, 0}
array<int, 5> arr4 = {0}; // -> {0, 0 , 0, 0, 0}
*/

// iterators:
/*
	begin() -> points to first element
	rbegin() -> points to last element
	end() -> points to address just after last element
	rend() -> points to address just before first element
*/