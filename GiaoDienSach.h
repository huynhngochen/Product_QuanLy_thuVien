#pragma once
#pragma warning(disable : 4996)
#include "console.h"

int SoSanhNgay();
void Ghi_File_DauSach();
void GiaoDien_Chinh();
void GiaoDien_DauSach();
void themDauSach();
void GiaoDien_ThemDauSach();
void GiaoDien_HieuChinhDauSach();
void GiaoDien_XoaDauSach();
void GiaoDien_In10DauSach_DuocMuonNhieuNhat();
void GiaoDien_In_DauSach();
void GiaoDien_InDsDauSach();
void GiaoDien_TimKiemDauSach();
void GiaoDien_TimTenSach();
void GiaoDien_TimKiem();
void GiaoDien_InThongTin();
void TimKiem_DauSach_TheoTheLoai();
void GiaoDien_DanhMucSach();
void GiaoDien_ThemDanhMucSach();
void GiaoDien_InDanhMucSach();
void GiaoDien_TheDocGia();
void KhoiTaoTREE();
void Creat_Tree();
void Them_DOCGIA();
int Random_Ngaunhien();
void Xuat_THEDOCGIA();
void Xuat_danh_sach_THEDOCGIA();
void GiaoDien_ThemDocGia();
void GiaoDien_InDS_DocGia_TheoMaThe();
void GiaoDien_InDS_DocGia_TheoHoTenTangDan();
void GiaoDien_InDS_DocGia_QuaHan();
void GiaoDien_InDS_DocGia();
void GiaoDien_HieuChinh_TheDocGia();
void Hieu_Chinh_THEDOCGIA();
NODE_THEDOCGIA *Tim_MATHE();
void GiaoDien_XoaDocGia();
void Tim_Node_The_Mang();
void Xoa_DOCGIA();
void GiaoDien_MuonTra();
void GiaoDien_MuonSach();
void MUON_SACH();
void In_Sach_1DG_DangMuon();
int  KiemTra_TrangThaiMaSach();
void Insert_MuonTra();
void In_Ngay();
Ngay_Thang Lay_time_Hethong();
Ngay_Thang Lay_time_Phai_Tra_Sach();

int Search_Ten();
void GiaoDien_TraSach();
void TRA_SACH();
void In_DS_MuonTra_1DG();
void In_DS_MUONTRA();
void GiaoDien_In_DS_MuonTra();
void GiaoDien_MatSach();
void GhiFile_DauSach();
void DocFile_DauSach();
void DocFile_MaThe();
void GhiFile_MaThe();
void DuyetCay_LNR();
void GhiFile_DocGia();
void DocFile_DocGia();
void DuyetCay_DocMuonTra();
void DocFile_MuonTra();
void DuyetCay_GhiMuonTra();
void GhiFile_MuonTra();
int TimViTri_MaDauSach();

DS_DAUSACH dsDauSach; TREE t; int soluongdocgia = 0;
int *mathe; int soluongmathe;

void DocFile_MaThe()
{
	ifstream filein;
	filein.open("MaThe.TXT", ios_base::in);
	filein >> soluongmathe;
	mathe = new int[soluongmathe];
	filein.ignore();
	for (int i = 0; i < soluongmathe; i++)
	{
		filein >> mathe[i];
	}
	filein.close();
}
void GhiFile_MaThe()
{
	ofstream fileout;
	fileout.open("MaThe.TXT", ios_base::out);
	fileout << soluongmathe<<endl;
	for (int i = 0; i < soluongmathe; i++)
	{
		fileout << mathe[i] << " ";
	}
	fileout.close();
}
// ===================PHAN DANH MUC SACH // TTB==================
int Search(DS_DAUSACH dsDauSach, char ISBN[6])
{
	for (int i = 0; i < dsDauSach.n; i++)
	{
		if (stricmp(dsDauSach.ds[i]->ISBN, ISBN) == 0)
		{
			return i;
		}
	}
	return -1;
}
char *ChuanHoaMaSach(int stt, char madausach[6])
{
	char ma[10], res[10] = {};
	itoa(stt, ma, 10);
	strcat(res, madausach);
	strcat(res, "_");
	strcat(res, ma);
	return res;
}
void Them_Sach(NODE_SACH *&pHead, int stt, char madausach[6])
{
	NODE_SACH *tam = new NODE_SACH;
	char masach[10];
	strcpy(masach, ChuanHoaMaSach(stt, madausach));
	strcpy(tam->data.MaSach, masach);
	strcpy(tam->data.ViTriSach, "kho 1");
	tam->data.TrangThai = 0;
	tam->sNext = NULL;
	if (pHead == NULL){
		pHead = tam;
	}
	else{
		tam->sNext = pHead;
		pHead = tam;
	}
}
void Them_DanhMucSach(DS_DAUSACH &dsDauSach)
{
batphim_esc:
	gotoXY(27, 12);	Xu_Li_Con_Tro_Chi_Vi(true);

	int key = _getch();
	while (true){
		if (key == KEY_ESC){
			clrscr();
			GiaoDien_DanhMucSach();
		}
		else if (key == KEY_ENTER){
			goto ma;
		}
		else
		{
			BaoLoi("NHAN ENTER DE NHAP HOAC ESC DE THOAT");
			cout << "                                      ";
			goto batphim_esc;
		}
	}
ma:
	char maDauSach[6];	int soluong, vitrithem;
	gotoXY(38, 14); cout << "        ";
	gotoXY(38, 14);
	gets_s(maDauSach);
	if (stricmp(maDauSach, "") == 0)
	{
		BaoLoi("MA KHONG DUOC RONG");
		cout << "                    ";
		goto ma;
	}
	vitrithem = Search(dsDauSach, maDauSach);
	if (vitrithem >= 0)
	{
		Ve_Khung(10, 15, 100, 20); liney(16, 34, 19); liney(16, 34, 90); liney(16, 34, 80);
		liney(16, 34, 45); 	liney(16, 34, 65); liney(16, 34, 100);
		gotoXY(11, 16); cout << "MA ISBN";
		gotoXY(11, 17); cout << dsDauSach.ds[vitrithem]->ISBN;
		gotoXY(20, 16); cout << "TEN SACH";
		gotoXY(20, 17); cout << dsDauSach.ds[vitrithem]->TenSach;
		gotoXY(46, 16); cout << "TAC GIA";
		gotoXY(46, 17); cout << dsDauSach.ds[vitrithem]->TacGia;
		gotoXY(66, 16); cout << "THE LOAI";
		gotoXY(66, 17); cout << dsDauSach.ds[vitrithem]->TheLoai;
		gotoXY(82, 16); cout << "NAM X.BAN";
		gotoXY(82, 17); cout << dsDauSach.ds[vitrithem]->NamXuatBan;
		gotoXY(92, 16); cout << "SO TRANG";
		gotoXY(92, 17); cout << dsDauSach.ds[vitrithem]->SoTrang;
		gotoXY(102, 16); cout << "SO LUONG";
		gotoXY(102, 17); cout << dsDauSach.ds[vitrithem]->SoLuongSach;
	nhapsoluong:
		gotoXY(102, 17);
		cin >> soluong;
		fflush(stdin);
		if (soluong <= 0)
		{
			BaoLoi("So luong sach khong duoc bang 0");
			goto nhapsoluong;
		}
		else
		{
			for (int i = dsDauSach.ds[vitrithem]->SoLuongSach + 1; i <= dsDauSach.ds[vitrithem]->SoLuongSach + soluong; i++)
			{
				Them_Sach(dsDauSach.ds[vitrithem]->FirstDanhMucSach, i, dsDauSach.ds[vitrithem]->ISBN);
			}
			dsDauSach.ds[vitrithem]->SoLuongSach += soluong;
			BaoLoi("THEM THANH CONG");
			cout << "                    ";
			gotoXY(102, 17); cout << dsDauSach.ds[vitrithem]->SoLuongSach;
			goto batphim_esc;
		}
	}
	else
	{
		BaoLoi("MA DAU SACH KHONG TON TAI");
		cout << "                            ";
		goto batphim_esc;
	}
}
void Xuat_danhmucsach(NODE_SACH *phead, int vitri){
	clrscr();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(30, 11); cout << "=======================DANH MUC SACH=======================";
	gotoXY(10, 12); HighLight();  cout << "NHAN ESC DE THOAT"; Normal();
	gotoXY(20, 14); cout << "NHAP MA DAU SACH MUON IN: ";
	Ve_Khung(20, 18, 80, 15);
	liney(19, 32, 40); liney(19, 32, 70);
	gotoXY(25, 19); cout << "MA SACH";
	gotoXY(46, 19); cout << "TRANG THAI SACH";
	gotoXY(82, 19); cout << "VI TRI";
	gotoXY(27, 12);
	gotoXY(15, 15); cout << "MA ISBN: ";
	gotoXY(24, 15); cout << "         ";
	gotoXY(24, 15); cout << dsDauSach.ds[vitri]->ISBN;
	gotoXY(30, 15); cout << "TEN SACH: ";
	gotoXY(40, 15); cout << "                          ";
	gotoXY(40, 15); cout << dsDauSach.ds[vitri]->TenSach;
	gotoXY(65, 15); cout << "TAC GIA: ";
	gotoXY(75, 15); cout << "                         ";
	gotoXY(75, 15); cout << dsDauSach.ds[vitri]->TacGia;
	gotoXY(15, 16); cout << "THE LOAI: ";
	gotoXY(25, 16); cout << "                         ";
	gotoXY(25, 16); cout << dsDauSach.ds[vitri]->TheLoai;
	gotoXY(40, 16); cout << "NAM XUAT BAN: ";
	gotoXY(55, 16); cout << "      ";
	gotoXY(55, 16); cout << dsDauSach.ds[vitri]->NamXuatBan;
	gotoXY(65, 16); cout << "SO TRANG: ";
	gotoXY(76, 16); cout << "     ";
	gotoXY(76, 16); cout << dsDauSach.ds[vitri]->SoTrang;
	gotoXY(85, 16); cout << "SO LUONG SACH: ";
	gotoXY(100, 16); cout << "     ";
	gotoXY(100, 16); cout << dsDauSach.ds[vitri]->SoLuongSach;
	int  y = 20;
	for (NODE_SACH *k = phead; k != NULL; k = k->sNext)
	{
		gotoXY(25, y); cout << k->data.MaSach;
		gotoXY(46, y); 
		if (k->data.TrangThai == 0)
		{
			cout << "Cho Muon Duoc";
		}
		else if (k->data.TrangThai == 1)
		{
			cout << "Da Cho Muon";
		}
		else if (k->data.TrangThai == 2)
		{
			cout << "Da Thanh Ly";
		}
		gotoXY(82, y); cout << k->data.ViTriSach;
		y++;
	}
	//system("pause");
}
void In_DanhMucSach(DS_DAUSACH ds)
{
start:
	gotoXY(27, 12);
   Xu_Li_Con_Tro_Chi_Vi(true);

	while (true){
		int key = _getch();
		if (key == KEY_ESC){
			clrscr(); 
			GiaoDien_DanhMucSach();
		}
		else
		{
			goto nhap;
		}
	}
nhap:
	char madausach[6]; int vitri;
	gotoXY(45, 14); cout << "        ";
	gotoXY(45, 14); 	gets_s(madausach);
	vitri = Search(ds, madausach);
	if (vitri >= 0)
	{
		Xuat_danhmucsach(ds.ds[vitri]->FirstDanhMucSach,vitri);				
		goto start;		
	}
	else
	{
		BaoLoi("MA DAU SACH KHONG TON TAI");
		cout << "                           ";
		goto start;
	}
}
// ===============PHAN DAU SACH // TTB=====================
void themDauSach(DS_DAUSACH &dsdausach, DAUSACH ds)
{
	if (dsdausach.n < MAXDS){
		int n;
		for (n = 0; n < dsdausach.n; n++){
			if (strcmp(dsdausach.ds[n]->TheLoai, ds.TheLoai))
			{
				if (strcmp(dsdausach.ds[n]->TenSach, ds.TenSach) > 0)
					break;
			}
			else if (strcmp(dsdausach.ds[n]->TheLoai, ds.TheLoai) > 0)
				break;
		}

		for (int i = dsdausach.n; i > n; i--){
			dsdausach.ds[i] = dsdausach.ds[i - 1];
		}
		dsdausach.n++;
		dsdausach.ds[n] = new DAUSACH(ds);
	}
}

void nhap_dausach(DS_DAUSACH &dsdausach)
{
	Xu_Li_Con_Tro_Chi_Vi(true);
	gotoXY(78, 12);
	int y = 15;
batphim_esc:
	int key = _getch();
	if (key == KEY_ESC){
		GiaoDien_DauSach();
	}
	else
	{
		goto nhap;
	}

nhap:
	DAUSACH ds;
	int namxb, soluong, sotrang;
	dsdausach.ds[dsdausach.n] = new DAUSACH;

	while (dsdausach.n < MAXDS)
	{
	ma:
		gotoXY(45, 1); cout << "                   ";
		gotoXY(11, y); gets_s(ds.ISBN);
		//XoaTatCaDauCach(ds.ISBN);
		Chuan_Hoa_ISBN(ds.ISBN);
		gotoXY(11, y); cout << "        ";
		gotoXY(11, y); cout << ds.ISBN;
		if (stricmp(ds.ISBN, "") == 0)
		{
			BaoLoi("MA KHONG DUOC RONG");
			goto ma;
		}
		if (Search(dsDauSach, ds.ISBN) >= 0)
		{
			BaoLoi("MA DA TON TAI!");
			goto ma;
		}
		if (stricmp(ds.ISBN, "0") == 0)
		{
			gotoXY(60, 35);
			goto batphim_esc;
		}
	tensach:
		gotoXY(45, 1); cout << "                                           ";
		gotoXY(20, y); gets_s(ds.TenSach);
		Chuan_Hoa(ds.TenSach);
		gotoXY(20, y); cout << "                      ";
		gotoXY(20, y); cout << ds.TenSach;
		if (stricmp(ds.TenSach, "") == 0)
		{
			BaoLoi("TEN SACH KHONG DUOC RONG! MOI BAN NHAP LAI");
			//_getch();
			//BaoLoi("                                          ");
			goto tensach;
		}
	tacgia:
		gotoXY(45, 1); cout << "                                          ";
		gotoXY(46, y);
		gets_s(ds.TacGia);
		Chuan_Hoa(ds.TacGia);
		gotoXY(46, y); cout << "                  ";
		gotoXY(46, y); cout << ds.TacGia;
		if (stricmp(ds.TacGia, "") == 0)
		{
			BaoLoi("TAC GIA KHONG DUOC RONG! MOI BAN NHAP LAI");
			goto tacgia;
		}
	theloai:
		gotoXY(45, 1); cout << "                                           ";
		gotoXY(66, y);
		gets_s(ds.TheLoai);
		Chuan_Hoa(ds.TheLoai);
		gotoXY(66, y); cout << "             ";
		gotoXY(66, y); cout << ds.TheLoai;
		if (stricmp(ds.TheLoai, "") == 0)
		{
			BaoLoi("THE LOAI KHONG DUOC RONG! MOI BAN NHAP LAI");
			goto theloai;
		}

		gotoXY(82, y);
		cin >> ds.NamXuatBan;
		fflush(stdin);

		gotoXY(92, y);
		cin >> ds.SoTrang;
		fflush(stdin);

		gotoXY(102, y);
		cin >> ds.SoLuongSach;
		fflush(stdin);

		ds.SoLuotMuon = 0;
		
		gotoXY(92, 35);
	batphim_enter:
		int key = _getch();
		if (key == KEY_ENTER){
			/*strcpy(dsdausach.ds[dsdausach.n]->ISBN, isbn);
			strcpy(dsdausach.ds[dsdausach.n]->TenSach, tensach);
			strcpy(dsdausach.ds[dsdausach.n]->TacGia, tacgia);
			strcpy(dsdausach.ds[dsdausach.n]->TheLoai, theloai);
			dsdausach.ds[dsdausach.n]->NamXuatBan = namxb;
			dsdausach.ds[dsdausach.n]->SoTrang = sotrang;
			dsdausach.ds[dsdausach.n]->SoLuongSach = 0;*/
			if (ds.SoLuongSach > 0)
			{
				for (int i = ds.SoLuongSach; i > 0; i--)
				{
					Them_Sach(ds.FirstDanhMucSach, i, ds.ISBN);
				}
				//dsdausach.ds[dsdausach.n]->SoLuongSach += soluong;
				themDauSach(dsdausach, ds);
				//y = 15 + dsdausach.n;		
				y++;
				BaoLoi("LUU THANH CONG");
				gotoXY(45, 1); cout << "                       ";
			}
			else
			{
				ds.FirstDanhMucSach = NULL;				
				themDauSach(dsdausach, ds);	
				//y = 15 + dsdausach.n;
				y++;
				BaoLoi("LUU THANH CONG");
				gotoXY(45, 1); cout << "                      ";
			}
		}
		else{
			BaoLoi("NHAN ENTER DE LUU");
			gotoXY(45, 1); cout << "                          ";
			goto batphim_enter;
		}
		/*dsdausach.n++;
		y++;*/
		//y++;
		goto nhap;
	}
}
void Xuat_thong_tin_sach(NODE_SACH *pHead)
{
	cout << "\n\t\t\tDANH MUC SACH\n";
	for (NODE_SACH *k = pHead; k != NULL; k = k->sNext)
	{
		cout << "\nMa sach: " << k->data.MaSach << "\tVi tri:" << k->data.ViTriSach << "\tTrang thai: " << k->data.TrangThai;
	}
}
void Xuat_DAUSACH(DS_DAUSACH dsDauSach)
{
	int y = 15;
	for (int i = 0; i < dsDauSach.n; i++)
	{
		gotoXY(11, y); cout << dsDauSach.ds[i]->ISBN;
		gotoXY(20, y); cout << dsDauSach.ds[i]->TenSach;
		gotoXY(46, y); cout << dsDauSach.ds[i]->TacGia;
		gotoXY(66, y); cout << dsDauSach.ds[i]->TheLoai;
		gotoXY(82, y); cout << dsDauSach.ds[i]->NamXuatBan;
		gotoXY(92, y); cout << dsDauSach.ds[i]->SoTrang;
		gotoXY(102, y); cout << dsDauSach.ds[i]->SoLuongSach;
		y++;
	}
}
void Hieu_Chinh_DAUSACH(DS_DAUSACH &dsDauSach)
{
start:
	gotoXY(67, 12);
	Xu_Li_Con_Tro_Chi_Vi(true);
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC)
		{
			GiaoDien_DauSach();
		}
		else
		{
			goto nhap_isbn;
		}
	}
