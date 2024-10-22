#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
// 定义显卡结构体
struct GraphicsCard {
    std::string brand; // 品牌

    int model; // 型号编号
    bool isTi; // 是否是 Ti 版本
    int frequency; // 频率

    // 比较函数，用于排序
    static bool compare(const GraphicsCard &a, const GraphicsCard &b) {
        if (a.model != b.model) return a.model > b.model;
        if (a.isTi != b.isTi) return a.isTi > b.isTi;
        return a.frequency > b.frequency;
    }
};

// 解析显卡型号字符串
// NVIDIA GeForce RTX 4090 Founders Edition @ 2520 MHz
// NVIDIA GeForce RTX 4090 Founders Edition Rev. 2 @ 2520 MHz
// NVIDIA GeForce RTX 4080 Founders Edition @ 2505 MHz
// NVIDIA GeForce RTX 4070 Founders Edition @ 2475 MHz
// NVIDIA GeForce RTX 4060 Ti Founders Edition @ 2535 MHz
GraphicsCard parseGraphicsCard(const std::string &line) {
    GraphicsCard card;
    std::istringstream iss(line);
    // 读取品牌
    // iss 读取是按照空格分隔的
    
    iss >> card.brand; // 读取 "NVIDIA" 部分
    string GeForce;
    iss >> GeForce; // 读取 "GeForce" 部分
    std::string modelStr;
    iss >> modelStr; // 读取 "RTX" 部分

    std::string modelNumber;
    iss >> modelNumber; // 读取型号编号
    // 提取型号编号
    cout << modelNumber << endl;
    card.model = std::stoi(modelNumber);


    // 检查是否是 Ti 版本
    // Ti 版本的型号编号中会包含 "Ti" 字符串
    // 继续读取，如果有Ti，就是Ti版本，如果是Founders Edition，就是非Ti版本

    string Founders;
    iss >> Founders; // 读取 "Founders" 部分
    if(Founders == "Founders"){
        card.isTi = false;
    }else{
        card.isTi = true;
        iss >> Founders; // 刚刚提出的不是Founders，而是Ti所以再读一次
    }

    // size_t tiPos = modelNumber.find("Ti");
    // if (tiPos != std::string::npos) {
    //     card.isTi = true;
    //     modelNumber.erase(tiPos, 2); // 移除 "Ti"
    // } else {
    //     card.isTi = false;
    // }



    // 提取频率，要一直读到@之前，然后再提取数字

    string at;
    iss >> at; // 读取 "@" 部分
    while (at != "@") {
        at = "";
        iss >> at;
    }
    string frequencyStr;
    iss >> frequencyStr; // 读取频率
    card.frequency = std::stoi(frequencyStr);

    // std::string freqStr
    // iss >> freqStr;
    // card.frequency = std::stoi(freqStr.substr(2, freqStr.size() - 6));

    return card;
}

int main() {
    std::vector<GraphicsCard> cards;
    std::string line;

    // 读取输入
    while (std::getline(std::cin, line)) {
        if (line == "") {
            break;
        }
        cards.push_back(parseGraphicsCard(line));
 
    }

    // 排序
    std::sort(cards.begin(), cards.end(), GraphicsCard::compare);

    // 找到性能最高的显卡
    if (!cards.empty()) {
        int maxPerformance = cards.front().model * 10 + cards.front().isTi * 1 + cards.front().frequency;

        // 输出性能最高的显卡
        for (const auto &card : cards) {
            if (card.model * 10 + card.isTi * 1 + card.frequency == maxPerformance) {
                
            } else {
                break; // 因为已经排序过了，所以一旦找到不同的就可以停止
            }
        }
    } else {
        std::cerr << "No valid graphics cards found." << std::endl;
    }

    return 0;
}