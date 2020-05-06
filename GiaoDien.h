//#include <iostream>
//#include <conio.h>
//#include <Windows.h>
//#include <stdio.h>
//#include <string.h>
#pragma once
#include "mylib.h"
#include "console.h"
using namespace std;

void TaoKhungChinh()
{
	for (int x = 10; x < 155; x++)
	{
		gotoXY(x, 0); cout << char(205); // duong ngang dau tien
		gotoXY(x, 20); cout << char(205); // duong ngang phia duoi
	}
	for (int y = 1; y < 20; y++)
	{
		gotoXY(10, y); cout << char(186); // duong dung ben trai
		gotoXY(154, y); cout << char(186); // duong dung ben phai
	}
	gotoXY(154, 0); cout << char(187); // dau ngoat goc tren ben phai
	gotoXY(154, 20); cout << char(188); // dau ngoat goc duoi ben phai
	gotoXY(10, 0); cout << char(201); // dau ngoat goc tren ben trai
	gotoXY(10, 20); cout << char(200) << endl; // dau ngoat goc duoi ben trai

	SetColor(14);
	gotoXY(15, 3);
	cout << "    ===       =        =      =      ==     =    =        =      =    ========  =      =  =      =    =       =   =  =======   ==     =";
	gotoXY(15, 4);
	cout << "=         =   =        =     = =     =  =   =    =          =   =        ==     =      =  =      =     =     =    =  =         =  =   =";
	gotoXY(15, 5);
	cout << "=         =   =        =    =====    =   =  =    =           = =         ==     ========  =      =      =    =    =  =======   =   =  =";
	gotoXY(15, 6);
	cout << "=         =   =        =   =     =   =    = =    =            =          ==     =      =  =      =       =  =     =  =         =    = =";
	gotoXY(15, 7);
	cout << "    ===  \\    ==========  =       =  =     ==    ========     =          ==     =      =  ========        ==      =  =======   =     ==" << "\t";

	SetColor(10);
	gotoXY(60, 10);
	cout << "GIAO VIEN: LUU NGUYEN KY THU";
	gotoXY(60, 11);
	cout << "KHOA: D16CQCN01-N";
	gotoXY(60, 12);
	cout << "SINH VIEN THUC HIEN";
	gotoXY(61, 13);
	cout << "1. Huynh Ngoc Hen  -  N16DCCN055";
	gotoXY(61, 14);
	cout << "2. Trinh Thanh Binh - N16DCCN012" << endl;
}
