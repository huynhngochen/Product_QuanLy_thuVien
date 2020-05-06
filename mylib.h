//
//#include <conio.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <dos.h>
//#include <string.h>
//#include <windows.h>
//#include <math.h>
//#pragma warning(disable: 4996)
//#define Enter 13
//const int WHITE = 15;
//#define PASSWORD "abcdef"
////const int WHITE=15;

#pragma once
//// hàm xóa 1 ký tự chuỗi ký tự
void Xoa_Ky_Tu(char s[], int vt)
{
	int n = strlen(s);
	for (int i = vt + 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n - 1] = '\0';
}
//
//// hàm thêm 1 ký tự chuỗi ký tự
void Them_Ky_Tu(char s[], int vt, char c)
{
	int n = strlen(s);
	for (int i = n - 1; i >= vt; i--)
	{
		s[i + 1] = s[i];
	}
	s[vt] = c;
	s[n + 1] = '\0';
}
//
//// hàm chuyển đổi chuỗi số sang số nguyên
int Chuoi_Sang_So(char str[])
{
	int Sum = 0;
	int length = strlen(str);
	int mu = length - 1;
	for (int i = 0; i < length; i++)
	{
		Sum += ((str[i] - 48) * pow(10, mu-- * 1.0));
	}
	return Sum;
}
//
//// hàm chuẩn hóa chuỗi theo nguyên tắc: viết hoa chữ cái đầu và mỗi từ cách nhau 1 khoảng trắng
void Chuan_Hoa(char str[])
{
	Them_Ky_Tu(str, 0, ' '); // thêm vào đầu kí tự khoảng trắng
	Them_Ky_Tu(str, strlen(str), ' '); // thêm vào cuối kí tự khoảng trắng. Nếu không thêm thì sẽ không kiểm tra kí tự cuối cùng, vì i < chiều dài - 1

	for (int i = 0; i < strlen(str) - 1; i++)
	{

		if (str[i] == ' ' && str[i + 1] == ' ') // nếu 2 kí tự liên tiếp nhau là khoảng trắng thì xóa 1 kí tự khoảng trắng
		{
			Xoa_Ky_Tu(str, i);
			i--;
		}
		else if (str[i] == ' ' && str[i + 1] != ' ') // nếu kí tự thứ i là khoảng trắng và kí tự i + 1 khác khoảng trắng thì in hoa kí tự i + 1(nếu là kí tự thường)
		{
			if (str[i + 1] >= 97 && str[i + 1] <= 122)
			{
				str[i + 1] -= 32;

			}
			// vòng lặp có tác dụng chuẩn hóa các kí tự tiếp theo sau kí tự vừa được chuẩn hóa thành các kí tự thường
			for (int j = i + 2;; j++)
			{
				if (str[j] >= 65 && str[j] < 97)
				{
					str[j] += 32;
				}
				else if (str[j] == ' ') // khi gặp khoảng trằng thì dừng 
				{
					i = j - 1; // trả i bằng j - 1, bởi sau đó i++
					break;
				}
			}
		}
	}

	if (str[0] == ' ')
	{
		Xoa_Ky_Tu(str, 0);
	}
	if (str[strlen(str) - 1] == ' ')
	{
		Xoa_Ky_Tu(str, strlen(str) - 1);
	}
}
void XoaTatCaDauCach(char s[])
{
	for (int i = 0; i<strlen(s); i++)
	if (s[i] == ' ')
	{
		Xoa_Ky_Tu(s, i);
		i--;
	}
	if (s[0] == ' ')
		Xoa_Ky_Tu(s, 0);
	if (s[strlen(s) - 1] == ' ')
		Xoa_Ky_Tu(s, strlen(s) - 1);
}
void VietHoaTatCa(char s[])
{
	int i;
	if (s[0] != ' ')
	{
		for (i = 0; i<strlen(s); i++)
		{
			//viet hoa tat ca ki tu 
			s[i] = toupper(s[i]);
		}
	}
}

void Chuan_Hoa_ISBN(char s[])
{
	XoaTatCaDauCach(s);
	VietHoaTatCa(s);
}

int NhapSo(char s[])
{
	int i, l;
	l = strlen(s);
	for (i = 0; i <= l; i++)
	{
		if (s[i] != '\0')
		if (s[i]< 48 || s[i]>57) return 0;
	}
	return 1;
}

