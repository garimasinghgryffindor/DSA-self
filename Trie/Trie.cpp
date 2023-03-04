struct Node {
    Node* links[26];
    bool flag = false;
};

class Trie {
public:
    Node * root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            if(!node->links[ch-'a']) {
                node->links[ch-'a'] = new Node();
            }
            node = node->links[ch-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node * node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            if(!node->links[ch-'a']) {
                return false;
            }
            node = node->links[ch-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node * node = root;
        for(int i=0 ; i<prefix.length() ; i++) {
            char ch = prefix[i];
            if(!node->links[ch-'a']) {
                return false;
            }
            node = node->links[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
