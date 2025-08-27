class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        vector<char> temp;
        temp.clear();
        unordered_map<char, int> dic;
        dic['I'] = 1;
        dic['V'] = 5;
        dic['X'] = 10;
        dic['L'] = 50;
        dic['C'] = 100;
        dic['D'] = 500;
        dic['M'] = 1000;

        for(int i = s.size() - 1; i>= 0; i--) {
            if (temp.size() == 0 || (s[i] == temp[0] && temp.size() < 4)) {
                temp.push_back(s[i]);
            }
            auto c1 = dic.find(s[i]);
            auto c2 = dic.find(temp[0]);
            if (c1->second < c2->second) {
                result += c2->second - c1->second;
                temp.clear();
            }
            if (c1->second > c2->second) {
                result += (c2->second * temp.size());
                temp.clear();
                temp.push_back(c1->first);
            }
        }
        result += (dic.find(temp[0])->second * temp.size());

        return result;
    }
};