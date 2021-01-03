string Solution::findDigitsInBinary(int A) {
    
    if(A==0){
        return "0";
    }
    
    string binary = "";
    
    while(A!=0){
        binary = binary + (to_string)(A%2);
        A = A/2;
    }
    
    reverse(binary.begin(),binary.end());
    
    return binary;
}
