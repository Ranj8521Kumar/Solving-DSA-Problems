// //Number hashing
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int p; // at-max element for searching frequency
//     cin >> p;

//     //precompute
//     int hash[p + 1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         hash[arr[i]] += 1;
//     }

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int number;
//         cin >> number;
//         cout << hash[number] << endl;
//     }
//     return 0;
// }

//Character Hashing
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // //for only lower case letter
//     // string s;
//     // cin>>s;

//     // int hash[26] = {0};
//     // for (int i = 1; i <= s.length(); i++)
//     // {
//     //     hash[s[i]-'a']+=1;
//     // }

//     // int q;
//     // cin>>q;
//     // while(q--){
//     //     char ch;
//     //     cin>>ch;
//     //     cout<<hash[ch - 'a']<<endl;
//     // }



//     //for all 256 character
//     string s;
//     cin>>s;

//     int hash[256] = {0};
//     for (int i = 1; i <= s.length(); i++)
//     {
//         hash[s[i]]+=1;
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         char ch;
//         cin>>ch;
//         cout<<hash[ch]<<endl;
//     }
    
//     return 0;
// }



//Since, In simple hashing we can't create hash array of size greater then 10^6 (Globally 10^7), So we need hashing with STL/JAVA Collection 

//In STL, we go with map ao unordered map

// //with map
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }

//     map<int, int> mpp;
//     for (int i = 0; i < n; i++)
//     {
//         mpp[arr[i]]++;
//     }

//     // int q;
//     // cin>>q;
//     // while(q--){
//     //     int num;
//     //     cin>>num;
//     //     cout<<mpp[num]<<endl;
//     // }

//     //It(map) always in sorted
//     for(auto it : mpp){
//         cout<<it.first<<"->"<<it.second<<endl;
//     }
//     return 0;
// }



//with unordered_map
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // int q;
    // cin>>q;
    // while(q--){
    //     int num;
    //     cin>>num;
    //     cout<<mpp[num]<<endl;
    // }

    //It(map) always in sorted
    for(auto it : mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    return 0;
}