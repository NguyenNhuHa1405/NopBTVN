#include<iostream.h>
using namespace std;
class DaThuc3{
	private:
	int a, b, c, d;
	public:
	DaThuc3(int bac3 = 0, int bac2 = 0, int bac1 = 0, int bac0 = 0){
		this ->a = bac3;
		this ->b = bac2;
		this ->c = bac1;
		this ->d = bac0;
	}
	~DaThuc3(){}	
	friend istream& operator >> (istream& in, DaThuc3& a);
	friend ostream& operator << (ostream& out, DaThuc3 a);
	DaThuc3 operator + (DaThuc3 a);
};
istream& operator >> (istream& in, DaThuc3& a){
	cout << "a = ";in >> a.a;
	cout << "b = ";in >> a.b;
	cout << "c = ";in >> a.c;
	cout << "d = ";in >> a.d;
	return in;
}
ostream& operator << (ostream& out, DaThuc3 a){
	out << a.a << "x^3 + " << a.b << "x^2 + " << a.c << "x + " << a.d << endl;
	return out;
}
DaThuc3 DaThuc3::operator + (DaThuc3 a){
	DaThuc3 tong;
	tong.a = this ->a + a.a;
	tong.b = this ->b + a.b;
	tong.c = this ->c + a.c;
	tong.d = this ->d + a.d;
	return tong;
}
int main(){
	DaThuc3 x, y;
	cin >> x >> y;
	DaThuc3 tong = x + y;
	cout << tong;
	return 0;
}