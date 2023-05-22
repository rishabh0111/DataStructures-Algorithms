#include<iostream>
#include<tuple> // for tuple & tie()
using namespace std;

int main()
{
	tuple <char, int, float> tuple1;
	tuple1 = make_tuple('a', 10, 15.5);

	// Printing initial tuple values using get()
	cout << "The initial values of tuple are : ";
	cout << get<0>(tuple1) << " " << get<1>(tuple1) << " " << get<2>(tuple1) << endl;

	// Use of get() to change values of tuple
	get<0>(tuple1) = 'b';
	get<2>(tuple1) = 20.5;

	// Printing modified tuple values
	cout << "The modified values of tuple are : ";
	cout << get<0>(tuple1) << " " << get<1>(tuple1) << " " << get<2>(tuple1) << endl;

	// Use of size to find tuple_size of tuple
    cout << "The size of tuple is : ";
    cout << tuple_size<decltype(tuple1)>::value << endl;

	tuple <int,char,float> tup1(20,'g',17.5);
	tuple <int,char,float> tup2(30,'f',10.5);
		
	// Concatenating 2 tuples to return a new tuple
	auto tup3 = tuple_cat(tup1,tup2);
	// or tuple <int,char,float,int,char,float> tup3 = tuple_cat(tup1,tup2);
		
	// Displaying new tuple elements
	cout << "The new tuple elements in order are : ";
	cout << get<0>(tup3) << " " << get<1>(tup3) << " " << get<2>(tup3) << " " << get<3>(tup3) << " " << get<4>(tup3) << " " << get<5>(tup3) << endl;

	// 2. tie() in tuples:  
    // Initializing tuple
    tuple <int,char,float> tupl1(20,'g',17.5);

		// Initializing variables for unpacking
    int i_val;
    char ch_val;
    float f_val;
  
    // Use of tie() without ignore
    tie(i_val,ch_val,f_val) = tupl1;
      
    // Displaying unpacked tuple elements without ignore
    cout << "The unpacked tuple values (without ignore) are : ";
    cout << i_val << " " << ch_val << " " << f_val << endl;
      
    // Use of tie() with ignore, ignores char value
    tie(i_val,ignore,f_val) = tupl1;
      
    // Displaying unpacked tuple elements with ignore
    cout << "The unpacked tuple values (with ignore) are : ";
    cout << i_val  << " " << f_val << endl;
	return 0;
}