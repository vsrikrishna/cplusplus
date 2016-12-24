/*
Give an matrix of m *n with all the elements=1, Also given is a list of (x,y) points. 
The question is to zero out all the elements of xth row and yth column. 
*/
#include <iostream>
#include <algorithm>
using namespace std;

void zeroMatrix(int m, int n, int* x, int xlen, int* y, int ylen){
  bool xVal[m],yVal[n];
  int max[m][n];
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      max[i][j]=1;
    }
  }
  fill_n(xVal,m,false);
  fill_n(yVal,n,false);
  
  for(int i=0;i<xlen;i++){
    int val=*(x+i);
    xVal[val]=true;
  }
  
  for(int j=0;j<ylen;j++){
    int val=*(y+j);
    yVal[val]=true;
  }
  
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(xVal[i] ||yVal[j]){
        max[i][j]=0;
      }
    }
  }
  
  cout<<"The matrix is:"<<endl;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cout<<max[i][j]<<" ";
    }
    cout<<endl;
  }
}

int main(){
  int m,n;  
  
  cout<<"Enter m,n"<<endl;
  cin>>m>>n;
  
  int x[]={0,1};
  int y[]={1,2};
  int xlen=sizeof(x)/sizeof(x[0]);
  int ylen=sizeof(y)/sizeof(y[0]);
  zeroMatrix(m,n,x,xlen,y,ylen);
  
  return 0;
}
