string value(int n){
    if(n==1000){ return "M";}
    if(n==900){ return "CM";}
    if(n==500){ return "D";}
    if(n==400){ return "CD";}
    if(n==100){ return "C";}
    if(n==90){ return "XC";}
    if(n==50){ return "L";}
    if(n==40){ return "XL";}
    if(n==10){ return "X";}
    if(n==9){ return "IX";}
    if(n==5){ return "V";}
    if(n==4){ return "IV";}
    if(n==1){ return "I";}
}

int largestBase(int n){
    if(n>=1000){ return 1000;}
    if(n>=900){ return 900; }
    if(n>=500){ return 500;}
    if(n>=400){ return 400;}
    if(n>=100){ return 100;}
    if(n>=90){ return 90;}
    if(n>=50){ return 50;}
    if(n>=40){ return 40;}
    if(n>=10){
        return 10;
    }
    if(n>=9){
        return 9;
    }
    if(n>=5){ return 5;}
    if(n>=4){ return 4;}
    if(n>=1){ return 1;}
}

string Solution::intToRoman(int A) {
    
    string res = "";
    while(A!=0){
        int LB = largestBase(A);
        int n = A/LB;
        for(int i=0;i<n;i++){
            res = res + value(LB);
        }
        A = A % LB;
    }
    
    return res;
}
