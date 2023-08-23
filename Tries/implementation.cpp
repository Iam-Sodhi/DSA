#include <iostream>
#include<string>

using namespace std;
// implement the addtion, search, and removing the words in tries
class trieNode
{
public:
    char data;
    trieNode *children[26];
    bool isTerminal;
    trieNode(char a)
    {
        data = a;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class trie
{
public:
   
  
     trieNode *root;
     trie(){
       root=new trieNode('\0'); // to make root node equal to it
     } 
        void insertUtil(trieNode * root, string word)
        {
            if (word.length() == 0)
            {
             root->isTerminal=true; // here we mark it as terminal node to differentiate bw words like king & kingdom
             return;
            }
            trieNode *child;
            int index = word[0] - 'a'; // for small caps(sssumption)

            if (root->children[index] != NULL) // if that letter is present
            {
                child = root->children[index];
            }
            else
            { // absent
                child = new trieNode(word[0]);
                root->children[index] = child;
            }

            // recursion
            insertUtil(child, word.substr(1));
        }
        void insertWord(string word)
        {
            insertUtil(root, word);
        }


        //******Searching*******
        bool searchUtil(trieNode *root, string word){
             if (word.length() == 0)
            {
            return root->isTerminal; // so that king & kingdom will not be treated 
            //true only when the last character will be like leaf element
            //****return true; // if we need only to find the prefix or start with
            }
            trieNode* child;
            int index=word[0]-'a';
            if (root->children[index]!=NULL) // word[0] character is present as children
            {
               child=root->children[index];
            }
            else
            {
                return false;
            }
            
            return searchUtil(child,word.substr(1));
            
        }

        bool search(string word){
           return  searchUtil(root,word);
        }

        //*****Deleting ******
        //here we need first to search and at last mark the isTerminal as false
           void deleteUtil(trieNode *root, string word){
             if (word.length() == 0)
            {
             root->isTerminal=false; //mark it false
            return;
            }
            trieNode* child;
            int index=word[0]-'a';
            if (root->children[index]!=NULL) // word[0] character is present as children
            {
               child=root->children[index];
            }
            else
            {
                cout<<"The given word is not present in trie"<<endl;
                return;
            }
            
           deleteUtil(child,word.substr(1));
            
        }
        void deleteWord(string word){
            deleteUtil(root,word);
        }
    
};
int main()
{     trie* t=new trie();
      t->insertWord("hello");
      cout<<t->search("hello")<<endl;
      cout<<t->search("hellow")<<endl;
      cout<<t->search("hell")<<endl;
      t->deleteWord("hello"); // now this will be deleted
      cout<<t->search("hello")<<endl;

    return 0;
}