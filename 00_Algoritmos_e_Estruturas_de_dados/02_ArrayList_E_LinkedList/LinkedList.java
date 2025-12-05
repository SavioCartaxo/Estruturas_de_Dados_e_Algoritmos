// Referenicia do Estudo: https://joaoarthurbm.github.io/eda/posts/linkedlist/

class Node {
    
    String nome;
    Node next;
    Node prev;
    
    public Node(String nome) {
        this.nome = nome;
        this.prev = null;
        this.next = null;
    }   
}


public class LinkedList {
    
    private Node head;
    private Node tail;
    private int size;

    public LinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public boolean isEmpty() {
        return head == null;
    }
    
    // addLast(Aluno aluno)
    public void addLast(String s) {
        Node newNode = new Node(s);

        if (this.isEmpty()){
            this.head = newNode;
            this.tail = newNode;
            this .size += 1;
            return;
        } 

        newNode.prev = this.tail;
        this.tail.next = newNode;
        this.tail = newNode;
        this.size += 1;
    }
    
    // addFirst(Aluno aluno)
    public void addFirst(String s) {
        Node newNode = new Node(s);

        if (this.isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
            this.size += 1;
            return;
        } // eu não sou muito fã de else, então evito quando posso dentro de metodos

        this.head.prev = newNode;
        newNode.next = this.head;
        this.head = newNode;
        size += 1;
    }

    // add(int index, Aluno aluno)
    public void add(String s, int idx) {
        Node newNode = new Node(s);
        
        if (idx < 0 || idx >= this.size) {
            throw new IndexOutOfBoundsException();
        }

        if (idx == 0) {
            this.addFirst(s);
            return;
        } else if (idx == size - 1) {
            this.addLast(s);
            return;
        }

        Node aux = this.head;
        for (int i = 0; i < idx - 1; i++) {
            aux = aux.next;
        }

        newNode.next = aux.next;
        newNode.prev = aux.prev;

        aux.prev.next = newNode;
        aux.prev = newNode;

        size += 1;
    }
     
    public String get(int index) {
        if (index < 0 || index >= this.size) {
            throw new RuntimeException("deu ruim");
        }

        Node aux = this.head;
        for (int i = 0; i < this.size - 1; i++) {
            if (i == index) return aux.nome;
            aux = aux.next;
        }
        return null;
    }

    public int indexOf(String s) {
        Node aux = this.head;
        for (int i = 0; i < this.size - 1; i++) {
            if (aux.nome.equals(s)) return i;
            aux = aux.next;
        }
        return -1;
    }

    public boolean contains(String s) {
        return indexOf(s) != -1;
    }
}