nhap_isbn:
	char maISBN[6];
	DAUSACH dausach;
	gotoXY(11, 15);
	gets_s(maISBN);
	int i = Search(dsDauSach, maISBN);
	if (i == -1)
	{
		BaoLoi("KHONG TON TAI MA DAU SACH!!");
		cout << "                             ";
		goto start;
	}
	else
	{
		//cout info
		gotoXY(11, 15); cout << dsDauSach.ds[i]->ISBN;
		gotoXY(20, 15); cout << dsDauSach.ds[i]->TenSach;
		gotoXY(46, 15); cout << dsDauSach.ds[i]->TacGia;
		gotoXY(66, 15); cout << dsDauSach.ds[i]->TheLoai;
		gotoXY(82, 15); cout << dsDauSach.ds[i]->NamXuatBan;
		gotoXY(92, 15); cout << dsDauSach.ds[i]->SoTrang;
		gotoXY(102, 15); cout << dsDauSach.ds[i]->SoLuongSach;
		int kt = 0;

		while (true){
		batphim:
			int key = _getch();
			if (key == KEY_RIGHT) {
				if (kt == 0) {
					kt = 1;
					gotoXY(20, 15);
				}
				else if (kt == 1) {
					kt = 2;
					gotoXY(46, 15);
				}
				else if (kt == 2) {
					kt = 3;
					gotoXY(66, 15);
				}
				else if (kt == 3) {
					kt = 4;
					gotoXY(82, 15);
				}
				else if (kt == 4) {
					kt = 5;
					gotoXY(92, 15);
				}				
				else if (kt == 5){
					kt = 6;
					gotoXY(102, 15);
				}
				else if (kt == 6){
					kt = 0;
					gotoXY(11, 15);
				}
			}
			else if (key == KEY_LEFT) {
				if (kt == 0){
					kt = 6;
					gotoXY(102, 15);
				}
				if (kt == 6) {
					kt = 5;
					gotoXY(92, 15);
				}
				else if (kt == 5) {
					kt = 4;
					gotoXY(82, 15);
				}
				else if (kt == 4) {
					kt = 3;
					gotoXY(66, 15);
				}
				else if (kt == 3) {
					kt = 2;
					gotoXY(46, 15);
				}
				else if (kt == 2) {
					kt = 1;
					gotoXY(20, 15);
				}
				else if (kt == 1){
					kt = 0;
					gotoXY(11, 15);
				}
			}
			else if (key == KEY_ENTER){
				if (kt == 0)
				{
					BaoLoi("KHONG HIEU CHINH MA ISBN!");
					cout << "                         ";
					goto batphim;
				}
				else if (kt == 1){
					gotoXY(20, 15); cout << "                    ";
				TENSACH:
					gotoXY(20, 15);
					gets_s(dausach.TenSach); 
					if (stricmp(dausach.TenSach, "") == 0)
					{
						BaoLoi("TEN SACH KHONG DUOC RONG");
						cout << "                        ";
						goto TENSACH;
					}
					Chuan_Hoa(dausach.TenSach); strcpy(dsDauSach.ds[i]->TenSach, dausach.TenSach);
					gotoXY(20 ,15); cout << dsDauSach.ds[i]->TenSach;		
					goto batphim;
				}
				else if (kt == 2){
					gotoXY(46, 15); cout << "             ";
				TACGIA:
					gotoXY(46, 15);
					gets_s(dausach.TacGia);
					if (stricmp(dausach.TacGia, "") == 0)
					{
						BaoLoi("TAC GIA KHONG DUOC RONG");
						cout << "                        ";
						goto TACGIA;
					}
					Chuan_Hoa(dausach.TacGia); strcpy(dsDauSach.ds[i]->TacGia, dausach.TacGia);
					gotoXY(46, 15); cout << dsDauSach.ds[i]->TacGia;
					goto batphim;
				}
				else if (kt == 3){
					gotoXY(66, 15); cout << "            ";
				THELOAI:
					gotoXY(66, 15); gets_s(dausach.TheLoai); 
					if (stricmp(dausach.TheLoai, "") == 0)
					{
						BaoLoi("THE LOAI KHONG DUOC RONG");
						cout << "                         ";
						goto THELOAI;
					}
					Chuan_Hoa(dausach.TheLoai); strcpy(dsDauSach.ds[i]->TheLoai, dausach.TheLoai);
					gotoXY(66, 15); cout << dsDauSach.ds[i]->TheLoai;
					goto batphim;
				}
				else if (kt == 4){
					gotoXY(82, 15); cout << "     ";
					gotoXY(82, 15); cin >> dausach.NamXuatBan; fflush(stdin);
					dsDauSach.ds[i]->NamXuatBan = dausach.NamXuatBan;
					goto batphim;
				}
				else if (kt == 5){
					gotoXY(77, 15); cout << "     ";
					gotoXY(77, 15); cin >> dausach.SoTrang; fflush(stdin);
					dsDauSach.ds[i]->SoTrang = dausach.SoTrang;
					goto batphim;
				}
				else if (kt == 6)
				{
					BaoLoi("VAO QL DANH MUC SACH DE THEM SACH!");
					cout << "                                    ";
					goto batphim;
				}
			}
			else if (key == KEY_ESC)
			{
				clrscr();
				GiaoDien_DauSach();
			}
		}
	}
}
void Xoa_DAUSACH(DS_DAUSACH &dsDauSach)
{
start:
	gotoXY(47, 12);	Xu_Li_Con_Tro_Chi_Vi(true);
	while (true){
		
		int key = _getch();
		if (key == KEY_ESC){
			GiaoDien_DauSach();
		}
		else{
			goto nhap;
		}
	}
nhap:
	char madausach[6];
	gotoXY(70, 15); cout << "           ";
	gotoXY(70, 15);  gets_s(madausach);
	int i = Search(dsDauSach, madausach);
	if (i == -1)
	{
		BaoLoi("MA DAU SACH KHONG TON TAI!!");
		cout << "                            ";
		goto start;
	}
	else
	{
		gotoXY(45, 1);
		cout << "BAN CO CHAC MUON XOA HAY KHONG (c/k): ";
		char c = toupper(getche());
		if (c == 'C'){
			for (int j = i + 1; j < dsDauSach.n; j++)
			{
				dsDauSach.ds[j - 1] = dsDauSach.ds[j];
			}
			dsDauSach.n--;
			BaoLoi("XOA THANH CONG!");
			cout << "                 ";
			goto start;
		}
		else
			gotoXY(45, 1);
			cout << "                                            ";
			goto start;
	}
}
void TimKiem_DauSach_TheoTheLoai(DS_DAUSACH dsDauSach)
{
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_DauSach;
		}
		else
		{
			goto THELOAI;
		}
	}
THELOAI:
	char* binh[50];
	bool flag = false;
	int tmp = 0;
	int k = 0;
	for (int i = 0; i < dsDauSach.n; i++)
	{
		flag = false;
		for (int j = 0; j <= k; j++)
		{
			binh[tmp] = "";
			if (strcmp(dsDauSach.ds[i]->TheLoai, binh[j]) == 0)
			{
				flag = true;
				break;

			}
			tmp++;
		}
		if (flag == false)
		{
			binh[k] = dsDauSach.ds[i]->TheLoai;
			k++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		gotoXY(20, 16 + i);
		cout << binh[i];
	}
nhaptheloai:
	char theloai[50];
	while (getchar() != '\n');
	gotoXY(36, 11);
	Xu_Li_Con_Tro_Chi_Vi(1); gets_s(theloai);
	if (strcmp(theloai, " ") == 0)
	{
		BaoLoi("THE LOAI KHONG DUOC RONG!");
		goto nhaptheloai;
	}
	Chuan_Hoa(theloai);
	gotoXY(36, 11); cout << theloai;
	gotoXY(82, 14); cout << theloai;
	DAUSACH *a[100];
	int m = 0;
	for (int i = 0; i < dsDauSach.n; i++)
	{
		if (strcmp(dsDauSach.ds[i]->TheLoai, theloai) == 0)
		{
			a[m] = dsDauSach.ds[i];
			m++;
		}
	}
	for (int i = 0; i < m - 1; i++)
	{
		int y = 18;
		gotoXY(53, y);
		cout << a[i]->TenSach;
		y++;
	}
	DAUSACH *tamp;
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			char s1[50], s2[50];
			strcpy(s1, a[i]->TenSach);
			strcpy(s2, a[j]->TenSach);
			if (strcmp(s1, s2) > 0)
			{
				tamp = a[i];
				a[i] = a[j];
				a[j] = tamp;
			}
		}
	}
	int c = 50;
	int b = 16;
	for (int i = 0; i < m; i++)
	{
		gotoXY(c, b);
		cout << a[i]->TenSach;
		b += 2;
	}
	Xu_Li_Con_Tro_Chi_Vi(false);
	while (true)
	{
		int key = getch();
		if (key == KEY_ENTER)
		{
			clrscr();
			GiaoDien_TimKiemDauSach();
		}
		else if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_DauSach();
		}
	}

}


void Tim_TenSach(DS_DAUSACH dsDauSach)
{
	/*gotoXY(33, 13);
	Xu_Li_Con_Tro_Chi_Vi(true);*/
start:
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_DauSach;
		}
		else
		{
			goto NHAPTENSACH;
		}
	}
NHAPTENSACH:
	char tensach[100];
	gotoXY(33, 11);
	Xu_Li_Con_Tro_Chi_Vi(true);
	gets_s(tensach);
	Chuan_Hoa(tensach);
	if (strcmp(tensach, "") == 0)
	{
		BaoLoi("TEN SACH KHONG DUOC BO TRONG!");
		goto NHAPTENSACH;
	}
	int x = 18;
	int y = 17;
	DAUSACH *binh[50];
	bool flag = false;
	int dem = 0;
	for (int i = 0; i < dsDauSach.n; i++)
	{
		char *res = strstr(dsDauSach.ds[i]->TenSach, tensach);
		if (res != NULL)
		{
			flag = true;
			binh[dem] = dsDauSach.ds[i];
			gotoXY(x, y);
			cout << dsDauSach.ds[i]->TenSach;
			gotoXY(55, y);
			cout << dsDauSach.ds[i]->ISBN;
			y = y + 2;
			dem++;
		}
	}
	if (flag == false)
	{
		BaoLoi("KHONG CO SACH CAN TIM!");
		goto NHAPTENSACH;
	}
nhapma:
	char ma[6];
	gotoXY(33, 11);
	cout << "                                             ";
	Xu_Li_Con_Tro_Chi_Vi(true);
	gotoXY(16, 11);
	cout << "Nhap ma dau sach cua sach muon xem thong tin: ";
	gets_s(ma);
	Chuan_Hoa_ISBN(ma);
	if (strcmp(ma, "") == 0)
	{
		BaoLoi("MA DAU SACH KHONG DUOC BO TRONG!");
		goto nhapma;
	}
	for (int i = 0; i < dem; i++)
	{
		if (strcmp(binh[i]->ISBN, ma) == 0)
		{
			clrscr();
			GiaoDien_InThongTin();
			gotoXY(32, 14); cout << binh[i]->ISBN;
			gotoXY(32, 15); cout << binh[i]->TenSach;
			gotoXY(32, 16); cout << binh[i]->TacGia;
			gotoXY(32, 17); cout << binh[i]->NamXuatBan;
			gotoXY(32, 18); cout << binh[i]->TheLoai;
			int y = 19;
			for (node_sach *p = dsDauSach.ds[i]->FirstDanhMucSach; p != NULL; p = p->sNext)
			{
				gotoXY(32, y);
				cout << p->data.MaSach;
				gotoXY(50, y);
				if (p->data.TrangThai == 0)
				{
					cout << "Cho Muon Duoc";
				}
				else if (p->data.TrangThai == 1)
				{
					cout << "Da Cho Muon";
				}
				else if (p->data.TrangThai == 2)
				{
					cout << "Da Thanh Ly";
				}
				y++;
			}
			int key = getch();
			if (key == KEY_ENTER)
			{
				GiaoDien_TimTenSach();
			}
			else if (key == KEY_ESC)
			{
				GiaoDien_DauSach();
			}
		}
	}
	BaoLoi("MA DAU SACH KHONG HOP LE!");
}

