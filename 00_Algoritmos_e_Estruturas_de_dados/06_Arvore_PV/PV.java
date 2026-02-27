class Node {
    int value;
    int color; //0 == P;  1 == V
    
    Node left;
    Node right;
    Node parent;

    public Node(int val) {
        this.value = val;
        this.color = 1;
    }

    public Node(int val, int color) {
        this.value = val;
        this.color = color;
    }

    public void preto() {
        this.color = 0;
    }

    public void vermelho() {
        this.color = 1;
    }
} 

public class PV{
    
    Node root;

    public void add(int i) {
        
        Node n = new Node(i);

        // Caso 1: root 
        if (root == null) {
            root = n;
            n.preto();
            return;
        }

        Node aux = root;

        // adiciona Node
        while (true) {
            if (i < aux.value) {
                if (aux.left == null) {
                    aux.left = n;
                    n.parent = aux;
                    break;
                }
                aux = aux.left;
            } else if (i > aux.value) {
                if (aux.right == null) {
                    aux.right = n;
                    n.parent = aux;
                    break;
                }
                aux = aux.right;
            } else {
                return; // valor duplicado
            }
        }

        Node pai = pai(n);
        Node avo = avo(n);
        Node tio = tio(n);
        
        // Caso 2
        if (pai.color == 0)
            return;

        // Caso 3 - tio e pai vermelho
        int corTio = (tio == null ? 0 : tio.color);

        if (corTio == 1) {
            caso3(n);
            return;
        }

        int vPai = pai.value;
        int vAvo = avo.value;
        int vtio = tio.value;

        boolean avoPaiDireita = vAvo < vPai;
        boolean avoPaiEsquerda = !avoPaiDireita;
        boolean paifilhoDireita = vPai < n.value;
        boolean paifilhoEsquerda = !paifilhoDireita;
        
        // Caso 4. zeg zag
        if (avoPaiDireita && paifilhoEsquerda) {
            rotacaoDireita(pai);
        }

        if (avoPaiEsquerda && paifilhoDireita) {
            rotacaoEsquerda(pai);
        }

        // Caso 5 - rotação de correção
        n = pai;
        pai = pai(n);
        avo = avo(n);
        
        pai.preto();
        avo.vermelho();

        if (n == pai.left) {
            rotacaoDireita(avo);
        } else {
            rotacaoEsquerda(avo);
        }

        root.preto();
    }

    public void rotacaoDireita(Node node) {

        // Seta o esquerda direita
        Node nodeEsquerda = node.left;

        node.left = nodeEsquerda.right;
        if (nodeEsquerda.right != null)
            nodeEsquerda.right.parent = node;

        // Seta pai do nodeEsquerda
        nodeEsquerda.parent = node.parent;

        if (node.parent == null) {
            root = nodeEsquerda;
        } else if(node == node.parent.left) {
            node.parent.left = nodeEsquerda;
        } else {
            node.parent.right = nodeEsquerda;
        }

        nodeEsquerda.right = node;
        node.parent = nodeEsquerda;

    }

    public void rotacaoEsquerda(Node node) {
    
        Node nodeDireita = node.right;

        node.right = nodeDireita.left;
        if (node.right != null) {
            node.right.parent = node;
        }

        nodeDireita.parent = node.parent;

        if (node.parent == null) {
            root = nodeDireita;
        } else if (node == node.parent.right) {
            node.parent.right = nodeDireita;
        } else {
            node.parent.left = nodeDireita;
        }

        node.parent = nodeDireita;
        nodeDireita.left = node;
    }

    public void caso3(Node n) {
        if (n == root || n.color == 0)
            return;
        
        Node pai = pai(n);
        Node avo = avo(n);
        Node tio = tio(n);

        if (pai.color == 1 && tio.color == 1) {
            pai.preto();
            tio.preto();
            avo.vermelho();
            caso3(avo);
        }
    }

    public int height(Node n) {
        if (n == null)
            return 0;

        int add = 0;
        if (n.color == 0) 
            add = 1;

        int esquerda = height(n.left);
        int direita = height(n.right);

        return add + Math.max(esquerda, direita);
    }

    public int verificaBlackHeight(Node n) {
        // NIL é preto
        if (n == null)
            return 1;

        int esquerda = verificaBlackHeight(n.left);
        int direita = verificaBlackHeight(n.right);

        // Se alguma subárvore já deu erro
        if (esquerda == -1 || direita == -1)
            return -1;

        // Se alturas pretas diferentes → viola propriedade
        if (esquerda != direita)
            return -1;

        int add;
        if (n.color == 0)
            add = 1;
        else
            add = 0;

        return esquerda + add;
    }

    public Node pai(Node n) {
        return n.parent;
    }

    public Node avo(Node n) {
        if (n.parent == null) {
            return null;
        }

        return pai(n.parent);
    }

    public Node tio(Node n) {
        Node avo = avo(n);
        if (avo == null)
            return null;

        if (n.parent == avo.left)
            return avo.right;
        else
            return avo.left;
    }

    public boolean isPV() {
        if (root == null) return true;
        if (root.color == 1) return false;

        return validHeight(root) && checkColors(root);
    }

    public boolean validHeight(Node n) {
        if (n == null) return true;
        if (blackHeight(n.left) != blackHeight(n.right)) return false;
        return validHeight(n.left) && validHeight(n.right);
    }

    public int blackHeight(Node n) {
        if (n == null) return 1;
        if (n.color == 1) return blackHeight(n.left);
        return 1 + blackHeight(n.left);
    }

    public boolean checkColors(Node n) {
        if (n == null) return true;
        
        boolean esquerdaNull = n.left == null;
        boolean direitaNull = n.right == null;
        
        if (esquerdaNull && direitaNull)
            return true;

        if (esquerdaNull)
            if (n.right.color == 1)
                return false;
        
        if (direitaNull)
            if (n.left.color == 1)
                return false;
        
        return checkColors(n.left) && checkColors(n.right);
    }
}