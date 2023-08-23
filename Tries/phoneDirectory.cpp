#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//You are given a list of strings which denotes the contacts that exist in your phone directory. The search query on a string 'str' which is a query string displays all that contacts which are present in the given directroy with the prefix as 'str'.
//One special property of the search functionis that when a user searches for a contact from the contact list then suggestions (contacts with prefix as the string enteres so far) are shown agter the user enters each character.

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
    
      void printSuggestions(trieNode* curr, string prefix, vector<string> &temp){

         if (curr->isTerminal==true) 
         {
            temp.push_back(prefix);
            //*******here don't return ;  // as it is removed so we can have nodes after terminal also e.g. cod & coding  here for cod , isterminal= true at d but also need the after nodes
         }
         
          for (char i = 'a'; i <= 'z'; i++)
          {
              trieNode *child = curr->children[i-'a'];
              if (child!=NULL)
              {
                prefix.push_back(i);
                printSuggestions(child,prefix,temp);
                prefix.pop_back(); //to bachtrack
              }
              
          }
          
      }
        vector<vector<string>> getSuggestions(string queryStr){
            trieNode* prev= root;
            vector<vector<string>> suggestions;
            string prefix="";

            for (int i = 0; i < queryStr.length(); i++)
            {
                char lastch= queryStr[i];
                prefix.push_back(lastch);
                //check for lastch
                trieNode* curr=prev->children[lastch-'a'];
                //if not found
                if (curr==NULL) 
                {
                   break;
                }
                //if found 
                vector<string> temp;  // to contain the suggestions which start with the ongoing prefix 
                printSuggestions(curr,prefix,temp);
                suggestions.push_back(temp);
                //now clear the temp  so that for next prefix we will have fresh suggestions
                temp.clear();
                prev=curr;
            }
            return suggestions;

        }
};
int main()
{	  trie* t= new trie();
      t->insertWord("ninjas");
      t->insertWord("coding");
      t->insertWord("ninjahattori");
      t->insertWord("nights");
   
      string queryStr= "ninja";
    vector<vector<string>> ans= t->getSuggestions(queryStr);

      for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
      }
    return 0;
}