void GhiFile_DauSach()
{
	ofstream fileout;
	fileout.open("DS_DAUSACH.TXT", ios_base::out);
	fileout << dsDauSach.n << endl;

	for (int i = 0; i < dsDauSach.n; i++)
	{
		fileout << dsDauSach.ds[i]->ISBN << ","
			<< dsDauSach.ds[i]->TenSach << ","
			<< dsDauSach.ds[i]->TacGia << ","
			<< dsDauSach.ds[i]->TheLoai << ","
			<< dsDauSach.ds[i]->NamXuatBan << ","
			<< dsDauSach.ds[i]->SoTrang << ","
			<< dsDauSach.ds[i]->SoLuongSach << ","
			<< dsDauSach.ds[i]->SoLuotMuon << endl;
	}
	fileout.close();
}
void DocFile_DauSach()
{
	ifstream filein;
	filein.open("DS_DAUSACH.TXT", ios_base::in);

	int n;
	filein >> n;
	filein.ignore();
	for (int i = 0; i < n; i++)
	{
		DAUSACH ds;
		filein.getline(ds.ISBN, 6,',');
		filein.getline(ds.TenSach, 100, ',');
		filein.getline(ds.TacGia, 50, ',');
		filein.getline(ds.TheLoai, 50, ',');
		filein >> ds.NamXuatBan;
		filein.seekg(1, 1);
		filein >> ds.SoTrang;
		filein.seekg(1, 1);
		filein >> ds.SoLuongSach;
		filein.seekg(1, 1);
		filein >> ds.SoLuotMuon;
		filein.ignore();
		if (ds.SoLuongSach > 0)
		{
			for (int i = ds.SoLuongSach; i > 0; i--)
			{
				Them_Sach(ds.FirstDanhMucSach, i, ds.ISBN);
			}
			//dsdausach.ds[dsdausach.n]->SoLuongSach += soluong;
			themDauSach(dsDauSach, ds);
			//y = 15 + dsdausach.n;
			//BaoLoi("LUU THANH CONG");
			//goto nhap;
		}
		else
		{
			ds.FirstDanhMucSach = NULL;
			themDauSach(dsDauSach, ds);
		}
	}
	filein.close();
}
void GiaoDien_TimKiem()
{
	clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(35, 13); cout << "=================TIM KIEM THONG TIN================";
	Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "   THEO THE LOAI   ";
	Ve_Khung(50, 23, 20, 2); gotoXY(51, 24); cout << "   THEO TEN SACH   ";
	HighLight();
	Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "   THEO THE LOAI   ";
	Normal();
	Xu_Li_Con_Tro_Chi_Vi(false);
	int kt = 1;

	while (true)
	{
		int key = _getch();
		if (key == KEY_DOWN)
		{
			if (kt == 1){
				kt = 2;
			}
			else if (kt == 2){
				kt = 1;
			}
		}
		else if (key == KEY_UP)
		{
			if (kt == 1)
			{
				kt = 2;
			}
			else if (kt == 2)
			{
				kt = 1;
			}
		}
		else if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_DauSach();
		}

		if (kt == 1)
		{
			HighLight();
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "   THEO THE LOAI   ";
			Normal();
			Ve_Khung(50, 23, 20, 2); gotoXY(51, 24); cout << "   THEO TEN SACH   ";
		}
		else if (kt == 2)
		{
			HighLight();
			Ve_Khung(50, 23, 20, 2); gotoXY(51, 24); cout << "   THEO TEN SACH   ";
			Normal();
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "   THEO THE LOAI   ";
		}
		if (key == KEY_ENTER)
		{
			if (kt == 1)
			{
				clrscr();
				GiaoDien_TimKiemDauSach();
			}
			else if (kt == 2)
			{
				clrscr();
				GiaoDien_TimTenSach();
			}
		}
	}
}

void GiaoDien_TimTenSach()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	Ve_Khung(15, 13, 90, 20);
	gotoXY(16, 11); cout << "Nhap ten sach: ";
	gotoXY(30, 15); cout << "Ten sach";
	liney(15, 30, 50);
	linex(18, 70, 16);
	gotoXY(56, 15); cout << "Ma ISBN";
	HighLight();
	gotoXY(15, 34); cout << "NHAN ESC DE THOAT";
	Normal();
	Tim_TenSach(dsDauSach);

}

void GiaoDien_TimKiemDauSach()
{
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	Ve_Khung(15, 13, 90, 20);

	gotoXY(17, 14); cout << "Danh sach cac the loai sach";
	liney(14, 15, 46);
	liney(15, 32, 46);
	linex(16, 105, 15);
	Normal();
	gotoXY(16, 11);   cout << "Nhap the loai sach: ";
	gotoXY(51, 14);   cout << "Danh sach sach thuoc the loai: ";
	TimKiem_DauSach_TheoTheLoai(dsDauSach);
	HighLight();
	gotoXY(15, 34); cout << "NHAN ESC DE THOAT";
	Normal();
	HighLight();
	gotoXY(35, 34); cout << "NHAN ENTER DE TIEP TUC";
	Normal();

}

void GiaoDien_InThongTin()
{
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	Ve_Khung(15, 13, 90, 20);
	gotoXY(16, 14); cout << "Ma ISBN: ";
	gotoXY(16, 15); cout << "Ten sach: ";
	gotoXY(16, 16); cout << "Tac gia: ";
	gotoXY(16, 17); cout << "Nam xuat ban: ";
	gotoXY(16, 18); cout << "The loai: ";
	gotoXY(16, 19); cout << "Cac ma sach: ";
}

void GiaoDien_ThemDauSach()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	Ve_Khung(10, 13, 100, 20); liney(14, 32, 19); liney(14, 32, 90); liney(14, 32, 80);
	liney(14, 32, 45); 	liney(14, 32, 65); liney(14, 32, 100);
	gotoXY(12, 14); cout << "MA ISBN";
	gotoXY(20, 14); cout << "TEN SACH";
	gotoXY(46, 14); cout << "TAC GIA";
	gotoXY(66, 14); cout << "THE LOAI";
	gotoXY(81, 14); cout << "NAM X.BAN";
	gotoXY(91, 14); cout << "SO TRANG";
	gotoXY(101, 14); cout << "SO LUONG";
	HighLight();
	gotoXY(15, 12); cout << "NHAN 0 DE KET THUC NHAP";
	Normal();
	HighLight(); gotoXY(60, 12); cout << "NHAN ENTER DE NHAP";
	Normal();
	HighLight();
	gotoXY(25, 35); cout << "NHAN ESC DE QUAY VE GIAO DIEN CHINH";
	Normal();
	HighLight();
	gotoXY(75, 35); cout << "NHAN ENTER DE LUU";
	Normal();	
	nhap_dausach(dsDauSach);	
	
}
void GiaoDien_HieuChinhDauSach()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	Ve_Khung(10, 13, 100, 20); liney(14, 32, 19); liney(14, 32, 90); liney(14, 32, 80);
	liney(14, 32, 45); 	liney(14, 32, 65); liney(14, 32, 100);
	gotoXY(12, 14); cout << "MA ISBN";
	gotoXY(20, 14); cout << "TEN SACH";
	gotoXY(46, 14); cout << "TAC GIA";
	gotoXY(66, 14); cout << "THE LOAI";
	gotoXY(81, 14); cout << "NAM X.BAN";
	gotoXY(91, 14); cout << "SO TRANG";
	gotoXY(101, 14); cout << "SO LUONG";
	HighLight();
	gotoXY(35, 12); cout << "NHAN PHIM BAT KY DE BAT DAU NHAP";
	Normal();
	HighLight();
	gotoXY(50, 35); cout << "ESC DE THOAT";
	Normal();
	Hieu_Chinh_DAUSACH(dsDauSach);
}
void GiaoDien_XoaDauSach()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35); // khung to
	Ve_Khung(32, 13, 60, 10); // khung nho
	HighLight();
	gotoXY(30, 12); cout << "NHAN ESC DE THOAT"; 
	Normal();
	HighLight();
	gotoXY(65, 12); cout << "NHAN PHIM BAT KY DE NHAP";
	Normal();
	gotoXY(40, 15); cout << "NHAP MA ISBN DE XOA DAU SACH:";
	Xoa_DAUSACH(dsDauSach);

}
void GiaoDien_InDSDauSach()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	Ve_Khung(10, 13, 100, 20); liney(14, 32, 19); liney(14, 32, 90); liney(14, 32, 80);
	liney(14, 32, 45); 	liney(14, 32, 65); liney(14, 32, 100);
	HighLight();
	gotoXY(15, 12); cout << "NHAN ESC DE THOAT";
	Normal();
	gotoXY(12, 14); cout << "MA ISBN";
	gotoXY(20, 14); cout << "TEN SACH";
	gotoXY(46, 14); cout << "TAC GIA";
	gotoXY(66, 14); cout << "THE LOAI";
	gotoXY(81, 14); cout << "NAM X.BAN";
	gotoXY(91, 14); cout << "SO TRANG";
	gotoXY(101, 14); cout << "SO LUONG";
	Xuat_DAUSACH(dsDauSach);
	while (true){
	batphim:
		gotoXY(32, 12);  Xu_Li_Con_Tro_Chi_Vi(true);
		int key = _getch();
		if (key == KEY_ESC){
			clrscr();
			GiaoDien_In_DauSach();
		}
		else{
			BaoLoi("NHAN ESC DE THOAT");
			cout << "                    ";
			goto batphim;
		}
	}
}
void TaoMangTam_InDauSach(DAUSACH *arr, int &m)
{
	for (int i = 0; i < dsDauSach.n; i++)
	{		
		arr[i]= *dsDauSach.ds[i];
	}
	m = dsDauSach.n;
}
void SapXep_DauSachGiamDan()
{
	int m = 0; DAUSACH x;  
	DAUSACH *tam = new DAUSACH[dsDauSach.n];
	TaoMangTam_InDauSach(tam, m);

	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (tam[j].SoLuotMuon > tam[i].SoLuotMuon)
			{
				x = tam[j];
				tam[j] = tam[i];
				tam[i] = x;
			}
		}
	}

	int y = 15;
	for (int i = 0; i < 10; i++)
	{
		gotoXY(11, y); cout << tam[i].ISBN;
		gotoXY(20, y); cout << tam[i].TenSach;
		gotoXY(46, y); cout << tam[i].TacGia;
		gotoXY(66, y); cout << tam[i].TheLoai;
		gotoXY(82, y); cout << tam[i].NamXuatBan;
		gotoXY(92, y); cout << tam[i].SoTrang;
		gotoXY(102, y); cout << tam[i].SoLuongSach;
		y++;
	}
}
void GiaoDien_In10DauSach_DuocMuonNhieuNhat()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	Ve_Khung(10, 13, 100, 20); liney(14, 32, 19); liney(14, 32, 90); liney(14, 32, 80);
	liney(14, 32, 45); 	liney(14, 32, 65); liney(14, 32, 100);
	HighLight();
	gotoXY(15, 12); cout << "NHAN ESC DE THOAT";
	Normal();
	gotoXY(12, 14); cout << "MA ISBN";
	gotoXY(20, 14); cout << "TEN SACH";
	gotoXY(46, 14); cout << "TAC GIA";
	gotoXY(66, 14); cout << "THE LOAI";
	gotoXY(81, 14); cout << "NAM X.BAN";
	gotoXY(91, 14); cout << "SO TRANG";
	gotoXY(101, 14); cout << "SO LUONG";
	SapXep_DauSachGiamDan();
	while (true){
	batphim:
		gotoXY(32, 12);  Xu_Li_Con_Tro_Chi_Vi(true);
		int key = _getch();
		if (key == KEY_ESC){
			clrscr();
			GiaoDien_In_DauSach();
		}
		else{
			BaoLoi("NHAN ESC DE THOAT");
			cout << "                    ";
			goto batphim;
		}
	}
}
void GiaoDien_In_DauSach()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(30, 13); cout << "=======================IN DAU SACH=======================";
	Ve_Khung(40, 17, 40, 2); gotoXY(41, 18); cout << "               IN DS DAU SACH          ";
	Ve_Khung(40, 21, 40, 2); gotoXY(41, 22); cout << " IN 10 DAU SACH DUOC MUON NHIEU NHAT   ";

	HighLight();
	Ve_Khung(40, 17, 40, 2); gotoXY(41, 18); cout << "               IN DS DAU SACH          ";
	Normal();
	Xu_Li_Con_Tro_Chi_Vi(false);
	int kt = 1;

	while (true)
	{
		int key = _getch();
		if (key == KEY_UP)
		{
			if (kt == 1)
			{
				kt = 2;
			}
			else if (kt == 2)
			{
				kt = 1;
			}
		}
		else if (key == KEY_DOWN)
		{
			if (kt == 1)
			{
				kt = 2;
			}
			else if (kt == 2)
			{
				kt = 1;
			}
		}
		else if (key == KEY_ESC)
		{
			GiaoDien_DauSach();
		}
		if (kt == 1)
		{
			HighLight();
			Ve_Khung(40, 17, 40, 2); gotoXY(41, 18); cout << "               IN DS DAU SACH          ";
			Normal();
			Ve_Khung(40, 21, 40, 2); gotoXY(41, 22); cout << " IN 10 DAU SACH DUOC MUON NHIEU NHAT   ";
		}
		else if (kt == 2)
		{
			HighLight();
			Ve_Khung(40, 21, 40, 2); gotoXY(41, 22); cout << " IN 10 DAU SACH DUOC MUON NHIEU NHAT   ";
			Normal();
			Ve_Khung(40, 17, 40, 2); gotoXY(41, 18); cout << "               IN DS DAU SACH          ";		
		}
		if (key == KEY_ENTER)
		{
			if (kt == 1)
			{
				clrscr();
				GiaoDien_InDSDauSach();
			}
			else if (kt == 2)
			{
				clrscr();
				GiaoDien_In10DauSach_DuocMuonNhieuNhat();
			}
		}
	}
}

