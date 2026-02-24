class Node {
    int value;
    Node left;
    Node right;
    Node Parent;

    public Node(int value) {
        this.value = value;
        this.left = null;
        this.right = null;
        this.Parent = null;
    }
}

class Bst {
    Node root;

    public boolean isEmpty() {
        return this.root == null;
    }

    // Existe o add recursivo, tenho que estudar ele
    public void add(int value) {
        if (this.isEmpty()) {
            this.root = new Node(value);
            return;
        }

        Node aux = this.root;
        while (aux != null) {
            
            if (value < aux.value) {
                if (aux.left == null) {
                    Node newNode = new Node(value);
                    aux.left = newNode;
                    newNode.Parent = aux;
                    return;
                }

                aux = aux.left;
            } else {
                if (aux.right == null) {
                    Node newNode = new Node(value);
                    aux.right = newNode;
                    newNode.Parent = aux;
                    return;
                }

                aux = aux.right;
            }
        }
    }

    public Node search(int value) {

        Node node = this.root;
        
        while (node != null) {
            
            if (node.value == value) return node;
            else if (value < node.value) node = node.left;
            else if (value > node.value) node = node.right;
        
        }

        return null;
    }

    public Node min() {
        if (isEmpty()) return null;
        return min(this.root);
    }
        
    private Node min(Node node) {
        if (node.left == null) return node;
        else return min(node.left);
    }

    public Node max() {
        if (isEmpty()) return null;
            
        Node node = this.root;
        while(node.right != null)
            node = node.right;      

        return node;
    }

    // como pega sucessor e predecessor?

    public int height() {
        return height(this.root);
    }
    
    private int height(Node node) {
        if(node == null) return -1;
        else return 1 + Math.max(height(node.left), height(node.right));
    }

    // e pra remover? como faz?


    // printando em pre, pos e ordem?
}