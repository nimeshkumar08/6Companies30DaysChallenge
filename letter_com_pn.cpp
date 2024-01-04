class Solution {
private:
void helper(vector<string>& res, string digits, int i, string st[], string t){
    if(i>=digits.length()){
        res.push_back(t);
        return;
    }
    int num = digits[i]-'0';
    string nstr= st[num];
    for(int j=0;j<nstr.length();j++){
        t.push_back(nstr[j]);
        helper(res,digits,i+1,st,t);
        t.pop_back();
    }
}
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string t="";
        string st[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.length()==0){return res;}
        helper(res,digits,0,st,t);
        return res;
    }
};