void GiaoDien_DauSach()
{
	clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(30, 13); cout << "=======================QUAN LY DAU SACH=======================";
	Ve_Khung(50, 15, 20, 2); gotoXY(51, 16); cout << "       THEM        ";
	Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "        SUA        ";
	Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        XOA        ";
	Ve_Khung(50, 24, 20, 2); gotoXY(51, 25); cout << "     IN DAU SACH   ";
	Ve_Khung(50, 27, 20, 2); gotoXY(51, 28); cout << "      TIM KIEM     ";

	HighLight();
	Ve_Khung(50, 15, 20, 2); gotoXY(51, 16); cout << "       THEM        ";
	Normal();
	Xu_Li_Con_Tro_Chi_Vi(false);
	int kt = 1;

	while (true)
	{
		int key = _getch();
		if (key == KEY_DOWN)
		{
			if (kt == 1){
				kt = 2;
			}
			else if (kt == 2){
				kt = 3;
			}
			else if (kt == 3){
				kt = 4;
			}
			else if (kt == 4){
				kt = 5;
			}
			else if (kt == 5){
				kt = 1;
			}
		}
		// bat phim len
		else if (key == KEY_UP){
			if (kt == 1){
				kt = 5;
			}
			else if (kt == 2){
				kt = 1;
			}
			else if (kt == 3){
				kt = 2;
			}
			else if (kt == 4){
				kt = 3;
			}
			else if (kt == 5){
				kt = 4;
			}
		}
		else if (key == KEY_ENTER)
		{
			if (kt == 1)
			{
				clrscr();
				GiaoDien_ThemDauSach();
			}
			else if (kt == 2){
				clrscr();
				GiaoDien_HieuChinhDauSach();
			}
			else if (kt == 3){
				clrscr();
				GiaoDien_XoaDauSach();
			}
			else if (kt == 4){
				clrscr();
				GiaoDien_In_DauSach();
			}
			else if (kt == 5){
				clrscr();
				GiaoDien_TimKiem();
			}
		}
		else if (key == KEY_ESC){
			clrscr();
			GiaoDien_Chinh();
		}
		if (kt == 1){
			HighLight();
			Ve_Khung(50, 15, 20, 2); gotoXY(51, 16); cout << "       THEM        ";
			Normal();
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "        SUA        ";
			Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        XOA        ";
			Ve_Khung(50, 24, 20, 2); gotoXY(51, 25); cout << "     IN DAU SACH   ";
			Ve_Khung(50, 27, 20, 2); gotoXY(51, 28); cout << "      TIM KIEM     ";
		}
		else if (kt == 2){
			HighLight();
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "        SUA        ";
			Normal();
			Ve_Khung(50, 15, 20, 2); gotoXY(51, 16); cout << "       THEM        ";
			Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        XOA        ";
			Ve_Khung(50, 24, 20, 2); gotoXY(51, 25); cout << "     IN DAU SACH   ";
			Ve_Khung(50, 27, 20, 2); gotoXY(51, 28); cout << "      TIM KIEM     ";
		}
		else if (kt == 3){
			HighLight();
			Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        XOA        ";
			Normal();
			Ve_Khung(50, 15, 20, 2); gotoXY(51, 16); cout << "       THEM        ";
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "        SUA        ";
			Ve_Khung(50, 24, 20, 2); gotoXY(51, 25); cout << "     IN DAU SACH   ";
			Ve_Khung(50, 27, 20, 2); gotoXY(51, 28); cout << "      TIM KIEM     ";
		}
		else if (kt == 4){
			HighLight();
			Ve_Khung(50, 24, 20, 2); gotoXY(51, 25); cout << "     IN DAU SACH   ";
			Normal();
			Ve_Khung(50, 15, 20, 2); gotoXY(51, 16); cout << "       THEM        ";
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "        SUA        ";
			Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        XOA        ";
			Ve_Khung(50, 27, 20, 2); gotoXY(51, 28); cout << "      TIM KIEM     ";
		}
		else if (kt == 5){
			HighLight();
			Ve_Khung(50, 27, 20, 2); gotoXY(51, 28); cout << "      TIM KIEM     ";
			Normal();
			Ve_Khung(50, 15, 20, 2); gotoXY(51, 16); cout << "       THEM        ";
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "        SUA        ";
			Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        XOA        ";
			Ve_Khung(50, 24, 20, 2); gotoXY(51, 25); cout << "     IN DAU SACH   ";
		}
	}
}
void GiaoDien_ThemDanhMucSach()
{
	clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(30, 11); cout << "=======================THEM DANH MUC SACH=======================";	
	gotoXY(10, 12); HighLight();  cout << "NHAN ESC DE THOAT"; Normal();
	gotoXY(60, 12); HighLight(); cout << "NHAN ENTER DE NHAP"; Normal();
	gotoXY(10, 14); cout << "NHAP MA DAU SACH MUON THEM: ";

	Them_DanhMucSach(dsDauSach);
}
void GiaoDien_InDanhMucSach()
{
	clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(30, 11); cout << "=======================DANH MUC SACH=======================";
	gotoXY(10, 12); HighLight();  cout << "NHAN ESC DE THOAT"; Normal();
	gotoXY(20, 14); cout << "NHAP MA DAU SACH MUON IN: ";
	Ve_Khung(20, 18, 80, 15);
	liney(19, 32, 40); liney(19, 32, 70);
	gotoXY(25, 19); cout << "MA SACH";
	gotoXY(46, 19); cout << "TRANG THAI SACH";
	gotoXY(82, 19); cout << "VI TRI";

	In_DanhMucSach(dsDauSach);
}
void GiaoDien_DanhMucSach()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(30, 13); cout << "=======================QUAN LY DANH MUC SACH=======================";
	Ve_Khung(50, 17, 25, 2); gotoXY(51, 18); cout << "          THEM         ";
	Ve_Khung(50, 21, 25, 2); gotoXY(51, 22); cout << "    IN DANH MUC SACH   ";

	HighLight();
	Ve_Khung(50, 17, 25, 2); gotoXY(51, 18); cout << "          THEM          ";
	Normal();
	Xu_Li_Con_Tro_Chi_Vi(false);
	int kt = 1;

	while (true)
	{
		int key = _getch();
		if (key == KEY_UP)
		{
			if (kt == 1){
				kt = 2;
			}
			else if (kt == 2){
				kt = 1;
			}
		}
		else if (key == KEY_DOWN){
			if (kt == 1){
				kt = 2;
			}
			else if (kt == 2){
				kt = 1;
			}
		}
		if (kt == 1)
		{
			HighLight();
			Ve_Khung(50, 17, 25, 2); gotoXY(51, 18); cout << "          THEM          ";
			Normal();
			Ve_Khung(50, 21, 25, 2); gotoXY(51, 22); cout << "    IN DANH MUC SACH    ";
		}
		else if (kt == 2)
		{
			HighLight();
			Ve_Khung(50, 21, 25, 2); gotoXY(51, 22); cout << "    IN DANH MUC SACH    ";
			Normal();
			Ve_Khung(50, 17, 25, 2); gotoXY(51, 18); cout << "          THEM          ";
		}
		if (key == KEY_ENTER){
			if (kt == 1){
				clrscr();
				GiaoDien_ThemDanhMucSach();
			}
			else if (kt == 2){
				clrscr();
				GiaoDien_InDanhMucSach();
			}
		}
		else if (key == KEY_ESC){
			clrscr();
			GiaoDien_Chinh();
		}
	}
}
// =================DOC GIA // HNH============
Ngay_Thang Lay_time_Hethong()
{
	Ngay_Thang ngay;
	// tra ve date/time hien tai dua tren system hien tai
	time_t baygio = time(0);
	tm *today = localtime(&baygio);

	ngay.nam = 1900 + today->tm_year;
	ngay.thang = 1 + today->tm_mon;
	ngay.ngay = today->tm_mday;
	return ngay;
}
Ngay_Thang Lay_time_Phai_Tra_Sach()
{
	Ngay_Thang ngay;
	// tra ve date/time hien tai dua tren system hien tai
	time_t baygio = time(0);
	tm *today = localtime(&baygio);

	ngay.nam = 1900 + today->tm_year;
	ngay.thang = 1 + today->tm_mon;
	ngay.ngay = 7 + today->tm_mday;
	return ngay;
}
// 1:ngay > ngay1; 2:ngay < ngay1; 3:ngay=ngay1
int SoSanhNgay(Ngay_Thang d, Ngay_Thang t)
{
	if (d.nam == t.nam)
	{
		if (d.thang == t.thang)
		{
			if (d.ngay > t.ngay)
			{
				return 1;
			}
			else if (d.ngay < t.ngay)
			{
				return 2;
			}
			else
				return 3;
		}
		else if (d.thang > t.thang)
		{
			return 1;
		}
		else
			return 2;
	}
	else if (d.nam > t.nam)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
void In_Ngay(Ngay_Thang a)
{
	cout << a.ngay << "/";
	cout << a.thang << "/";
	cout << a.nam;
}
void KhoiTaoTREE(TREE &t)
{
	t = NULL;
}
//int Random_Ngaunhien()
//{
//	srand(time(NULL));
//	int ran = rand() % MAXDS;
//	return ran;
//}
void Them_DOCGIA(TREE &t, THEDOCGIA dg)
{
	if (t == NULL)
	{
		NODE_THEDOCGIA *p = new NODE_THEDOCGIA;
		p->data = dg;
		p->left = NULL;
		p->right = NULL;
		p->data.First = NULL;
		p->data.Last = NULL;
		//p->First = NULL;
		//p->Last = NULL;
		t = p;
	}
	else // cay ton tai phan tu
	{
		if (dg.MaThe < t->data.MaThe)
		{
			Them_DOCGIA(t->left, dg);
		}
		else if (dg.MaThe > t->data.MaThe)
		{
			Them_DOCGIA(t->right, dg);
		}
	}
}
void Creat_Tree(TREE &t)
{
	int y = 17;
start:
	gotoXY(50, 13); Xu_Li_Con_Tro_Chi_Vi(true);
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC){
			clrscr();
			GiaoDien_TheDocGia();
		}
		else
		{
			goto mathe;
		}
	}
mathe:
	THEDOCGIA dg;
	dg.MaThe = mathe[soluongmathe - 1];
	soluongmathe--;
	gotoXY(21, y);	cout << dg.MaThe;
ho:
	gotoXY(37, y); gets_s(dg.Ho);
	if (stricmp(dg.Ho, "") == 0)
	{
		BaoLoi("HO KHONG DUOC RONG");
		cout << "                     ";
		goto ho;
	}
	Chuan_Hoa(dg.Ho); gotoXY(37, y); cout << dg.Ho;

ten:
	gotoXY(56, y); gets_s(dg.Ten);
	if (stricmp(dg.Ten, "") == 0)
	{
		BaoLoi("TEN KHONG DUOC RONG");
		cout << "                      ";
		goto ten;
	}
	Chuan_Hoa(dg.Ten); gotoXY(56, y); cout << dg.Ten;

phai:
	gotoXY(66, y); gets_s(dg.Phai);
	Chuan_Hoa(dg.Phai); gotoXY(66, y); cout << dg.Phai;
	dg.TrangThaiThe = 1;
	gotoXY(77, y);
	if (dg.TrangThaiThe == 1)
	{
		cout << "THE DANG HOAT DONG";
	}
	else if (dg.TrangThaiThe == 0)
	{
		cout << "THE BI KHOA";
	}
	//dg.songayquahan = 0;
	Them_DOCGIA(t, dg);
	soluongdocgia++; 
	y++;
	goto start;
}
void Xuat_THEDOCGIA(THEDOCGIA dg, int &y)
{
	gotoXY(26, y); cout << t->data.MaThe;
	gotoXY(36, y); cout << t->data.Ho;
	gotoXY(57, y); cout << t->data.Ten;
	gotoXY(68, y); cout << t->data.Phai;
	gotoXY(78, y);
	if (t->data.TrangThaiThe == 1)
	{
		cout << "THE DANG HOAT DONG";
	}
	else if (t->data.TrangThaiThe == 0)
	{
		cout << "THE BI KHOA";
	}
}
void Xuat_danh_sach_THEDOCGIA(TREE t,int &y)
{
	if (t == NULL)
	{
		return;
	}
	Xuat_danh_sach_THEDOCGIA(t->left, y);	
	gotoXY(26, y); cout << t->data.MaThe;
	gotoXY(36, y); cout << t->data.Ho;
	gotoXY(57, y); cout << t->data.Ten;
	gotoXY(68, y); cout << t->data.Phai;
	gotoXY(78, y);
	if (t->data.TrangThaiThe == 1)
	{
		cout << "THE DANG HOAT DONG";
	}
	else if (t->data.TrangThaiThe == 0)
	{
		cout << "THE BI KHOA";
	}
	y++;
	Xuat_danh_sach_THEDOCGIA(t->right, y);
	
}

void Xuat_danh_sach_TENDOCGIA(TREE t, int &y)
{
	if (t == NULL)
	{
		return;
	}
	gotoXY(26, y); cout << t->data.MaThe;
	gotoXY(36, y); cout << t->data.Ho;
	gotoXY(57, y); cout << t->data.Ten;
	gotoXY(68, y); cout << t->data.Phai;
	gotoXY(78, y);
	if (t->data.TrangThaiThe == 1)
	{
		cout << "THE DANG HOAT DONG";
	}
	else if (t->data.TrangThaiThe == 0)
	{
		cout << "THE BI KHOA";
	}
	y++;
	//Xuat_danh_sach_THEDOCGIA(t->right, y);

}
// TIM MA THE DOC GIA tra ve node the doc gia
NODE_THEDOCGIA *Tim_MATHE(NODE_THEDOCGIA *t, int mathe)
{
	NODE_THEDOCGIA *tdg;
	tdg = t;
	while (tdg != NULL && tdg->data.MaThe != mathe)
	{
		if (mathe < tdg->data.MaThe)
		{
			tdg = tdg->left;
		}
		else
		{
			tdg = tdg->right;
		}
	}
	return tdg;
}
void Hieu_Chinh_THEDOCGIA(TREE &t)
{
start: 
	gotoXY(52, 13); Xu_Li_Con_Tro_Chi_Vi(true);
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_TheDocGia();
		}
		else
		{
			goto nhapmathe;
		}
	}
