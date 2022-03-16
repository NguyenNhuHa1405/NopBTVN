#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
 using namespace std;
struct hang_hoa
{
  char ma_hang[10];
  char ten_hang[10];
  char don_vi_tinh[10];
  float don_gia;
  int so_luong;
  float thanh_tien;	
  void nhap()
  {
  	 cin.ignore();
     cout<<"\nMa mat hang : ";cin.getline(ma_hang,10);
	 cout<<"Ten mat hang : ";cin.getline(ten_hang,10);
	 cout<<"Don vi tinh : ";cin.getline(don_vi_tinh,10);
	 cout<<"Don gia : ";cin>>don_gia;
	 cout<<"So luong : ";cin>>so_luong;
  }
  float thanhtien()
  {
  	return(don_gia*so_luong);
  }
  void xuat()
  {
  	cout<<setw(10)<<ma_hang<<setw(15)<<ten_hang<<setw(15)<<don_vi_tinh;
 	cout<<setw(15)<<so_luong<<setw(15)<<don_gia;
 	cout<<setw(17)<<thanhtien()<<endl;
  }
};
typedef hang_hoa HH;
void nhapsl(int &n)
{
	do
	{
		cout<<"Nhap so mat hang: ";cin>>n;
		if(n<0)
		{
			cout<<"Moi ban nhap lai!"<<endl;
		}
	}while(n<0);
}
void nhaphh(HH *hh,int n)
{
	int d=0;
	for(int i=0;i<n;i++)
	{
		do
		{
			cout<<"========================================"<<endl;
			cout<<"Nhap thong tin mat hang thu "<<i+1<<": "<<endl;
		    hh[i].nhap();
		    for(int j=0;j<i;j++)
		    {
    			if(hh[j].ma_hang == hh[i].ma_hang)
    			{
			    	cout<<"Moi ban nhap lai!"<<endl;
			    	d++;
			    }
    		}
		}while(d!=0);
	}
}
void tieude()
{
	cout<<"\n--- DANH SACH SAN PHAM ---"<<endl;
    cout<<setw(10)<<"Ma san pham"<<setw(15)<<"Ten san pham"<<setw(15)<<"Don vi tinh";
    cout<<setw(15)<<"So luong"<<setw(15)<<"Don gia";
    cout<<setw(20)<<"Thanh tien"<<endl;
}
void xuathh(HH *hh,int n)
{
	tieude();
	for(int i=0;i<n;i++)
	{
		hh[i].xuat();
	}
}
void tinh(HH *hh,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Thanh tien cua mat hang thu "<<i+1<<": "<<hh[i].thanhtien()<<endl;
	}
}
void sapxep(HH *hh,int n)
{
	cout<<"\nDanh sach sinh vien theo thu tu tang dan ve so luong: "<<endl;
    for(int i=0;i<n;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
	    	if(hh[i].so_luong > hh[j].so_luong)
	    	{
	    		HH tg=hh[i];
	    		hh[i]=hh[j];
	    		hh[j]=tg;
	    	}
	    }
    }
    xuathh(hh, n);
}
float MAX(HH *hh,int n)
{
	float max=hh[0].thanhtien();
	for(int i=0;i<n;i++)
	{
		if(hh[i].thanhtien()> max )
		{
			max = hh[i].thanhtien(); 
		}
	}
	return max;
}
void INMAX(HH *hh, int n)
{
	cout<<"\nDanh sach mat hang co thanh tien lon nhat: "<<endl;
	tieude();
	for(int i=0;i<n;i++)
	{
		if(hh[i].thanhtien() == MAX(hh, n))
		{
			hh[i].xuat();
		}
	}
}
void them(HH *hh,int &n)
{
	n++;
	int d=0;
	do
	{
		d=0;
		cout<<"\nNhap thong tin mat hang can them: "<<endl;
	    hh[n-1].nhap();
		for(int i=0;i<n-1;i++)
		{
			if(hh[i].ma_hang == hh[n-1].ma_hang)
			{
				cout<<"Ma so khong duoc trung! Moi ban nhap lai!"<<endl;
				d++;
			}
		}	
	}while(d!=0);
	sapxep(hh, n);
}
void xoa(HH *hh,int &n)
{
	int d=0;
	char dv[10];
	cout<<"\nNhap don vi tinh can xoa: ";
	cin>>dv;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		if(*hh[i].don_vi_tinh = 'dv')
		{
		
			for(int j=i;j<n;j++)
			{
				hh[j] = hh[j+1];
			}break;
		}
	}n--;
	xuathh(hh, n);
}
void luu(HH* hh,int n)
{
	fstream f;
	f.open("F:\\product.dat",ios::out);
	if(!f)
    {
       cout<<"Khong the ghi tep";
       exit(1);
    }
    f<<n<<endl;

	for(int i=0;i<n;i++)
	{
	  f<<hh[i].ma_hang<<endl;
	  f<<hh[i].ten_hang<<endl;
	  f<<hh[i].don_vi_tinh<<endl;
	  f<<hh[i].don_gia<<endl;
	  f<<hh[i].so_luong<<endl;
	  f<<hh[i].thanhtien()<<"\n"<<endl;	
	}
	cout<<"Da ghi tep"<<endl;
	f.close();
}
void doc(HH *hh,int n)
{
	fstream f;
	f.open("F:\\product.dat",ios::in);
	if(!f)
    {
       cout<<"Khong the doc tep";
       exit(1);
    }
    f>>n;
    for(int i=0;i<n;i++)
    {
    	f.ignore();
    	f.getline(hh[i].ma_hang,10);
    	f.getline(hh[i].ten_hang,10);
    	f.getline(hh[i].don_vi_tinh,10);
    	f>>hh[i].don_gia;
    	f>>hh[i].so_luong;
    	f>>hh[i].thanh_tien;
    	f.ignore();
    }cout<<"Doc tep thanh cong!"<<endl;
    xuathh(hh, n);
    f.close();
}
void MENU()
{
	cout<<"--------------------------------MENU---------------------------------------------"<<endl;
	cout<<"|1.Nhap thong tin cac mat hang                                                  |"<<endl;
	cout<<"|2.Tinh thanh tien                                                              |"<<endl;
	cout<<"|3.Danh sach thong tin cac mat hang                                             |"<<endl;
	cout<<"|4.Sap xep cac mat hang theo thu tu tang dan ve so luong. In danh sach          |"<<endl;
	cout<<"|5.In thong tin cac mat hang co thanh tien lon nhat                             |"<<endl;
	cout<<"|6.Them mat hang                                                                |"<<endl;
	cout<<"|7.Xoa cac mat hang co don vi tinh la dv                                        |"<<endl;
	cout<<"|8.Luu danh sach cac mat hang ra tep product.dat                                |"<<endl;
	cout<<"|9.Doc danh sach cac mat hang tu product.dat va in thong tin ra man hinh        |"<<endl;
	cout<<"|10.Thoat                                                                       |"<<endl;
	cout<<"---------------------------------------------------------------------------------"<<endl;																																																																																																			
}

int main()
{
	int n=0;
	HH *hh;
	hh= new HH[100];
	int luachon;
	char chon;
	do
	{
		system("cls");
		MENU();
		cout<<"Moi ban nhap lua chon: ";
		cin>>luachon;
		switch(luachon)
		{
			case 1:
			nhapsl(n);
			nhaphh(hh, n);
			system("pause");
			break;
			case 2:
			tinh(hh, n);
			system("pause");
			break;
			case 3:
			xuathh(hh, n);
			system("pause");
			break;
			case 4:
			sapxep(hh, n);
			system("pause");
			break;
			case 5:
			INMAX(hh, n);
			system("pause");
			break;
			case 6:
			them(hh, n);
			system("pause");
			break;
			case 7:
			xoa(hh, n);
			system("pause");
			break;
			case 8:
			luu(hh, n);
			system("pause");
			break;
			case 9:
			doc(hh, n);
			system("pause");
			break;
			default:
			cout<<"Ban da nhap lua chon sai!"<<endl;
			break;
		}
		cout<<"Ban co muon tiep tuc khong (y/n): ";
		cin>>chon;
		if(chon == 'n')
		{
			cout<<"Tam biet!"<<endl;
		}
	}while(chon == 'y');
	return 0;
}                                              