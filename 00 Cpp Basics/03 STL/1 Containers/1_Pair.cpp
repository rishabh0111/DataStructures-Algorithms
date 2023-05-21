#include <iostream>
#include <utility> // contains definition of pair
#include <tuple> //for tie()
using namespace std;

int main ()
{
	pair<int,string> pair1, pair2; // creates pair of an integer and a string

	pair1 = make_pair(1, "Hello");  // insert 1 and "Hello" to pair1
	pair2 = make_pair(2, "World"); // insert 2 and "World" in pair2

	cout<< pair1.first << " "; // prints 1, 1 being 1st element of pair1
	cout<< pair1.second << endl; // prints Hello

	if(pair1 == pair2)
		cout<< "Pairs are equal" << endl;
	else
		cout<< "Pairs are not equal" << endl;

// Different ways to initialize pair:	
	pair g1(1, 'a');  //1. initialized, different data type
	pair g2(g1); //2. copy of g1
	cout << g2.first << " " << g2.second << endl;
	g1 = {2, 'b'}; //3.
	cout << g1.first << " " << g1.second << endl << endl;

// tie() in pairs:
	pair<int, int> par1 = { 1, 2 };
    int a, b;
    tie(a, b) = par1;
    cout << a << " " << b << endl;
 
    pair<int, int> par2 = { 3, 4 };
    tie(a, ignore) = par2;
    cout << a << " " << b << endl; // prints old value of b
 
    // Illustrating pair of pairs
    pair<int, pair<int, char> > par3 = { 3, { 4, 'a' } };
    int x, y;
    char z;
     
    // tie(x,y,z) = pair3; Gives compilation error
    // tie(x, tie(y,z)) = pair3; Gives compilation error
    // Each pair needs to be explicitly handled
    x = par3.first;
    tie(y, z) = par3.second;
    cout << x << " " << y << " " << z << endl;

	par1.swap(par2);
	return 0;
}

/*
Here are some function for pair template :
	1. Operator = : assign values to a pair.
	2. swap : swaps the contents of the pair.
	3. make_pair() : create and returns a pair having objects defined by parameter list.
	4. Operators( == , != , > , < , <= , >= ) : lexicographically compares two pairs.
*/