#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>

using namespace std;

void main() {
	string str1 = "hello world!", str2 = str1;
	reverse(&str1[0],&str1[0]+12);

	cout << str1 << endl;


	copy(&str1[0],&str1[0],&str2[0]);
	cout << str2 << endl;

	reverse_copy(&str2[0],&str2[0]+12,ostream_iterator<char>(cout));
}