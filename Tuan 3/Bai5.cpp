#include <iostream> 
#include <string> 
using namespace std; 
  

int Tim(string str) 
{ 
    int n = str.length(); 
  
   
    int dp[n+1][n+1]; // Tao mot bang 
    for (int i=0; i<=n; i++) 
        for (int j=0; j<=n; j++) 
            dp[i][j] = 0; 
  
    
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=n; j++) 
        { 
           
            if (str[i-1] == str[j-1] && i != j) // Neu cac ki tu trugn nhau tai nhung vi tri khac nhau
                dp[i][j] =  1 + dp[i-1][j-1];           
                       
           
            else       // Neu cac ki tu khong trung nhau
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]); 
        } 
    } 
    return dp[n][n]; 
} 
  

int main() 
{ 
    string stra = "";
	cout<<"Nhap vao chuoi A: "; getline(cin, stra);
    cout << "\nChuoi lap lai dai nhat la: "<< Tim(stra); 
        
    return 0; 
} 
