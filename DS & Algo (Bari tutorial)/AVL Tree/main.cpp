#include<iostream>

using namespace std;

class Node {

    public:
    int data, height;
    Node *lchild, *rchild;

    Node(int data) {

        this -> data = data;
        height = 1;
        lchild = rchild = nullptr;
    }
};

class AVL {

    private:
    Node* root;

    public:

    AVL();

    Node* getRoot() {
        return root;
    }

    void setRoot(Node* tree) {
        this -> root = tree;
    }

    int height(Node* tree);
    int balanceFactor(Node* tree);
    Node* inPre(Node* tree);
    Node* inSucc(Node* tree);

    // Rotations
    Node* LLRotation(Node* tree);
    Node* RRRotation(Node* tree);
    Node* LRRotation(Node* tree);
    Node* RLRotation(Node* tree);

    Node* insert(Node* tree, int key);
    Node* deleteNode(Node* tree, int key);

    // Traversal
    void preorder(Node* tree);
    void inorder(Node* tree);
    void postorder(Node* tree);

    ~AVL();
};

AVL :: AVL() {
    root = nullptr;
}

int AVL :: height(Node* tree) {

    int x, y;

    x = (tree && tree -> lchild) ? tree -> lchild -> height : 0;
    y = (tree && tree -> rchild) ? tree -> rchild -> height : 0;

    return (x > y) ? x + 1 : y + 1;
}

int AVL :: balanceFactor(Node* tree) {

    int x, y;

    x = (tree && tree -> lchild) ? tree -> lchild -> height : 0;
    y = (tree && tree -> rchild) ? tree -> rchild -> height : 0;

    return x - y;
}

Node* AVL :: inPre(Node* tree) {

    Node* p = tree;

    while (p && p -> rchild)
        p = p -> rchild;
    
    return p;
}

Node* AVL :: inSucc(Node* tree) {

    Node* p = tree;

    while (p && p -> lchild)
        p = p -> lchild;
    
    return p;
}

Node* AVL :: LLRotation(Node *tree) {

    Node* pl = tree -> lchild;
    Node* plr = pl -> rchild;

    pl -> rchild = tree;
    tree -> lchild = plr;

    tree -> height = height(tree);
    pl -> height = height(pl);

    if (tree == root)
        root = pl;

    return pl;
}

Node* AVL :: RRRotation(Node *tree) {
    
    Node* pr = tree -> rchild;
    Node* prl = pr -> lchild;

    pr -> lchild = tree;
    tree -> rchild = prl;

    tree -> height = height(tree);
    pr -> height = height(pr);

    if (tree == root)
        root = pr;

    return pr;
}

Node* AVL :: LRRotation(Node *tree) {

    Node* pl = tree -> lchild;
    Node* plr = pl -> rchild;

    pl -> rchild = plr -> lchild;
    tree -> lchild = plr -> rchild;

    plr -> lchild = pl;
    plr -> rchild = tree;

    tree -> height = height(tree);
    pl -> height = height(pl);
    plr -> height = height(plr);

    if (tree == root)
        root = plr;

    return plr;
}

Node* AVL :: RLRotation(Node *tree) {

    Node* pr = tree -> rchild;
    Node* prl = pr -> lchild;

    pr -> lchild = prl -> rchild;
    tree -> rchild = prl -> lchild;

    prl -> lchild = tree;
    prl -> rchild = pr;

    tree -> height = height(tree);
    pr -> height = height(pr);
    prl -> height = height(prl);

    if (tree == root)
        root = prl;

    return prl;
}