nhapmathe:
	int mathe;
	gotoXY(26, 17); cin >> mathe; fflush(stdin);
	NODE_THEDOCGIA *p;
	p = Tim_MATHE(t, mathe);

	if (p == NULL)
	{
		BaoLoi("MA THE KHONG TON TAI");
		cout << "                       ";
		goto start;
	}
	else
	{
		gotoXY(26, 17); cout << p->data.MaThe;
		gotoXY(36, 17); cout << p->data.Ho;
		gotoXY(57, 17); cout << p->data.Ten;
		gotoXY(68, 17); cout << p->data.Phai;
		gotoXY(78, 17);
		if (p->data.TrangThaiThe == 1)
		{
			cout << "THE DANG HOAT DONG";
		}
		else if (p->data.TrangThaiThe == 0)
		{
			cout << "THE BI KHOA";
		}
		int kt = 0;
		THEDOCGIA y;
		while (true)
		{
		batphim:
			int key = _getch();
			if (key == KEY_RIGHT)
			{
				if (kt == 0)
				{
					kt = 1;
					gotoXY(36, 17);
				}
				else if (kt == 1)
				{
					kt = 2;
					gotoXY(57, 17);
				}
				else if (kt == 2)
				{
					kt = 3;
					gotoXY(68, 17);
				}
				else if (kt == 3)
				{
					kt = 4;
					gotoXY(78, 17);
				}
				else if (kt == 4)
				{
					kt = 0;
					gotoXY(26, 17);
				}
			}
			else if (key == KEY_LEFT)
			{
				if (kt == 4)
				{
					kt = 3;
					gotoXY(68, 17);
				}
				else if (kt == 3)
				{
					kt = 2;
					gotoXY(57, 17);
				}
				else if (kt == 2)
				{
					kt = 1;
					gotoXY(36, 17);
				}
				else if (kt == 1)
				{
					kt = 0;
					gotoXY(26, 17);
				}
				else if (kt == 0)
				{
					kt = 4;
					gotoXY(78, 17);
				}
			}
			else if (key == KEY_ENTER)
			{
				if (kt == 0)
				{
					BaoLoi("KHONG THE HIEU CHINH MA THE");
					cout << "                              ";
					goto batphim;
				}
				else if (kt == 1)
				{
					gotoXY(36, 17); cout << "                ";
				ho:
					gotoXY(36, 17);	gets_s(y.Ho);
					if (stricmp(y.Ho, "") == 0)
					{
						BaoLoi("HO KHONG DUOC RONG");
						cout << "                     ";
						goto ho;
					}
					Chuan_Hoa(y.Ho); strcpy(p->data.Ho, y.Ho);
					gotoXY(36, 17); cout << p->data.Ho;
				}
				else if (kt == 2)
				{
					gotoXY(57, 17); cout << "     ";
				ten:
					gotoXY(57, 17); gets_s(y.Ten);
					if (stricmp(y.Ten, "") == 0)
					{
						BaoLoi("TEN KHONG DUOC RONG");
						cout << "                     ";
						goto ten;
					}
					Chuan_Hoa(y.Ten); strcpy(p->data.Ten, y.Ten);
					gotoXY(57, 17); cout << p->data.Ten;
				}
				else if (kt == 3)
				{
					gotoXY(68, 17); cout << "     ";
					gotoXY(68, 17); gets_s(y.Phai);
					Chuan_Hoa(y.Phai); strcpy(p->data.Phai, y.Phai);
					gotoXY(68, 17); cout << p->data.Phai;
				}
				else if (kt == 4)
				{
					BaoLoi("KHONG THE HIEU CHINH TRANG THAI");
					cout << "                                  ";
					goto batphim;
				}
			}
			else if (key == KEY_ESC)
			{
				clrscr();
				GiaoDien_TheDocGia();
			}
		}
	}
}
// hàm tìm node thế mạng
void Tim_Node_The_Mang(TREE &X, TREE &Y)
{
	// tìm node phải nhất của cây con trái
	if (Y->right != NULL)
	{
		Tim_Node_The_Mang(X, Y->right);
	}
	else
	{
		X->data = Y->data;
		X = Y;
		Y = Y->left;
	}
}
void Xoa_DOCGIA(TREE &t, int mathe)
{
//start:
//	gotoXY(52, 13); Xu_Li_Con_Tro_Chi_Vi(true);
//	while (true)
//	{
//		int key = _getch();
//		if (key == KEY_ESC){
//			clrscr();
//			GiaoDien_TheDocGia();
//		}
//		else
//		{
//			goto nhapmathe;
//		}
//	}
//nhapmathe:
//	int mathe;
//	gotoXY(46, 15); cin >> mathe; fflush(stdin);
	if (t == NULL)
	{
		BaoLoi("KHONG TON TAI PHAN TU");
		cout << "                       ";
		//goto start;
	}
	else
	{
		if (mathe < t->data.MaThe)
		{
			Xoa_DOCGIA(t->left,mathe);
		}
		else if (mathe > t->data.MaThe)
		{
			Xoa_DOCGIA(t->right,mathe);
		}
		else
		{
			NODE_THEDOCGIA *X = t;
			if (t->left == NULL)
			{
				t = t->right;
			}
			else if (t->right == NULL)
			{
				t = t->left;
			}
			else
			{
				// tim node phai nhat cua cay con trai
				Tim_Node_The_Mang(X, t->left);
			}
			delete X;
			//BaoLoi("XOA THANH CONG");
			//cout << "                 ";
			//clrscr();
			//GiaoDien_XoaDocGia();
			//goto start;
		}
	}
}
void Tao_MangTam_InDS_TheDocGia(TREE t, int &y){
	THEDOCGIA *arr = new THEDOCGIA[soluongdocgia];
	int n = 0; 
	if (t != NULL)
	{		
		arr[n] = t->data;
		n++;
		Tao_MangTam_InDS_TheDocGia(t->left, y);
		Tao_MangTam_InDS_TheDocGia(t->right,y);			
	}
	THEDOCGIA tam;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			//if (stricmp(arr[i].Ten, arr[j].Ten)>0)
			//{				
				char s1[50], s2[50];
				strcpy(s1, arr[j-1].Ho);
				strcat(s1, " ");
				strcpy(s1, arr[j-1].Ten);
				strcpy(s2, arr[j].Ho);
				strcat(s2, " ");
				strcpy(s2, arr[j].Ten);
				if (stricmp(s1, s2) > 0)
				{
					tam = arr[i];
					arr[i] = arr[j];
					arr[j] = tam;
				}

			//}
		}
	}	
	for (int i = 0; i < n; i++)
	{
		system("pause");
		gotoXY(26, y); cout << arr[i].MaThe;
		gotoXY(36, y); cout << arr[i].Ho;
		gotoXY(57, y); cout << arr[i].Ten;
		gotoXY(68, y); cout << arr[i].Phai;
		gotoXY(78, y);
		if (arr[i].TrangThaiThe == 1)
		{
			cout << "THE DANG HOAT DONG";
		}
		else if (arr[i].TrangThaiThe == 0)
		{
			cout << "THE BI KHOA";
		}
		y++;
	}
}



void Tao_MangDanhSachTheDocGia(TREE t, THEDOCGIA arr[], int &n){
	const int STACKSIZE = 10000;
	NODE_THEDOCGIA *Stack[STACKSIZE];
	int sp = -1; // khoi tao Stack rong

	while (t != NULL)
	{
		arr[n] = t->data;
		n++;
		if (t->right != NULL)
			Stack[++sp] = t->right;
		if (t->left != NULL)
			t = t->left;
		else if (sp == -1)
			break;
		else
			t = Stack[sp--];
	}

}

void Sap_Xep_Tang_Dan_Theo_HOTEN(THEDOCGIA *arr, int m)
{
	THEDOCGIA x;
	int i, j;
	for (i = 0; i<m; i++)
	{
		for (j = m - 1; j>i; j--)
		{
			char s1[50], s2[50];
			strcpy(s1, arr[j - 1].Ten);
			strcat(s1, " ");
			strcat(s1, arr[j - 1].Ho);
			strcpy(s2, arr[j].Ten);
			strcat(s2, " ");
			strcat(s2, arr[j].Ho);
			if (stricmp(s1, s2) > 0)
			{
				x = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = x;
			}
		}
	}
}
void DuyetCay_LNR(TREE t, ofstream &fileout)
{
	if (t != NULL)
	{
		DuyetCay_LNR(t->left, fileout);
		fileout << t->data.MaThe << ","
			<< t->data.Ho << ","
			<< t->data.Ten << ","
			<< t->data.Phai << ","
			<< t->data.TrangThaiThe << endl;
		DuyetCay_LNR(t->right, fileout);
	}
}
void GhiFile_DocGia()
{
	ofstream fileout;
	fileout.open("DS_DOCGIA.TXT", ios_base::out);
	fileout << soluongdocgia << endl;
	DuyetCay_LNR(t, fileout);
	fileout.close();
}
void DocFile_DocGia()
{
	ifstream filein;
	filein.open("DS_DOCGIA.TXT", ios_base::in);

	filein >> soluongdocgia;
	filein.ignore();
	for (int i = 0; i < soluongdocgia; i++)
	{
		THEDOCGIA dg;
		filein >> dg.MaThe;// cout << dg.MaThe;
		filein.seekg(1, 1);
		filein.getline(dg.Ho, 20, ','); //cout << dg.Ho;
		filein.getline(dg.Ten, 10, ','); //cout << dg.Ten;
		filein.getline(dg.Phai, 5, ','); //cout << dg.Phai;
		filein >> dg.TrangThaiThe; //cout << dg.TrangThaiThe;
		filein.ignore();
		Them_DOCGIA(t, dg);
	}
	filein.close();
}
void GiaoDien_ThemDocGia(){
	clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(35, 11); cout << "=================THEM DOC GIA================";
	HighLight(); gotoXY(33, 13); cout << "NHAN ESC DE THOAT"; Normal();
	HighLight(); gotoXY(65, 13); cout << "NHAN PHIM BAT KY DE NHAP"; Normal();
	Ve_Khung(20, 15, 80, 20); liney(16, 34, 35); liney(16, 34, 55); liney(16, 34, 65); liney(16, 34, 75);
	gotoXY(25, 16); cout << "MA THE";
	gotoXY(42, 16); cout << "HO";
	gotoXY(58, 16); cout << "TEN";
	gotoXY(68, 16); cout << "PHAI";
	gotoXY(82, 16); cout << "TRANG THAI THE";

	Creat_Tree(t);
}
void GiaoDien_InDS_DocGia_TheoMaThe()
{
	clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(35, 11); cout << "=================DANH SACH DOC GIA================";
	HighLight(); gotoXY(25, 13); cout << "NHAN ESC DE THOAT"; Normal();
	Ve_Khung(20, 15, 80, 20); liney(16, 34, 35); liney(16, 34, 55); liney(16, 34, 65); liney(16, 34, 75);
	gotoXY(25, 16); cout << "MA THE";
	gotoXY(42, 16); cout << "HO";
	gotoXY(58, 16); cout << "TEN";
	gotoXY(68, 16); cout << "PHAI";
	gotoXY(82, 16); cout << "TRANG THAI THE";
	int y = 17;
	Xuat_danh_sach_THEDOCGIA(t,y);
	while (true){
	batphim:
		gotoXY(42, 13);  Xu_Li_Con_Tro_Chi_Vi(false);
		int key = _getch();
		if (key == KEY_ESC){
			clrscr();
			GiaoDien_InDS_DocGia();
		}
		else{
			BaoLoi("NHAN ESC DE THOAT");
			cout << "                    ";
			goto batphim;
		}
	}
}
void xuatdocgia(THEDOCGIA a, int x, int y){
	gotoXY(x, y);
	cout << a.MaThe;
	x = x + 13;
	gotoXY(x, y); cout << a.Ho;
	x = x + 20;
	gotoXY(x, y); cout << a.Ten;
	x = x + 10;
	gotoXY(x, y); cout << a.Phai;
	x = x + 12;
	gotoXY(x, y); 
	if (t->data.TrangThaiThe == 1)
	{
		cout << "THE DANG HOAT DONG";
	}
	else if (t->data.TrangThaiThe == 0)
	{
		cout << "THE BI KHOA";
	}
}
void xoaindocgia(int x, int y){
	for (int j = 0; j < 17; j++)
	{
		x = 25;
		gotoXY(x, y);
		cout << "       ";
		x = x + 13;
		gotoXY(x, y); cout << "               ";
		x = x + 20;
		gotoXY(x, y); cout << "      ";
		x = x + 10;
		gotoXY(x, y); cout << "      ";
		x = x + 20;
		gotoXY(x, y); cout << "           ";
		y = y + 1;
	}
}
void GiaoDien_InDS_DocGia_TheoHoTenTangDan()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(35, 11); cout << "=================DANH SACH DOC GIA================";
	HighLight(); gotoXY(25, 13); cout << "NHAN ESC DE THOAT"; Normal();
	Ve_Khung(20, 15, 80, 20); liney(16, 34, 35); liney(16, 34, 55); liney(16, 34, 65); liney(16, 34, 75);
	gotoXY(25, 16); cout << "MA THE";
	gotoXY(42, 16); cout << "HO";
	gotoXY(58, 16); cout << "TEN";
	gotoXY(68, 16); cout << "PHAI";
	gotoXY(82, 16); cout << "TRANG THAI THE";
	int y = 17;
	THEDOCGIA arr[1000];
	int n = 0;
	Tao_MangDanhSachTheDocGia(t, arr, n);
	Sap_Xep_Tang_Dan_Theo_HOTEN(arr, n);
	int key, kt = 0;
	int vitriin = 0; int i = 0; int x = 25; int dem = 0;
	while (true){
		gotoXY(42, 13);  Xu_Li_Con_Tro_Chi_Vi(true);
		if (i < n){
			xuatdocgia(arr[i], x, y);
			y += 1;
			dem++;
			i++;
		}
		if (i == n){
		bat:
			key = _getch();
			if (key == KEY_UP)
			{
				i = (i - dem - 17);
				y = 17;
				xoaindocgia(x, 17);
				dem = 0;
			}
			else if (key == KEY_ESC){
				kt = 1;
				break;
			}
			else
			{
				goto bat;
			}
		}
		if (dem == 17){
		batphim:
			key = _getch();
			if (key == KEY_DOWN)
			{
				dem = 0;
				y = 17;
				xoaindocgia(x, 17);
			}
			else if (key == KEY_UP)
			{
				dem == 0;
				i = i - 17 * 2;
				y = 17;
				xoaindocgia(x, 17);
			}
			else if (key == KEY_ESC){
				kt == 1;
				break;
			}
			else{
				goto batphim;
			}
		}

	}
	if (kt == 1)
	{
		clrscr();
		GiaoDien_InDS_DocGia();
	}
	//Xuat_danh_sach_TENDOCGIA(t, y);
	/*while (true){
	batphim:
		gotoXY(42, 13);  Xu_Li_Con_Tro_Chi_Vi(true);
		int key = _getch();
		if (key == KEY_ESC){
			clrscr();
			GiaoDien_InDS_DocGia();
		}
		else{
			BaoLoi("NHAN ESC DE THOAT");
			cout << "                    ";
			goto batphim;
		}
	}*/
}
void Tao_MangTam_DocGia_QuaHan(TREE t, THEDOCGIA *a, int &n)
{ 
	Ngay_Thang hientai;
	hientai = Lay_time_Hethong();
	if (t != NULL)
	{		
		for (NODEMUONTRA *p = t->data.First; p != NULL; p = p->next)
		{
			if (p->data.TrangThai == 0)
			{
				if (SoSanhNgay(hientai,p->data.NgayPhaiTra)==1)
				{
					a[n] = t->data;
					n++;
					t->data.songayquahan = hientai.ngay - p->data.NgayPhaiTra.ngay;
				}
			}
		}
		Tao_MangTam_DocGia_QuaHan(t->left, a, n);
		Tao_MangTam_DocGia_QuaHan(t->right, a, n);
	}
}
void SapXep_DocGia_QuaHanGiamDan(THEDOCGIA *a, int &n)
{
	Ngay_Thang hientai;
	int ngayquahanmax1/*=0*/; int ngayquahanmax2/*=0*/;
	hientai = Lay_time_Hethong();
	THEDOCGIA tam;		
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{	
			for (NODEMUONTRA *p = a[i].First; p != NULL; p = p->next)
			{
				if (hientai.ngay - p->data.NgayMuon.ngay > 7)
				{
					ngayquahanmax1 = hientai.ngay - p->data.NgayPhaiTra.ngay;
				}
			}
			
			for (NODEMUONTRA *q = a[j].First; q != NULL; q = q->next)
			{
				
				if (hientai.ngay - q->data.NgayMuon.ngay > 7)
				{
					ngayquahanmax2 = hientai.ngay - q->data.NgayPhaiTra.ngay;										
				}
			}
			if (ngayquahanmax1 < ngayquahanmax2)
			{
				tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
		}
	}
}
void In_DocGia_QuaHan()
{
	THEDOCGIA *a; Ngay_Thang hientai; char masach[10]; Ngay_Thang tam; char *maISBN; int songayquahan;
	THEDOCGIA thetam; NODEMUONTRA *p;
	hientai = Lay_time_Hethong();
	a = new THEDOCGIA[100]; int k = 0;
	Tao_MangTam_DocGia_QuaHan(t, a, k);	
	SapXep_DocGia_QuaHanGiamDan(a,k);
	int y = 18;
	for (int i = 0; i < k; i++)
	{
		for (NODEMUONTRA *p = a[i].First; p != NULL; p = p->next)
		{
			if (p->data.TrangThai == 0 && (SoSanhNgay(hientai, p->data.NgayPhaiTra)==1))
			{
				strcpy(masach, p->data.MaSach);
				tam = p->data.NgayMuon;
				break;
			}			
		}
		songayquahan = hientai.ngay - tam.ngay - 7;
		maISBN = strtok(masach, "_");
		int vitridausach = Search(dsDauSach, maISBN);
		gotoXY(18, y); cout << a[i].MaThe;
		gotoXY(26, y); cout << a[i].Ho << " " << a[i].Ten;
		gotoXY(50, y); cout << masach;
		gotoXY(58, y); cout << dsDauSach.ds[vitridausach]->TenSach;
		gotoXY(84, y);
		In_Ngay(tam);
		gotoXY(97, y); cout << songayquahan;
		y++;
	}
}
void GiaoDien_InDS_DocGia_QuaHan()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(35, 11); cout << "=================DANH SACH DOC GIA MUON SACH QUA HAN================";
	HighLight(); gotoXY(25, 13); cout << "NHAN ESC DE THOAT"; Normal();
	Ve_Khung(15, 16, 90, 20);
	liney(17, 35, 25); liney(17, 35, 48); liney(17, 35, 57); liney(17, 35, 80); liney(17, 35, 95);
	gotoXY(18, 17); cout << "MA THE";
	gotoXY(33, 17); cout << "HO & TEN";
	gotoXY(49, 17); cout << "MA SACH";
	gotoXY(65, 17); cout << "TEN SACH";
	gotoXY(83, 17); cout << "NGAY MUON";
	gotoXY(96, 17); cout << "NGAY.QH";
	In_DocGia_QuaHan();
