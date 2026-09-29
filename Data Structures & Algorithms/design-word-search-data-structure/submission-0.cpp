class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool endOfWord = false;

};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.size(); i++) {
            if (!current->children.count(word[i])) {
                current->children[word[i]] = new TrieNode();
            }

            current = current->children[word[i]];
        }

        current->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        return helper(word, 0, root);
        // if we reach a dot, try every single combination
    }

    bool helper(string& word, int i, TrieNode* current) {
        if (i == word.size() && current->endOfWord) return true;

        if (word[i] == '.') {
            unordered_map<char, TrieNode*>& children = current->children;
            for (auto c : children) {
                if (helper(word, i + 1, current->children[c.first])) return true;
            }
        } else {
            unordered_map<char, TrieNode*>& children = current->children;
            if (!children.count(word[i])) return false;
            if (helper(word, i + 1, current->children[word[i]])) return true;
        }

        return false;
    }
};