Node* AVL :: insert(Node *tree, int key) {

    if (!tree) {

        Node* temp = new Node(key);

        if (tree == root)
            root = temp;

        return temp;
    }

    if (tree -> data == key) {

        cout << "Node already exists." << endl;
        return tree;
    }

    if (key < tree -> data)
        tree -> lchild = insert(tree -> lchild, key);
    
    else if (key > tree -> data)
        tree -> rchild = insert(tree -> rchild, key);

    tree -> height = height(tree);

    if (balanceFactor(tree) == 2 && balanceFactor(tree -> lchild) >= 0)
        return LLRotation(tree);
    
    else if (balanceFactor(tree) == -2 && balanceFactor(tree -> rchild) < 0)
        return RRRotation(tree);
    
    else if (balanceFactor(tree) == 2 && balanceFactor(tree -> lchild) < 0)
        return LRRotation(tree);

    else if (balanceFactor(tree) == -2 && balanceFactor(tree -> rchild) >= 0)
        return RLRotation(tree);

    return tree;
}

Node* AVL :: deleteNode(Node* tree, int key) {

    if (!tree)
        tree = nullptr;
    
    if (key < tree -> data)
        tree -> lchild = deleteNode(tree -> lchild, key);
    
    else if (key > tree -> data)
        tree -> rchild = deleteNode(tree -> rchild, key);

    else if (key == tree -> data) {

        if (!tree -> lchild && !tree -> rchild) {
            
            delete tree;
            tree = nullptr;
        } 
        else {

            if (height(tree -> lchild) > height(tree -> rchild)) {

                Node *p = inPre(tree -> lchild);
                tree -> data = p -> data;
                tree -> lchild = deleteNode(tree -> lchild, p -> data);
            }
            else {
                Node *p = inSucc(tree -> rchild);
                tree -> data = p -> data;
                tree -> rchild = deleteNode(tree -> rchild, p -> data);
            }
        }
    }

    if (tree)
        tree -> height = height(tree);

    if (balanceFactor(tree) == 2 && balanceFactor(tree -> lchild) == 1) // L1
        return LLRotation(tree);
    
    if (balanceFactor(tree) == 2 && balanceFactor(tree -> lchild) == -1) // L-1
        return LRRotation(tree);

    if (balanceFactor(tree) == 2 && balanceFactor(tree -> lchild) == 0) // L0
        return LLRotation(tree);

    if (balanceFactor(tree) == -2 && balanceFactor(tree -> lchild) == -1) // R-1
        return RRRotation(tree);

    if (balanceFactor(tree) == -2 && balanceFactor(tree -> lchild) == 1) // R1
        return RLRotation(tree);

    if (balanceFactor(tree) == -2 && balanceFactor(tree -> lchild) == 0) // R0
        return RRRotation(tree);

    return tree;
}

void AVL :: preorder(Node* tree) {

    if (tree) {
        
        cout << tree -> data << " ";
        preorder(tree -> lchild);
        preorder(tree -> rchild);
    }
}

void AVL :: inorder(Node* tree) {

    if (tree) {
        
        inorder(tree -> lchild);
        cout << tree -> data << " ";
        inorder(tree -> rchild);
    }
}

void AVL :: postorder(Node* tree) {

    if (tree) {
        
        postorder(tree -> lchild);
        postorder(tree -> rchild);
        cout << tree -> data << " ";
    }
}

void releaseTree(Node *tree) {

    if (tree) {

        releaseTree(tree -> lchild);
        releaseTree(tree -> rchild);
        delete tree;
    }
}

AVL :: ~AVL() {
    releaseTree(root);
}

int main() {

    AVL avl;
    
    int nodes[9] = {30,15,7,22,17,27,60,45,75};

    // int n;

    // cout << "Enter number of nodes : ";
    // cin >> n;

    for (int i = 0; i < 9; i++) {

        // cout << "Node " << i << " : ";
        
        // int temp;
        // cin >> temp;

        avl.insert(avl.getRoot(), nodes[i]);
    }

    avl.deleteNode(avl.getRoot(), 22);

    cout << "Height : " << avl.height(avl.getRoot()) << endl;
    cout << "Balance factor : " << avl.balanceFactor(avl.getRoot()) << endl;

    avl.preorder(avl.getRoot());
    cout << endl;

    avl.inorder(avl.getRoot());
    cout << endl;

    avl.postorder(avl.getRoot());
    cout << endl;

    return 0;
}