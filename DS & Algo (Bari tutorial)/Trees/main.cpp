#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Node {

    public:
    int data;
    Node *l_child;
    Node *r_child;

    Node (int data) {

        this -> data = data;
        l_child = r_child = nullptr;
    }
};

class Tree {

    private:
    Node* root;

    public:
    Tree();
    Node* getRoot();
    void setRoot(Node *newTree);
    void preOrder_traversal(Node *tree);
    void inOrder_traversal(Node *tree);
    void postOrder_traversal(Node *tree);
    void it_preOrder_traversal();
    void it_inOrder_traversal();
    void it_postOrder_traversal(); // doesn't work
    void levelOrder_traversal();
    void countEverything(); // Function created by me to find out total node, sum, leaf, degree(1), degree(2)
    int countNode(Node *tree);
    int countLeaf(Node *tree);
    int countDegree1(Node *tree);
    int countDegree2(Node *tree);
    int sum(Node *tree);
    int height(Node *p);
    Node* generateFromTraversal(int* preorder, int* inorder, int inStart, int inEnd);
    ~Tree();
};

Tree :: Tree() {

    int i;
    queue<Node*> q;

    cout << "Enter root value : ";
    cin >> i;

    if (i < 1) {
        root = nullptr;
        return;
    }

    root = new Node(i);
    q.push(root);

    while (!q.empty()) {

        Node *ptr = q.front();
        q.pop();

        cout << "Enter left child of " << ptr -> data << " : ";
        cin >> i;

        if (i > 0) {

            Node *temp = new Node(i);
            ptr -> l_child = temp;
            q.push(temp);
        }

        cout << "Enter right child of " << ptr -> data << " : ";
        cin >> i;

        if (i > 0) {

            Node *temp = new Node(i);
            ptr -> r_child = temp;
            q.push(temp);
        }
    }
}

Node* Tree :: getRoot() {
    return root;
}

void Tree :: setRoot(Node *newTree) {
    root = newTree;
}

void Tree :: preOrder_traversal(Node *tree) {

    if (tree) {

        cout << tree -> data << " ";
        preOrder_traversal(tree -> l_child);
        preOrder_traversal(tree -> r_child);
    } 
}

void Tree :: inOrder_traversal(Node *tree) {

    if (tree) {

        inOrder_traversal(tree -> l_child);
        cout << tree -> data << " ";
        inOrder_traversal(tree -> r_child);
    }
}

void Tree :: postOrder_traversal(Node *tree) {

    if (tree) {

        postOrder_traversal(tree -> l_child);
        postOrder_traversal(tree -> r_child);
        cout << tree -> data << " ";
    }
}

void Tree :: it_preOrder_traversal() {

    stack<Node*> st;
    Node *ptr = root;

    while (ptr || !st.empty()) {

        if (ptr) {

            cout << ptr -> data << " ";
            st.push(ptr);
            ptr = ptr -> l_child;
        }
        else {

            ptr = st.top();
            st.pop();
            ptr = ptr -> r_child;
        }
    }
}

void Tree :: it_inOrder_traversal() {

    stack<Node*> st;
    Node *ptr = root;

    while (ptr || !st.empty()) {

        if (ptr) {

            st.push(ptr);
            ptr = ptr -> l_child;
        }
        else {

            ptr = st.top();
            st.pop();
            cout << ptr -> data << " ";
            ptr = ptr -> r_child;
        }
    }
}

void Tree :: it_postOrder_traversal() { // doesn't work

    stack<long int> st;
    Node *ptr = root;
    long int temp;

    while (ptr || !st.empty()) {

        if (ptr) {

            st.push((long int) temp);
            ptr = ptr -> l_child;
        }
        else {

            temp = st.top();
            st.pop();

            if (temp > 0) {
                
                st.push(-temp);
                ptr = ((Node*) temp) -> r_child;
            }
            else {
                
                cout << ((Node*)(-1 * temp)) -> data << " ";
                ptr = nullptr;
            }
        }
    }
}

void Tree :: levelOrder_traversal() {

    queue<Node*> q;

    cout << root -> data << " ";
    q.push(root);

    while (!q.empty()) {

        Node *ptr = q.front();
        q.pop();

        if (ptr -> l_child) {
            
            cout << ptr -> l_child -> data << " ";
            q.push(ptr -> l_child);
        }
        if (ptr -> r_child) {
            
            cout << ptr -> r_child -> data << " ";
            q.push(ptr -> r_child);
        }
    }
}

