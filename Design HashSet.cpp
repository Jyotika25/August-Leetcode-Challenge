class MyHashSet {
    int numBuckets;
    vector<list<int>> buckets;
    
    int hash_function(int key){
        return key % numBuckets;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<list<int>>(numBuckets , list<int>{});
        
    }
    
    void add(int key) {
        int i = hash_function(key);
        //if key not found then add it
        if(find(buckets[i].begin(),buckets[i].end(),key) == buckets[i].end())
            buckets[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hash_function(key);
        
        auto itr = find(buckets[i].begin(),buckets[i].end(),key);
        if(itr!=buckets[i].end())
            buckets[i].erase(itr);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i = hash_function(key);
        //if key not found then it doesnt contains else true it contains
        if(find(buckets[i].begin(),buckets[i].end(),key) == buckets[i].end())
            return false;
        return true;
    }
};

//approach 2
/*
class MyHashSet {
    int *arr;
public:

    MyHashSet() {
  
       arr=new int[1000001] ;
       memset(arr,-1,sizeof(arr));
    }
    
    void add(int key) {
        arr[key]=1;
    }
    
    void remove(int key) {
        arr[key]=-1;
    }
    
    
    bool contains(int key) {
        return arr[key]==1;
    }
};


*/




/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
