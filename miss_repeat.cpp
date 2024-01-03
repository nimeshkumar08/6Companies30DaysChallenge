class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int ans[n+1] = {0};
        int repeat =0,miss=0;
        
        for(int i=0;i<n;i++){
            ans[arr[i]]++;
        }
        for(int i=1;i<n+1;i++){
            if(ans[i]==2){
                repeat = i;
            }
            else if(ans[i]==0){
                miss = i;
            }
        }
        return {repeat,miss};
    }
};