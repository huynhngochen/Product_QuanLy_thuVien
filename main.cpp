#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <string.h>
#include <Windows.h> 
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "GiaoDien.h"
#include "Header.h"
#include "GiaoDienSach.h"
#include "mylib.h"

#define MAXDS 1000

using namespace std;


//void Xuat_thong_tin_1_DAUSACH(DAUSACH *dausach)
//{
//	cout << "\nMA ISBN: " << dausach->ISBN << "\tTENSACH: " << dausach->TenSach << "\tTACGIA:" << dausach->TacGia << "\tTHELOAI: " << dausach->TheLoai
//		<< "\tNAMXUATBAN: " << dausach->NamXuatBan;
//	for (NODE_SACH *k = dausach->FirstDanhMucSach; k != NULL; k = k->sNext)
//	{
//		cout << "\nMASACH: " << k->data.MaSach << "\t\tTRANGTHAI: " << k->data.TrangThai;
//	}
//}

//void Tim_Kiem_DAUSACH_Theo_TENSACH(DS_DAUSACH dsDauSach, char tensach[100], int &vitri)
//{
//	vitri = Search_Ten(dsDauSach, tensach);
//	if (vitri == -1)
//	{
//		BaoLoi("TEN SACH KHONG TON TAI!!KIEM TRA LAI");
//		//return vitri;
//	}
//	else
//	{
//		SetColor(14);
//		cout << "\n\t\t=======THONG TIN SACH CAN TIM==========\n";
//		Xuat_thong_tin_1_DAUSACH(dsDauSach.ds[vitri]);
//		//return vitri;
//	}
//}




//======================THE DOC GIA======================

