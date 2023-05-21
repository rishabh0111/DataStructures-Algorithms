#include <iostream>
#include <vector>
using namespace std;

int main() {
	//1. Declaring & Installizing Vectors:
		vector <int> vec1 {1, 2, 3, 4, 5};
		vector <int> vec2 (vec1.begin(),vec1.end()); // -> [1, 2, 3, 4, 5] //Copies elements of vec1 from start to end
		vector <string> vec3 (4,"Hello"); // -> ["Hello", "Hello", "Hello", "Hello"] //Repeating single element

	//2. Element access:
	cout << "Reference operator [g] : vec1[2] = " << vec1[2];  
    cout << "\nat : vec1.at(4) = " << vec1.at(4);
    cout << "\nfront() : vec1.front() = " << vec1.front();
    cout << "\nback() : vec1.back() = " << vec1.back() << endl;
  
    // pointer to the first element
    int* pos = vec1.data();
    cout << "The vector elements are: ";
    for (auto i = vec1.cbegin(); i != vec1.cend(); ++i)
        cout << *pos++ << " ";
		cout << endl << endl;

	//3. Modifiers:
		vector <int> vec5;
		vec5.push_back(11); // inserts value to last position
		vec5.push_back(22);
		vec5.push_back(33);
		for(vector<int>::iterator i = vec5.begin(); i != vec5.end(); i++)
				cout << *i <<" ";   // for printing the vector
		cout << endl;

		vec5.insert(vec5.begin(),44); // inserts new elements before the element at the specified position
		for(vector<int>::iterator i = vec5.begin(); i != vec5.end(); i++)
				cout << *i <<" ";   // for printing the vector
		cout << endl;

		vec5.insert(vec5.begin(),3,77); // here 3 is count, no. of repetitions
		for(vector<int>::iterator i = vec5.begin(); i != vec5.end(); i++)
				cout << *i <<" ";   // for printing the vector
		cout << endl;

		vec5.pop_back(); // removes last element
		for(vector<int>::iterator i = vec5.begin(); i != vec5.end(); i++)
				cout << *i <<" ";   // for printing the vector
		cout << endl;

		vec5.erase(vec5.begin()); //erases first element
		vec5.erase(vec5.begin(),vec5.end() - 2);
		for(vector<int>::iterator i = vec5.begin(); i != vec5.end(); i++)
				cout << *i <<" ";   // for printing the vector
		cout << endl;

		//assigns new value to the vector elements by replacing old ones
		vec5.assign(5, 10); // fill the array with 10 five times
		for(vector<int>::iterator i = vec5.begin(); i != vec5.end(); i++)
				cout << *i <<" ";   // for printing the vector
		cout << endl;

		vec1.swap(vec5);// Sizes may differ
        vec1.emplace(vec1.begin(), 5); // inserts at the beginning
        cout << "The first element is: " << vec1[0] << endl;
    
        vec1.emplace_back(20); // Inserts 20 at the end // faster than push_back
        int n = vec1.size();
        cout << "The last element is: " << vec1[n - 1] << endl << endl;

		vec1.clear(); // remove all the elements of the vector container
		
	//Capacity:
		cout << "Size : " << vec5.size() << endl; // Returns the number of elements in the vector.
		cout << "Capacity : " << vec5.capacity() << endl; // Returns the size of the storage space currently allocated to the vector expressed as number of elements.
		cout << "Max_Size : " << vec5.max_size() << endl; // Returns the maximum number of elements that the vector can hold.

		// resizes the vector size to 4
		vec5.resize(4);
		// prints the vector size after resize()
		cout << "Size : " << vec5.size() << endl;

		if (vec5.empty() == false)
        cout << "Vector is not empty" << endl;
        else
        cout << "Vector is empty" << endl;

		vec5.shrink_to_fit(); // Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
		for (auto i = vec5.cbegin(); i != vec5.cend(); ++i)
        cout << *i << " ";
		cout << endl;

		//reserve() – Requests that the vector capacity be at least enough to contain n elements.
		

		return 0;
}