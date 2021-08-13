#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> isp;
int main()
{
    isp["a"] = 100;
    isp["s"] = 100;
    isp["d"] = 100;
    isp["f"] = 100;
    isp["g"] = 100;
    isp["h"] = 100;
    auto it = isp.find("d");
    if(it!=isp.end())
        isp.erase(it);
    if(it==isp.find("d"))
        cout << "Yes";
        
    return 0;
}