class Solution {
public:
    bool isPalindrome(int x) {
        //transforma o int inicial em string
        std::string x_str = std::to_string(x); //O(n)
        //percorre a string dois a dois comparando os caracteres do final com o do início até a metade
        for(int i = 0; i < x_str.size() / 2; i++) { //O(n)
            if(x_str[i] != x_str[x_str.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
//Total: O(n)