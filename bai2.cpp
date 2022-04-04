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
	float lcb(){
		return bl * 610;
	}
	friend istream& operator >> (istream& in, GV& a);
	friend ostream& operator << (ostream& out, GV a);
	friend bool operator == (GV a, GV b);
};
bool operator == (GV a, GV b){
	return a.bc == b.bc;
}
istream& operator >> (istream& in, GV& a){
	in.ignore();
	cout << "\nNhap ten : "; in.getline(a.ht, 30);
	cout << "Nhap tuoi : "; in >> a.t;
	in.ignore();
	cout << "Bang cap : "; in.getline(a.bc, 15);
	cout << "Chuyen nganh : "; in.getline(a.cn, 20);
	cout << "Bac luong : "; in >> a.bl;
	return in;
}
ostream& operator << (ostream& out, GV a){
	out << a.ht << " " << a.t << " " << a.bc << " " << a.cn << " " << a.bl << endl;
	return out ;
}             
int main(){
	int n; cin >> n;
	GV a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	return 0;
}