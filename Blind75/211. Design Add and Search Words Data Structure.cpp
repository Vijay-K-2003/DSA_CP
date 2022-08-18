struct Node {
	Node *links[26];
	bool flag;
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
        flag = false;
    }
	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	void setEnd() {
		flag = true;
	}
	bool isEnd() {
		return flag;
	}
};
class WordDictionary {
private: 
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0 ; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        return searchInNode(word, 0, node);
    }
private:
    bool searchInNode(string& word, int i, Node* node) {
        if (node == NULL) {
            return false;
        }
        if (i == word.size()) {
            return node->flag;
        }
        if (word[i] != '.') {
            return searchInNode(word, i + 1, node->links[word[i] - 'a']);
        }
        for (int j = 0; j < 26; j++) {
            if (searchInNode(word, i + 1, node->links[j])) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
