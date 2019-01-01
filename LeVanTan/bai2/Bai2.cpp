#include<iostream>
#include <vector>
#include<stdio.h>
using namespace std;

struct Node {
	int giatri;
	int row_position;
	int col_position;
	struct Node *tiep;
};
char vemenu;
bool VeMenu();
class DSNode {
private:
	int h = 0, c = 0;
	Node *dau, *cuoi;
public:
	DSNode(int h, int c);
	int GetRow();
	int GetCol();

	Node *TaoNode(int hang, int cot, int giatri);
	void NhapDSNode();
	DSNode();
	void Themdau(Node *p);
	void Themcuoi(Node *p);
    bool Matranthua();
	void XuatNode();
	void Xuat();
	
	void Nhan(int n);
	
};


DSNode::DSNode(int row, int col)
{
	h = row;
	c = col;
}

int DSNode::GetRow()
{
	return h;
}

int DSNode::GetCol()
{
	return c;
}

void DSNode::NhapDSNode()
{	
	int tam = 0, note = 0; // index: so phan tu khac 0;
	do {
		cout << "Nhap so hang: "; cin >> h;
	} while (h == 0);
	do {
		cout << "Nhap so cot: "; cin >> c;
	} while (c == 0);
	
	for (int i = 0; i < h; i++) 
	{
		for (int j = 0; j < c; j++) 
		{
			cout << "a(" << i << "," << j << ")" << " : ";
			cin >> note;
			if (tam != 0)
			 {
				note++;
				Themcuoi(TaoNode(i, j, tam));
			}
		}
	}
	// Kiem tra ma tran nhap vao co la ma tran thua. 
	if (note > (c*h) / 2) 
	{
		cout << "Khong phai ma tran thua" << endl;
		cout << "Moi ban nhap lai:" << endl;
		NhapDSNode();
	}
}

Node * DSNode::TaoNode(int hang, int cot, int giatri)
{
	Node *p = new Node;
	p->col_position = cot;
	p->row_position = hang;
	p->giatri = giatri;
	p->tiep = NULL;
	return p;
}

void DSNode::Themdau(Node * p)
{
	if (dau == NULL) // Neu node dau la rong
	{
		dau = cuoi = p;
	}
	else 
	{
		p->tiep = dau->tiep;
		dau = p;
	}
}

void DSNode::Themcuoi(Node * p)
{
	if (dau == NULL) 
	{
		dau = cuoi = p;
	}
	else {
		cuoi->tiep = p;
		cuoi = p;
	}
}

// Xuat ra danh sach cac node // matran dang link list
void DSNode::XuatNode()
{
	if (dau == NULL) 
	{
		cout << "Danh sach rong" << endl;
		return;
	}
	Node * tam = dau;
	while (tam != NULL)
	{
		cout << "Row_position: " << tam->row_position <<endl;
		cout<<"Col_position: " << tam->col_position <<endl;
		cout<<"Value: " << tam->giatri << ";" << endl;
		tam = tam->tiep;
	}
}

// Xuat ra ma tran 2 chieu tu link list
void DSNode::Xuat()
{
	int temp[10][10];
	Node * p = dau;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = 0;
		}
	}

	while (p != NULL) {
		temp[p->row_position][p->col_position] = p->giatri;
		p = p->tiep;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < c; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}

// Nhan voi 1 so khac 0
void DSNode::Nhan(int n)
{
	Node *p = dau;
	cout << "Nhap so can nhan: ";
	do {
		cin >> n;
		if (n == 0) {
			cout << "Nhap lai: ";
		}
	} while (n == 0);
	
	while (p != NULL)
	{
		p->giatri = p->giatri * n;
		p = p->tiep;
	}
	cout << "Ma tran sau khi nhan voi " << n << ":" << endl;
	Xuat();
}


DSNode::DSNode() // Khoi tao
{
	dau = cuoi = NULL;
}
DSNode *x = new DSNode;
void Menu() {
	cout << "1. Tao ma tran thua" << endl;
	cout << "2. Hien thi ma tran thua dang link list" << endl;
	cout << "3. Hien thi ma tran thua dang array" << endl;
	cout << "4. Nhan ma tran thua voi 1 so" << endl;
	cout << "5. Thoat" << endl;
}

void Xulymenu() {
	int n, tam = 0;
	cout << "Lua chon: "; cin >> n;
	switch (n)
	{
	case 1:
		x->NhapDSNode();
		system("cls");
		cout << "Da tao ma tran thua!" << endl;	
		if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Da thoat" << endl;
            }
		break;
	case 2:
		system("cls");
		cout << "Ma tran thua dang link list la: " << endl;
		x->XuatNode();
		if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Da thoat" << endl;
            }
		break;
	case 3:
		system("cls");
		cout << "Ma tran thua dang array: " << endl;
		x->Xuat();
		if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Da thoat" << endl;
            }
		break;
	case 4:
		x->Nhan(tam);
		if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Da thoat" << endl;
            }
		break;
	case 5: 
		return;
	default:
		system("cls");
		cout << "Sai cu phap" << endl;
		if(VeMenu()) {
                system("cls");
                Menu();
                Xulymenu();
            } else {
                cout << "Da thoat" << endl;
            }
		break;
	}
}
bool VeMenu() {
    cout << "Nhan phim E de tro ve Menu "; cin >> vemenu;
    if(vemenu == 'e' || vemenu == 'E') {
        return true;
    } return false;
}
int main() {
	Menu();
	Xulymenu();
	system("pause");
}