void Tree :: countEverything() {

    if (!root) {
        
        cout << "Tree is empty.\n";
        return;
    }

    int n, s, l, d1, d2;
    n = 1;
    s = root -> data;
    l = d1 = d2 = 0;

    stack<Node*> st;

    Node *p = root;

    while (p || !st.empty()) {

        if (p -> l_child && p -> r_child) {
            
            d2++;
            n += 2;
            s += p -> l_child -> data + p -> r_child -> data;
            st.push(p);
            p = p -> l_child;
        }

        else if (p -> l_child && !p -> r_child) {

            d1++;
            n++;
            s += p ->l_child -> data;
            p = p -> l_child;
        }
        
        else if (!p -> l_child && p -> r_child) {

            d1++;
            n++;
            s += p ->r_child -> data;
            p = p -> r_child;
        }
        
        else if (!p -> l_child && !p -> r_child){  

            l++;
            
            if (st.empty())
                break;

            p = st.top() -> r_child;
            st.pop();
        }

        else if (!p && !st.empty()) {

            p = st.top() -> r_child;
            st.pop();
        }
    }

    cout << "Total number of nodes : " << n << "\n";
    cout << "Sum : " << s << "\n";
    cout << "Total number of leaf nodes : " << l << "\n";
    cout << "Total number of nodes with degree(1) : " << d1 << "\n";
    cout << "Total number of nodes with degree(2) : " << d2 << "\n";
}

int Tree :: countNode(Node *tree) {


    if (tree)
        return countNode(tree -> l_child) + countNode(tree -> r_child) + 1;
    
    return 0;
}

int Tree :: countLeaf(Node *tree) {

    int x = 0, y = 0;

    if (tree) {

        x = countLeaf(tree -> l_child);
        y = countLeaf(tree -> r_child);

        if (!tree -> l_child && !tree -> r_child)
            return x + y + 1;
        
        return x + y;
    }
    return 0;
}

int Tree :: countDegree1(Node *tree) {

    int x = 0, y = 0;

    if (tree) {

        x = countDegree1(tree -> l_child);
        y = countDegree1(tree -> r_child);

        if ((tree -> l_child && !tree -> r_child) || (!tree -> l_child && tree -> r_child))
            return x + y + 1;
        
        return x + y;
    }
    return 0;
}

int Tree :: countDegree2(Node *tree) {

    int x = 0, y = 0;

    if (tree) {

        x = countDegree2(tree -> l_child);
        y = countDegree2(tree -> r_child);

        if (tree -> l_child && tree -> r_child)
            return x + y + 1;
        
        return x + y;
    }
    return 0;
}

int sum(Node *tree) {

    int x = 0, y = 0;

    if (tree) {

        x = sum(tree -> l_child);
        y = sum(tree -> r_child);

        return x + y + tree -> data;
    }
    return 0;
}

int Tree :: height(Node *tree) {

    int x = 0, y = 0;

    if (!tree)
        return -1;

    x = height(tree -> l_child);
    y = height(tree -> r_child);

    return x > y ? x + 1 : y + 1;
}

int searchInorder(int* inArray, int inStart, int inEnd, int data) {

    for (int i = inStart; i <= inEnd; i++) {

        if(inArray[i] == data)
            return i;
    }
    return -1;
}

Node* Tree :: generateFromTraversal(int* preorder, int* inorder, int inStart, int inEnd) {

    static int preIndex = 0;

    if (inStart > inEnd)
        return nullptr;

    Node* node = new Node(preorder[preIndex++]);

    if (inStart == inEnd)
        return node;

    int splitIndex = searchInorder(inorder, inStart, inEnd, node -> data);

    node -> l_child = generateFromTraversal(preorder, inorder, inStart, splitIndex-1);
    node -> r_child = generateFromTraversal(preorder, inorder, splitIndex+1, inEnd);

    return node;
}

void releaseTree(Node *tree) {

    if (tree) {

        releaseTree(tree -> l_child);
        releaseTree(tree -> r_child);
        delete tree;
    }
}

Tree :: ~Tree() {

    releaseTree(root);
}

int main() {

    Tree t;

    int pre[9], in[9], input;

    for (int i = 0; i < 9; i++) {

        cin >> input;
        pre[i] = input;
    }

    for (int i = 0; i < 9; i++) {

        cin >> input;
        in[i] = input;
    }

    Node *tree = t.generateFromTraversal(pre, in, 0, 8);

    t.setRoot(tree);

    t.preOrder_traversal(t.getRoot());
    cout << endl;
    t.inOrder_traversal(t.getRoot());
    cout << endl;
    t.postOrder_traversal(t.getRoot());
    cout << endl;
    t.levelOrder_traversal();
    cout << endl;

    t.countEverything();
    cout << endl;

    // cout << "Number of nodes : " << t.countNode(t.getRoot()) << endl;
    // cout << "Number of leaf : " << t.countLeaf(t.getRoot()) << endl;
    // cout << "Number of nodes with degree(1) : " << t.countDegree1(t.getRoot()) << endl;
    // cout << "Number of nodes with degree(2) : " << t.countDegree2(t.getRoot()) << endl;

    // cout << "Sum : " << sum(t.getRoot()) << endl;

    cout << "Height of tree : " << t.height(t.getRoot()) << endl;

    return 0;
}