start:
	gotoXY(42, 13); Xu_Li_Con_Tro_Chi_Vi(false);
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_InDS_DocGia();
		}
		else
		{
			BaoLoi("NHAN ESC DE THOAT");
			cout << "                   ";
			goto start;
		}
	}

}
void GiaoDien_InDS_DocGia()
{
	clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(35, 13); cout << "=================IN DANH SACH DOC GIA================";
	Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "   IN THEO MA THE  ";
	Ve_Khung(50, 23, 20, 2); gotoXY(51, 24); cout << "   IN THEO HO TEN  ";
	Ve_Khung(45, 28, 32, 2); gotoXY(46, 29); cout << "IN DS DOC GIA MUON SACH QUA HAN";
	HighLight();
	Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "   IN THEO MA THE  ";
	Normal();
	Xu_Li_Con_Tro_Chi_Vi(false);
	int kt = 1;

	while (true)
	{
		int key = _getch();
		if (key == KEY_DOWN)
		{
			if (kt == 1){
				kt = 2;
			}
			else if (kt == 2){
				kt = 3;
			}
			else if (kt == 3)
			{
				kt = 1;
			}
		}
		else if (key == KEY_UP)
		{
			if (kt == 1)
			{
				kt = 3;
			}
			else if (kt == 2)
			{
				kt = 1;
			}
			else if (kt == 3)
			{
				kt = 2;
			}
		}
		else if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_TheDocGia();
		}
		
		if (kt == 1)
		{
			HighLight();
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "   IN THEO MA THE  ";
			Normal();
			Ve_Khung(50, 23, 20, 2); gotoXY(51, 24); cout << "   IN THEO HO TEN  ";
			Ve_Khung(45, 28, 32, 2); gotoXY(46, 29); cout << "IN DS DOC GIA MUON SACH QUA HAN";
		}
		else if (kt == 2)
		{
			HighLight();
			Ve_Khung(50, 23, 20, 2); gotoXY(51, 24); cout << "   IN THEO HO TEN  ";
			Normal();
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "   IN THEO MA THE  ";			
			Ve_Khung(45, 28, 32, 2); gotoXY(46, 29); cout << "IN DS DOC GIA MUON SACH QUA HAN";
		}
		else if (kt == 3)
		{
			HighLight();
			Ve_Khung(45, 28, 32, 2); gotoXY(46, 29); cout << "IN DS DOC GIA MUON SACH QUA HAN";
			Normal();
			Ve_Khung(50, 18, 20, 2); gotoXY(51, 19); cout << "   IN THEO MA THE  ";
			Ve_Khung(50, 23, 20, 2); gotoXY(51, 24); cout << "   IN THEO HO TEN  ";
		}
		if (key == KEY_ENTER)
		{
			if (kt == 1)
			{
				clrscr();
				GiaoDien_InDS_DocGia_TheoMaThe();
			}
			else if (kt == 2)
			{
				clrscr();
				GiaoDien_InDS_DocGia_TheoHoTenTangDan();
			}
			else if (kt == 3)
			{
				clrscr();
				GiaoDien_InDS_DocGia_QuaHan();
			}
		}
	}
}
void GiaoDien_HieuChinh_TheDocGia()
{
	clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(35, 11); cout << "=================HIEU CHINH DOC GIA================";
	HighLight(); gotoXY(35, 13); cout << "NHAN ESC DE THOAT"; Normal();
	HighLight(); gotoXY(65, 13); cout << "NHAN PHIM BAT KY DE NHAP"; Normal();
	Ve_Khung(20, 15, 80, 20); liney(16, 34, 35); liney(16, 34, 55); liney(16, 34, 65); liney(16, 34, 75);
	gotoXY(25, 16); cout << "MA THE";
	gotoXY(42, 16); cout << "HO";
	gotoXY(58, 16); cout << "TEN";
	gotoXY(68, 16); cout << "PHAI";
	gotoXY(82, 16); cout << "TRANG THAI THE";
	Hieu_Chinh_THEDOCGIA(t);
}
void GiaoDien_XoaDocGia()
{
	clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35); // ve khung lon
	gotoXY(35, 11); cout << "=================XOA DOC GIA================";
	HighLight(); gotoXY(35, 13); cout << "NHAN ESC DE THOAT"; Normal();
	HighLight(); gotoXY(65, 13); cout << "NHAN PHIM BAT KY DE NHAP"; Normal();
	gotoXY(25, 15); cout << "NHAP MA THE MUON XOA: ";
	Ve_Khung(20, 16, 80, 20); // ve khung nho
	liney(17, 35, 35); liney(17, 35, 55); liney(17, 35, 65); liney(17, 35, 75); // ve cac duong thang dung
	gotoXY(25, 17); cout << "MA THE";
	gotoXY(42, 17); cout << "HO";
	gotoXY(58, 17); cout << "TEN";
	gotoXY(68, 17); cout << "PHAI";
	gotoXY(82, 17); cout << "TRANG THAI THE";

	int y = 18;
	Xuat_danh_sach_THEDOCGIA(t, y);
start:
	
	gotoXY(52, 13); Xu_Li_Con_Tro_Chi_Vi(true);
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC){
			clrscr();
			GiaoDien_TheDocGia();
		}
		else
		{
			goto nhapmathe;
		}
	}
nhapmathe:
	int mathe;
	gotoXY(46, 15); cin >> mathe; fflush(stdin);
	Xoa_DOCGIA(t,mathe);
	BaoLoi("XOA THANH CONG");
	cout << "                ";
	clrscr();
	GiaoDien_XoaDocGia();
	goto start;
}
void GiaoDien_TheDocGia(){
	//clrscr();
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(30, 13); cout << "=======================QUAN LY THE DOC GIA=======================";
	Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "       THEM        ";
	Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        SUA        ";
	Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "        XOA        ";
	Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "    IN DS DOC GIA  ";

	HighLight();
	Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "       THEM        ";
	Normal();
	Xu_Li_Con_Tro_Chi_Vi(false);
	int kt = 1;

	while (true){
		int key = _getch();
		// bat phim xuong
		if (key == KEY_DOWN)
		{
			if (kt == 1){
				kt = 2;
			}
			else if (kt == 2){
				kt = 3;
			}
			else if (kt == 3){
				kt = 4;
			}
			else if (kt == 4){
				kt = 1;
			}
		}
		// bat phim len
		else if (key == KEY_UP){
			if (kt == 1){
				kt = 4;
			}
			else if (kt == 2){
				kt = 1;
			}
			else if (kt == 3){
				kt = 2;
			}
			else if (kt == 4){
				kt = 3;
			}
		}
		else if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_Chinh();
		}
		if (kt == 1)
		{
			HighLight();
			Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "       THEM        ";
			Normal();
			Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        SUA        ";
			Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "        XOA        ";
			Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "    IN DS DOC GIA  ";
		}
		else if (kt == 2)
		{
			HighLight();
			Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        SUA        ";
			Normal();
			Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "       THEM        ";			
			Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "        XOA        ";
			Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "    IN DS DOC GIA  ";
		}
		else if (kt == 3)
		{
			HighLight();
			Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "        XOA        ";
			Normal();
			Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "       THEM        ";
			Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        SUA        ";			
			Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "    IN DS DOC GIA  ";
		}
		else if (kt == 4)
		{
			HighLight();			
			Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "    IN DS DOC GIA  ";			
			Normal();
			Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "       THEM        ";
			Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "        SUA        ";
			Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "        XOA        ";
		}
		
		if (key == KEY_ENTER)
		{
			if (kt == 1)
			{
				clrscr();
				GiaoDien_ThemDocGia();
			}
			else if (kt == 2)
			{
				clrscr();
				GiaoDien_HieuChinh_TheDocGia();
			}
			else if (kt == 3)
			{
				clrscr();
				GiaoDien_XoaDocGia();
			}
			else if (kt == 4)
			{
				clrscr();
				GiaoDien_InDS_DocGia();
			}
		}
	}
}
//=================ket thuc doc gia=============

// ========================= MUON TRA SACH // HNH===========================

bool KiemTra_QuaHan(NODEMUONTRA *Last)
{
	Ngay_Thang hientai;
	hientai = Lay_time_Hethong();
	//In_Ngay(hientai);
	NODEMUONTRA *p = Last;
	while (p != NULL)
	{
		if (p->data.TrangThai == 0)
		{
			if (SoSanhNgay(hientai, p->data.NgayPhaiTra) == 1)
			{
				return true;
			}
			/*if (hientai.ngay > p->data.NgayPhaiTra.ngay)
			{
				return true;
			}*/
		}
		p = p->rev;
	}
	return false;
}
int Search_Ten(DS_DAUSACH dsDauSach, char ten[100])
{
	for (int i = 0; i < dsDauSach.n; i++)
	{
		if (stricmp(dsDauSach.ds[i]->TenSach, ten) == 0)
		{
			return i;
		}
	}
	return -1;
}

// them 1 node vao dau danh sach lien ket kep
//void Insert_MuonTra(NODEMUONTRA *&First, NODEMUONTRA *&Last, MUONTRA info) 
//{
//	NODEMUONTRA *p;
//	p = new NODEMUONTRA;
//	p->data = info;
//	p->rev = NULL;
//	p->next = First;
//	if (First == NULL) // truong hop danh sach dang rong
//	{
//		Last = p;
//	}
//	else
//	{
//		First->rev = p; // tao lien ket giua p va First
//	}
//	First = p;
//}
void Insert_MuonTra(NODEMUONTRA *&First, NODEMUONTRA *&Last, MUONTRA info)
{
	NODEMUONTRA *p;
	p = new NODEMUONTRA;
	p->data = info;
	p->next = NULL;
	p->rev = NULL;
	if (First == NULL && Last == NULL)
	{
		First = Last = p;
	}
	else
	{
		p->next = First;
		First->rev = p;
		First = p;
	}
}
void Tao_MangTam_InSach_1Dg_DangMuon(NODEMUONTRA *First, MUONTRA *dangmuon, int &m)
{
	NODEMUONTRA *p = First;
	while (p != NULL)
	{
		if (p->data.TrangThai == 0)
		{
			dangmuon[m] = p->data;
			m++;
		}
		p = p->next;
	}
}
void In_Sach_1DG_DangMuon(NODEMUONTRA *First, int &dangmuon, NODE_THEDOCGIA *dg)
{
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	HighLight(); gotoXY(33, 15); cout << "NHAN ESC DE THOAT"; Normal();
	HighLight(); gotoXY(65, 15); cout << "NHAN PHIM BAT KY DE NHAP"; Normal();
	gotoXY(33, 16); cout << "NHAP MA THE DOC GIA:";
	Ve_Khung(25, 19, 70, 15); liney(20, 33, 40); liney(20, 33, 58); liney(20, 33, 78);
	gotoXY(28, 20); cout << "MA SACH";
	gotoXY(44, 20); cout << "NGAY MUON";
	gotoXY(61, 20); cout << "NGAY PHAI TRA";
	gotoXY(82, 20); cout << "NGAY TRA";
	gotoXY(30, 17); cout << "MA THE: " << dg->data.MaThe << "\tHO &TEN: " << dg->data.Ho << " " << dg->data.Ten;
	MUONTRA *tam; int m = 0; int y = 21;
	tam = new MUONTRA[100];
	Tao_MangTam_InSach_1Dg_DangMuon(First, tam, m);
	for (int i = 0; i < m; i++)
	{
		gotoXY(26, y); cout << tam[i].MaSach;
		gotoXY(41, y);
		In_Ngay(tam[i].NgayMuon);
		gotoXY(59, y);
		In_Ngay(tam[i].NgayPhaiTra);
		dangmuon++;
		y++;
	}	

	//while (p != NULL)
	//{
	//	if (p->data.TrangThai == 0)
	//	{
	//		gotoXY(26, y); cout << p->data.MaSach;
	//		gotoXY(41, y); 
	//		In_Ngay(p->data.NgayMuon);
	//		gotoXY(59, y);
	//		In_Ngay(p->data.NgayPhaiTra);
	//		dangmuon++;
	//	}
	//	p = p->next;
	//	y++;
	//}
	//dangmuon--;
}
void In_DS_MuonTra_1DG(NODE_THEDOCGIA *dg)
{
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	gotoXY(30, 13); cout << "=======================DANH SACH MUON TRA=======================";
	HighLight(); gotoXY(33, 15); cout << "NHAN ESC DE THOAT"; Normal();
	gotoXY(33, 16); cout << "NHAP MA THE DOC GIA:";
	Ve_Khung(20, 19, 80, 15); liney(20, 33, 35); liney(20, 33, 50); liney(20, 33, 65); liney(20, 33, 80);
	gotoXY(25, 20); cout << "MA SACH";
	gotoXY(38, 20); cout << "NGAY MUON";
	gotoXY(51, 20); cout << "NGAY PHAI TRA";
	gotoXY(68, 20); cout << "NGAY TRA";
	gotoXY(82, 20); cout << "TRANG THAI SACH";
	gotoXY(30, 17); cout << "                                                            ";
	gotoXY(30, 17); cout << "MA THE: " << dg->data.MaThe << "\tHO &TEN: " << dg->data.Ho << " " << dg->data.Ten;
	int y = 21;
	NODEMUONTRA *p = dg->data.First;
	while (p != NULL)
	{
		gotoXY(23, y);
		cout << p->data.MaSach;
		gotoXY(36, y);
		In_Ngay(p->data.NgayMuon);
		gotoXY(51, y);
		In_Ngay(p->data.NgayPhaiTra);
		gotoXY(66, y);
		In_Ngay(p->data.NgayTra);
		gotoXY(82, y);
		if (p->data.TrangThai == 0)
		{
			cout << "Dang Muon";
		}
		else if (p->data.TrangThai == 1)
		{
			cout << "Da Tra";
		}
		else if (p->data.TrangThai == 2)
		{
			cout << "Da Thanh Ly";
		}
		p = p->next;
		y++;
	}
}
void In_DS_MUONTRA(TREE t)
{
start: 
	gotoXY(50, 15); Xu_Li_Con_Tro_Chi_Vi(true);
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_MuonTra();
		}
		else
		{
			goto nhapmathe;
		}
	}
nhapmathe: 
	int mathe; gotoXY(53, 16); cout << "        ";
	gotoXY(53, 16); cin >> mathe; fflush(stdin);
	NODE_THEDOCGIA *dg = new NODE_THEDOCGIA;
	if (Tim_MATHE(t, mathe) == NULL)
	{
		BaoLoi("DOC GIA NAY KHONG TON TAI");
		cout << "                           ";
		goto start;
	}
	else
	{
		dg = Tim_MATHE(t, mathe);
		clrscr();
		In_DS_MuonTra_1DG(dg);
		goto start;
	}

}
int TimViTri_MaDauSach(char masach[10])
{
	char *tam;
	tam = strtok(masach, "_");
	for (int i = 0; i < dsDauSach.n; i++)
	{
		if (stricmp(dsDauSach.ds[i]->ISBN, tam) == 0)
		{
			//cout << i;
			//system("pause");
			return i;
			
		}
	}
	return -1;
}

