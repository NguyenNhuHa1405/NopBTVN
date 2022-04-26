#include<iostream.h>
#include<iomanip.h>
using namespace std;
class nguoi{
	protected:
	char ht[30];
	char scm[10];
	char gt[5];
	public:
	nguoi(char* ht = " ", char* scm = " ", char* gt = " "){
		strcpy(this ->ht, ht);
		strcpy(this ->scm, scm);
		strcpy(this ->gt, gt);
	}
	~nguoi(){}
	void nhap();
	void xuat();
};
void nguoi::nhap(){
	cout << "Ho ten : ";
	cin.getline(ht, 30);
	cout << "So chung minh : ";
	cin.getline(scm, 10);
	cout << "Gioi tinh : ";
	cin.getline(gt, 5);
}
void nguoi::xuat(){
	cout << setw(25) << ht << setw(15) << scm << setw(7) << gt ;
}
class gv : public nguoi{
	private:
	char tdcm[10];
	int tn;
	public:
	gv(char* ht = " ", char* scm = " ", char* gt = " ", char* tdcm = " ",
	int tn = 0) : nguoi(ht, scm, gt){
		strcpy(this ->tdcm, tdcm);
		this ->tn = tn;
	}
	~gv(){}
	void nhap();
	int tien_tham_nien(){
		return 100 * tn;
	}
	bool operator >= (gv a){
		return this ->tn >= a.tn;
	}
	void xuat();
};
void gv::nhap(){
	nguoi::nhap();
	cout << "Trinh do chuyen mon : ";
	cin.getline(tdcm, 10);
	cout << "So nam cong tac : ";
	cin >> tn;
	fflush(stdin);
}
void gv::xuat(){
	nguoi::xuat();
	cout << setw(15) << tdcm << setw(5) << tn << setw(15) << tien_tham_nien() << endl;
}
bool cmp(gv a, gv b){
	return a.tien_tham_nien() < b.tien_tham_nien();
}
int main(){
	/*
int n;
	cin >> n;
	fflush(stdin);
	nguoi x[n];
	for(int i = 0; i < n; i++){
		x[i].nhap();
	}
	for(int i = 0; i < n; i++){
		x[i].xuat();
		cout << endl;
	}*/
	int m;
	cin >> m;
	fflush(stdin);
	gv y[m];
	for(int i = 0; i < m; i++){
		y[i].nhap();
	}
	sort(y, y + m, cmp);
	for(int i = 0; i < m; i++){
		y[i].xuat();
	}
	return 0;
}