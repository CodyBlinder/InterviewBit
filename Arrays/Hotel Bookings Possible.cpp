bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size(), st, ed, last_time = INT_MIN, cnt = 1;
    vector<pair<int, int>> record;
    
    for(int i = 0 ; i < n ; i++){
        record.push_back(make_pair(arrive[i], depart[i]));
    }
    
    sort(record.begin(), record.end(), [](pair<int, int> &p1, pair<int, int> &p2){
        return p1.second < p2.second;
    });
    
    for(int i = 0 ; i < n ; i++){
        st = record[i].first;
        ed = record[i].second;
        if(st >= last_time){
            last_time = ed;
        }
        else{
            cnt++;
            if(cnt > K){
                return false;
            }
        }
    }
    
    return cnt>K ? false : true;
}
