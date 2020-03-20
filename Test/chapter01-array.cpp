#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

void main() {
	double arrayA[] = { 1.2, 3.1, 5.2, 7.5, 1.1 ,2.8}, arrayB[6];
	//正向输出数组arrayA，以空格隔开
	copy(arrayA, arrayA + 6, ostream_iterator<double>(cout, " "));
	cout << endl;
	
	//逆向输出数组arrayA，以空格隔开
	reverse_copy(arrayA, arrayA + 6, ostream_iterator<double>(cout, " "));
	cout << endl;

	//复制数组到arrayB
	copy(arrayA,arrayA+6,arrayB);
	
	//正向输出数组arrayB，以空格隔开
	copy(arrayB, arrayB + 6, ostream_iterator<double>(cout, " "));
	cout << endl;

	//对数组arrayA进行升幂排序
	sort(arrayA,arrayA+6);

	//输出数组arrayA
	copy(arrayA, arrayA + 6, ostream_iterator<double>(cout, " "));
	cout << endl;

	//将arrayA的内容逆向复制给数组arrayB
	reverse_copy(arrayA, arrayA + 6, arrayB);

	//输出arrayB
	copy(arrayB, arrayB + 6, ostream_iterator<double>(cout, " "));
	cout << endl;
}