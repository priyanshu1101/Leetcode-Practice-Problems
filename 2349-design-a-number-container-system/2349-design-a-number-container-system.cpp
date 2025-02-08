class NumberContainers {
public:
    unordered_map<int,int> record;
    unordered_map<int,set<int>> numberIndex;
    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(record[index]!=0){
            int prevNumber = record[index];
            numberIndex[prevNumber].erase(index);
            record[index]=number;
            numberIndex[number].insert(index);
        }
        else{
            record[index]=number;
            numberIndex[number].insert(index);
        };
    }
    
    int find(int number) {
        if(numberIndex[number].size()!=0) return *numberIndex[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */