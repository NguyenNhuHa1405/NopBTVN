#include<iostream.h>
using namespace std;
class GV{
	private:
	char ht[30];
	int t;
	char bc[15];
	char cn[20];
	float bl;
	public:
	void nhap();
	void in();
	float lcb();
	char getcn();
};
float GV::lcb(){
	return this->bl * 610;
}
void GV::nhap(){
	cout << "Nhap ten : "; cin >> this->ht;
	cout << "Nhap tuoi : "; cin >> this->t;
	cin .ignore();
	cout << "Bang cap : "; cin >> this->bc;
	cout << "Chuyen Nganh : "; cin >> this->cn;
	cout << "Bac luong : "; cin >> this->bl;
}
void GV::in(){
	cout << ht << " " << t << " " << bc << " " << cn << " " << bl << " " << lcb() << endl; 
}
char GV::getcn(){
	return this->cn[20];
}
bool cmp(GV a, GV b){
	return a.getcn() > b.getcn();
}
int main(){
	int n; cin >> n;
	GV a[100];
	for(int i=0; i < n; i++){
		a[i].nhap();
	}
	sort(a, a+n, cmp);
	for(int i=0; i < n; i++){
		if(a[i].lcb() < 2000){
			a[i].in();
		}
	}
	return 0;
}