//void menu()
//{
//	//DS_DAUSACH dsDauSach;
//	char maDauSach[6];
//	//TREE t;
//	KhoiTaoTREE(t);
//	NODE_THEDOCGIA *dg;
//	dg = new NODE_THEDOCGIA;
//	dg->First = NULL;
//	dg->Last = NULL;
//	dg->left = NULL;
//	dg->right = NULL;
//	//THEDOCGIA dg;
//
//
//	int luachon;
//	Normal();
//	//gotoxy(cot, dong);
//	while (true)
//	{
//		SetColor(15);
//		system("cls");
//		cout << "\n1. Them dau sach";
//		cout << "\n2. Them sach";
//		cout << "\n3. Xuat danh sach sach";
//		cout << "\n4. Ghi file DS Dau Sach";
//		cout << "\n5. Them the doc gia";
//		cout << "\n6. Xuat thong tin the doc gia";
//		cout << "\n7. Xuat cac dau sach";
//		cout << "\n8. Xoa Thong tin DOCGIA";
//		cout << "\n9. HIEU CHINH THE DOC GIA";
//		cout << "\n10. Sap Xep Tang Dan Theo ALPHA";
//		cout << "\n11. HIEU CHINH DAU SACH";
//		cout << "\n12. Xoa Dau Sach";
//		cout << "\n13. Tim Thong Tin Sach Theo TENSACH";
//		cout << "\n14. MUON SACH";
//		cout << "\n15. IN DANH SACH MUON TRA CUA DOC GIA";
//		cout << "\n0. Ket thuc";
//
//		cout << "\nNhap lua chon: ";
//		cin >> luachon;
//
//		if (luachon == 1)
//		{
//			//SetColor(3);
//			clrscr();
//			int n = 0;
//			//Nhap_DAUSACH(dsDauSach, n);
//
//		}
//		else if (luachon == 2)
//		{
//			clrscr();
//			//	gotoxy(0, 0);
//			Xuat_DAUSACH(dsDauSach);
//			Them_DanhMucSach(dsDauSach);
//		}
//
//		else if (luachon == 3)
//		{
//			for (int i = 0; i < dsDauSach.n; i++)
//			{
//				cout << "\nMa ISBN: " << dsDauSach.ds[i]->ISBN << "\tTen Sach: " << dsDauSach.ds[i]->TenSach << "\tTac Gia: " << dsDauSach.ds[i]->TacGia
//					<< "\tThe Loai: " << dsDauSach.ds[i]->TheLoai << "\tSo Trang:" << dsDauSach.ds[i]->SoTrang
//					<< "\tNam XB: " << dsDauSach.ds[i]->NamXuatBan << "\tSo Luong Sach: " << dsDauSach.ds[i]->SoLuongSach;
//				cout << "\n\n\t\tDANH MUC CAC SACH\n";
//				for (NODE_SACH *k = dsDauSach.ds[i]->FirstDanhMucSach; k != NULL; k = k->sNext)
//				{
//					cout << "\nMa Sach: " << k->data.MaSach << "\tVi Tri: " << k->data.ViTriSach << "\tTrang Thai: " << k->data.TrangThai;
//				}
//			}
//			system("pause");
//		}
//		else if (luachon == 4)
//		{
//			//gotoxy(45, 10);
//			BaoLoi("Da ghi file thanh cong!");
//
//		}
//		else if (luachon == 5)
//		{
//			cout << "\n\n\t\tNHAP THONG TIN THE DOC GIA\n";
//			Creat_Tree(t);
//		}
//		else if (luachon == 6)
//		{
//			// MA DOC GIA TANG DAN
//			cout << "\n\n\t\tDANH SACH THE DOC GIA\n";
//			//	Xuat_danh_sach_THEDOCGIA(t);
//			system("pause");
//		}
//		else if (luachon == 7)
//		{
//			Xuat_DAUSACH(dsDauSach);
//			system("pause");
//		}
//		else if (luachon == 8)
//		{
//			//system("cls");
//			//	gotoxy(50, 2);
//			cout << "\n\n\t\tDANH SACH THE DOC GIA\n";
//			//	Xuat_danh_sach_THEDOCGIA(t);
//			//SetColor(14);
//			int mathe;
//			cout << "\n\n\t\tNHAP MA THE MUON XOA: ";
//			cin >> mathe;
//			//Xoa_DOCGIA(t, mathe);
//			BaoLoi("XOA THANH CONG!");
//			system("pause");
//		}
//		else if (luachon == 9)
//		{
//			int mt;
//			cout << "\nNHAP MA THE: ";
//			cin >> mt;
//			//Hieu_Chinh_THEDOCGIA(t, mt);
//			system("pause");
//		}
//		else if (luachon == 10)
//		{
//
//		}
//		else if (luachon == 11)
//		{
//			while (getchar() != '\n');
//			char maISBN[6];
//			cout << "\nNhap ma sach : ";
//			gets_s(maISBN);
//			//Hieu_Chinh_DAUSACH(dsDauSach, maISBN);
//		}
//		else if (luachon == 12)
//		{
//			//system("cls");
//			while (getchar() != '\n');
//			char maISBN[6];
//			cout << "\nNhap ma dau sach muon xoa: ";
//			gets_s(maISBN);
//			//	Xoa_DAUSACH(dsDauSach, maISBN);
//		}
//		else if (luachon == 13)
//		{
//			while (getchar() != '\n');
//			char tensach[100]; int vitri;
//			cout << "\n\t\tNHAP TEN SACH: ";
//			gets_s(tensach);
//			//Tim_Kiem_DAUSACH_Theo_TENSACH(dsDauSach, tensach, vitri);
//			system("pause");
//		}
//		else if (luachon == 14)
//		{
//			int chon, mathe;
//			MUONTRA mt;
//			int dangmuon = 0;
//
//			system("cls");
//			cout << "\nNHAP MA THE DOC GIA: ";
//			cin >> mathe;
//			dg = Tim_MATHE(t, mathe);
//			if (dg == NULL)
//			{
//				cout << "\nDOC GIA NAY KHONG TON TAI!";
//			}
//			else
//			{
//				cout << "\n\n\t\tQUAN LY MUON SACH\n";
//				cout << "\n1. MUON SACH";
//				cout << "\n2. TRA SACH";
//				cout << "\n3. IN CAC SACH 1 DOC GIA DANG MUON";
//				cout << "\n4. IN DS MUON TRA CUA 1 DOC GIA";
//				cout << "\n0. End";
//
//				cout << "\nCHON THAO TAC: "; cin >> chon;
//				if (chon == 1)
//				{
//					//MUON_SACH(t, mt, dg, mathe);
//					system("pause");
//				}
//				else if (chon == 2)
//				{
//
//					//	TRA_SACH(t, mathe);
//					//Xuat_DSMUONTRA(t);
//					system("pause");
//				}
//				else if (chon == 3)
//				{
//
//					cout << "\n\n\t\tTHONG TIN DOC GIA CAN TIM\n";
//					cout << "\nMA THE: " << dg->data.MaThe << "\tHO&TEN: " << dg->data.Ho << " " << dg->data.Ten << "\tPHAI: " << dg->data.Phai;
//					cout << "\n\n\t\tDANH SACH MUON TRA";
//					In_Sach_1DG_DangMuon(dg->First, dangmuon);
//					system("pause");
//				}
//				else if (chon == 4)
//				{
//					cout << "\n\n\t\tTHONG TIN DOC GIA CAN TIM\n";
//					cout << "\nMA THE: " << dg->data.MaThe << "\tHO&TEN: " << dg->data.Ho << " " << dg->data.Ten << "\tPHAI: " << dg->data.Phai;
//					cout << "\n\n\t\tDANH SACH MUON TRA";
//					//In_DS_MUONTRA(dg->First);
//					system("pause");
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//		else if (luachon == 15)
//		{
//			//Xuat_DSMUONTRA(t);
//			system("pause");
//		}
//		else
//		{
//			break;
//		}
//	}
//}

