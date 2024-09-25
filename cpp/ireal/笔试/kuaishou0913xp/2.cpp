#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    // 总的时间和技能的持续时间
    int n, k;
    cin >> n >> k;
    // 技能在每个时间的伤害
    vector<int> damage(n);
    for(int i = 0; i < n; i++){
        cin >> damage[i];
    }
    // 技能带来的debuff
    vector<int> debuff(n);
    for(int i = 0; i < n; i++){
        cin >> debuff[i];
    }
    long  damage_acc = 0, debuff_acc = 0;
    for(int i = 0; i < k; i++){
        damage_acc += damage[i];
        debuff_acc += debuff[i];
    }
    long max_damage = damage_acc;
    long min_debuff = debuff_acc;
    int time = 0;
    for(int i = k; i < n; i++){
        damage_acc += damage[i];
        debuff_acc += debuff[i];
        damage_acc -= damage[i - k];
        debuff_acc -= debuff[i - k];
        if(damage_acc > max_damage){
            max_damage = damage_acc;
            min_debuff = debuff_acc;
            time = i - k + 1;
        }
        else if(damage_acc == max_damage && debuff_acc <= min_debuff){
            min_debuff = debuff_acc;
            time = i - k + 1;
        }
    }
    cout << time + 1 << endl;
}