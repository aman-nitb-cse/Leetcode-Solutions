// Last updated: 6/25/2026, 11:12:13 PM
class Node {
public:
    char val = '\0';
    Node* prev = NULL;
    Node* next = NULL;

    Node(){}
    Node(char c) : val(c){}
};

class TextEditor {
private: 
    Node* head, *tail, *curr;
    void add_char(char c){
        auto node = new Node(c);
        curr->prev->next = node;
        node->next = curr;
        node->prev = curr->prev;
        curr->prev = node;
    }

    void del_char(){
        auto node = curr->prev;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    string left_string(){
        string s;
        for(auto i = curr->prev; i != head && s.size() < 10; i = i->prev){
            s += i->val;
        }
        ranges::reverse(s);
        return s;
    }
public:
    TextEditor() {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
        curr = tail;
    }

    void addText(string s) {
        for(char &c : s) add_char(c);
    }
    
    int deleteText(int k) {
        int i;
        for(i = 0; i < k && curr->prev != head; i++){
            del_char();
        }
        return i;
    }
    
    string cursorLeft(int k) {
        while(k-- && curr->prev != head){
            curr = curr->prev;
        }
        return left_string();
    }
    
    string cursorRight(int k) {
        while(k-- && curr != tail){
            curr = curr->next;
        }
        return left_string();
    }
};