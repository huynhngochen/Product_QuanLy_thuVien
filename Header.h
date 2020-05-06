//#include <iostream>
#pragma once
#define MAXDS 1000
using namespace std;
// danh muc sach
struct sach
{
	char MaSach[10];
	int TrangThai;
	char ViTriSach[50];
};
typedef struct sach SACH;
struct node_sach
{
	SACH data;
	struct node_sach *sNext;
};
typedef struct  node_sach NODE_SACH;

// dau sach
struct dausach
{
	char ISBN[6];
	char TenSach[100];
	char TacGia[50];
	char TheLoai[50];
	int NamXuatBan;
	int SoTrang;
	int SoLuongSach;
	int SoLuotMuon;
	NODE_SACH *FirstDanhMucSach = NULL;
};
typedef struct dausach DAUSACH;

struct DS_DAUSACH
{
	int n; // so luong phan tu trong ds
	DAUSACH *ds[MAXDS]; // mang con tro danh sach cac dau sach
};
// muon tra sach
struct ngay_thang
{
	int ngay;
	int thang;
	int nam;
};
typedef struct ngay_thang Ngay_Thang;
struct muontra
{
	char MaSach[10];
	Ngay_Thang NgayMuon;
	Ngay_Thang NgayTra;
	Ngay_Thang NgayPhaiTra;
	int TrangThai;
};
typedef struct muontra MUONTRA;
struct node_muontra
{
	MUONTRA data;
	struct node_muontra *next;
	struct node_muontra *rev;
};
typedef struct node_muontra NODEMUONTRA;

// the doc gia
struct thedocgia
{
	int MaThe = 0;
	char Ho[20];
	char Ten[10];
	char Phai[5];
	int TrangThaiThe;
	int songayquahan=0;
	NODEMUONTRA *First, *Last;
};
typedef struct thedocgia THEDOCGIA;
struct node_thedocgia
{
	//int key;
	THEDOCGIA data;
	struct node_thedocgia *left;
	struct node_thedocgia *right;
	
};
typedef struct node_thedocgia NODE_THEDOCGIA;
typedef NODE_THEDOCGIA* TREE;

