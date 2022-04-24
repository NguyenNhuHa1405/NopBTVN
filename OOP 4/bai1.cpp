#include<iostream.h>
#include<iomanip.h>
using namespace std;
class nguoi{
	protected:
	char ht[30];
	char scm[10];
	char gt[5];
	public:
	nguoi(char* ht, char* scm, char* gt){
		strcpy(this ->ht, ht);
		strcpy(this ->scm, scm);
		strcpy(this ->gt, gt);
	}
	nguoi(){}
	~nguoi(){}
	void nhap();
	void in();
};
void nguoi::nhap(){
	cout << "Ho ten : ";
	cin.getline(ht, 30);
	cout << "So chung minh : ";
	cin.getline(scm, 10);
	cout << "Gioi tinh : ";
	cin.getline(gt, 5);
}
void nguoi::in(){
	cout << setw(15) << ht << setw(15) << scm << setw(7) << gt ;
}
class hs : public nguoi{
	private:
	char cn[20];
	float dtk;
	public:
	hs(char* ht = " ", char* scm = " ", char* gt = " ", char* cn = " ", float dtk = 0):nguoi(ht, scm, gt){
		strcpy(this ->cn, cn);
		this ->dtk = dtk;
	}
	~hs(){}
	void nhap();
	void in();
	char* xep_loai();
	bool operator > (float diem){
		return this ->dtk > diem;
	}
};
void hs::nhap(){
	nguoi::nhap();
	cout << "Chuyen nganh : ";
	cin.getline(cn, 20);
	cout << "Diem tong ket : ";
	cin >> dtk;
	fflush(stdin);
}
char* hs::xep_loai(){
	if(0 <= dtk < 5){
		return "Yeu!";	
	}
	if(dtk < 8){
		return "Kha!";
	}
	if(dtk < 10){
		return "Gioi";
	}
}
void hs::in(){
	nguoi::in();
	cout << setw(23) << cn << setw(5)<< dtk << "     " <<  xep_loai() << endl;
}
int main(){
	/*
int n;
	cin >> n;
	nguoi x[n];
	for(int i = 0; i < n; i++){
		x[i].nhap();
	}
	for(int i = 0; i < n; i++){
		x[i].in();
	}*/
	int k; 
	cin >> k;
	fflush(stdin);
	hs y[k];
	for(int i = 0; i < k; i++){
		y[i].nhap();
	}
	for(int i = 0; i < k; i++){
		if(y[i] > 8){
			y[i].in();
		}
	}
	return 0;
}