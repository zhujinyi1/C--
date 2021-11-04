#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int xm = 0x3f3f3f3f,xM = -0x3f3f3f3f,ym = 0x3f3f3f3f,yM = -0x3f3f3f3f;

int main(){
  int n;
  cin >> n;
  while(n--){
		int x,y;
    cin >> x >> y;
    xM = max(xM,x);
    xm = min(xm,x);
    ym = min(ym,y);
    yM = max(yM,y);
  }
  
  printf("%.5lf",double(xM-xm)*(yM-ym));
  return 0;
}