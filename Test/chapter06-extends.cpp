#include <iostream>

using namespace std;

class A {
	private:
		int a1;
	protected:
		int a2;
	public:
		int a3;
		A() :a1(0), a2(0), a3(0) {
			cout << "���� class A �޲ι��캯��" << endl;
		}
		A(int i, int j, int k) {
			this->a1 = i;
			this->a2 = j;
			this->a3 = k;
			cout << "���� class A ���޲ι��캯�� " << "a1:" << a1 << ",a2:" << a2 << ",a3:" << a3 << endl;
		}
		void show()
		{
			cout << "class A: " << "a1:" << a1 << ",a2:" << a2 << ",a3:" << a3 << endl;
		}
		~A() {
			cout << "delete A" << endl;
		}
};


class B : public A {
	private:
		int b1;
	protected:
		int b2;
	public:
		int b3;
		B() :b1(0), b2(0), b3(0) {
			cout << "���� class B �޲ι��캯�� " << endl;
		}
		B(int i, int j, int k) : A(i+1, j + 1, k + 1) {
			this->b1 = i;
			this->b2 = j;
			this->b3 = k;
			cout << "���� class B ���޲ι��캯�� " << "b1:" << b1 << ",b2:" << b2 << ",b3:" << b3 << endl;
		}
		void show()
		{
			cout << "class B:" << "b1:" << b1 << ",b2:" << b2 << ",b3:" << b3
				<< "--" << "a2:" << a2 << "a3:" << a3 << endl;
		}
		~B() {
			cout << "delete B" << endl;
		}
};


class C : public B {
	private:
		int c1;
	protected:
		int c2;
	public:
		int c3;
		C() :c1(0), c2(0), c3(0) {
			cout << "���� class C �޲ι��캯��" << endl;
		}
		C(int i, int j, int k) : B(i + 1,j + 1,k + 1) {
			this->c1 = i;
			this->c2 = j;
			this->c3 = k;
			cout << "���� class C ���޲ι��캯�� " << "c1:" << c1 << ",c2:" << c2 << ",c3:" << c3 << endl;
		}
		void show()
		{
			cout << "class C:" << "c1:" << c1 << ",c2:" << c2 << ",c3:" << c3
				<< "--" << "b2:" << b2 << "b3:" << b3
				<< "--" << "a2:" << a2 << "a3:" << a3
				<< endl;
		}
		~C() {
			cout << "delete C" << endl;
		}
};



class D : public A, public B, public C {
	private:
		int d1;
	protected:
		int d2;
	public:
		int d3;
		D() :d1(0), d2(0), d3(0) {
			cout << "���� class D �޲ι��캯��" << endl;
		}
		D(int i, int j, int k) : A(i + 1,j + 1,k + 1),B(i + 2,j + 2,k + 2),C(i+3,j+3,k+3) {
			this->d1 = i;
			this->d2 = j;
			this->d3 = k;
			cout << "���� class D ���޲ι��캯�� " << "d1:" << d1 << ",d2:" << d2 << ",d3:" << d3 << endl;
		}
		void show()
		{
			cout << "class D:" << "d1:" << d1 << ",d2:" << d2 << ",d3:" << d3 << endl;
		}
		~D() {
			cout << "delete D" << endl;
		}
};

class E {
	int i, j, k;
	public :
		E() : i(0),j(0),k(0)
		{
			cout << "���� class E �޲ι��캯��" << endl;
		}
		E(int i, int j, int k)
		{
			this->i = i;
			this->j = j;
			this->k = k;
			cout << "���� class E ���޲ι��캯�� " << "i:" << i << ",j:" << j << ",k:" << k << endl;
		}
		~E() {
			cout << "delete E" << endl;
		}
};


class F {
	int i, j, k;
public:
	F() : i(0), j(0), k(0)
	{
		cout << "���� class F �޲ι��캯��" << endl;
	}
	F(int i, int j, int k)
	{
		this->i = i;
		this->j = j;
		this->k = k;
		cout << "���� class F ���޲ι��캯�� " << "i:" << i << ",j:" << j << ",k:" << k << endl;
	}
	~F() {
		cout << "delete F" << endl;
	}
};

class G {
	int i, j, k;
public:
	G() : i(0), j(0), k(0)
	{
		cout << "���� class G �޲ι��캯��" << endl;
	}
	G(int i, int j, int k)
	{
		this->i = i;
		this->j = j;
		this->k = k;
		cout << "���� class G ���޲ι��캯�� " << "i:" << i << ",j:" << j << ",k:" << k << endl;
	}
	~G() {
		cout << "delete G" << endl;
	}
};

class H {
	int i, j, k;
public:
	H() : i(0), j(0), k(0)
	{
		cout << "���� class H �޲ι��캯��" << endl;
	}
	H(int i, int j, int k)
	{
		this->i = i;
		this->j = j;
		this->k = k;
		cout << "���� class H ���޲ι��캯�� " << "i:" << i << ",j:" << j << ",k:" << k << endl;
	}
	~H() {
		cout << "delete H" << endl;
	}
};

class I : public E {
	private:
		int e1;
		F f;
	protected:
		int e2;
		G c;
	public:
		int e3;
		H d;
		I() :e1(0),e2(0),e3(0) {
			cout << "���� class I �޲ι��캯��" << endl;
		}
		I(int i, int j, int k){
			this->e1 = i;
			this->e2 = j;
			this->e3 = k;
			cout << "���� class I ���޲ι��캯�� " << "e1:" << e1 << ",e2:" << e2 << ",e3:" << e3 << endl;
		}
		void show()
		{
			cout << "class I:" << "e1:" << e1 << ",e2:" << e2 << ",e3:" << e3 << endl;
		}
		~I() {
			cout << "delete I" << endl;
		}
		
};

void main() {
	//��һ�̳�
	B b(1, 2, 3);
	b.show();

	A& a = b;
	a.show();

	A* a2 = &b;
	a2->show();

	cout << endl << endl;

	//���̳�
	C c(5, 6, 7);
	c.show();

	//B * b = &c; //�����class C : protected B����ᱨ��
	//b ->show();//���ֲ����ԣ�ֻ��ת��A

	A* a3 = &c;
	a3->show();

	cout << endl << endl;

	//��̳�
	D d(1, 2, 3);
	d.show();

	//������
	d.A::show();
	d.B::show();
	d.C::show();
	
	cout << endl << endl;

	cout << "�������Ա������ĳ�ʼ��ѭ��" << endl;
	I i(1,2,3);


	cout << "�˳� main ����" << endl << endl;
}