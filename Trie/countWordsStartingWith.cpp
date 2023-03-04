#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node* links[26];
    int prefixCount = 0;
    int wordCount = 0;
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
            node->prefixCount++;
        }
        node->wordCount++;
    }
    
    int countWordsStartingWith(string word) {
        Node * node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            if(!node->links[ch-'a']) {
                return 0;
            }
            node = node->links[ch-'a'];
        }
        return node->prefixCount;
    }

    int countWordsEqualTo(string word) {
        Node * node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            if(!node->links[ch-'a']) {
                return 0;
            }
            node = node->links[ch-'a'];
        }

        return node->wordCount;
    }
};


int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" , "there" , "hello" , "there"};
    int n = sizeof(keys)/sizeof(keys[0]);
    
    Trie trie = Trie();

    // Construct trie
    for (int i = 0; i < n; i++)
        trie.insert(keys[i]);

    string chkWord = "there";

    int count = trie.countWordsEqualTo(chkWord);
    cout<<"Count for the word   "<<chkWord<<"  :   "<<count<<endl; 

    string prefix = "the";
    int count2 = trie.countWordsStartingWith(prefix);
    cout<<endl<<"Count for the prefix   "<<prefix<<"  :   "<<count2<<endl;
    
    return 0;
}

