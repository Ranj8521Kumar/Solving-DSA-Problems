#include<bits/stdc++.h>
using namespace std;

//first method
/*Complete the functions below*/
int find(int A[],int x)
{
       //add code here
       if(A[x] == x){
           return A[x];
       }
       
       return find(A, A[x]);
}

void unionSet(int A[],int x,int z)
{
	//add code here.
	int x_parent = find(A, x);
	int z_parent = find(A, z);
	
	if(x_parent != z_parent){
	    A[x_parent] = z_parent;
	}
}

//second method
//Improved version using rank and path compression
int find(int A[], int x) {
    // Path compression: make every node point directly to the root
    if (A[x] != x) {
        A[x] = find(A, A[x]); // Recursively find the root and compress the path
    }
    return A[x];
}

void unionSet(int A[], int rank[], int x, int z) {
    // Find roots of x and z
    int x_parent = find(A, x);
    int z_parent = find(A, z);

    // If already in the same set, do nothing
    if (x_parent == z_parent) return;

    // Union by rank: attach the smaller tree under the larger tree
    if (rank[x_parent] < rank[z_parent]) {
        A[x_parent] = z_parent;
    } else if (rank[x_parent] > rank[z_parent]) {
        A[z_parent] = x_parent;
    } else {
        A[z_parent] = x_parent;
        rank[x_parent]++; // Increment rank if both have the same rank
    }
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++)
        {
            A[i]=i;
        }
        int q;
        cin>>q;
        while(q--)
        {
            string s;
            cin>>s;
            if(s=="UNION")
            {
                int z,x;
                cin>>z>>x;
                unionSet(A,z,x);
            }
            else
            {
                int x;
                cin>>x;
                cout<<find(A,x)<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}