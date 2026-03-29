//https://codeforces.com/contest/706/problem/D

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

string toBinary(int num){
    return bitset<32>(num).to_string();
}

int toDecimal(string binaryNumber){
    return stoi(binaryNumber, 0, 2);
}

class TrieNode{
    public:
        TrieNode* children[2];
        int eow;

    TrieNode(){
        children[0]=NULL;
        children[1]=NULL;
        eow=0;
    }

    TrieNode* addChild(char charToAdd){
        if(charToAdd=='0'){
            return children[0]=new TrieNode();
        }
        return children[1]=new TrieNode();
    }

    TrieNode* findChild(char charToFind){
        if(charToFind=='0'){
            return children[0];
        }
        return children[1];
    }

};

void insertWord(string word, TrieNode* root){
    int n=word.size();
    if(n==0)return;

    TrieNode* temp=root;

    for(int i=0;i<n;i++){
        TrieNode* child=temp->findChild(word[i]);
        if(child==NULL){
            child=temp->addChild(word[i]);
        }
        temp=child;
    }
    temp->eow++;
}



void removeChild(TrieNode* root, string word){
    if(root==NULL)return;

    TrieNode* parent=root;
    char letter=word[0];
    int n=word.size();
    TrieNode* temp=root;
    for(int i=0;i<n;i++){
        if(temp->findChild('0')!=NULL && temp->findChild('1')!=NULL){
            parent=temp;
            letter=word[i];
        }
        temp=temp->findChild(word[i]);
    }
    temp->eow--;
    if(temp->eow==0)
    parent->children[letter-'0']=NULL;
}


string maxXor(string word, TrieNode* root){
    int n=word.size();

    TrieNode* temp=root;
    string ans="";
    for(int i=0;i<n;i++){
        TrieNode* child=NULL;
        if(word[i]=='0'){
            child=temp->findChild('1');
            if(child==NULL){
                //go to 0
                child=temp->findChild('0');
                ans+='0';
            }else{
                ans+='1';
            }

        } else {
            child=temp->findChild('0');
            if(child==NULL){
                //go to 1
                child=temp->findChild('1');
                ans+='1';
            }else{
                ans+='0';
            }
        }
        if(child==NULL)return "0";
        temp=child;
    }
    return ans;
}


int32_t main(){

    TrieNode* root=new TrieNode();
    insertWord(toBinary(0), root);
    int t;cin>>t;
    while(t--){
        char q;cin>>q;
        int num;cin>>num;
        if(q=='+'){
            insertWord(toBinary(num), root);
        }
        else if(q=='?'){
            string val=maxXor(toBinary(num), root);
            cout<<(toDecimal(val)^num)<<endl;
        }
        else if(q=='-'){
            removeChild(root, toBinary(num));
        }
    }

    return 0;
}
