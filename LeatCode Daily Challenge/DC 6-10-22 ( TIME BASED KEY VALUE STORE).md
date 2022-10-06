[TIME BASED KEY VALUE STORE](https://leetcode.com/problems/time-based-key-value-store/)

```cpp
class TimeMap {
public:
    map<string,vector<string>>mp;
    map<string,vector<int>>mp1;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(value);
        mp1[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        int pos = lower_bound(mp1[key].begin(),mp1[key].end(),timestamp)-mp1[key].begin();
        if(pos != mp1[key].size() and  mp1[key][pos] == timestamp){
            return mp[key][pos];    
        }else{
            if( pos == 0)return "";
            else return mp[key][pos-1]; 
        } 
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
```