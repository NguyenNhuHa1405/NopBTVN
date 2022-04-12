#include<iostream.h>
#include<iomanip.h>
using namespace std;
class ANPHAM{
	private:
	char mahang[15];
	char tennxb[15];
	int ngayxb;
	int dongia;
	public:
	ANPHAM(char* mahang = "", char* tennxb = "", int ngayxb = 0, int dongia = 0){
		strcpy(this ->mahang, mahang);
		strcpy(this ->tennxb, tennxb);
		this ->ngayxb = ngayxb;
		this ->dongia = dongia;
	}
	void nhap();
	void xuat();
	int getdongia(){
		return dongia;
	}
	bool operator == (ANPHAM a){
		return this ->tennxb == a.tennxb;
	}
};
void ANPHAM::nhap(){
	fflush(stdin);
	cout << "Ma Hang : ";
	cin.getline(mahang, 15);
	cout << "Ten Nha Xuat Ban : ";
	cin.getline(tennxb, 15);
	cout << "Ngay Xuat Ban :";
	cin >> ngayxb;
	cout << "Don Gia : ";
	cin >> dongia;
	fflush(stdin);
}
void ANPHAM::xuat(){
	cout << mahang << setw(15) << tennxb << setw(15) << ngayxb << " " << dongia << " ";
}
class SACH : public ANPHAM{
	private:
	char tensach[15];
	char tentacgia[15];
	int soluong;
	public:
	SACH(char* mahang = "", char* tennxb = "", int ngayxb = 0, int dongia = 0, char* tensach = "",
	char* tentacgia = "", int soluong = 0) : ANPHAM(mahang, tennxb, ngayxb, dongia){
		strcpy(this ->tensach, tensach);
		strcpy(this ->tentacgia, tentacgia);
		this ->soluong = soluong;
	}
	friend istream& operator >> (istream& in, SACH& a);
	friend ostream& operator << (ostream& out, SACH a);
	int thanhtien(){
		return soluong * getdongia();
	}
	void tentg();
};
istream& operator >> (istream& in, SACH& a){
	cout << "Ten Sach : ";
	in.getline(a.tensach, 15);
	cout << "Ten Tac Gia : ";
	in.getline(a.tentacgia, 15);
	cout << "So Luong : ";
	in >> a.soluong;
	return in;
}
ostream& operator << (ostream& out, SACH a){
	out << a.tensach << setw(15) << a.tentacgia << setw(15) << a.soluong << endl;
	return out;
}
bool cmp(SACH a, SACH b){
	return a.thanhtien() > b.thanhtien();
}
void SACH::tentg(){
	int d = 1;
	if (tentacgia == "Nguyen Van A"){
		++d;
	}
	cout << d << endl;
}
int main(){
	int n;
	cin >> n;
	fflush(stdin);
	SACH x[n];
	for (int i = 0; i < n; i++){
		x[i].nhap();
		cin >> x[i];
	}
	for (int i = 0; i < n; i++){
		x[i].xuat();
		cout << x[i];
	}
	for (int i = 0; i < n; i++){
		int min = x[0].getdongia();
		if(x[i] == "Kim Dong", x[i].getdongia()	< min){
			x[i].xuat();
			cout << x[i];
		}
	}
	for (int i = 0; i < n; i++){
	     x[i].tentg();
	}
	
	sort(x, x + n, cmp);
	for(int i = 0; i < n; i++){
		if(x[i] == "Le Minh"){
			x[i].xuat();
		    cout << x[i];
		}
	}
	return 0;
}