#include <iostream>
#include <map>
#include <set>

using namespace std;

// Comparison function for sorting the set by increasing order of its pair's
// second value. If second value are equal, order by the pair's first value (descending)
struct compareMap
{
	template<typename T>
	bool operator()(const T& element1, const T& element2) const
	{
		if (element1.second != element2.second)
			return element1.second > element2.second;

		return element1.first < element2.first;
	}
};

int main1(void){

    int n, m, price;
    string name;
    map<string, int> names;


    cin>>n;
    for(int i = 0; i < n; i++){
        cin >> name;
        names[name] = 0;
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> name >> price;
        names[name] += price;
    }

    set<pair<string, int>, compareMap> setOfWords(names.begin(), names.end());
    for(pair<string, int> element : setOfWords){
        cout << element.first << endl;
    }

    return 0;
}
