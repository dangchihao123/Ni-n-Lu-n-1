#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include "stdio.h"

#define MAX 100
#define vocuc 666

using namespace std;

class Dijsktra
{
private:

	int a[MAX][MAX],n;
	ifstream ifile; // khoi tao file vao.
	ofstream ofile; // khoi tao file ra.
public:
	int Doc_File(char [],int [][MAX], int &);
	void Ghi_File(int [][MAX], int);
	void Xuat_Matran(int [][MAX],int);
	int TT_Dijkstra(int [][MAX],int,int );
	void Nhap_Tay(int [][MAX], int &);
	void DeTai();
	void Ghi_DeTai();
	void menu();
};