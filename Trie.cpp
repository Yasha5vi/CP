class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal = false;

    TrieNode(char ch) : data(ch) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode('\0'); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode(c);
            }
            curr = curr->children[c];
        }
        curr->isTerminal = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) return false;
            curr = curr->children[c];
        }
        return curr->isTerminal;
    }

    bool remove(string word) { return removeUtil(root, word, 0); }

private:
    bool removeUtil(TrieNode* node, string word, int depth) {
        if (depth == word.length()) {
            if (!node->isTerminal) return false;
            node->isTerminal = false;
            return node->children.empty();
        }
        char c = word[depth];
        if (node->children.find(c) == node->children.end()) return false;
        bool shouldDeleteChild = removeUtil(node->children[c], word, depth + 1);
        if (shouldDeleteChild) {
            delete node->children[c];
            node->children.erase(c);
        }
        return node->children.empty() && !node->isTerminal;
    }
};
