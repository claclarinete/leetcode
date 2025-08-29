class TrieNode {
public:
    bool fim; //diz se aquele nó é o fim de uma palavra
    unordered_map<char, TrieNode*> filhos; // mapa de filhos

    TrieNode() {
        fim = false;
    }
};

class Trie {
    private:
        TrieNode* raiz; 

public:
    Trie() {
        raiz = new TrieNode();
    }

    void inserir(string& palavra) { //O(m), m = tamanho da palavra
        TrieNode* atual = raiz;
        for(char c : palavra) {
            if(atual->filhos.find(c) == atual->filhos.end()) {
                atual->filhos[c] = new TrieNode();
            }
            atual = atual->filhos[c];
        }
        atual->fim = true;
    }

    string maoir_prefixo(int n_palavras) { //O(m), m = tamanho da menor palavra
        TrieNode* atual = raiz;
        string prefixo;
        while (true) {
            if(atual->fim || atual->filhos.size() > 1) { //caso o nó seja o fim de uma palavra ou tenha mais de um filho, sai do loop
                break;
            }
            auto prox = atual->filhos.begin();
            prefixo += prox->first;
            atual = prox->second;
        }
        return prefixo;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(int i = 0; i < strs.size(); i++) { //O(n*m), n = número de palavras, m = tamanho da palavra
            trie.inserir(strs[i]);
        }
        return trie.maoir_prefixo(strs.size()); //O(m), m = tamanho da menor palavra
    }
};
//Complexidade total: O(n*m), n = número de palavras, m = tamanho da palavra