int Solution::numSetBits(unsigned int A) {
    
    string binary = "";
    
    while(A!=0){
        binary+=to_string(A%2);
        A = A/2;
    }
    
    int count = 0;
    for(unsigned int i=0;i<binary.length();i++){
        if(binary[i]=='1'){
            count++;
        }
    }
    
    return count;
}
