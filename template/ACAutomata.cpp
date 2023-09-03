class ACAutomata {
    int sonnum;    
    struct Node {
        Node **s;
        Node *fail;
        int val;
        Node operator++() { val++; return *this; }
        Node operator++(int) { return *this = ++*this; }
        Node(const int _sonnum) {
            s = new Node*[_sonnum];
        }
    } *root;
    ACAutomata(const int _sonnnum = 26) {
        root = new Node(sonnum);
    }
};