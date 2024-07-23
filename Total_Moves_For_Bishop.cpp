#include<bits/stdc++.h>
using namespace std;

int solve(int A, int B) {
    int topRight = min(8 - A, 8 - B);
    int topLeft = min(8 - A, B - 1);
    int buttomRight = min(A - 1, 8 - B);
    int buttomleft = min(A-1, B-1);
    
    int totalMove = topRight + topLeft + buttomRight + buttomleft;
    return totalMove;
}


int main()
{
    int A = 4, B = 4;//1>= A, B <=8
    cout<<solve(A, B); 
    return 0;
}