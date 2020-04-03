#include <iostream>
#include <string>

using namespace std;

void swap1(string, string);
void swap2(string *, string *);
void swap3(int[]);
void swap4(string&, string&);
void swap5(string str1="str1",string str2="str2");
void swap6(const string&);
int& index1(int i);
int* index2(int&);


int main() {

	//ʹ��string��Ķ�����Ϊ��������
	string str1 = "str1", str2 = "str2";
	swap1(str1, str2);
	cout << "������>> str1:" << str1 << "; str2:" << str2 << endl << endl;

	//ʹ��string���ָ����Ϊ��������
	str1 = "str1", str2 = "str2";
	swap2(&str1, &str2);
	cout << "������>> str1:" << str1 << "; str2:" << str2 << endl << endl;

	//����������ʵ��
	int a[] = {3,8};
	swap3(a);
	cout << "������>> a[0]:" << a[0] << "; a[1]:" << a[1] << endl << endl;

	//������Ϊ��������
	str1 = "str1", str2 = "str2";
	swap4(str1, str2);
	cout << "������>> str1:" << str1 << "; str2:" << str2 << endl << endl;

	//Ĭ�ϲ���
	swap5();
	cout << endl << endl;

	//ʹ��const��������
	str1 = "str1";
	swap6(str1);
	cout << "������>> str:" << str1 << endl << endl;


	//�������õĺ��� �����⣬���������16
	index1(3) = 16;
	cout << "ִ�к�>> " << index1(3) << endl << endl;


	//����ָ�뺯��
	int i;
	int* value;
	value = index2(i);
	cout << "ִ�к�>> value[0]:" << value[0] << "; i:" << i << endl << endl;


	return 0;
}

void swap1(string str1, string str2) {
	string temp = str1;
	str1 = str2;
	str2 = temp;
	cout << "swap1>>  str1:" << str1 << "; str2:" << str2 << endl;
}


void swap2(string * str1, string * str2) {
	string * temp = str1;
	str1 = str2;
	str2 = temp;
	cout << "swap2>>  str1:" << *str1 << "; str2:" << *str2 << endl;
}

void swap3(int a[]) {
	int temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	cout << "swap3>>  a[0]:" << a[0] << "; a[1]:" << a[1] << endl;
}

void swap4(string & str1, string & str2) {
	string temp = str1;
	str1 = str2;
	str2 = temp;
	cout << "swap4>>  str1:" << str1 << "; str2:" << str2 << endl;
}

void swap5(string str1, string str2) {
	cout << "swap5>>  str1:" << str1 << "; str2:" << str2 << endl;
}

void swap6(const string& str) {
	string str2 = "str2";
	//str = str2;//�����޷�ͨ��
	cout << "swap6>>  str:" << str2 << endl;
}


int& index1(int i) {
	cout << "index1>>  i:" << i << endl;
	return i;
}

int* index2(int& i) {
	i = 1;
	int* value = new int[i];

	value[0] = 2;
	return value;
}