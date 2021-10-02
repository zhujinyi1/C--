#include<bits/stdc++.h>
using namespace std;



class Solution {
public:

    bool Search(vector<vector<int>> array, int target,int i,int j){
        
        if(array[i][j]==target) return true;
        bool b = false;
        if(i<array.size()-1&&array[i+1][j]<=target) b = Search(array,target,i+1,j);
        if(b) return true;
        if(j<array[0].size()-1&&array[i][j+1]<=target) b = Search(array,target,i,j+1);
        return b;
    }

    bool searchArray(vector<vector<int>> array, int target) {
        if(!array.size()||!array[0].size()) return false;
        return Search(array,target,0,0);
    }

};

int main(){
    Solution S;
    vector<vector<int>> v;
    for(int i = 0;i<4;i++){
        v.resize(4);
    }

    v[0].push_back(1);
    v[0].push_back(2);
    v[0].push_back(8);
    v[0].push_back(9);
    v[1].push_back(2);
    v[1].push_back(4);
    v[1].push_back(9);
    v[1].push_back(12);
    v[2].push_back(4);
    v[2].push_back(7);
    v[2].push_back(10);
    v[2].push_back(13);
    v[3].push_back(6);
    v[3].push_back(8);
    v[3].push_back(11);
    v[3].push_back(15);
    cout << S.searchArray(v,7);
}