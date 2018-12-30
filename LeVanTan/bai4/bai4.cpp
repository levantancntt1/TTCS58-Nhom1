#include <iostream>
#include <fstream>
#include<string.h>
#include <sstream>
using namespace std;

bool Sosanh(int a[]);
void Quaylui(int a[], int n, int i = 0);
void Traveketqua(int a[]);
void SetKQ();
void Xuat();
void Docfile();
bool Vaofile();
ifstream f;
int n, p, dem;
int a[6], kq[6],dl[6]; // dl[] : mang tu file du lieu

bool Sosanh(int a[]) // lap mot chuoi nhi phan gom n bit
{
    int start = 0; // Chon mot gia tri trong chuoi du lieu
    for(int i = 0; i < n; i++) 
	{
       start = (start + a[i] * dl[i]);  // nhan tung gia tri ben chuoi du lieu voi tung so ( 0 và 1) roi lay gia tri
    }
    if(start == p) // kiem tra ket qua vua nhan co trung voi gia tri p 
        return true;
    else 
	    return false;
}
void SetKQ()
{
	Traveketqua(a);		
	dem++;
}
void Quaylui(int a[], int n, int i) 
{
    for(int j = 0; j <= 1; j++) 
	{
        a[i] = j;
        if(i == n - 1) 
		{
            if(Sosanh(a)) // Neu Sosanh tra ve true thi thuc hien
			{
                SetKQ();
            }
        } else 
		{
            Quaylui(a, n, i + 1);
        }
    }
}
void Traveketqua(int a[]) // Sau khi thuc kien kiem tra, tra ve ket qua bang chuoi vua kiem tra.
{
	for(int j = 0; j < n; j++)
	{
		for( int i = 0; i < n; i++)
		{
			kq[j] = a[i];
		}
	}
}
void Xuat() {
    int tam = sizeof(kq);
    for(int i = 0; i < tam; i++) 
	{   // kiem tra i co bang so phan tu cua mang
        if(i % n == 0) {cout <<"\n";}
        else
		cout << kq[i] <<" ";
    } 
	cout << endl;
}
void Docfile() 
{
    string dong;
    f.open("input4.txt");
    if(Vaofile())
    {
    	cout << "Khong the mo file" << endl;
    }
    else
    {
    	getline(f, dong);
        stringstream s1(dong);s1 >> n >> p;  // lay chuoi du lieu tren mot dong  
        getline(f, dong);
        stringstream s2(dong);
        for(int i = 0; i < n; i++) 
		{
            s2 >> dl[i];
        }
    }
    
    f.close();
}
bool Vaofile()
{
   if(f.is_open())	
     return false;
   return true;
}
int main() 
{
    Docfile();
    cout <<n<<" "<<p<<endl;
    Quaylui(a, n);
    Xuat();
    
}
