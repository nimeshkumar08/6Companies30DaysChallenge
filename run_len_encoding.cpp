string encode(string src)
{     
  //Your code here 
   int count=1;
    string s;
    for(int i=0;i<src.length();i++){

        if(src[i]!=src[i+1]){
            s=s+src[i];
            s=s+to_string(count);
            count=1;
        }
        else{
            count++;
        }
    }
    return s;
}     