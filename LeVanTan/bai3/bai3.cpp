#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
struct NhanVien {
    int Manhanvien;
    string Ten; // ten
    string Ho; // ho
    int Luong;
} nva, nvb;
//typedef NhanVien nva, nvb; // nva: nhan vien dc tim thay, nvb: nhan vien co luong cao nhat
class DSNhanvien 
{
    public:
        int n;
        void Nhap();
        void Xuat();
        void Sapxep();
        vector<NhanVien>DS;
        NhanVien TimNV();
        NhanVien MaxLuong();
};
DSNhanvien dsnv;
int key;
char vemenu;

void Docfile();
void Menu();
void Xulymenu();
void Ghifileinput(DSNhanvien dsnv);
void Ghifileoutput(NhanVien nva, NhanVien nvb, DSNhanvien dsnv);
bool VeMenu();

int main() 
{
    //Docfile();
    Menu();
    Xulymenu();
}

void DSNhanvien::Nhap() 
{
    int tam;
    cout << "Nhap vao so luong nhan vien: "; cin >> tam;
    int m = n;
    n += tam;
    DS.resize(n);
    // cout << m << " " << n << endl;
    for(int i = m; i < n; i++) {
        cout << "Nhap ma nhan vien: ";
        fflush(stdin);
        cin >> DS[i].Manhanvien;
        cout << "Nhap ho nhan vien: ";
        fflush(stdin);
        getline(cin, DS[i].Ho);
        cout << "Nhap ten nhan vien: ";
        fflush(stdin);
        getline(cin, DS[i].Ten);
        cout << "Nhap luong nhan vien: ";
        cin >> DS[i].Luong;
    }
}
void DSNhanvien::Xuat() 
{
    if(n) {
        cout << "STT" <<"\t\t"<< "Emp code" <<"\t\t"<< "Ho"<<"\t\t"<<"Ten"<<"\t\t"<< "Salary" << endl;;
        for(int i = 0; i < n; i++) {
            cout << i + 1 << "\t\t" << DS[i].Manhanvien << "\t\t"<< DS[i].Ho <<"\t\t"<< DS[i].Ten<<"\t\t"<< DS[i].Luong << endl;;
        }
    } else {
        cout << "Khong co nhan vien nao!" << endl;
    }
}
NhanVien DSNhanvien::TimNV() 
{
    int Manhanvientim;
    cout << "Nhap vao ma nhan vien can tim: ";
	cin >> Manhanvientim;
    for(int i = 0; i < n; i++) {
        if(DS[i].Manhanvien == Manhanvientim)
            return DS[i];
    }
    return nva;
}
NhanVien DSNhanvien::MaxLuong() 
{
    if(DS.size()) // Neu co DSNhanvien 
	{
        int maxluong = DS[0].Luong;
        int key = 0;
        for(int i = 1; i < n; i++) {
            if(DS[i].Luong > maxluong) {
                maxluong = DS[i].Luong;
                key = i; // Gan cho nhan vien co luong cao nhat hien tai
            }
        } return DS[key];
    } else {
        return nvb;
    }
}
void DSNhanvien::Sapxep() 
{
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++) 
		{
            if(DS[i].Ten.compare(DS[j].Ten) > 0) // So sanh hai chuoi ten nhan vien
			{
                NhanVien tam;
				tam = DS[i];
                DS[i] = DS[j];
                DS[j] = tam;
            } else if(DS[i].Ten.compare(DS[j].Ten) == 0) {
                if(DS[i].Ho.compare(DS[j].Ho) > 0) {
                    NhanVien tam = DS[i];
                    DS[i] = DS[j];
                    DS[j] = tam;
                }
            }
        }
}

