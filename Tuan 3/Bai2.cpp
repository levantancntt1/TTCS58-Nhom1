#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
void Nhap(int a[], int &n);
void Xuat(int a[], int n);
void Sum(int a[], int n);
int a[20], n;
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
void Docfile()
{
	
}
void Xuat(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout<<"Phan tu thu a["<<i<<"] : "<<a[i]<<endl;
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
bool binarySearch(int a[], int n, int x)
{
	int l = 0, r = n - 1;
	while(l <= r)
	{
		int mid = (r-l)/2;
		if(a[mid] == x) return true;
		else if(a[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
	return false;
}

void Sum(int a[], int n)
{
	int maxtam = 0, maxsum = 0;
	for(int i = 0; i < n; i++)
	{ 
	    maxtam =maxtam + a[i];
		if(maxtam < 0)
		{
			maxtam = 0;
		}
		else if(maxsum < maxtam)
		{
			maxsum = maxtam;
		}
	
	}
		cout<<"Tong lon nhat: "<<maxsum<<endl;
}

int main()
{   int x;
	Nhap(a,n);
	Sum(a,n);
    Sapxep(a,n);
    cout<<"Nhap vao phan tu ban muon tim kiem: "; cin>>x;
    binarySearch(a,n,x);
}
