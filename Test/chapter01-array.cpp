#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

void main() {
	double arrayA[] = { 1.2, 3.1, 5.2, 7.5, 1.1 ,2.8}, arrayB[6];
	//�����������arrayA���Կո����
	copy(arrayA, arrayA + 6, ostream_iterator<double>(cout, " "));
	cout << endl;
	
	//�����������arrayA���Կո����
	reverse_copy(arrayA, arrayA + 6, ostream_iterator<double>(cout, " "));
	cout << endl;

	//�������鵽arrayB
	copy(arrayA,arrayA+6,arrayB);
	
	//�����������arrayB���Կո����
	copy(arrayB, arrayB + 6, ostream_iterator<double>(cout, " "));
	cout << endl;

	//������arrayA������������
	sort(arrayA,arrayA+6);

	//�������arrayA
	copy(arrayA, arrayA + 6, ostream_iterator<double>(cout, " "));
	cout << endl;

	//��arrayA�����������Ƹ�����arrayB
	reverse_copy(arrayA, arrayA + 6, arrayB);

	//���arrayB
	copy(arrayB, arrayB + 6, ostream_iterator<double>(cout, " "));
	cout << endl;
}