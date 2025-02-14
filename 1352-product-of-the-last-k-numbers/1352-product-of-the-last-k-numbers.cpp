class ProductOfNumbers {
public:
    vector<int> record;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        record.push_back(num);
    }
    
    int getProduct(int k) {
        if(k>record.size()){
            return -1;
        }
        int product = 1;
        for(int i=record.size()-k;i<record.size();i++) product*=record[i];
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */