#include <bits/stdc++.h>

using namespace std;

#define int long long

class Trie {
    class Node {
    public:
        Node* links[26]; // array to store the links to other nodes
        int end = 0; // counter for the number of complete strings
        int curr = 0; // counter for the prefix strings

        bool check_key(char ch) {
            if (links[ch - 'a'] != NULL)
                return true;
            return false;
        }

        void put(char ch, Node* curr) {
            links[ch - 'a'] = curr;
        }

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

int32_t main()
{
    return 0;
}
