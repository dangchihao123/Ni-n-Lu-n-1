// Nhom_19_De_Tai_Dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KhaiBao.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Dijsktra d;
	ofstream ofile;
	int a[MAX][MAX],n,ch,key;
	char duongdan[100],kt;

	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	ofile.open("Output.txt", ios::app);
	d.DeTai();
	d.menu();
	cout<<"\nMoi lua chon cong viec muon thuc hien: ";
	cin>>ch;

	switch(ch)
	{
	case 1:
		{
			d.Nhap_Tay(a,n);
			system("cls");
			d.DeTai();
			d.Xuat_Matran(a,n);
			d.Ghi_DeTai();
			d.Ghi_File(a,n);
			ofile<<"\n\nNgay gio tao file: "<<asctime (timeinfo);
			cout<<"\nXin moi chon dinh xuat phat: ";	
			cin>>key;
			ofile<<"\nDinh xuat phat: "<<key;
			ofile.close();
			if(d.TT_Dijkstra(a,n,key)==0){
				cout<<"\nDo thi xuat phat tu "<<key<<" khong len thong...."<<endl;
				ofile<<"\nDo thi xuat phat tu "<<key<<" khong len thong...."<<endl;
			}
			system("pause");
			break;
		}
	case 2:
		{
			while(1)
			{
				system("cls");
				d.DeTai();
				cin.ignore();
				cout<<"\n\n\nXin moi nhap vao duong dan tap tin: ";
				cin.getline(duongdan,MAX);
				if(d.Doc_File(duongdan,a,n)){
					d.Xuat_Matran(a,n);
					d.Ghi_DeTai();
					d.Ghi_File(a,n);
					ofile<<"\n\nNgay gio tao file: "<<asctime (timeinfo);
					ofile<<"\n\n\nDuong dan tap tin: "<<duongdan;
					cout<<"\n\nXin moi chon dinh xuat phat: ";
					cin>>key;
					ofile<<"\n\nDinh xuat phat: "<<key;
					ofile.close();
					if(d.TT_Dijkstra(a,n,key)==0){
						cout<<"\nDo thi xuat phat tu "<<key<<" khong lien thong...";
						ofile<<"\n\nNgay gio tao file: "<<asctime (timeinfo);
						ofile<<"\nDo thi xuat phat tu "<<key<<" khong lien thong...";
						ofile.close();
					}
				}
				cout<<"\nBam phim bat ky de tiep tuc...\nBam 'n' hoac 'N' de ket thuc... ";
				cin>>kt;
				if(kt == 'n' || kt == 'N'){
					system("cls");
					d.DeTai();
					cout<<"\nNhan Enter de thoat chuong trinh....."<<endl;
					system("pause");
					ofile<<"\nBan da thoat khoi chuong trinh......\n";
					ofile.close();
					exit(0);
				}
			}
		}
			
	case 3:
		{
			cout<<"\nBan da chon thoat khoi chuong trinh..."<<endl<<"\nNhan Enter de thoat "<<endl;
			ofile<<"\n\nBan vua chon muc thuc hien thu 3 la thoat khoi chuong trinh....";
			ofile<<"\n";
			ofile<<"\n\nNgay gio ghi vao file: "<<asctime (timeinfo);
			system("pause");
			exit(0);
		}

	default:	cout<<"\nBan lua chon cong viec thuc hien khong dung....."<<endl;
	}
	system("pause");
	return 0;
}

