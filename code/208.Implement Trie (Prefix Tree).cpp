class TrieNode {
public:
    bool is_str;
    TrieNode* next[26];
    
    TrieNode(): is_str(false) {
        for(int i=0; i<26; i++) next[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if(!word.length()) return ;
        
        TrieNode* cur = root;
        for(int i=0; i<word.length(); i++) {
            if(!cur->next[word[i]-'a']) {
                cur->next[word[i]-'a'] = new TrieNode();
            }
            cur = cur->next[word[i]-'a'];
        }
        cur->is_str = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.length(); i++) {
            if(!cur->next[word[i]-'a']) return false;
            cur = cur->next[word[i]-'a'];
        }
        return cur->is_str;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i=0; i<prefix.length(); i++) {
            if(!cur->next[prefix[i]-'a']) return false;
            cur = cur->next[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