void DuyetCay_DocMuonTra(TREE t, ifstream &filein, int madocgia)
{	
	if (t != NULL)
	{
		if (t->data.MaThe == madocgia)
		{
			MUONTRA k;
				filein.getline(k.MaSach, 10, ',');
				filein >> k.NgayMuon.ngay;
				filein.seekg(1, 1);
				filein >> k.NgayMuon.thang;
				filein.seekg(1, 1);
				filein >> k.NgayMuon.nam;
				filein.seekg(1, 1);
				filein >> k.NgayPhaiTra.ngay;
				filein.seekg(1, 1);
				filein >> k.NgayPhaiTra.thang;
				filein.seekg(1, 1);
				filein >> k.NgayPhaiTra.nam;
				filein.seekg(1, 1);
				filein >> k.NgayTra.ngay;
				filein.seekg(1, 1);
				filein >> k.NgayTra.thang;
				filein.seekg(1, 1);
				filein >> k.NgayTra.nam;
				filein.seekg(1, 1);
				filein >> k.TrangThai;
				filein.ignore();
				Insert_MuonTra(t->data.First, t->data.Last, k);
				//cout << k.MaSach << endl;
				char tam[10];
				strcpy(tam, k.MaSach);
				int i = TimViTri_MaDauSach(tam);
				for (NODE_SACH *h = dsDauSach.ds[i]->FirstDanhMucSach; h != NULL; h = h->sNext)
				{
					if (stricmp(h->data.MaSach, k.MaSach) == 0)
					{
						h->data.TrangThai = 1;
						break;
					}
				}
		}
		else if (t->data.MaThe > madocgia)
		{
			DuyetCay_DocMuonTra(t->left, filein,madocgia);
		}
		else
		{
			DuyetCay_DocMuonTra(t->right, filein,madocgia);
		}
	}
}
void DocFile_MuonTra()
{
	ifstream filein;
	filein.open("DS_MUONTRA.TXT", ios_base::in);
	while (true)
	{
		int mathe;
		filein >> mathe;
		filein.seekg(1, 1);
		if (mathe == 0)
		{
			break;
		}
		DuyetCay_DocMuonTra(t, filein, mathe);
	}
	filein.close();
}
void DuyetCay_GhiMuonTra(TREE t, ofstream &fileout)
{
	if (t != NULL)
	{
		DuyetCay_GhiMuonTra(t->left, fileout);
		if (t->data.First != NULL)
		{
			for (NODEMUONTRA *k = t->data.First; k != NULL; k = k->next)
			{
				fileout << t->data.MaThe << ","
					<< k->data.MaSach << ","
					<< k->data.NgayMuon.ngay << "/" << k->data.NgayMuon.thang << "/" << k->data.NgayMuon.nam << ","
					<< k->data.NgayPhaiTra.ngay << "/" << k->data.NgayPhaiTra.thang << "/" << k->data.NgayPhaiTra.nam << ","
					<< k->data.NgayTra.ngay << "/" << k->data.NgayTra.thang << "/" << k->data.NgayTra.nam << ","
					<< k->data.TrangThai << endl;
			}
		}
		DuyetCay_GhiMuonTra(t->right, fileout);
	}
}
void GhiFile_MuonTra()
{
	ofstream fileout;
	fileout.open("DS_MUONTRA.TXT", ios_base::out);
	DuyetCay_GhiMuonTra(t, fileout);
	fileout << "0";
	fileout.close();
}

void MUON_SACH(TREE &t)
{
start:
	gotoXY(50, 15); Xu_Li_Con_Tro_Chi_Vi(true);
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_MuonTra();
		}
		else
		{
			goto nhapmathe;
		}
	}
nhapmathe:
	MUONTRA x; NODE_THEDOCGIA *dg = new NODE_THEDOCGIA; 

	int mathe;	 int dangmuon = 0; char tenSach[100];	char *maISBN;	char tam[10];
    gotoXY(53, 16); cout << "    ";
	gotoXY(53, 16); cin >> mathe; fflush(stdin);
	if (Tim_MATHE(t, mathe) == NULL)
	{
		BaoLoi("DOC GIA NAY KHONG TON TAI");
		cout << "                            ";
		goto start;
	}
	else // doc gia co ton tai
	{
		dg = Tim_MATHE(t, mathe);
		if (dg->data.TrangThaiThe == 0) // kiem tra trang thai the bi khoa thi khong cho muon
		{
			BaoLoi("THE BAN BI KHOA KHONG THE MUON SACH");
			cout << "                                     ";
			goto start;
		}
		else // The hoat dong binh thuong thi in ra thong tin doc gia
		{
			gotoXY(30, 17); cout << "                                                            ";

			In_Sach_1DG_DangMuon(dg->data.First, dangmuon, dg);

			if (KiemTra_QuaHan(dg->data.Last) == true)
			{
				BaoLoi("BAN CO SACH QUA HAN CHUA TRA NEN KHONG THE MUON THEM");
				cout << "                                                       ";
				goto start;
			}
			else // khong co sach qua han 
			{
				while (true)
				{
				nhapsach:
					if (dangmuon >= 3) // kiem tra tiep tuc neu da muon 3 cuon thi k cho muon them
					{
						BaoLoi("BAN DA MUON 3 CUON KHONG THE MUON THEM");
						cout << "                                        ";
						goto start;
					}
					while (getchar() != '\n');
					gotoXY(30, 18); cout << "NHAP TEN SACH: ";
					gotoXY(44, 18); cout << "                 ";
					gotoXY(44, 18); gets_s(tenSach);
					if (stricmp(tenSach, "0") == 0)
					{
						goto start;
					}
					int i = Search_Ten(dsDauSach, tenSach);

						// kiem tra xem doc gia da muon sach do hay chua
					if (i == -1)
					{
						BaoLoi("KHONG CO SACH NAY!");
							cout << "                     ";
							goto nhapsach;
					}
					else
					{
						for (NODEMUONTRA *h = dg->data.First; h != NULL; h = h->next)
						{
							strcpy(tam, h->data.MaSach);
							maISBN = strtok(tam, "_");
							if (stricmp(maISBN, dsDauSach.ds[i]->ISBN) == 0)
							{
								BaoLoi("BAN DA MUON QUYEN SACH NAY, KHONG THE MUON THEM");
								cout << "                                                  ";
								goto nhapsach;
							}
						}
						gotoXY(30, 35); cout << "MA DAU SACH: ";
						gotoXY(44, 35); cout << "         ";
						gotoXY(44, 35); cout << dsDauSach.ds[i]->ISBN;
						gotoXY(60, 35); cout << "TEN SACH: ";
						gotoXY(70, 35); cout << "                         ";
						gotoXY(70, 35);	cout << dsDauSach.ds[i]->TenSach;
						for (NODE_SACH *k = dsDauSach.ds[i]->FirstDanhMucSach; k != NULL; k = k->sNext)
						{

							if (k->data.TrangThai == 0)
							{
								strcpy(x.MaSach, k->data.MaSach);
								x.NgayMuon = Lay_time_Hethong();
								x.NgayPhaiTra = Lay_time_Phai_Tra_Sach();
								x.NgayTra.ngay = 0;
								x.NgayTra.thang = 0;
								x.NgayTra.nam = 0;
								x.TrangThai = 0;
								Insert_MuonTra(dg->data.First, dg->data.Last, x);
								k->data.TrangThai = 1;
								dsDauSach.ds[i]->SoLuotMuon += 1;

								BaoLoi("CHO MUON THANH CONG");
								cout << "                      ";
								//clrscr();
								//In_Sach_1DG_DangMuon(dg->data.First, dangmuon, dg);
								dangmuon++;
								goto nhapsach;
							}
						}
						/*BaoLoi("BAN DA MUON SACH NAY!");
						cout << "                           ";
						goto nhapsach;*/
					}
				}
			}
		}
	}
}
void Xoa_First_NODEMUONTRA(NODEMUONTRA *&First)
{
	NODEMUONTRA *p;
	{
		if (First == NULL)
		{
			cout << "\nDANH SACH DANG RONG!!";
		}
		else
		{
			p = First; // p la nut can xoa
			if (First->next == NULL) // truong hop danh sach co mot nut
			{
				First = NULL;
			}
			else // truong hop danh sach co nhieu nut
			{
				First = p->next;
				First->rev = NULL;
			}
			delete p;
		}
	}
}
void Xoa_NODEMUONTRA(NODEMUONTRA *&First, NODEMUONTRA *p)
{
	NODEMUONTRA *q, *r;
	if (p == NULL)
	{
		cout << "\nNODE KHONG TON TAI! KIEM TRA LAI";
	}
	else
	{
		if (First == NULL)
		{
			cout << "\nDANH SACH DANG RONG!";
		}
		else
		{
			if (p == First)
			{
				Xoa_First_NODEMUONTRA(First);
			}
			else
			{
				q = p->rev; // q la nut truoc
				r = p->next; // r la nut sau
				// tao lien ket giua q va r
				r->rev = q;
				q->next = r;
				delete p;
			}
		}
	}
}
void Tra_Sach(TREE &t)
{
start:
	gotoXY(50, 15); Xu_Li_Con_Tro_Chi_Vi(true);
	while (true)
	{
		//int key = _getch();
		int key = _getch();
		if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_MuonTra();
		}
		else
		{
			goto nhapmathe;
		}
	}
nhapmathe:
	int mathe; int dangmuon = 0; NODE_THEDOCGIA *dg = new NODE_THEDOCGIA;
	char masach[10];  char *isbn; char matam[10];
	gotoXY(53, 16); cout << "    ";
	gotoXY(53, 16); cin >> mathe; fflush(stdin);
	dg = Tim_MATHE(t, mathe);
	if (dg == NULL)
	{
		BaoLoi("KHONG CO DOC GIA NAY");
		cout << "                        ";
		goto start;
	}
	else
	{
		In_Sach_1DG_DangMuon(dg->data.First, dangmuon, dg);
		if (dangmuon <= 0)
		{
			BaoLoi("BAN CHUA MUON SACH NAO");
			cout << "                          ";
			goto start;
		}
		else
		{
		nhapsach: 
			gotoXY(55, 18); cout << "NHAP MA SACH: ";
			gotoXY(68, 18); cout << "                       ";
			while (getchar() != '\n');
			gotoXY(68, 18); gets_s(masach);
			//while (getch() != '\n');
			if (stricmp(masach, "0") == 0)
			{
				goto start;
			}
		trasach:
			for (NODEMUONTRA *k = dg->data.First; k != NULL; k = k->next)
			{
				if (stricmp(masach, k->data.MaSach) == 0 && k->data.TrangThai == 0)
				{
					k->data.TrangThai = 1;
					k->data.NgayTra = Lay_time_Hethong();
					strcpy(matam, k->data.MaSach);
					isbn = strtok(matam, "_");
					int vitri = Search(dsDauSach, isbn);
					for (NODE_SACH *h = dsDauSach.ds[vitri]->FirstDanhMucSach; h != NULL; h = h->sNext)
					{
						if (stricmp(h->data.MaSach, k->data.MaSach) == 0)
						{
							h->data.TrangThai = 0;
							break;
						}
					}
					BaoLoi("TRA SACH THANH CONG");
					cout << "                       ";
					dangmuon--;
					goto trasach;
				}
				/*
				BaoLoi("BAN CHUA MUON SACH NAY");
				cout << "                          ";
				goto trasach;*/
				/*else
				{
					BaoLoi("BAN CHUA MUON SACH NAY");
					cout << "                          ";
					goto trasach;
				}*/
			}
		}
	}
}
//void TRA_SACH(TREE &t)
//{
//start:
//	gotoXY(50, 15); Xu_Li_Con_Tro_Chi_Vi(true);
//	while (true)
//	{
//		int key = _getch();
//		if (key == KEY_ESC)
//		{
//			clrscr();
//			GiaoDien_MuonTra();
//		}
//		else
//		{
//			goto nhapmathe;
//		}
//	}
//nhapmathe:
//	int mathe; int dangmuon = 0;
//	NODE_THEDOCGIA *dg = new NODE_THEDOCGIA; 
//	//dg->left = NULL; dg->right = NULL; dg->data.First = NULL; dg->data.Last = NULL;
//	char MaSach[10];		char tam[10]; char *maISBN;
//	gotoXY(53, 16); cout << "    ";
//	gotoXY(53, 16); cin >> mathe; fflush(stdin);
//	dg = Tim_MATHE(t, mathe);
//	if (dg == NULL)
//	{
//		BaoLoi("MA THE KHONG TON TAI");
//		cout << "                       ";
//		goto start;
//	}
//	else
//	{
//		In_Sach_1DG_DangMuon(dg->data.First, dangmuon,dg);
//		if (dangmuon == 0)
//		{
//			BaoLoi("BAN CHUA MUON SACH NAO");
//			cout << "                         ";
//			goto start;
//		}
//		else // DOC GIA DA CO MUON SACH
//		{
//		trasach:
//			char *masach;
//			gotoXY(55, 18); cout << "NHAP MA SACH: ";
//			gotoXY(68, 18); cout << "           ";			
//			gotoXY(68, 18);		gets_s(MaSach);
//			
//			if (stricmp(MaSach, "0") == 0)
//			{
//				goto start;
//			}
//			// cat ma sach lay ma isbn
//			masach = strtok(MaSach, "_");
//			for (NODEMUONTRA *k = dg->data.First; k != NULL; k = k->next)
//			{
//				// tim trong danh sach muon tra co ma sach da nhap vao hay khong
//				strcpy(tam, k->data.MaSach);
//				
//				maISBN = strtok(tam, "_");
//				//if (k->data.TrangThai == 0 && (stricmp(masach, maISBN) == 0))
//				//{
//				//	/*if (stricmp(masach, maISBN) == 0)
//				//	{*/
//				//		k->data.TrangThai = 1;
//				//		k->data.NgayTra = Lay_time_Hethong();
//				//		int vitriDauSach = Search(dsDauSach, maISBN);
//				//		for (NODE_SACH *h = dsDauSach.ds[vitriDauSach]->FirstDanhMucSach; h != NULL; h = h->sNext)
//				//		{
//				//			if (stricmp(h->data.MaSach, k->data.MaSach) == 0)
//				//			{
//				//				h->data.TrangThai = 0;
//				//				break;
//				//			}
//				//		}
//				//		//Xoa_NODEMUONTRA(dg->First, k);
//				//		BaoLoi("DA TRA THANH CONG");
//				//		cout << "                    ";
//				//		dangmuon--;
//				//		clrscr();
//				//		In_Sach_1DG_DangMuon(dg->data.First, dangmuon, dg);
//				//		goto trasach;
//				//	//}
//				//}
//				if ((stricmp(masach, maISBN) == 0) && (k->data.TrangThai == 0))
//				{
//					k->data.TrangThai = 1;
//					k->data.NgayTra = Lay_time_Hethong();
//					int vitriDauSach = Search(dsDauSach, maISBN);
//					for (NODE_SACH *h = dsDauSach.ds[vitriDauSach]->FirstDanhMucSach; h != NULL; h = h->sNext)
//					{
//						if (stricmp(h->data.MaSach, k->data.MaSach) == 0)
//						{
//							h->data.TrangThai = 0;
//							break;
//						}
//					}
//					//Xoa_NODEMUONTRA(dg->First, k);
//					BaoLoi("DA TRA THANH CONG");
//					cout << "                    ";
//					dangmuon--;
//					clrscr();
//					In_Sach_1DG_DangMuon(dg->data.First, dangmuon, dg);
//					goto trasach;
//				}
//			}
//				BaoLoi("MA SACH KHONG TON TAI");
//				cout << "                           ";
//				goto trasach;
//		}
//	}
//}
void MAT_SACH(TREE &t)
{
start:
	gotoXY(50, 15); Xu_Li_Con_Tro_Chi_Vi(true);
	while (true)
	{
		int key = _getch();
		if (key == KEY_ESC)
		{
			clrscr();
			GiaoDien_MuonTra();
		}
		else
		{
			goto nhapmathe;
		}
	}
nhapmathe:
	int mathe; int dangmuon = 0;
	NODE_THEDOCGIA *dg = new NODE_THEDOCGIA;
//	dg->left = NULL; dg->right = NULL; dg->data.First = NULL; dg->data.Last = NULL;
	char MaSach[10];	char *masachtam;	char tam[10]; char *maISBN;	
	gotoXY(53, 16); cout << "    ";
	gotoXY(53, 16); cin >> mathe; fflush(stdin);
	dg = Tim_MATHE(t, mathe);
	if (dg == NULL)
	{
		BaoLoi("MA THE KHONG TON TAI");
		cout << "                       ";
		goto start;
	}
	else
	{
		//clrscr();
		In_Sach_1DG_DangMuon(dg->data.First, dangmuon, dg);
		if (dangmuon <= 0)
		{
			BaoLoi("BAN CHUA MUON SACH NAO");
			cout << "                         ";
			goto start;
		}
		else
		{
		matsach:
			gotoXY(55, 18); cout << "NHAP MA SACH: ";
			gotoXY(69, 18); cout << "            ";
			while (getchar() != '\n');
			gotoXY(69, 18); gets_s(MaSach);
			if (stricmp(MaSach, "0") == 0)
			{
				goto start;
			}
			//masachtam = strtok(MaSach, "_");
			for (NODEMUONTRA *k = dg->data.First; k != NULL; k = k->next)
			{
				strcpy(tam, k->data.MaSach);
				maISBN = strtok(tam, "_");
				if ((stricmp(MaSach, k->data.MaSach) == 0) && (k->data.TrangThai == 0))
				{
					k->data.TrangThai = 2;
					for (NODE_SACH *h = dsDauSach.ds[Search(dsDauSach, maISBN)]->FirstDanhMucSach; h != NULL; h = h->sNext)
					{
						if (stricmp(h->data.MaSach, k->data.MaSach) == 0)
						{
							h->data.TrangThai = 2;
							break;
						}
					}
					BaoLoi("CAP NHAT THANH CONG!");
					cout << "                       ";
					dangmuon--;
					//clrscr();
					//In_Sach_1DG_DangMuon(dg->First, dangmuon,dg);
					goto start;
				}
			}
				BaoLoi("MA SACH KHONG TON TAI!");
				cout << "                         ";
				goto start;
			}
		}
	}

