
        for(int i = a; i < b; i++){
            if(record[a].find(i) != record[a].end() && record[i+1].find(b) != record[i+1].end()){
                if(record[a][i] + record[i+1][b] != c){
                    isRight = false;
                    cout << "BUG Detected " << (record[a][i] + record[i+1][b]) << endl;
                    break;
                }
            }
        }
    }
    if(isRight){
        cout << "Accept" << endl;
        record[a][b] = c;
    }