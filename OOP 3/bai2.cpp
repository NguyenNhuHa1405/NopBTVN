#include<iostream.h>
#include<iomanip.h>
using namespace std;
class san_pham{
	protected:
	char masp[15];
	char tensp[15];
	int namsx;
	public:
	void nhap();
	void xuat();
};
void san_pham::nhap(){
	cout << "Ma san pham : ";
	cin.getline(masp, 15);
	cout << "Ten san pham : ";
	cin.getline(tensp, 15);
	cout << "Nam san xuat : ";
	cin >> namsx;
}
void san_pham::xuat(){
	cout << setw(5) << masp << setw(10) << tensp << setw(10) << namsx ;
}
class tivi : public san_pham{
	private:
	int chieu_dai;
	int chieu_rong;
	public:
	void nhap();
	void in();
	int dien_tich(){
		return chieu_rong * chieu_dai;
	}
};
void tivi::nhap(){
	san_pham::nhap();
	cout << "Chieu dai : ";
	cin >> chieu_dai;
	cout << "Chieu rong : ";
	cin >> chieu_rong;
	fflush(stdin);
}
void tivi::in(){
	san_pham::xuat();
	cout << setw(10) << chieu_dai << setw(10) << chieu_rong << setw(10) << dien_tich() << endl;
}
bool cmp(tivi a, tivi b){
	return a.dien_tich() < b.dien_tich();
}
int main(){
	int n; cin >> n;
	fflush(stdin);
	tivi x[n];
	for(int i = 0; i < n; i++){
		x[i].nhap();
	}
	sort(x, x + n, cmp);
	for(int i = 0; i < n; i++){
		x[i].in();
	}
	return 0;
}