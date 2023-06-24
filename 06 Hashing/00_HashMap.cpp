#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // key of type string & value of type double
    unordered_map<string, double> umap = {
        // Inserting element directly
        {"One", 1},
        {"Two", 2},
        {"Three", 3}
    };

    // inserting values by using [] operator
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;

    // inserting value by insert function
    umap.insert(make_pair("e",2.718));

    // accessing through keys
    // intializes new key with default value of 0
    cout << umap["unknownKey"] << endl;
    // throws error if called for absent key
    cout << umap.at("unknownKey") << endl;

    // searching for key
    string key = "PI";

    // If key not found in map iterator 
    // to end is returned
    if(umap.find(key) == umap.end())
        cout << key << " not found" << endl;
    else
        cout << "Found " << key << endl;
    
    key = "lambda";
    if(umap.find(key) == umap.end())
        cout << key << " not found" << endl;
    else
        cout << "Found " << key << endl;

    // count function can also be used for searching
    if(umap.count(key))
        cout << "Found " << key << endl;
    else
        cout << key << " not found" << endl;

    // key deletion
    umap.erase("log10");
    cout << umap.size() << endl;

    // iterating over all the values of umap
    unordered_map<string, double>::iterator itr;
    cout << "All elements :" << endl;
    for(itr = umap.begin(); itr != umap.end(); itr++)
        cout << itr->first << " " << itr->second << endl;
    
    return 0;
}

/*
For Unordered_map: Time Complexity: O(1) for map operations -> implemented using unbalanced tree
For Map : Time Complexity: O(log N) for map operations -> implemented using balanceed tree
*/