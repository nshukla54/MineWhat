#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

void print(vector<string>keys, vector<string>values) {
cout << "{";
for ( int i = 0; i < keys.size(); i++ ) {
    if ( i < values.size() ) {
    if ( i != keys.size()-1 )
    cout  << "\"" << keys[i] << "\"" << ": " <<  '"' << values[i] << '"' << ",";
    else {
        cout  << "\"" << keys[i] << "\"" << ": " <<  '"' << values[i] << '"';
    }

    } else {
        if ( i != keys.size()-1 )
        cout  << "\"" << keys[i] << "\"" << ": " <<  '"' << " " << '"' << ",";
        else {
        cout  << "\"" << keys[i] << "\"" << ": " <<  '"' << " " << '"';
        }
    }
}
cout << "}";
}

int main()
{
string keyList;
fstream fin("input.txt");
getline(fin,keyList);
while ( keyList == " " || keyList == "\n" || keyList == "\t" ) {
    getline(fin,keyList);
}

vector<string> keys;

string key = "";
int i;
for ( i = 0; i < keyList.size(); i++ ) {
    if ( isalpha(keyList[i])) {
    key += keyList[i];
    } else {
        if ( keyList[i] == ',' ) {
            keys.push_back(key);
            key = "";
        }
    }
}
if ( i == keyList.size()) {
    keys.push_back(key);
}
string keyValue;
cout << "[";
while ( getline(fin,keyValue) ) {
while (  keyValue == " " || keyValue == "\n" || keyValue == "\t" ) {
    getline(fin,keyValue);
}

string value = "";
vector<string>values;
for ( i = 0; i < keyValue.size(); i++ ) {
    if ( isalpha(keyValue[i]) || (keyValue[i] >= '0' && keyValue[i] <= '9')  ) {
        value += keyValue[i];
    } else {
        if ( keyValue[i] == ',' ) {
            values.push_back(value);
            value = "";
        }
    }
}
if ( i == keyValue.size()) {
    values.push_back(value);
}
print(keys,values);
cout << ",";
}
cout << "]\n";
return 0;
}
