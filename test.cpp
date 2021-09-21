#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        unordered_map<char,bool> inStack; //记录字符是否存在于栈中
        for(char ch : s){
            inStack[ch] = false; //初始时，s中的所有字符都没有进栈，初始值全都设为false
        }

        unordered_map<char,int> count;
        for(char ch : s){
            count[ch]++;
        }

        for(char ch : s){
            count[ch]--; //每遍历一个字符，相应字符的count就减一

            if(inStack[ch]) continue; //如果栈中存在这个字符，就不进栈，遍历下一个字符(目的是去重)

            while(!stk.empty() && stk.top() > ch ){
                //若之后不存在栈顶元素了，则不pop
                if(count[ch] == 0){
                    break;
                }
                //若之后还存在栈顶元素，则pop，并标记栈顶元素不存在栈中了
                char d = stk.top();
                stk.pop();
                inStack[d] = false;
            }

            //元素进栈，并标记栈中有该元素了
            stk.push(ch);
            inStack[ch] = true;

        }

        string res;
        while(!stk.empty()){
            char c = stk.top();
            stk.pop();
            res += c;
        }

        reverse(res.begin(),res.end());

        return res;


        
    }
};

