class PrefixTree {
    class TrieNode {
        public:
            unordered_map<char, TrieNode*> children;
            bool endOfWord = false;
    };

public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
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

        for (int i = 0; i < word.size(); i++) {
            if (!current->children.count(word[i])) {
                return false;
            } 
            current = current->children[word[i]];
        }

        return current->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (!current->children.count(prefix[i])) {
                return false;
            } 
            current = current->children[prefix[i]];
        }

        return true;
    }
};
