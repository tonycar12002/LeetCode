/*
Author: Tony Hsiao
Date: 2019/05/21
Topic: 208. Implement Trie (Prefix Tree)
Speed: 72 ms, 26.2MB
Note: 
Trie Tree Introduction http://www.csie.ntnu.edu.tw/~u91029/String.html#6

*/
class Node{
public:
    Node(char c){next=NULL, child=NULL, counter = 0, character = c;}

    char character;
    Node* next;
    Node* child;
    int counter; // record the end of word

};
class Trie {
private:
    Node* root = NULL;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node('0');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* tmp = root->child;
        Node* father = root;
        int cur = 0;
        while(cur < word.size()){
            if(tmp){ // no any sub trie node
                tmp = new Node(word[cur]);
                father -> child = tmp;
                father = tmp;
                tmp = tmp -> child;
            }    
            else{ // find same element
                bool find = false;
                while(tmp){
                    father = tmp;
                    if(tmp -> character == word[cur]){
                        tmp = tmp -> child;
                        find = true;
                        break;
                    }
                    else
                        tmp =  tmp -> next;
                }
                if(!find){
                    tmp = new Node(word[cur]);
                    father -> next = tmp;
                    father = tmp;
                    tmp = tmp -> child;
                }
            }
            cur += 1;
        }
        father -> counter += 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* tmp = root->child;
        int cur = 0;
        while(tmp){
            if(tmp->character == word[cur]){
                if(cur == word.size()-1)
                    return (tmp->counter > 0) ? true : false ;
                tmp = tmp -> child;
                cur ++;
            }
            else
                tmp = tmp -> next;
        }
        return false;        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* tmp = root->child;
        int cur = 0;
        while(tmp){
            if(tmp->character == prefix[cur]){
                if(cur == prefix.size()-1)
                    return true;
                tmp = tmp -> child;
                cur ++;
            }
            else
                tmp = tmp -> next;
        }
        return false;  
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */