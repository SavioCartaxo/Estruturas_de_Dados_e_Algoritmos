class Node {
    int height;
    int value;

    Node left;
    Node right;
    Node parent;

    public Node(int v) {
        this.value = v;
    }

    public int height() {
        if (this.left == null && this.right == null)
            return 0;
        if (this.left == null)
            return 1 + this.right.height();
        if (this.right == null)
            return 1 + this.left.height();
        return 1 + Math.max(this.left.height(), this.right.height());
    }

    public int balanced() {
        int l, r;

        if (this.left == null) 
            l = -1;
        else
            l = this.left.height();
        
        
        if (this.right == null)
            r = -1;
        else
            r = this.right.height();

        return l - r;
    }

    public boolean isLeftPending() {
        return this.balanced() == 1;
    }

    public boolean isRightPending() {
        return this.balanced() == -1;
    }

    public boolean isBalanced() {
        return Math.abs(this.balanced()) <= 1;
    }
}

public class AVL {
    
    Node root;

    public int height(Node node) {
        if (node == null) return -1;

        return 1 + Math.max(height(node.left), height(node.right));
    }

    public void rotateRight(Node x) {
        
        Node y = x.left;
        Node t3 = y.right;

        y.right = x;
        x.left = t3;

        if (t3 != null) {
            t3.parent = x;
        }

        y.parent = x.parent;
        x.parent = y;

        if (y.parent == null) {
            root = y;
            y.parent = null;
        } else {
            if (y.parent.left == x) {
                y.parent.left = y;
            } else {
                y.parent.right = y;
            }
        }

        x.height = x.height();
        y.height = y.height();
    }

    public void rotateLeft(Node x) {
        Node y = x.right;
        Node t3 = y.left;

        y.left = x;
        x.right = t3;

        if (t3 != null) {
            t3.parent = x;
        }

        y.parent = x.parent;
        x.parent = y;

        if (y.parent == null) {
            root = y;
        } else {
            if (y.parent.left == x) {
                y.parent.left = y;
            } else {
                y.parent.right = y;
            }
        }

        x.height = x.height();
        y.height = y.height();
    }

    // A árvore está balanceada?
    public int balance(Node node) {
        int l;
        int r;
        
        if (node.left == null)
            l = -1;
        else 
            l = height(node.left);
        
        if (node.right == null)
            r = -1;
        else
            r = height(node.right);

        return l - r;
    }
}
