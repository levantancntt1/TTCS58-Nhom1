#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
void Nhap(int a[], int &n);
void Xuat(int a[], int n);
void Sapxep(int a[], int n);
void XoaPhanTu(int a[], int &n, int x);
bool TimKiem(int A[], int n, int x);
int Search(int a[], int n, int x);
void Docfile(ifstream &f);
    int a[20];
    int n, x;
    
void Nhap(int a[], int &n)
{   
	do{
		cout<<"Moi ban nhap vap so phan tu: "; cin>>n;
	} while(n<10 || n>20);
	for(int i = 0; i < n; i++)
	{
			cout<<"Moi ban nhap vao phan tu thu "<<i<<": ";fflush(stdin) ;cin>>a[i];
			if(a[i] == 0) break;	
	}
}
void Sapxep(int a[], int n)
{   int tam;
	for(int i = 0; i < n - 1; i++)
    {
    	for(int j = i+1; j < n; j++)
    	{
    		if(a[i] > a[j])
    		{
    			tam = a[i];
    		    a[i] = a[j];
    	        a[j] = tam;
    		}
    	}
    }
    Xuat(a,n);
}
void Xuat(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Phan tu thu a["<<i<<"] : "<<a[i]<<endl;
	}
}

void Chen(int a[], int n)
{   int x, tam;
    cout<<"Chen phan tu"<<endl;
	cout<<"Nhap vao phan tu X: "; cin>>x;
	for(int i = 0; i < n; i++)
	{
		if(TimKiem(a,n,x))
		{
			cout<<"Phan tu "<<x<<" co ton tai trong day"<<endl;
			break;
		}
		else 
		{
			cout<<"Phan tu "<<x<<" khong ton tai trong day!"<<endl;
			cout<<"Chen phan tu vao day: "<<endl;
			for(int i = 0; i <= n; i++)
			{
				 if(a[i] > x && x >=0)
				 { 
				    
				     for(int j = n; j > i; j--)
				     {
				     	a[j] = a[j-1];
				     }
				     	a[i] = x;
				     	break;
				 }
			}
			Xuat(a,n+1);
			break;
		}
	}
}
void XoaPhanTu(int a[], int &n, int x)
{  cout<<"Xoa phan tu"<<endl;
   cout<<"Nhap vao phan tu can xoa: "; cin>>x;
   int vitri = Search(a,n,x);
   
   	  if(TimKiem(a, n, x))  // Tim xem co phan tu trong day khong ?
         {
   	       for (int i = vitri; i < n-1 ; i++) 
   	       {
   	       	  a[i] = a[i+1];
   	       }
            
   	     }  
      else cout<<"Phan tu khong ton tai trong day!"; 
}
void XoaTrunglap(int a[], int n)
{
	for (int  i = 0; i < n; i++) 
	{
      for (int j = i + 1; j < n;) 
	  {
         if (a[j] == a[i]) 
		 {
            for (int k = j; k < n; k++) 
			{
               a[k] = a[k + 1];
            }
            n--;
         } else
            j++;
      }
   }
   cout<<"Day sau khi da xoa cac phan tu trung lap!"<<endl;
   for (int i = 0; i < n; i++) {
      cout<<"Phan tu thu a["<<i<<"] : "<<a[i]<<endl;
   }
}

bool TimKiem(int a[], int n, int x)
{
   for(int i = 0; i<n ; i++)
   if(x==a[i])
      return 1;
   return 0;
}
int Search(int a[], int n, int x)
{  int s;
   for(int i = 0; i<n ; i++)
   if(x==a[i]) 
   return  s = i;
}
int main()
{   int n;
	Nhap(a,n);
	cout<<"Danh sach phan tu: "<<endl;
	Xuat(a,n);
	cout<<"Danh sach sau khi sap xep: "<<endl;
	Sapxep(a,n);
	Chen(a,n);
	XoaPhanTu(a,n,x);
	Xuat(a,n);
	XoaTrunglap(a,n);
}
