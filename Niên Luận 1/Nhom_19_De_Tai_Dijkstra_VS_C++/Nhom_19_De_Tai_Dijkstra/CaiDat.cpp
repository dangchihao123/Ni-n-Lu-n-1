#include "stdafx.h"
#include "KhaiBao.h"
void Dijsktra::Nhap_Tay(int a[][MAX], int &n)
{
	cout<<endl<<endl;
	cout<<"\n\nNhap vao ma tran vuong cap: ";
	cin>>n;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cout<<"\nNhap vao phan tu thu a["<<i<<"]["<<j<<"]: ";
			cin>>a[i][j];
		}
	}
}

int Dijsktra::Doc_File(char filename[],int a[][MAX], int &n)
{
	ifile.open(filename, ios::in); 
	if(ifile.fail()){
		cout<<"\nCo loi xay ra....";	return 0;
	}
		ifile>>n;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				ifile>>a[i][j];
			}
		}
		ifile.close();
		return 1;
	
}

void Dijsktra::Xuat_Matran(int a[][MAX],int n)
{
	cout<<"\n\nMa Tran vua duoc nap vao la  "<<endl;
	for(int i=0 ; i<n ; i++){
		cout<<endl;
		for(int j=0 ; j<n ; j++)
			cout<<"\t "<<a[i][j]<<"  ";
	}
	cout<<endl;
}

void Dijsktra::Ghi_File(int a[][MAX], int n)
{
	ofile.open("Output.txt", ios::app);	//doc cac thong so va ghi ra file. tu save de file da ton tai.
	ofile<<"Cap cua ma tran vua duoc nap vao "<<n;
	ofile<<"\nMa Tran vua duoc nap vao co hinh dang nhu sau "<<endl;
	for(int i=0 ; i<n ; i++)
	{
		ofile<<endl;
		for(int j=0 ; j<n ; j++)				
			ofile<<"\t "<<a[i][j]<<"  ";
	}
	ofile.close();

}

//Ham tra ve 0: do thi khong lien thong, tra ve 1: lien thong, [s: dinh xuat phat, dinh goc]
int Dijsktra::TT_Dijkstra(int a[][MAX],int n,int s) 
{
	int Mark[MAX],d[MAX],pr[MAX], k,min,dem;
	ofile.open("Output.txt",ios::app);
	//Khoi tao theo ly thuyet slide hoc cua cac ban
	for(int i=0;i<n;i++){
		d[i]=vocuc;			//tu dinh goc s den cac dinh con lai la vocuc
		Mark[i]=0; 			//chua co dinh nao dc chon vao cay T
		pr[i]=s;			//s la dinh truoc khi den tat ca dinh i con lai
	}

	//khoi tao
	for(int j=0;j<n;j++) {
		if(a[s][j])		//neu co canh noi giua s va j
			d[j]=a[s][j];	//luu lai khoang cach tu s->j vao mang d [d la mang luu lai khoang cach tinh tu s]
	}

	d[s]=0;				//khoang cach s->s la 0  [d la mang luu lai khoang cach tinh tu s]
	Mark[s]=1; 			//s la dinh dau tien dua vao cay T
	dem=n-1;				//chuan bi lap n-1 lan, tuc chon n-1 dinh con lai vao cay T, [n-1: tru ra dinh s da dc chon roi]
	while (dem>0) {			//lan luot chon n-1 dinh dua vao cay T [co n dinh, tru ra dinh s da dua vao cay T truoc do roi]
		min = vocuc;   		
		for(int i=0;i<n;i++)					//di tim dinh k, 
			if ((Mark[i]==0) && (d[i]<min)) {	//ma k o ngoai cay T, sao cho d[k] la nho nhat
				min = d[i];
				k = i;
			}
			if (min==vocuc){
				cout<<"\nDo thi khong lien thong";
				return 0;
			}
			Mark[k]=1;								//Chon dc k dua vao cay T
			for (int j=0;j<n;j++) 					//Cap nhat lai gia tri
				if ((Mark[j]==0) && (d[k]+a[k][j]<d[j]) && (a[k][j]>0)) {
					d[j]=d[k]+a[k][j];
					pr[j]=k;
				}
				dem--;
	}
	//In kq: dinh goc xp- > tat ca cac dinh con lai	
	for (int i=0;i<n;i++)
		if (i!=s)				//neu la dinh goc ==> khong in ra man hinh
			if(d[i]==vocuc) {		//khong co duong di tu s->i
				cout<<"\nko co duong di tu "<<s<<" -> "<<i;
				ofile<<"\nko co duong di tu "<<s<<" -> "<<i;
			}
			else {
				cout<<"\n\nduong di tu "<<s<<" -> "<<i<<" co do dai la: "<<d[i];
				ofile<<"\n\nduong di tu "<<s<<" -> "<<i<<" co do dai la: "<<d[i];
				cout<<"\nCac dinh di qua la : ";
				ofile<<"\nCac dinh di qua la : ";
				int mang[MAX];
				dem=0;
				int tam=pr[i];
				while (tam!=s) {
					mang[dem]=tam;
					tam=pr[tam];
					dem++;
				}
				cout<<s<<" -> ";
				ofile<<s<<" -> ";
				for (int j=dem;j>0;j--) {
					cout<<mang[j-1]<<" -> ";
					ofile<<mang[j-1]<<" -> ";
				}
				cout<<i<<"\n";
				ofile<<i<<"\n";
			}
			ofile.close();
			return 1;
}

void Dijsktra::DeTai()
{
	cout<<"\n\n********************* CHUONG TRING TIM DUONG DI NGAN NHAT *********************"<<endl;
	cout<<"\n\t Giao vien:\t Trần Thị Thu Lan";
	cout<<"\n\t Nhom:\t\t 19";
	cout<<"\n\t Thanh Vien";
	cout<<"\n\t\t\t 1.Đặng chí hào\tMSSV: 1752060069\t Lop: CNTT12";
	
}

void Dijsktra::menu()
{
	cout<<"\n\n\n\n\t------------------- MENU LUA CHON -------------------";
	cout<<"\n\t 1. Nhap du lieu bang tay.";
	cout<<"\n\t 2. Chon duong dan chua tap tin.";
	cout<<"\n\t 3. Thoat chuong trinh"<<endl;
}
void Dijsktra::Ghi_DeTai()
{
	ofile.open("Output.txt", ios::out);
	ofile<<"\n\n********************* CHUONG TRING TIM DUONG DI NGAN NHAT *********************"<<endl;
	ofile<<"\n\t Giao vien:\t Trinh Minh Luong";
	ofile<<"\n\t Nhom:\t\t 19";
	ofile<<"\n\t Thanh Vien";
	ofile<<"\n\t\t\t 1.Nguyen Trong Tiep\tMSSV: 51220054\t Lop: 12250301";
	ofile<<"\n\t\t\t 2.Nguyen Hai Dang\tMSSV: 51220008\t Lop: 12250301";
	ofile<<"\n\n";
	ofile.close();
}
