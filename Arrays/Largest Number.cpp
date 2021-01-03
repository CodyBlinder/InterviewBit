int Mycompare(string x,string y){
    string xy = x.append(y);
    string yx = y.append(x);
    
    return xy.compare(yx) > 0 ? 1 : 0;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    for(int i=0;i<A.size();i++){
        v.push_back(to_string(A[i]));
    }
    
    std::sort(v.begin(),v.end(),Mycompare);
    
    string res="";
    for(int i=0;i<v.size();i++){
        res+=v[i];
    }
    
    int j=0;
    while(res[j]=='0' && j<=res.length()){
        j++;
    }
    if(j==res.length()){
        res="0";
    }
    
    return res;;
}
