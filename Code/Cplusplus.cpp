#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <map>

using namespace std;

template<class K, class V>
class Map{
    public:
        V& operator[](const K& v);
        pair<K,V>* begin(){ return &elem[0]; }
        pair<K,V>* end(){ return &elem[0]+elem.size(); }


    private:
        vector<pair<K,V>> elem;
};

template<class K, class V>
V& Map<K,V>::operator[](const K& k)
{
    for(auto& x : elem)
        if(k==x.first)
            return x.second;
    
    elem.push_back({k, V{}});
    return elem.back().second;
}

int main()
{   
    Map<string,int> buf;
    for(string s; cin>>s;) ++buf[s];
    for(const auto& x : buf)
        cout << x.first <<":"<< x.second << "\n";
    return 0;
}