class TrieNode {
public:
    char data = '\0';
    unordered_map<char, TrieNode*> children;
    bool isTerminal = false;
    int freq = 1;  // You can increment this in the future if needed
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
                cur = cur->children[c];
            } else {
                cur = cur->children[c];
                cur->freq++;  // Increment frequency for the given path
            }
        }
        cur->isTerminal = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children.count(c)) return false;
            cur = cur->children[c];
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
        if (!node->children.count(c)) return false;

        bool shouldDeleteChild = removeUtil(node->children[c], word, depth + 1);
        if (shouldDeleteChild) {
            delete node->children[c];
            node->children.erase(c);
        }

        return node->children.empty() && !node->isTerminal;
    }
};
