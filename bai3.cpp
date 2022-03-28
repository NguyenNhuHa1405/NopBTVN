#include<iostream.h>
using namespace std;
class DaThuc3{
	private:
	int a, b, c, d;
	public:
	/*DaThuc3(int, int, int, int);
	~DaThuc3();*/
	void nhap();
	void in();
	int geta(){
		return this->a;
	}
	int getb(){
		return this->b;
	}
	int getc(){
		return this->c;
	}
	int getd(){
		return this->d;
	}
};
void DaThuc3::nhap(){
	cout << "\nBac 3 : ";cin >> this->a;
	cout << "Bac 2 : ";cin >> this->b;
	cout << "Bac 1 : ";cin >> this->c;
	cout << "Bac 0 : ";cin >> this->d;
};
/*DaThuc3::DaThuc3(int bac3, int bac2, int bac1, int bac0){
	cout << "Ham khoi tao co tham so" << endl;
	this->a = bac3;
	this->b = bac2;
	this->c = bac1;
	this->d = bac0;
	cout << this->a << "x^3 + " << this->b << "x^2 + " << this->c << "x + " << this->d << endl;
}
DaThuc3::~DaThuc3(){
	cout << "Da thuc duoc huy "<< endl;
}*/
int main(){
	DaThuc3 t[2];
	for(int i = 0;i < 2; i++){
		t[i].nhap();
	}
	cout << t[0].geta() + t[1].geta() << "x^3 + ";
	cout << t[0].getb() + t[1].getb() << "x^2 + ";
	cout << t[0].getc() + t[1].getc() << "x + " ;
	cout << t[0].getd() + t[1].getd() << endl;
	return 0;
}