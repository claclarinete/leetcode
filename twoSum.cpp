#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash; 

        //percorre o vetor uma vez adicionando os elementos na tabela hash
        for (int i = 0; i < nums.size(); i++) { //O(n) em media
            hash[nums[i]] = i;
        }
        std::vector<int> result;
        //percorre mais uma vez só até achar o primeiro elemento da dupla desejada
        for (int i = 0; i < nums.size(); i++) { //pior caso: O(n-1)
            auto complemento = hash.find(target - nums[i]);
            if (complemento != hash.end() && complemento->second != i) {
                result.push_back(i);
                result.push_back(complemento->second);
                break;
            }
        }
        return result;
    }
};
//total: O(n)