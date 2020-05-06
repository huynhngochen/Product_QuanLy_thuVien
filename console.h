#pragma once
#include<iostream>
using namespace std;
#include <stdio.h>
#include <conio.h>
#include<string>
#include<string.h>
#include<cmath>
#include <windows.h>
#pragma warning(disable:4996) // bỏ qua lỗi 4996 - lỗi bảo mật


#define ColorCode_Black			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7


//key
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_BACKSPACE 8
#define KEY_DELETE 83
#define KEY_TAB 9
#define KEY_INS 82
#define KEY_CONTROL 224
#define F4 115
#define KEY_HOME 71
#define BELL 7

int maxX, maxY;

void getScreen() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	maxX = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	maxY = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void RemoveScroll() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
	csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;
	SetConsoleScreenBufferSize(hstdout, csbi.dwSize);

	HWND x = GetConsoleWindow();
	ShowScrollBar(x, SB_BOTH, FALSE);
}

void fullScreen() {
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

void clrscr()
{
	system("cls");
}

void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void Normal() {
	SetColor(15);
	SetBGColor(0);
}
void HighLight() {
	SetColor(15);
	SetBGColor(12);
}


void clreol() {
	COORD coord;
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = info.dwCursorPosition.X;
	coord.Y = info.dwCursorPosition.Y;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
		info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
	gotoXY(info.dwCursorPosition.X, info.dwCursorPosition.Y);

}
void BaoLoi(char *s){
	int x = whereX(), y = whereY();
	gotoXY(45, 1);
	HighLight();
	cout << s;
	Normal();
	gotoXY(45, 1);
	Sleep(1500);
	clreol();
}

/* ======================================= HÀM XỬ LÍ ĐỘ HỌA ======================================= */

// hàm vẽ khung băt đầu tại tọa độ (x, y) với chiều dài width và chiều cao height
void Ve_Khung(int x, int y, int width, int height)
{
	char a = 218, b = 196, c = 191, d = 179, e = 192, f = 217;//Ki tu dac biet 
	gotoXY(x, y);
	cout << a;                // goc tren trai
	for (int i = 1; i < width; i++) {
		gotoXY(x + i, y);
		cout << b;
	}
	gotoXY(x + width, y);     // goc tren phai
	cout << c;
	for (int i = 1; i < height; i++) {
		gotoXY(x, y + i);
		cout << d;
	}
	gotoXY(x, y + height);    // goc duoi trai
	cout << e;
	for (int i = 1; i < width; i++) {
		gotoXY(x + i, y + height);
		cout << b;
	}
	gotoXY(x + width, y + height);   // goc duoi phai
	cout << f;
	for (int i = 1; i < height; i++) {
		gotoXY(x + width, y + i);
		cout << d;
	}
}

//ẩn đi con trỏ chỉ vị nhấp nháy trên màn hình, Xu_Li_Con_Tro_Chi_Vi(0) -> Ẩn con trỏ ------- Xu_Li_Con_Tro_Chi_Vi(1)-> hiện lại con trỏ
void Xu_Li_Con_Tro_Chi_Vi(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

// vẽ đường thẳng ngang từ tọa độ (x0, y) đến (x1, y)
void linex(int x0, int x1, int y)
{
	gotoXY(x0, y);
	for (int i = x0; i < x1; i++)
	{
		cout << char(196);
	}
}

//vẽ đường thẳng dọc từ tọa độ (x, y0) đến (x, y1)
void liney(int y0, int y1, int x)
{
	for (int i = y0; i <= y1; i++)
	{
		gotoXY(x, i);
		cout << char(179);
	}
	gotoXY(whereX(), y0);
}
void DRAW_title(){
	ifstream file;
	file.open("title.txt", ios::out);
	string line;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			cout << line << endl;
		}
		file.close();
	}
}
//mau nen chu
void textbk(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
/* ======================================= HÀM XỬ LÍ NHẬP DỮ LIỆU ======================================= */
bool Kiem_Tra_Ki_Tu_So(char c)
{
	if (c < '0' || c > '9')
	{
		return false;
	}
	return true;
}

// hàm chuyển đổi chuỗi số sang số nguyên
int Chuoi_Sang_So(string str)
{
	int Sum = 0;
	int length = str.length();
	int mu = length - 1;
	for (int i = 0; i < length; i++)
	{
		Sum += ((str[i] - 48) * pow(10, mu-- * 1.0));
	}
	return Sum;
}

// hàm loại bỏ các khoảng trắng dư thừa
void Chuan_Hoa_Khoang_Trang(string & str)
{
	// xóa khoảng trắng mà vì i < str.length() - 1, nên chiều dài phải khác 0 thì mới duyệt
	if (str.length() != 0)
	{
		for (int i = 0; i < str.length() - 1; i++)
		{
			if (str[i] == ' ' && str[i + 1] == ' ')
			{
				str.erase(str.begin() + i);
				i--;
			}
		}
		if (str[0] == ' ')
		{
			str.erase(str.begin() + 0);
		}
		if (str[str.length() - 1] == ' ')
		{
			str.erase(str.begin() + str.length() - 1);
		}
	}
}

//// hàm chuẩn hóa theo nguyên tắc in hoa các kí tự của chuỗi
//void Chuan_Hoa_In_Hoa(string & str)
//{
//	int length = str.length();
//	for (int i = 0; i < length; i++)
//	{
//		if (str[i] >= 97 && str[i] <= 122)
//		{
//			str[i] -= 32;
//		}
//	}
//}

// hàm trả về false nếu chuỗi toàn khoảng trắng. Ngược lại trả về true
bool Kiem_Tra_Khoang_Trang(string str)
{
	int length = str.length();
	for (int i = 0; i < length; i++)
	{
		if (str[i] != ' ')
		{
			return true;
		}
	}
	return false;
}
//int Nhap_So_Nguyen()
//{
//	string str;
//	char c;
//	c = _getch(); // nhập kí tự đầu tiên
//
//	// vòng lặp lặp vô tận cho đến khi ta nhấn phím enter <=> kết thúc việc nhập
//	while ((int)c != 13)
//	{
//
//		if (int(c) == 8)
//		{
//
//			if (str.length() != 0) // nếu như độ dài chuỗi bằng 0 thì ko cho xóa tiếp
//			{
//				cout << "\b \b"; // khi bấm phím Backspace thì sẽ xóa từng kí tự của chuỗi kí tự hiện tại
//			}
//			if (str.length() != 0) // xóa kí tự cuối trong chuỗi string 
//			{
//				str.erase(str.begin() + (str.length() - 1));
//			}
//		}
//		else // nếu không phải là kí tự enter và Backpace thì kiểm tra nếu là kí tự số thì thêm vào chuỗi
//		{
//			cout << c;
//			if (Kiem_Tra_Ki_Tu_So(c) == false)
//			{
//				cout << "\nKieu du lieu khong hop le. Xin nhap lai\n";
//				str.resize(0);
//			}
//			else
//			{
//				str.push_back(c);
//			}
//		}
//		c = _getch();
//	}
//	return Chuoi_Sang_So(str);
//}