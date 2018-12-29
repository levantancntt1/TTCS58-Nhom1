#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int key;
string s;
string t;
string c;
int count;
char vemenu;

void Menu();
void Xulymenu();
void NhapChuoi();
void GhiFile();
string XoaKhoangTrang(string s);
string Proper(string s);
int Dem(string s);
void Ghifileketqua();
bool VeMenu();
bool ktchuoi();

void Menu()
{
	cout << "1. Nhap vao mot chuoi va ghi vao tap tin." << endl;
	cout << "2. Loai bo cac khoang trang thua." << endl;
	cout << "3. Chuan hoa chuoi dang Proper." << endl;
	cout << "4. Thong ke so luong cac ki tu chu cai." << endl;
	cout << "5. Ghi tat ca ket qua thuc hien duoc vao tap tin." << endl;
	cout << "6. Thoat."<<endl;
}

void Xulymenu()
{  
	int key;
	cout << "Lua chon cua ban: ";
	cin >> key;
	switch (key)
	{
		case 1:
			system("cls");
			cout<<"Ban da chon nhap vao mot chuoi!\n"<<endl;
			NhapChuoi();
			
		     if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            }
			break;
		case 2:
			system("cls");
			cout<<"Ban da chon loai bo cac khong trang thua!\n"<<endl;
			if(ktchuoi()) {
                system("cls");
			    t = XoaKhoangTrang(s);
			    cout << "Chuoi sau khi xoa khoang trang: " << t << endl;}
			else cout<<"Ban chua nhap chuoi\n";
			if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            }
			break;
		case 3:
			system("cls");
			cout<<"Ban da chon chuan hoa chuoi!\n"<<endl;
			if(ktchuoi()) {
                system("cls");
                if(!t.empty()) c = Proper(t);
                else c = Proper(s);
                cout << "Chuoi duoc chuan hoa: " << c << endl;
            } else {
                system("cls");
                cout << "Ban chua nhap chuoi\n" << endl;
                Menu();
                Xulymenu();
            }
			if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            }
		
			break;
		case 4:
			system("cls");
			cout<<"Ban da chon thong ke so luong cac ki tu!\n"<<endl;
			if(ktchuoi()) {
                system("cls");
                count = Dem(s);
            } else {
                system("cls");
                cout << "Ban chua nhap chuoi\n" << endl;
                Menu();
                Xulymenu();
            }
			if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            }
			break;
		case 5:
			system("cls");
			if(ktchuoi()){
				Ghifileketqua();
			}
			else cout<<"Ban chua nhap chuoi\n"<<endl;
			Menu();
            Xulymenu();
            if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            }
			break;
		case 6: 
		    cout<<"Da thoat\n"<<endl;
		    break;
	    default:
	    	system("cls");
	    	cout<<"Khong co thao tac nay\n"<<endl;
	    	Menu();
            Xulymenu();
	}
}
void NhapChuoi()
{
	cout << "Nhap vao mot chuoi: ";
	cin.ignore();
	getline(cin, s);
	cout << "Chuoi vua nhap la: "<< s << endl;
	GhiFile();
}

void GhiFile()
{
	ofstream ghi;
	ghi.open("Input1.txt");
	ghi << s;
	ghi.close();
	cout << "Ghi file thanh cong!\n" << endl;
}
void Ghifileketqua() {
    ofstream ghikq;
    ghikq.open("output1.txt");
    ghikq << s << endl;
    ghikq << t << endl;
    ghikq << c << endl;
    ghikq << count << endl;
    ghikq.close();
    cout << "Xuat file thanh cong!\n" << endl;
}
string XoaKhoangTrang(string s) {
    int n = s.length();
    char char_arr[n + 1];

    strcpy(char_arr, s.c_str());

    
    for(int i = 0; i < n - 1; i++) {
        if(char_arr[i] == ' ' && char_arr[i + 1] == ' ') {
            for(int j = i; j < n; j++) {
                char_arr[j] = char_arr[j + 1];
            }
            n--; i--;
        }
    }
    
    if(char_arr[0] == ' ') {
        for(int i = 0; i < n; i++) {
            char_arr[i] = char_arr[i + 1];
        }
        n--;
    }
    
    if(char_arr[n - 1] == ' ') n--;

    s = char_arr;
    cout << s << endl;
    return s.substr(0, n);
}

string Proper(string s)
{
	int n = s.length();
    char char_arr[n + 1];

    strcpy(char_arr, s.c_str());

    if(isalpha(char_arr[0]))
        char_arr[0] = toupper(char_arr[0]);

    for(int i = 1; i < n; i++) {
        if(char_arr[i] == ' ' && isalpha(char_arr[i + 1])) {
            char_arr[i + 1] = toupper(char_arr[i + 1]);
        } else {
            char_arr[i + 1] = tolower(char_arr[i + 1]);
        }
    }

    s = char_arr;
    return s;
}

int Dem(string s) {
    int n = s.length();

    count = 0;
    for(int i = 0; i < n; i++) {
        if(isalpha(s[i])) count++;
    }

    if(count) {
        cout << "So ki ki co trong chuoi: " << count << endl;
    } else {
        cout << "Khong co ki tu nao\n" << endl;
    }

    return count;
}
bool ktchuoi()
{
	if(s.empty())
	{
		return false;
	}
	else if(!s.empty()) return true;
}
bool VeMenu() {
    cout << "Nhan phim M de hien menu \n"; cin >> vemenu;
    if(vemenu == 'm' || vemenu == 'M') {
        return true;
    } return false;
}
int main()
{
	Menu();
	Xulymenu();
}
