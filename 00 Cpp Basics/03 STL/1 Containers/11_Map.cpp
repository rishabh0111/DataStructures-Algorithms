#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

/*
The map <int, int> M is the implementation of self-balancing Red-Black Trees.
The unordered_map<int, int> M is the implementation of Hash Table.
The multimap<int, int> M is the implementation of Red-Black Trees.
*/

int main() {
	map<string, int> mpp;
	//Key Value
	mpp["raj"] = 27;
	mpp["hima"] = 33;
	mpp["sandeep"] = 33;
	mpp["tank"] = 89;
	mpp["raj"] = 29; //overwrites previous value
	mpp.emplace("raj", 45);

	cout << mpp.at("hima") << endl;
	cout << mpp.at("tank") << endl;
	cout << mpp["sandeep"] << endl;

	cout << "Map key-values are:" << endl;
	for(auto it: mpp){
		cout << it.first << " " << it.second << endl;
	}

	//empty() is same
	//size() returns number of entries in map, an entry consist of a key and a value.
	//maz_size() returns max possible entries

	mpp.insert(pair<string,int> ("rish", 7)); // inserts new entry
	mpp.insert(make_pair("Anjli",43)); // inserts new entry
	map<string,int>::iterator i,j;
	i = mpp.find("hima");
	j = mpp.find("tank");

	map<string,int> new_mp;
	new_mp.insert(i,j); //insert all the entries which are pointed by iterator i to iterator j
	
	mpp.insert(make_pair("Anjli",24)); // do not insert the pair as map mpp already contain key = "Anjli"
	// mpp.insert_or_assign(make_pair("Anjli",24)); // else do this //assign value = 24 to key "Anjli"

	mpp.erase("raj");
	mpp.erase(mpp.begin());
	mpp.erase(mpp.begin(), mpp.end());
	mpp.clear();
	auto it = mpp.find("raj");

    multimap<int, int> mump; // duplicate keys in sorted order
	unordered_map<int, int> umpp; // unique keys in unsorted order
	//O(1) in almost all cases
	//O(n) in the worst case, where n is the container size

	return 0;
}

/*
Function              | Time Complexity | Space Complexity
---------------------------------------------------------
M.find(x)             | O(log n)        | O(1)
M.insert(pair<int, int> (x, y) | O(log n) | O(1)
M.erase(x)            | O(log n)        | O(1)
M.empty( )            | O(1)            | O(1)
M.clear( )            | Theta(n)        | O(1)
M.size( )             | O(1)            | O(1)
*/