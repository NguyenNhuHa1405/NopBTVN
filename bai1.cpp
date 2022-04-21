#include<iostream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;
class nguoi{
	protected:
	char ho_ten[30];
	int nam_sinh;
	public:
	void nhap();
	void hien_thi();
};
void nguoi::nhap(){
	cout << "Ho ten : ";
	cin.getline(ho_ten, 30);
	cout << "Nam sinh : ";
	cin >> nam_sinh;
	fflush(stdin);
}
void nguoi::hien_thi(){
	cout << ho_ten << setw(15) << nam_sinh << setw(10);
}
class thi_sinh : public	nguoi{
	private:
	char sbd[15];
	int toan, li, hoa;
	public:
	void nhap();
	void in();
	int tong_diem(){
		return toan + li + hoa;
	}
	char* getsbd(){
		return sbd;
	}
};
void thi_sinh::nhap(){
	nguoi::nhap();
	cout << "SBD : ";
	cin.getline(sbd, 15);
	cout << "Toan : ";
	cin >> toan;
	cout << "Li : ";
	cin >> li;
	cout << "Hoa : ";
	cin >> hoa;
	fflush(stdin);
}
bool cmp(thi_sinh a, thi_sinh b){
	return a.tong_diem() < b.tong_diem();
}
void thi_sinh::in(){
	nguoi::hien_thi();
	cout << sbd << setw(15) << toan << setw(5) << li << setw(5) << hoa << setw(5) << tong_diem() << endl;
}
void tim_kiem_sbd(thi_sinh a[], int n){
	bool ktra = false;
	char sbd_cantim[15];
	cout << "Nhap sbd can tim : ";
	cin.getline(sbd_cantim, 15);
	for(int i = 0; i < n; i++){
		if(strcmpi(a[i].getsbd(), sbd_cantim) == 0){
			ktra = true;
		}
	}
	if(ktra == true){
		for(int i = 0; i < n; i++){
		if(strcmpi(a[i].getsbd(), sbd_cantim) == 0){
			a[i].in();
		}
	    }
	}
	else{
		cout << "Khong tim thay !" << endl;
	}
	
}
int main(){
	int n; cin >> n;
	fflush(stdin);
	thi_sinh x[n];
	for(int i = 0; i < n; i++){
		x[i].nhap();
	}
	sort(x, x + n, cmp);
	for(int i = 0; i < n; i++){
		x[i].in();
	}
	tim_kiem_sbd(x, n);
	return 0;
}