void Menu() {
    cout << "1. Nhap vao nhan vien." << endl;
    cout << "2. Tim nhan vien theo ma nhan vien." << endl;
    cout << "3. Tim nhan vien co luong cao nhat." << endl;
    cout << "4. Sap xep nhan vien theo ten." << endl;
    cout << "5. Luu ket qua thuc hien." << endl;
    cout << "6. Thoat" << endl;
}
void Xulymenu() {
    cout << "Lua chon cua ban : "; cin >> key;
    switch(key) {
        case 1:
            //system("cls");
            cin.ignore();
            dsnv.Nhap();
            Ghifileinput(dsnv);
            if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Da thoat" << endl;
            }
            break;
        case 2:
            //system("cls");
            cin.ignore();
            nva = dsnv.TimNV();
            if(nva.Manhanvien)  // Kiem tra nhan vien nay co ton tai khong
			 {
                cout << "Thong tin nhan vien can tim" << endl;
                cout << "Ma nhan vien: " << nva.Manhanvien << endl;
                cout << "Ho nhan vien: " << nva.Ho << endl;
                cout << "Ten nhan vien: " << nva.Ten << endl;
                cout << "Luong nhan vien: " << nva.Luong << endl;
            } else {
                cout << "Khong tim thay nhan vien nay" << endl;
            }
            if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Da thoat" << endl;
            }
            break;
        case 3:
            //system("cls");
            cin.ignore();
            nvb = dsnv.MaxLuong();
            if(nvb.Manhanvien) // Kiem tra nhan vien nay co ton tai khong
			 {  cout<<"Thong tin nhan vien co luong cao nhat"<<endl;
                cout << "Ma nhan vien: " <<nvb.Manhanvien << endl;
                cout << "Ho nhan vien: " <<nvb.Ho << endl;
                cout << "Ten nhan vien: " <<nvb.Ten << endl;
                cout << "Luong nhan vien: " <<nvb.Luong << endl;
            } else {
                cout << "Khong tim thay nhan vien nay" << endl;
            }
            if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Da thoat" << endl;
            }
            break;
        case 4:
            //system("cls");
            cin.ignore();
            dsnv.Sapxep();
            dsnv.Xuat();
            if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Da thoat" << endl;
            }
            break;
        case 5:
            //system("cls");
            cin.ignore();
            Ghifileoutput(nva, nvb, dsnv);
            if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Exited" << endl;
            }
            break;
        case 6:
            cout << "Exited";
            break;
        default:
            system("cls");
            Menu();
            cout << "Khong co thao tac nay!" << endl;
            Xulymenu();
    }
}
void Ghifileinput(DSNhanvien dsnv) {
    ofstream f;
    f.open("input3.txt");
    for(int i = 0; i < dsnv.n; i++) {
        f << dsnv.DS[i].Manhanvien << endl;
        f << dsnv.DS[i].Ho << endl;
        f << dsnv.DS[i].Ten << endl;
        f << dsnv.DS[i].Luong << endl;
    }
    f.close();
    cout << "Da ghi vao file" << endl;
}
void Ghifileoutput(NhanVien nva, NhanVien nvb, DSNhanvien dsnv) {
    ofstream s;
    s.open("output3.txt");
    s << "Ket qua tim nhan vien: " << endl;
    if(nva.Manhanvien) {
        s << "Ma nhan vien: " << nva.Manhanvien << endl;
        s << "Ho nhan vien: " << nva.Ho << endl;
        s << "Ten nhan vien: " << nva.Ten << endl;
        s << "Luong nhan vien: " <<nva.Luong << endl;
    } else {
        s << "Khong tim thay ket qua" << endl;
    }
    s << "Max of salary result: " << endl;
    if(nvb.Manhanvien) {
        s << "Ma nhan viene: " << nvb.Manhanvien << endl;
        s << "Ho nhan vien: " << nvb.Ho << endl;
        s << "Ten nhan vien: " << nvb.Ten << endl;
        s << "Luong nhan vieny: " << nvb.Luong << endl;
    } else {
        s << "Khong tim thay ket qua" << endl;
    }
    
    s << "Ket qua sap xep nhan vien: " << endl;
    int tmp = dsnv.DS.size();
    if(tmp) {
        for(int i = 0; i < tmp; i++) {
            s << "Ma nhan vien: " << dsnv.DS[i].Manhanvien << endl;
            s << "Ho nhan vien: " << dsnv.DS[i].Ho << endl;
            s << "Ten nhan vien: " << dsnv.DS[i].Ten << endl;
            s << "Luong nhan vien: " << dsnv.DS[i].Luong << endl;
        }
    } else {
        s << "Khong tim thay ket qua" << endl;
    }

    s.close();
    cout << endl << "Da ghi du lieu vao file output5.txt" << endl;
}
bool VeMenu() {
    cout << "Nhan phim E de tro ve Menu: "; cin >> vemenu;
    if(vemenu == 'e' || vemenu == 'E') {
        return true;
    } return false;
}
