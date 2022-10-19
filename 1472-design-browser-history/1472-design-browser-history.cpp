class Node{
    public:
    string val;
    Node *prev,*next;
    Node(){
        val = "";
        prev=next=NULL;
    }
    Node(string _val){
        val= _val;
        prev=next=NULL;
    }
};
class BrowserHistory {
public:
    Node* head  = new Node();
    BrowserHistory(string homepage) {
        Node*begin = new Node(homepage);
        head->next = begin;
        begin->prev = head;
        head = head->next;
    }
    
    void visit(string url) {
        Node *temp = new Node(url);
        head->next = temp;
        temp->prev = head;
        head = head->next;
    }
    
    string back(int steps) {
        while(steps-- and head->prev->val!=""){
            head = head->prev;
        }
        return head->val;
    }
    
    string forward(int steps) {
        while(steps-- and head->next){
            head=head->next;
        }
        return head->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */