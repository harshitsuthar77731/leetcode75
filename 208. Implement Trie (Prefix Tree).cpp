class Trie {
    struct trienode{
        char val;
        int count;
        int endshere;
        trienode *child[26];     
    };
    trienode *root;
    trienode* getnode(int index){
        trienode *newnode = new trienode;
        newnode->val = 'a'+index;
        newnode->count = newnode->endshere = 0;
        for(int i=0;i<26;i++)
            newnode->child[i] = NULL;
        return newnode;
    }
    
public:
    Trie() {
        //creating root node;
        root = getnode('/'-'a');
    }
    
    void insert(string word) {
        trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0';i++){
            index = word[i]-'a';
            if(curr->child[index]==NULL){
                curr->child[index] = getnode(index);
            }
            curr->child[index]->count+=1;
            curr = curr->child[index];
        }
        curr->endshere+=1;
    }
    
    bool search(string word) {
        trienode *curr = root;
        int index;
        for(int i=0;word[i]!='\0';i++){
            index = word[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->endshere>0);
    }
    
    bool startsWith(string prefix) {
        trienode *curr = root;
        int index;
        for(int i=0;prefix[i]!='\0';i++){
            index = prefix[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            curr = curr->child[index];
        }
        return (curr->count>0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
