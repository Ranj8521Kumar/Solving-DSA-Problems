#include<bits/stdc++.h>
using namespace std;

void reverseString(string &s){
    s+=" ";
    string str="";
    stack<string> st;
    for (int i = 0; i <s.length() ; i++)
    {
        if(s[i]==' '){
            st.push(str);
            str="";
        }else{
            str+=s[i];
        }
    }

    string result="";
    while(st.size()!=1){
        result+=st.top()+" ";
        st.pop();
    }
    result+=st.top();
    cout<<result<<endl;
    
}

int main()
{
    string s = "TUF is    great for interview preparation";
    reverseString(s);
    return 0;
}