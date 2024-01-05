class DataStream {
public:
    int val, size, count=0;
    DataStream(int value, int k){
        val = value;
        size = k;
    }
    
    bool consec(int num) {
        if(num == val)
            count++;    
        else
            count = 0;
        return count>=size;
    }
};