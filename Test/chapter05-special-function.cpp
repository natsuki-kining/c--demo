#include <iostream>
using namespace std;

class object {
	private:
		int val;
	public :
		object() :val(0) {
			cout << "����object�޲ι��캯��" << endl;
		}
		object(int i) :val(i) {
			cout << "����object�вι��캯����val:" << val << endl;
		}
		~object() {
			cout << "delete object " << val << endl;
		}
};

class container {
	private :
		object one; //��ʼ��˳��������Ա������˳���й�
		object two; //����ǰ����ȳ�ʼ��
		int data;
	public:
		container():data(0)
		{
			cout << "����container�޲ι��캯��" << endl;
		}
		container(int i,int j,int k);
		~container() {
			cout << "delete container " << data << endl;
		}
};

container::container(int i, int j, int k) :two(i), one(j)
{
	data = k;
	cout << "����container�вι��캯����i:" << i << ",j:" << j << ",k:" << k << endl;
}


class StaticField {
	
	private:
		int n;
	public:
		static int x;
		static int getx() { return x; }
		static void setx() { ++x; }
		StaticField(int i) {
			n = i;
			cout << "���� StaticField �вι��캯����i:" << i << endl;
		}
		~StaticField() {
			cout << "delete StaticField " << n << endl;
		}
		int getn()
		{
			return n;
		}
		void inc()
		{
			++n;
		}
		friend int friendMethod(StaticField &);
};

int friendMethod(StaticField&f)
{
	cout << "������Ԫ����������˽�����ԣ�" << f.x << "," << f.n << endl;
	return f.x + f.n;
}
int StaticField::x = 10; //��ʼ����̬��Ա��main����д����

class A {
private:
	int val;
public:
	A(int i)
	{
		val = i;
	}
	int value(int i) 
	{
		return val + i;
	}
};

void main()
{
	cout << "����main����" << endl << endl << "�����Ա��ʼ����" << endl;
	/**
	�����Ա��ʼ����
		con1:
			�ȳ�ʼ��object������object���޲ι��캯�� * 2��Ȼ���ٳ�ʼ��container
			�ȳ�ʼ��one���ٳ�ʼ��two
		con2��
			����container���вι��캯�����ڳ�ʼ����ʱ�����object���вι��캯�����ȳ�ʼ��object���ٳ�ʼ��container
			�ȳ�ʼ��two���ٳ�ʼ��one

		console:
			����object�޲ι��캯��
			����object�޲ι��캯��
			����container�޲ι��캯��
			����object�вι��캯����val:2
			����object�вι��캯����val:1
			����container�вι��캯����i:1,j:2,k:3
			delete container 3
			delete object 1
			delete object 2
			delete container 0
			delete object 0
			delete object 0
	*/
	container con1, con2(1, 2, 3);

	cout << endl << endl << "��̬��Ա��" << endl;
	//��̬��Ա
	cout << "x:" << StaticField::x << endl;
	cout << "StaticField::getx():" << StaticField::getx() << endl;
	StaticField::setx();
	cout << "x:" << StaticField::x << endl;
	cout << "StaticField::getx():" << StaticField::getx() << endl;
	StaticField s(1);
	cout << "s.x:" << s.x << endl;

	//��̬����ֻ��ʼ��һ��
	cout << endl << endl << "��̬����" << endl;
	for (int i = 0;i<3;i++)
	{
		static StaticField field1(1);
		StaticField field2(2);
	}

	//��Ԫ�������ܹ�����˽�����ԣ����Ǳ�����������������ʹ��friend���Ρ�
	cout << endl << endl << "��Ԫ������" << endl;
	StaticField field3(3);
	int result = friendMethod(field3);
	cout << "�����" << result << endl;

	//����Ԫ��������ĳ�Ա������������Ԫ���������ܡ�

	//const


	//ָ�����Ա�ĺ���ָ��
	cout << endl << endl << "�ຯ��ָ�룺" << endl;
	int(A :: * pfun)(int); //����ָ����A�ĳ�Ա������ָ��
	pfun = &(A :: value); //ָ��ָ������Ա����,����&��vs�ϻᱨ����������û�мӡ�
	A objA(10); //����A����
	cout << (objA.*pfun)(15) << endl; //����ʹ����ĺ���ָ�룬���������Ű������������ָ��������ʹ�á�->��
	A* pc = &objA;
	cout << (pc->*pfun)(15) << endl; //ָ�����ʹ����ĺ���ָ��


	cout << endl << endl << "�˳�main����" << endl;
}