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
class nv : public nguoi{
	private:
	char tdcm[10];
	float sn;
	public:
	nv(char* ht = " ", char* scm = " ", char* gt = " ", char* tdcm = " ", 
	float sn = 0.0) : nguoi(ht, scm, gt){
		strcpy(this ->tdcm, tdcm);
		this ->sn = sn;
	}
	~nv(){}
	void nhap();
	float tien_huong_che_do(){
		return 50 * sn;
	}
	bool operator >= (nv a){
		return this ->sn >= a.sn;
	}
	void xuat();
};
void nv::nhap(){
	nguoi::nhap();
	cout << "Trinh do chuyen mon ; ";
	cin.getline(tdcm, 10);
	cout << "So nam nop tien bao hiem xa hoi : ";
	cin >> sn;
	fflush(stdin);
}
void nv::xuat(){
	nguoi::xuat();
	cout << setw(15) << tdcm << setw(5) << sn << setw(10) << tien_huong_che_do() << endl;
}
bool cmp(nv a, nv b){
	return a.tien_huong_che_do() < b.tien_huong_che_do();
}
int main(){
	int n;
	cin >> n;
	fflush(stdin);
	nguoi x[n];
	for(int i = 0; i < n; i++){
		x[i].nhap();
	}
	for(int i = 0; i < n; i++){
		x[i].xuat();
	}
	int m; 
	cin >> m;
	fflush(stdin);
	nv y[m];
	for(int i = 0; i < m; i++){
		y[i].nhap();
	}
	sort(y, y + m, cmp);
	for(int i = 0; i < m; i++){
		y[i].xuat();
	}
	return 0;
}