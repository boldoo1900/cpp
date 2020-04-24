//#include<bits/stdc++.h>

bool isDigitPresent(int x, int d)
{
    // Breal loop if d is present as digit
    while (x > 0)
    {
        if (x % 10 == d)
            break;

        x = x / 10;
    }

    // If loop broke
    return (x > 0);
}

int countOC(string s, char c)
{
    // Count variable
    int res = 0;
    for (int i=0; i<s.length(); i++)
        // checking character in string
        if (s[i] == c)
            res++;

    return res;
}

//#include <string>
//#include <vector>
//#include <sstream>
//#include <utility>
vector<string> explode(char delim, string const & s)
{
    vector<string> result;
    istringstream iss(s);

    for (string token; getline(iss, token, delim); )
    {
        result.push_back(move(token));
    }

    return result;
}

//descending (vector and pair combination)
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second > b.second);
}


int findGCD(int arr[], int n) { 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
        result = __gcd(arr[i], result); 

    return result; 
}

// cin.tie(nullptr);
// ios::sync_with_stdio(false);

// 2 hemjeest int array dynamic
// int **a = new int*[h];
// for(int i = 0; i < h; ++i) {
//     a[i] = new int[w];
}




/*

x & 1 is equivalent to x % 2
x >> 1 is equivalent to x / 2

*/





