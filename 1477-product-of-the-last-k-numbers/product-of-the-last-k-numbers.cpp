class ProductOfNumbers {
public:
    vector<int> arr;
    //vector<int> product;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int product =  1;
        int i = arr.size()-1;
       for(int j = k;j>0;j--){
        product *= arr[i--];
       }
       return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */