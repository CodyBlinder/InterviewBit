bool isOperator(string str){
    if(str=="+"){ return true;}
    if(str=="-"){ return true;}
    if(str=="*"){ return true;}
    if(str=="/"){ return true;}
    return false;
}

int Perform(string a,string b,string c){
    int x = stoi(a);
    int y = stoi(b);
    if(c=="+"){ return x+y;}
    if(c=="-"){ return x-y;}
    if(c=="*"){ return x*y;}
    if(c=="/"){ return x/y;}
}

int Solution::evalRPN(vector<string> &A) {
    
    int n = A.size();
    stack<string> S;
    
    for(int i=0;i<n;i++){
        if(!isOperator(A[i])){
            S.push(A[i]);
        }
        else{
            string op2 = S.top(); S.pop();
            string op1 = S.top(); S.pop();
            S.push(to_string(Perform(op1,op2,A[i])));
        }
    }
    
    return stoi(S.top());
}