void GiaoDien_MatSach()
	{
		clrscr();
		Normal();
		resizeConsole(1000, 700);
		gotoXY(0, 0);
		DRAW_title();
		Ve_Khung(5, 2, 110, 35);
		gotoXY(30, 13); cout << "=======================MAT SACH=======================";
		HighLight(); gotoXY(33, 15); cout << "NHAN ESC DE THOAT"; Normal();
		HighLight(); gotoXY(65, 15); cout << "NHAN PHIM BAT KY DE NHAP"; Normal();
		gotoXY(33, 16); cout << "NHAP MA THE DOC GIA:";
		Ve_Khung(25, 19, 70, 15); liney(20, 33, 40); liney(20, 33, 58); liney(20, 33, 78);
		gotoXY(28, 20); cout << "MA SACH";
		gotoXY(44, 20); cout << "NGAY MUON";
		gotoXY(61, 20); cout << "NGAY PHAI TRA";
		gotoXY(82, 20); cout << "NGAY TRA";
		MAT_SACH(t);
	}
void GiaoDien_In_DS_MuonTra()
	{
		clrscr();
		resizeConsole(1000, 700);
		gotoXY(0, 0);
		DRAW_title();
		Ve_Khung(5, 2, 110, 35);
		gotoXY(30, 13); cout << "=======================DANH SACH MUON TRA=======================";
		HighLight(); gotoXY(33, 15); cout << "NHAN ESC DE THOAT"; Normal();
		gotoXY(33, 16); cout << "NHAP MA THE DOC GIA:";
		Ve_Khung(20, 19, 80, 15); liney(20, 33, 35); liney(20, 33, 50); liney(20, 33, 65); liney(20, 33, 80);
		gotoXY(25, 20); cout << "MA SACH";
		gotoXY(38, 20); cout << "NGAY MUON";
		gotoXY(51, 20); cout << "NGAY PHAI TRA";
		gotoXY(68, 20); cout << "NGAY TRA";
		gotoXY(82, 20); cout << "TRANG THAI SACH";
		In_DS_MUONTRA(t);
	}
void GiaoDien_MuonSach()
	{
		clrscr();
		//Normal();
		resizeConsole(1000, 700);
		gotoXY(0, 0);
		DRAW_title();
		Ve_Khung(5, 2, 110, 35);
		gotoXY(30, 13); cout << "=======================MUON SACH=======================";
		HighLight(); gotoXY(33, 15); cout << "NHAN ESC DE THOAT"; Normal();
		HighLight(); gotoXY(65, 15); cout << "NHAN PHIM BAT KY DE NHAP"; Normal();
		gotoXY(33, 16); cout << "NHAP MA THE DOC GIA:";
		Ve_Khung(25, 19, 70, 15); liney(20, 33, 40); liney(20, 33, 58); liney(20, 33, 78);
		gotoXY(28, 20); cout << "MA SACH";
		gotoXY(44, 20); cout << "NGAY MUON";
		gotoXY(61, 20); cout << "NGAY PHAI TRA";
		gotoXY(82, 20); cout << "NGAY TRA";
		MUON_SACH(t);
	}
void GiaoDien_TraSach()
	{
		clrscr();
		Normal();
		resizeConsole(1000, 700);
		gotoXY(0, 0);
		DRAW_title();
		Ve_Khung(5, 2, 110, 35);
		gotoXY(30, 13); cout << "=======================TRA SACH=======================";
		HighLight(); gotoXY(33, 15); cout << "NHAN ESC DE THOAT"; Normal();
		HighLight(); gotoXY(65, 15); cout << "NHAN PHIM BAT KY DE NHAP"; Normal();
		gotoXY(33, 16); cout << "NHAP MA THE DOC GIA:";
		Ve_Khung(25, 19, 70, 15); liney(20, 33, 40); liney(20, 33, 58); liney(20, 33, 78);
		gotoXY(28, 20); cout << "MA SACH";
		gotoXY(44, 20); cout << "NGAY MUON";
		gotoXY(61, 20); cout << "NGAY PHAI TRA";
		gotoXY(82, 20); cout << "NGAY TRA";
		Tra_Sach(t);
	}

void GiaoDien_MuonTra()
{
		clrscr();
		Normal();
		resizeConsole(1000, 700);
		gotoXY(0, 0);
		DRAW_title();
		Ve_Khung(5, 2, 110, 35);
		gotoXY(30, 13); cout << "=======================QUAN LY MUON TRA=======================";
		Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "      MUON SACH    ";
		Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "      TRA SACH     ";
		Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "   IN DS MUON TRA  ";
		Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "      MAT SACH     ";

		HighLight();
		Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "      MUON SACH    ";
		Normal();
		Xu_Li_Con_Tro_Chi_Vi(false);
		int kt = 1;

		while (true){
			int key = _getch();
			// bat phim xuong
			if (key == KEY_DOWN)
			{
				if (kt == 1){
					kt = 2;
				}
				else if (kt == 2){
					kt = 3;
				}
				else if (kt == 3){
					kt = 4;
				}
				else if (kt == 4){
					kt = 1;
				}
			}
			// bat phim len
			else if (key == KEY_UP){
				if (kt == 1){
					kt = 4;
				}
				else if (kt == 2){
					kt = 1;
				}
				else if (kt == 3){
					kt = 2;
				}
				else if (kt == 4){
					kt = 3;
				}
			}
			else if (key == KEY_ESC)
			{
				clrscr();
				GiaoDien_Chinh();
			}
			if (kt == 1)
			{
				HighLight();
				Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "      MUON SACH    ";
				Normal();
				Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "      TRA SACH     ";
				Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "   IN DS MUON TRA  ";
				Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "      MAT SACH     ";
			}
			else if (kt == 2)
			{
				HighLight();
				Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "      TRA SACH     ";
				Normal();
				Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "      MUON SACH    ";
				Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "   IN DS MUON TRA  ";
				Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "      MAT SACH     ";
			}
			else if (kt == 3)
			{
				HighLight();
				Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "   IN DS MUON TRA  ";
				Normal();
				Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "      MUON SACH    ";
				Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "      TRA SACH     ";
				Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "      MAT SACH     ";
			}
			else if (kt == 4)
			{
				HighLight();
				Ve_Khung(50, 29, 20, 2); gotoXY(51, 30); cout << "      MAT SACH     ";
				Normal();
				Ve_Khung(50, 17, 20, 2); gotoXY(51, 18); cout << "      MUON SACH    ";
				Ve_Khung(50, 21, 20, 2); gotoXY(51, 22); cout << "      TRA SACH     ";
				Ve_Khung(50, 25, 20, 2); gotoXY(51, 26); cout << "   IN DS MUON TRA  ";
			}

			if (key == KEY_ENTER)
			{
				if (kt == 1)
				{
					clrscr();
					GiaoDien_MuonSach();
				}
				else if (kt == 2)
				{
					clrscr();
					GiaoDien_TraSach();
				}
				else if (kt == 3)
				{
					clrscr();
					GiaoDien_In_DS_MuonTra();
				}
				else if (kt == 4)
				{
					clrscr();
					GiaoDien_MatSach();
				}
			}
		}
	
}
void GiaoDien_Chinh()
{
	Normal();
	resizeConsole(1000, 700);
	gotoXY(0, 0);
	DRAW_title();
	Ve_Khung(5, 2, 110, 35);
	Ve_Khung(45, 15, 30, 2); gotoXY(46, 16); cout << "       QUAN LY DAU SACH      ";
	Ve_Khung(45, 19, 30, 2); gotoXY(46, 20); cout << "    QUAN LY DANH MUC SACH    ";
	Ve_Khung(45, 23, 30, 2); gotoXY(46, 24); cout << "     QUAN LY THE DOC GIA     ";
	Ve_Khung(45, 27, 30, 2); gotoXY(46, 28); cout << "       QUAN LY MUON TRA      ";
	Ve_Khung(45, 31, 30, 2); gotoXY(46, 32); cout << "              THOAT          ";

	HighLight();
	Ve_Khung(45, 15, 30, 2); gotoXY(46, 16); cout << "       QUAN LY DAU SACH      ";
	Normal();
	Xu_Li_Con_Tro_Chi_Vi(false);
	int kt = 1;


	while (true)
	{
		int key = _getch();
		// bat phim xuong
		if (key == KEY_DOWN)
		{
			if (kt == 1){
				kt = 2;
			}
			else if (kt == 2){
				kt = 3;
			}
			else if (kt == 3){
				kt = 4;
			}
			else if (kt == 4){
				kt = 5;
			}
			else if (kt == 5)
			{
				kt = 1;
			}

		}
		// bat phim len
		else if (key == KEY_UP){
			if (kt == 1){
				kt = 5;
			}
			else if (kt == 2){
				kt = 1;
			}
			else if (kt == 3){
				kt = 2;
			}
			else if (kt == 4){
				kt = 3;
			}
			else if (kt == 5)
			{
				kt = 4;
			}
		}

		if (kt == 1)
		{
			HighLight();
			Ve_Khung(45, 15, 30, 2); gotoXY(46, 16); cout << "       QUAN LY DAU SACH      ";
			Normal();
			Ve_Khung(45, 19, 30, 2); gotoXY(46, 20); cout << "    QUAN LY DANH MUC SACH    ";
			Ve_Khung(45, 23, 30, 2); gotoXY(46, 24); cout << "     QUAN LY THE DOC GIA     ";
			Ve_Khung(45, 27, 30, 2); gotoXY(46, 28); cout << "       QUAN LY MUON TRA      ";
			Ve_Khung(45, 31, 30, 2); gotoXY(46, 32); cout << "              THOAT          ";
		}
		else if (kt == 2)
		{
			HighLight();
			Ve_Khung(45, 19, 30, 2); gotoXY(46, 20); cout << "    QUAN LY DANH MUC SACH    ";
			Normal();
			Ve_Khung(45, 15, 30, 2); gotoXY(46, 16); cout << "       QUAN LY DAU SACH      ";
			Ve_Khung(45, 23, 30, 2); gotoXY(46, 24); cout << "     QUAN LY THE DOC GIA     ";
			Ve_Khung(45, 27, 30, 2); gotoXY(46, 28); cout << "       QUAN LY MUON TRA      ";
			Ve_Khung(45, 31, 30, 2); gotoXY(46, 32); cout << "              THOAT          ";
		}
		else if (kt == 3)
		{
			HighLight();
			Ve_Khung(45, 23, 30, 2); gotoXY(46, 24); cout << "     QUAN LY THE DOC GIA     ";
			Normal();
			Ve_Khung(45, 15, 30, 2); gotoXY(46, 16); cout << "       QUAN LY DAU SACH      ";
			Ve_Khung(45, 19, 30, 2); gotoXY(46, 20); cout << "    QUAN LY DANH MUC SACH    ";
			Ve_Khung(45, 27, 30, 2); gotoXY(46, 28); cout << "       QUAN LY MUON TRA      ";
			Ve_Khung(45, 31, 30, 2); gotoXY(46, 32); cout << "              THOAT          ";
		}
		else if (kt == 4)
		{
			HighLight();
			Ve_Khung(45, 27, 30, 2); gotoXY(46, 28); cout << "       QUAN LY MUON TRA      ";
			Normal();
			Ve_Khung(45, 15, 30, 2); gotoXY(46, 16); cout << "       QUAN LY DAU SACH      ";
			Ve_Khung(45, 19, 30, 2); gotoXY(46, 20); cout << "    QUAN LY DANH MUC SACH    ";
			Ve_Khung(45, 23, 30, 2); gotoXY(46, 24); cout << "     QUAN LY THE DOC GIA     ";
			Ve_Khung(45, 31, 30, 2); gotoXY(46, 32); cout << "              THOAT          ";
		}
		else if (kt == 5)
		{
			HighLight();
			Ve_Khung(45, 31, 30, 2); gotoXY(46, 32); cout << "              THOAT          ";			
			Normal();
			Ve_Khung(45, 15, 30, 2); gotoXY(46, 16); cout << "       QUAN LY DAU SACH      ";
			Ve_Khung(45, 19, 30, 2); gotoXY(46, 20); cout << "    QUAN LY DANH MUC SACH    ";
			Ve_Khung(45, 23, 30, 2); gotoXY(46, 24); cout << "     QUAN LY THE DOC GIA     ";
			Ve_Khung(45, 27, 30, 2); gotoXY(46, 28); cout << "       QUAN LY MUON TRA      ";
		}

		// bat phim enter
		if (key == KEY_ENTER)
		{
			if (kt == 1)
			{
				clrscr();
				GiaoDien_DauSach();
			}
			else if (kt == 2)
			{
				clrscr();
				GiaoDien_DanhMucSach();
			}
			else if (kt == 3)
			{
				clrscr();
				GiaoDien_TheDocGia();
			}
			else if (kt == 4)
			{
				clrscr();
				GiaoDien_MuonTra();
			}
			else if (kt == 5)
			{	
				//system("pause");
				GhiFile_DauSach();
				GhiFile_DocGia();
				GhiFile_MuonTra();
				GhiFile_MaThe();
				exit(0);
			}
		}
	}
}
