string Solution::countAndSay(int A) {
    
    string str = "";
    string res = "";
    
    if(A == 1){return "1";}
    else{str = countAndSay(A-1);}
    
    int n = str.size();
    
    int i = 0;
    while(i < n){
        if(i == n-1){
            res = res + to_string(1) + str[i]; 
            break;
        }
        int cnt = 1;
        while(i < n && str[i] == str[i+1]){
            cnt++;
            i++;
        }
        res = res + to_string(cnt);
        res = res + str[i];
        i++;
    }
    
    return res;
}
