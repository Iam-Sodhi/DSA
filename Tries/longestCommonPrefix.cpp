#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// we can either use the approach where we will compare the characters of one string with all the characters (orderwise) of the other strings
// OR we will use the TRIES here (here when we find the node where the no of children of a node gets more than 1 , upto that we have required prefix)
//PURane wala method ki space complexityO((1)) better hai trie(O(n*size of string)) wale se ( hence that is more efficient)

//*****Ist Method*****
string lcp(vector<string> &arr, int n){   //space complexity = O(1)
    string ans="";
    //for traversing all characters of first string
    for(int i=0;i<arr[0].size();i++){
        char c=arr[0][i];
        bool match =true;
        // for comparing ch with rest of strings
        for (int j = 0; j < n; j++)
        {
            // not match
            if( arr[j].size()<i ||c!=arr[j][i]){ // arr[j].size()<i // to make sure the ith character exist int arr[j] wali string
                match =false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
             ans.push_back(c);
        }
        return ans;
        
    }
}
//****TRIES****
class trieNode{
    public: char data;
           trieNode* children[26];
           bool isTerminal;
           int count; // to count the number of children 
           trieNode(char a){
             data = a;
             for (int i = 0; i < 26; i++)
             {
                 children[i]=NULL;
                 isTerminal=false;
                 count=0;
             }

             
           }
};
class trie{
    public: 
     trieNode* root;
       trie(char a){
      root = new trieNode(a);
       }
        void insertUtil(trieNode* root, string s){
            if(s.length()==0){
               root->isTerminal=true;
               return;
            }
            int index=s[0]-'a';
            trieNode* child;
            if (root->children[index]!=NULL) // present then aage bado
            {  
                child=root->children[index];
            }
            else{
                child=new trieNode(s[0]);
                root->count++;
                root->children[index]=child;

            }
            insertUtil(child,s.substr(1));
            
        }
       void insertWord(string s){
         insertUtil(root,s);
       }


       void longestCommonPrefix(string s,string ans){ // we will compare using one string from given strings
           
           for(int i=0; i<s.length();i++){
                char ch=s[i];
                if (root->count==1)
                {
                    ans.push_back(ch);
                    // aage bade
                    int index=ch-'a';
                    root=root->children[index];

                }
                else
                {
                    break;
                } 
                if(root->isTerminal){ // when we find the terminal node , no need to look for next characters
                    break;
                }
                
           }
           cout<<ans<<endl;
       }
};
int main()
{	  trie* t=new trie('\0');
      t->insertWord("ninja");
      t->insertWord("nina");
      t->insertWord("nintra");
      string ans="";
      t->longestCommonPrefix("ninja",ans);
      
    return 0;
}