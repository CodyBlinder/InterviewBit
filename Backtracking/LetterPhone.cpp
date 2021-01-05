void letterCombinationsHelper(string digits, map<char, string> &keypad, string curr, vector<string> &res){
    // Base Case
    if(curr.size() == digits.size()){
        res.push_back(curr);
        return;
    }
    
    // Recursive Step
    for(char c : keypad[digits[curr.size()]]){
        curr += c;
        letterCombinationsHelper(digits, keypad, curr, res);
        curr.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> res;
    string curr = "";
    map<char, string> m;
    
    // Initializing the map
    m['0'] = "0";
    m['1'] = "1";
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    
    letterCombinationsHelper(A, m, curr, res);
    return res;
}
