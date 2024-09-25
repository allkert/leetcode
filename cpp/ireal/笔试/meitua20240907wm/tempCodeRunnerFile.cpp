        if(find(mp.begin(), mp.end(), x) == mp.end()){
            mp[x] = y;
            cout << x + y - 1 << endl;
        }
        else{
            cout << x + y - 1 + mp[x] << endl;
        }
        // 更新map
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->first > x){
                it->second += y;
            }
        }