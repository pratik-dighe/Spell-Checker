#include <iostream> 
#include <unordered_map> 
using namespace std;

// Trie Node 
struct TrieNode {
unordered_map<char, TrieNode*> children;

bool isEndOfWord;

};


// Function to create a new Trie Node 
TrieNode* createNode() {
    TrieNode* newNode = new TrieNode(); newNode->isEndOfWord = false; return newNode;
}


// Function to insert a word into the Trie

void insertWord(TrieNode* root, const string& word) {

TrieNode* curr = root; for (char ch : word) {
if (curr->children.find(ch) == curr->children.end()) {

curr->children[ch] = createNode();
}

curr = curr->children[ch];

}

curr->isEndOfWord = true;

}


// Function to search for a word in the Trie

bool searchWord(TrieNode* root, const string& word) {

TrieNode* curr = root; for (char ch : word) {
if (curr->children.find(ch) == curr->children.end()) {

return false;

}

curr = curr->children[ch];

}

return curr != nullptr && curr->isEndOfWord;

}


// Function to perform spell checking
string text;
void spellCheck(TrieNode* root, const string& text) {

string word = ""; 
for (char ch : text) {
    if (ch != ' ') {
        word += ch;
        
        } 
    else {
        
        if (!searchWord(root, word)) { cout << "Misspelled word: " <<word << endl;
}

word = "";
}
}
// Check the last word in the text

if (!word.empty() && !searchWord(root, word)) {

cout << "Misspelled word: " << word<< endl;

}
else {
    cout<<word<<" is correct word"<<endl;
}

}
int main() {

// Create the root of the Trie 

TrieNode* root = createNode();

// Insert some example words into the Trie 

insertWord(root, "apple"); 
insertWord(root, "banana"); 
insertWord(root, "cherry"); 
insertWord(root, "grape"); 
insertWord(root, "orange");

// Get the text to spell check string text;
cout << "Enter the text of fruits to spell check: "; 
getline(cin, text);

//perform spell checking

spellCheck(root,text);

return 0;
}