int main()
{
	//Ngay_Thang hientai;
	//hientai = Lay_time_Hethong();
	//In_Ngay(hientai);

	dsDauSach.n = 0; 	KhoiTaoTREE(t);
	DocFile_DauSach();
	DocFile_MaThe();
	DocFile_DocGia();
	DocFile_MuonTra();
	GiaoDien_Chinh();


	//GiaoDien_DauSach();
	//Ve_Khung(10, 2, 50, 3);


	//dausach ds;
	//DS_DAUSACH dsds;
	//int key = 0;
	//int check = 1;
	//string soluong;
	//string isbn;
	////while (true)
	////{
	////	soluong = "";
	////	isbn = "";
	////	while (key != KEY_ESC)
	////	{
	////		inChuoiNhap(isbn, 20, ColorCode_White, ColorCode_Red, 10, 3);
	////		inChuoiNhap(soluong, 20, ColorCode_White, ColorCode_Red, 10, 5);
	////		if (check){
	////			if (isbn.size() < 20){
	////				gotoXY(10 + isbn.size(), 3);
	////			}
	////			else{
	////				gotoXY(30, 3);
	////			}
	////		}
	////		else{
	////			if (soluong.size() < 20){
	////				gotoXY(10 + soluong.size(), 5);
	////			}
	////			else{
	////				gotoXY(30, 3);
	////			}
	////		}

	////		key = _getch();
	////		if (check){
	////			nhap(isbn, key, gioiHanSoLuong(isbn, 4) && dieuKienNhapSo(key));
	////			xoa(isbn, key);
	////		}
	////		else{
	////			nhap(soluong, key, gioiHanSoLuong(soluong, 5) && dieuKienNhapSo(key));
	////			xoa(soluong, key);
	////		}
	////		if (key == KEY_CONTROL){
	////			key = _getch();
	////			if (key == KEY_UP || key == KEY_DOWN)
	////				check = !check;
	////		}
	////	}
	////	ds.NamXuatBan = atoi(soluong.c_str());
	////	//ds.ISBN = isbn.c_str();
	////	ds.SoTrang = atoi(isbn.c_str());
	////	dsds.ds[dsds.n++] = new dausach(ds);

	////	for (int i = 0; i < dsds.n; i++){
	////		gotoXY(10, 10 + i);
	////		cout << dsds.ds[i]->SoTrang << " " << dsds.ds[i]->NamXuatBan;
	////	}
	////	key = 0;
	////	check = 1;
	////}
	//system("color F0");
	//fullScreen();
	//RemoveScroll();
	//getScreen();
	//GiaoDien_DauSach();

	//TaoKhungChinh();
	//Sleep(5000);
	//int chon;
	//chon = MenuDong(thucdon);
	//menu();
	//char ma[15], *p;
	//cout << "\nNhap ma: ";
	//gets_s(ma);
	//p = strtok(ma, "_");
	//cout << endl << p;
	//	system("pause");
	return 0;

}