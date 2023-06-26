//LRU
class LRUCache {
public:
    unordered_map<int,int> mp,cnt;
    queue<int> q;
    // list<pair<int,int>> lru;
    // unordered_map<int,list<pair<int,int>>::iterator> mp;
    int sz;
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(cnt.find(key) == cnt.end()){
            return -1;
        }
        q.push(key);
        cnt[key]++;
        return mp[key];
        // auto it = mp.find(key);
        // if(it == mp.end()) return -1;
        // int val = it->second->second;
        // lru.erase(it->second);
        // lru.push_front({key,val});
        // mp.erase(key);
        // mp[key] = lru.begin();
        // return val;
    }
    
    void put(int key, int value) {
        q.push(key);
        cnt[key]++;
        mp[key] = value;
        while(cnt.size() > sz){
            int cur = q.front();
            q.pop();
            if(cnt[cur]-- == 1) cnt.erase(cur);
        }
        // auto it= mp.find(key);
        // if(mp.find(key) != mp.end()){
        //     lru.erase(it->second);
        //     mp.erase(it);
        // }
        // lru.push_front({key,value});
        // mp[key] = lru.begin();

        // if(mp.size() > sz){
        //     auto it = mp.find(lru.begin()->first);
        //     mp.erase(it);
        //     lru.pop_back();
        // }
    }
};

//LFU
// class LFUCache {
// public:
    // unordered_map<int,pair<int,int>> mp; //key,{value,freq}
    // map<int,list<int>> freq;
    // map<int,list<int>::iterator> pos;
    // int sz,minFreq;
    // LFUCache(int capacity) {
    //     sz = capacity;
    //     minFreq = 0;
    // }
    
    // int get(int key) {
    //     if(mp.find(key) == mp.end()) return -1;
    //     freq[mp[key].second].erase(pos[key]);
    //     mp[key].second++;
    //     freq[mp[key].second].push_back(key);
    //     pos[key] = --freq[mp[key].second].end();
    //     if(freq[minFreq].empty()) minFreq++;
    //     return mp[key].first;
    // }
    
    // void put(int key, int value) {
    //     if(!sz) return;
    //     if(mp.find(key) != mp.end()){
    //         mp[key].first = value;
    //         freq[mp[key].second].erase(pos[key]);
    //         mp[key].second++;
    //         freq[mp[key].second].push_back(key);
    //         pos[key] = --freq[mp[key].second].end();
    //         if(freq[minFreq].empty()) minFreq++;
    //         return;
    //     }
    //     if(mp.size() == sz){
    //         int del = freq[minFreq].front();
    //         mp.erase(del);
    //         pos.erase(del);
    //         freq[minFreq].pop_front();
    //     }
    //     mp[key] = {value,1};
    //     freq[1].push_back(key);
    //     pos[key] = --freq[1].end();
    //     minFreq = 1;
    // 
class LFUCache {

    unordered_map<int,list<pair<int,int>>> freq; //freq,key,val
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>> cache;
    int sz,minFreq;
    void insert(int k,int f,int v){
        freq[f].push_back({k,v});
        cache[k] = {f,--freq[f].end()};
    }

public:
    LFUCache(int capacity) {
        sz = capacity;
        minFreq = 0;
    }

    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        int f = it->second.first;
        auto iter = it->second.second;
        pair<int,int> kv = *iter;
        freq[f].erase(iter);
        if(freq[f].empty()){
            freq.erase(f);
            if(minFreq == f) minFreq++;
        }
        insert(key,f+1,kv.second);
        return kv.second;
    }

    void put(int key, int value) {
        if(sz < 0) return;
        auto it = cache.find(key);
        if(it!= cache.end()){
            it->second.second->second = value;
            get(key);
            return;
        }
        if(sz == cache.size()){
            cache.erase(freq[minFreq].front().first);
            freq[minFreq].pop_front();
            if(freq[minFreq].empty()) freq.erase(minFreq);
        }
        minFreq = 1;
        insert(key,1,value);
    }    
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */