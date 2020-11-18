#include<iostream>
#include<stack>

using namespace std;

class Node {

    public:
    int data;
    Node *l_child, *r_child;

    Node(int data) {

        this -> data = data;
        l_child = r_child = nullptr;
    }
};

class BST {

    private:
    Node *root;

    public:
    BST();
    Node* getRoot();
    void setRoot(Node *n);

    // Searching
    Node* search_rec(Node *tree, int key);
    Node* search_it(int key);

    // Insertion
    void insert_it(int data);
    Node* insert_rec(Node *tree, int data);

    // Deletion

    Node* deleteNode(Node* tree, int key);

    // Traversal
    void preorder(Node *tree);
    void inorder(Node *tree);
    void postorder(Node *tree);

    // Other
    int height(Node* tree);
    Node* inPre(Node* tree);
    Node* inSucc(Node* tree);

    // Generate from traversal
    Node* generate_pre(int* preArr, int n); // This function doesn't execute as expected - Now works after modifications done by me

    ~BST();
};

BST :: BST() {
    root = nullptr;
}

Node* BST :: getRoot() {
    return root;
}

void BST :: setRoot(Node *n) {
    this -> root = n;
}

Node* BST :: search_rec(Node *tree, int key) {

    if (!tree)
        return nullptr;

    else if (tree -> data == key)
        return tree;
    
    else if (tree -> data > key)
        return search_rec(tree -> l_child, key);

    else if (tree -> data < key)
        return search_rec(tree -> r_child, key);

    return nullptr;
}

Node* BST :: search_it(int key) {

    Node *ptr = root;

    while (ptr) {

        if (ptr -> data == key)
            return ptr;
        
        else if (ptr -> data > key)
            ptr = ptr -> l_child;

        else if (ptr -> data < key)
            ptr = ptr -> r_child;
    }
    return ptr;
}

void BST :: insert_it(int key) {

    if (!root) {

        Node* n = new Node(key);
        root = n;
        return;
    }

    Node *p, *r;

    p = root;
    r = nullptr;

    while(p) {

        r = p;

        if (p -> data == key) {
            
            cout << "Node already exists." << endl;
            return;
        }

        else if (p -> data < key)
            p = p -> r_child;
        
        else if (p -> data > key)
            p = p -> l_child;
    }

    Node *n = new Node(key);

    r -> data > n -> data ? r -> l_child = n : r -> r_child = n;
}

Node* BST :: insert_rec(Node *tree, int key) {

    if (!tree) {

        Node* n = new Node(key);
        return n;
    }

    else if (tree -> data < key)
            tree -> r_child = insert_rec(tree -> r_child, key);
        
    else if (tree -> data > key)
        tree -> l_child = insert_rec(tree -> l_child, key);

    return tree;
}

void BST :: preorder(Node *tree) {

    if (tree) {

        cout << tree -> data << " ";
        preorder(tree -> l_child);
        preorder(tree -> r_child);
    }
}

void BST :: inorder(Node *tree) {

    if (tree) {

        inorder(tree -> l_child);
        cout << tree -> data << " ";
        inorder(tree -> r_child);
    }
}

void BST :: postorder(Node *tree) {

    if (tree) {

        postorder(tree -> l_child);
        postorder(tree -> r_child);
        cout << tree -> data << " ";
    }
}

Node* BST :: deleteNode(Node* tree, int key) {

    if (!tree)
            tree = nullptr;

    else if (key < tree -> data)
        tree -> l_child = deleteNode(tree -> l_child, key);

    else if (key > tree -> data)
        tree -> r_child = deleteNode(tree -> r_child, key);

    else if (key == tree -> data) {

        if (!tree -> l_child && !tree -> r_child) {

            delete tree;
            tree = nullptr;
        }
        else {

            if (height(tree -> l_child) > height(tree -> r_child)) {

                Node* q = inPre(tree -> l_child);
                tree -> data = q -> data;
                tree -> l_child = deleteNode(tree -> l_child, q -> data);
            }
            else {
                Node* q = inSucc(tree -> r_child);
                tree -> data = q -> data;
                tree -> r_child = deleteNode(tree -> r_child, q -> data);
            }
        }
    }
    return tree;
}

int BST :: height(Node* tree) {

    int x,y;

    if(!tree)
        return -1;

    x = height(tree -> l_child);
    y = height(tree -> r_child);

    return x > y ? x + 1 : y + 1;
}

Node* BST :: inPre(Node* tree) {

    Node* p = tree;

    while (p && p -> r_child)
        p = p -> r_child;
    
    return p;
}

Node* BST :: inSucc(Node* tree) {

    Node* p = tree;

    while (p && p -> l_child)
        p = p -> l_child;
    
    return p;
}

Node* BST :: generate_pre(int* preArr, int n) { // This function doesn't execute as expected - Now works after modifications done by me

    int i = 0;
    stack<Node *> st;

    Node* root = new Node(preArr[i++]);
    Node* p = root;

    while (i < n) {

        if (preArr[i] < p -> data) {

            Node* t = new Node(preArr[i++]);
            p -> l_child = t;
            st.push(p);
            p = t;
        }
        else {
            
            if ((!st.empty() && preArr[i] < st.top() -> data) || (st.empty() && preArr[i] < INT32_MAX)) {
                Node* t = new Node(preArr[i++]);
                p -> r_child = t;
                p = t;
            }
            else {
                p = st.top();
                st.pop();
            }
        }
    }
    return root;
}


void releaseTree(Node *tree) {

    if (tree) {

        releaseTree(tree -> l_child);
        releaseTree(tree -> r_child);
        delete tree;
    }
}

BST :: ~BST() {
    releaseTree(root);
}

int main() {

    BST b;
    int i, j, key;
    Node *n = nullptr, *last = nullptr;

    // int pre[9] = {30, 15, 7, 22, 17, 27, 60, 45, 75};
    // // int post[9] = {7, 17, 27, 22, 15, 45, 75, 60, 30};

    // b.setRoot(b.generate_pre(pre, 9));

    // b.preorder(b.getRoot());
    // cout << endl;
    // b.inorder(b.getRoot());
    // cout << endl;
    // b.postorder(b.getRoot());
    // cout << endl;

    // cout << "Height is " << b.height(b.getRoot()) << endl;

    // return 0;

    while (i != 0) {

        cout << endl;
        cout << "1. Insert node(iterative)" << endl;
        cout << "2. Insert node(recursive)\n" << endl;
        cout << "3. Print preorder" << endl;
        cout << "4. Print inorder" << endl;
        cout << "5. Print postorder\n" << endl;
        cout << "6. Search a node (recursive)" << endl;
        cout << "7. Search a node (iterative)\n" << endl;
        cout << "8. Delete a node\n" << endl;
        cout << "9. Insert multiple node\n" << endl;
        cout << "Enter 0 to quit" << endl;

        cin >> i;

        switch (i) {
            
            case 0 :
                break;

            case 1 :
               
                cout << "Enter key : ";
                cin >> key;

                b.insert_it(key);
                break;
            
            case 2 :

                cout << "Enter key : ";
                cin >> key;

                n = b.insert_rec(b.getRoot(), key);
                b.setRoot(n);
                break;

            case 3 :

                cout << endl;
                b.preorder(b.getRoot());
                cout << endl;
                break;

            case 4 :

                cout << endl;
                b.inorder(b.getRoot());
                cout << endl;
                break;

            case 5 :    

                cout << endl;
                b.postorder(b.getRoot());
                cout << endl;
                break;

            case 6 :

                cout << "Enter key : ";
                cin >> key;

                n = b.search_rec(b.getRoot(), key);

                n == nullptr ? cout << "Node doesn't exist." : cout << "Node address : " << n << endl << "Data : " << n -> data;
                break;
            
            case 7 :

                cout << "Enter key : ";
                cin >> key;

                n = b.search_it(key);

                n == nullptr ? cout << "Node doesn't exist." : cout << "Node address : " << n << endl << "Data : " << n -> data;
                break;

            case 8 :

                cout << "Enter key : ";
                cin >> key;
                
                n = b.deleteNode(b.getRoot(), key);
                break;

            case 9 :
                
                cout << "Enter number of nodes : ";
                cin >> j;

                for (int x = 0; x < j; x++) {

                    cout << "Enter key " << x+1 << " : ";
                    cin >> key;

                    b.insert_it(key);
                }
                break;

            default :

                cout << "Invalid input. Enter again.\n";
                break;
        }
        cout << endl;
    }
    return 0;
}