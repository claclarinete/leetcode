class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> dic = {{'(', 1}, {'{', 2}, {'[', 3},
                                        {')', 4}, {'}', 5}, {']', 6}}; // 1-3: abre, 4-6: fecha

        auto atual = dic.find(s[0]);
        if (atual->second > 3) { // se começa fechando, é inválido
            return false;
        }

        string temp = "";
        for (int i = 0; i < s.size(); i++) { //O(n)
            atual = dic.find(s[i]);
            if (atual->second <= 3) { // se abre, é válido
                temp += s[i];
            } else if (!temp.empty()) { // se fecha e temp não está vazio
                auto anterior = dic.find(temp[temp.size() - 1]);
                if (atual->second == anterior->second + 3) { // se fecha corretamente, remove do temp
                    temp.pop_back();
                } else { // se fecha incorretamente, é inválido
                    return false;
                }
            } else { // se fecha e temp está vazio, é inválido
                return false;
            }
        }
        if (temp.empty()) { // se todas as aberturas foram fechadas corretamente, é válido
            return true;
        }
        return false; // se ainda há aberturas não fechadas, é inválido
    }
};
//complexidade total: O(n), onde n é o tamanho da string de entrada