#include <bits/stdc++.h>

using namespace std;

#define int long long

class Trie {
    class Node {
    public:
        Node* links[26]; // array to store the links to other nodes
        int end = 0; // counter for the number of complete strings
        int curr = 0; // counter for the prefix strings
        // function to check the existance of the key
        bool check_key(char ch) {
            if (links[ch - 'a'] != NULL)
                return true;
            return false;
        }

        // function to insert node at given key
        void put(char ch, Node* curr) {
            links[ch - 'a'] = curr;
        }

        // function to get the node corresponding to given key
        Node* get_link(char ch) {
            return links[ch - 'a'];
        }

        void inc_end() {
            end++;
        }
        void inc_curr() {
            curr++;
        }
        void dec_end() {
            end--;
        }
        void dec_curr() {
            curr--;
        }
    };

    Node* Root;
public:

    Trie() {
        Root = new Node();
    }

    void insert(string& word) {
        Node* temp = Root;
        for (auto it : word) {
            if (temp->check_key(it)) {
                temp = temp->get_link(it);
            }
            else {
                temp->put(it, new Node());
                temp = temp->get_link(it);
            }
            temp->inc_curr();
        }
        temp->inc_end();
    }

    int countWordsEqualTo(string& word) {
        Node* temp = Root;
        for (auto it : word) {
            if (!temp->check_key(it))
                return 0;
            temp = temp->get_link(it);
        }
        return temp->end;
    }

    int countWordsStartingWith(string& word) {
        Node* temp = Root;
        for (auto it : word) {
            if (!temp->check_key(it))
                return 0;
            temp = temp->get_link(it);
        }
        return temp->curr;
    }

    void erase(string& word) {
        Node* temp = Root;
        for (auto it : word) {
            if (temp->check_key(it)) {
                temp = temp->get_link(it);
            }
            else {
                temp->put(it, new Node());
                temp = temp->get_link(it);
            }
            temp->dec_curr();
        }
        temp->dec_end();
    }
};


// link :- https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class Trie {
    class Node {
        Node* links[2];
    public:
        bool check(int id) {
            if (links[id] != NULL)
                return true;
            return false;
        }

        void put_link(int id, Node* curr) {
            links[id] = curr;
        }

        Node* get_link(int id) {
            return links[id];
        }

    };
    /////////////// root node ////////////
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* temp = root;
        for (int i = 31;i >= 0;i--) {
            int bit = (num >> i) & 1;
            if (temp->check(bit)) {
                temp = temp->get_link(bit);
            }
            else {
                temp->put_link(bit, new Node());
                temp = temp->get_link(bit);
            }
        }
    }

    int get_max(int num) {
        Node* temp = root;
        int ans = 0;
        for (int i = 31;i >= 0;i--) {
            int bit = (num >> i) & 1;
            if (temp->check(1 - bit)) {
                temp = temp->get_link(1 - bit);
                ans |= (1 << i);
            }
            else {
                temp = temp->get_link(bit);
            }
        }
        return ans;
    }
};


int32_t main()
{
    return 0;
}
