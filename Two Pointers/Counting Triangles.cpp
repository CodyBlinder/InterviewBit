int n=A.size();
    if(n<3)return 0;
    // now n>=3
    sort(A.begin(),A.end());
    long long int ans=0;
    
    for(int en=(n-1);en>=2;--en){
        // for this c, i need to find pairs(a,b) whose sum greater than c
        for(int be=0,mid=(en-1);be<mid;){
            if(A.at(be)+A.at(mid) > A.at(en)){
                ans+=(mid-be)%(1000000007); //cout<<ans<<endl;
                --mid; 
            }
            else{
                ++be;
            }
        }
    }
    return (ans%(1000000007));
}
