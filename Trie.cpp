class TrieNode {
public:
    char data = '\0';
    TrieNode* children[26] = {NULL};
    bool isTerminal = false;
    int freq = 1;  
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c-'a';
            if (!cur->children[idx]) {
                cur->children[idx] = new TrieNode();
                cur = cur->children[idx];
            } else {
                cur = cur->children[idx];
                cur->freq++;  
            }
        }
        cur->isTerminal = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c-'a';
            if (!cur->children[idx]) return false;
            cur = cur->children[idx];
        }
        return cur->isTerminal;
    }

    bool remove(string word) {
        return removeUtil(root, word, 0);
    }

private:
    bool removeUtil(TrieNode* node, string word, int depth) {
        if (depth == word.length()) {
            if (!node->isTerminal) return false;
            node->isTerminal = false;
            return node->children.empty();
        }

        char c = word[depth];
        int idx = c-'a';
        if (!node->children[idx]) return false;

        bool shouldDeleteChild = removeUtil(node->children[idx], word, depth + 1);
        if (shouldDeleteChild) {
            delete node->children[idx];
            node->children[idx];
        }

        return node->children.empty() && !node->isTerminal;
    }
};
