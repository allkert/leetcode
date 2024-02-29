    Solution s;
    vector<int> a({1000000000,1000000000,1000000000,1000000000});
    vector<vector<int>> res = s.fourSum(a,0);
    for(vector<vector<int>>::iterator it1 = res.begin(); it1 < res.end(); it1++){
        cout <<"[";
        for(vector<int>:: iterator it2 = (*it1).begin(); it2 < (*it1).end(); it2++){
            cout << *it2 << '\t';
        }
        cout <<']'<<endl;
    }
    cout << '1' <<endl;