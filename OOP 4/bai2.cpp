#include<iostream.h>
#include<iomanip.h>
using namespace std;
class gv{
	protected:
	char ht[30];
	char cn[20];
	float bl;
	public:
	gv(char* ht = " ", char* cn = " ", float bl = 0){
		strcpy(this ->ht, ht);
		strcpy(this ->cn, cn);
		this ->bl = bl;
	}
	~gv(){}
	void nhap();
	void xuat();
	float getbl(){
		return bl;
	}
};
void gv::nhap(){
	cout << "Ho ten : ";
	cin.getline(ht, 30);
	cout << "Chuyen nganh : ";
	cin.getline(cn, 20);
	cout << "Bac luong : ";
	cin >> bl;
	fflush(stdin);
}
void gv::xuat(){
	cout << setw(25) << ht << setw(15) << cn << setw(10) << bl;
}
class gvth : public gv{
	private:
	char l[5];
	float lpc;
	public:
	gvth(char* ht = " ", char* cn = " ", float bl = 0, char* l = " "):gv(ht, cn, bl){
		strcpy(this ->l, l);
	}
	~gvth(){}
	void nhap();
	float tien_luong(){
		lpc = (50/100) * 1150 * bl;
		return 1150 * bl + lpc;
	}
	bool operator >= (gvth a){
		return this ->tien_luong() >= a.tien_luong();
	}
	void xuat();
};
void gvth::nhap(){
	gv::nhap();
	cout << "Lop : ";
	cin.getline(l, 5);
}
void gvth::xuat(){
	gv::xuat();
	cout << setw(7) << l << "    " << tien_luong() << endl;
}
bool cmp1(gv a, gv b){
	return a.getbl() < b.getbl();
}
bool cmp2(gvth a, gvth b){
	return a.tien_luong() < b.tien_luong();
}
int main(){
	int n;
	cin >> n;
	fflush(stdin);
	gv x[n];
	for(int i = 0; i < n; i++){
		x[i].nhap();
	}
	sort(x, x + n, cmp1);
	for(int i = 0; i < n; i++){
		x[i].xuat();
		cout << endl;
	}
	int m;
	cin >> m;
	fflush(stdin);
	gvth y[m];
	for(int i = 0; i < m; i++){
		y[i].nhap();
	}
	sort(y, y + m, cmp2);
	for(int i = 0; i < m; i++){
		y[i].xuat();
	}
	return 0;
}