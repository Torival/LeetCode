class TrieNode {
public:
    bool is_str;
    TrieNode* next[26];
    
    TrieNode(): is_str(false) {
        for(int i=0; i<26; i++) next[i] = NULL;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root, word);
    }
private:
    TrieNode *root;
    
    bool search(TrieNode* cur, string word) {
        if(!cur || !word.length()) return false;

        if(word[0] != '.') {
            if(word.length() == 1 && cur->next[word[0]-'a'])
                return cur->next[word[0]-'a']->is_str;
            else
                return search(cur->next[word[0]-'a'], word.substr(1));
        } else {
            if(word.length() == 1) {
                for(int i=0; i<26; i++)
                    if(cur->next[i] && cur->next[i]->is_str)
                        return true;
            } else {
                for(int i=0; i<26; i++) {
                    if(search(cur->next[i], word.substr(1)))
                        return true;
                }
            }
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
