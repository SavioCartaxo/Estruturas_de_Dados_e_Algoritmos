class Node {
    int value;
    Node parent;
    Node left;
    Node right;

    public Node(int value) {
        this.value = value;
    }
}

class BST {
    Node root;

    public BST() {}

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
                    newNode.parent = aux;
                    return;
                }
                aux = aux.left;
            } else {
                if (aux.right == null) {
                    Node newNode = new Node(value);
                    aux.right = newNode;
                    newNode.parent = aux;
                    return;
                }
                aux = aux.right;
            }
        }
    }

    public boolean isEmpty() {
        return this.root == null;
    }

    public Node max(Node node){
        if (this.isEmpty()) throw new IllegalArgumentException("Arvore vazia");

        Node aux = node;

        while (aux.right != null) {
            aux = aux.right;
        }

        return aux;
    }

    public Node min(Node node) {
        if (this.isEmpty()) throw new IllegalArgumentException("Arvore vazia");

        Node aux = node;

        while (aux.left != null) {
            aux = aux.left;
        }

        return aux;
    }

    public Node sucessor(Node node) {
        if (this.isEmpty()) throw new IllegalArgumentException("Arvore vazia");

        if (node.right != null) {
            return min(node.right);
        }

        int valorNode = node.value;
        Node aux = node;

        while (aux.parent != null) { // Enquanto o aux for diferente da raiz
            aux = aux.parent;
            if (aux.value > valorNode) {
                return aux;
            }
        }

        throw new IllegalArgumentException("Não possui sucessor");
    }

    public Node antecessor(Node node) {
        if (this.isEmpty()) throw new IllegalArgumentException("Arvore vazia");

        if (node.left != null) {
            return max(node.left);
        }

        int valorNode = node.value;
        Node aux = node;

        while (aux.parent != null) { // Enquanto o aux for diferente da raiz
            aux = aux.parent;
            if (aux.value < valorNode) {
                return aux;
            }
        }

        throw new IllegalArgumentException("Não possui antecessor");
    }

    public int altura(Node node) {
        if (node == null) {
            return 0;
        }

        int left = 1 + altura(node.left);
        int right = 1 + altura(node.right);

        return Math.max(left, right);
    }

    public void remove(int value) {
        if (this.isEmpty()) return;

        Node aux = this.root;

        while (aux != null) {

            if (aux.value == value) {
                remove(aux);
                return;
            }

            if (value < aux.value) {
                aux = aux.left;
            } else if (value > aux.value) {
                aux = aux.right;
            }
        }
    }

    public void remove(Node node) {

        // node removido é uma folha
        if (node.left == node.right && node.left == null) {
            
            // node removido é a raiz
            if (node == this.root) {
                this.root = null;
                return;
            }
            
            Node pai = node.parent;
            int pai_valor = pai.value;
            
            // nó é left em relação ao pai
            if (node.value < pai_valor) {
                pai.left = null;
                return;
            }
            
            // nó é right em relação ao pai
            pai.right = null;
            return;
        }

        // Se tem apenas filho ao lado direito
        if (node.left == null) {

            // node removido é a raiz
            if (node == this.root) {
                this.root = node.right;
                this.root.parent = null;
                return;
            }
            
            Node filho = node.right;
            Node pai = node.parent;

            if (pai.right == node) {
                pai.right = filho;
            } else {
                pai.left = filho;
            }

            filho.parent = pai;
            return;
        }

        // Se tem apenas filho ao lado esquerdo
        if (node.right == null) {

            // node removido é a raiz
            if (node == this.root) {
                this.root = node.left;
                node.left.parent = null;
                return;
            }
            
            Node filho = node.left;
            Node pai = node.parent;

            if (pai.right == node) {
                pai.right = filho;
            } else {
                pai.left = filho;
            }

            filho.parent = pai;

            return;
        }

        // Nó tem 2 filhos
        // oq fazer? troca o nó com seu sucessor e passa recursivamente o remove
        Node sucessor = sucessor(node);
        node.value = sucessor.value;
        remove(sucessor);
    }

    public void preOrdem(){
        preOrdem(this.root);
    }

    public void preOrdem(Node node) {
        if (node != null) {
            System.out.println(node.value);
            preOrdem(node.left);
            preOrdem(node.right);
        }
    }

    public void posOrdem(){
        posOrdem(this.root);
    }

    public void posOrdem(Node node) {
        if (node != null) {
            posOrdem(node.left);
            posOrdem(node.right);
            System.out.println(node.value);
        }
    }

    public void inOrdem(){
        inOrdem(this.root);
    }

    public void inOrdem(Node node) {
        if (node != null) {
            inOrdem(node.left);
            System.out.println(node.value);
            inOrdem(node.right);
        }
    }

    public int size(Node node) {
        if (node == null) return 0;

        return 1 + size(node.left) + size(node.right);
    }
}

public class Main{
    public static void main(String[] args) {
        BST bst = new BST();
        bst.add(100);
        bst.add(90);
        bst.add(32);
        bst.add(157);
        bst.add(12);
        bst.add(53);
        bst.add(89);

        bst.remove(12);

        bst.inOrdem();
    }
}