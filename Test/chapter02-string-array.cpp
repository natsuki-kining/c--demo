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


	cout << endl << "========================================================" << endl;

	string str[] = {"hello world","hello c++","hello cpp"};

	for (int i = 0; i < 3; i++)
	{
		copy(str[i].begin(),str[i].end(),ostream_iterator<char>(cout));
		cout << endl;
	}
	cout << endl << "========================================================" << endl;
	str[0].swap(str[2]);
	str[0].swap(str[1]);
	for (int i = 0; i < 3; i++)
		cout << str[i] << endl;


	cout << endl << "========================================================" << endl;

	str1 = "hello world!", str2 = str1;

	reverse(str1.begin(),str1.end());//�ַ���Ԫ������

	cout << str1 << endl;

	copy(str1.begin(), str1.end(),str2.begin());//ԭ�����Ƶ�str2,str2Ӧ��������

	sort(str1.begin(), str1.end());//Ĭ������

	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;

	reverse_copy(str1.begin(), str1.end(), str2.begin());//�����Ƶ�str2
	cout << "reverse_copy str1 to str2:" << str2 << endl;

	reverse(str2.begin()+2, str2.begin()+6);//�ַ���2����Ԫ������

	copy(str2.begin() + 2, str2.begin() + 6, ostream_iterator<char>(cout));//��������Ĳ�������

	cout << endl;

	sort(str1.begin(), str1.end(),greater<char>());//����
	cout << str1 << endl << endl << endl;

	str1.swap(str2);

	cout << "str1.swap(str2)" << endl << "str1:" << str1 << endl << "str2:" + str2 << endl << endl;

	cout << (*find(str1.begin(), str1.end(), 'o') == 'o') << " "
		<< (*find(str1.begin(), str1.end(), 'r') == 'r') << " " << endl;
}