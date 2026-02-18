// Heap - Fila de prioridade

import java.util.*;

public class Heap {
    private int[] heap;
    private int tail;

    public Heap(int capacidade) {
        this.heap = new int[capacidade];
        this.tail = -1;
    }

    public boolean isEmpty() {
        return this.tail == -1;
    }

    // implementar métodos que retornem a esquerda, a direita e o pai de um nó, baseado no seu índice.
    //left. A esquerda de um nó no índice index sempre segue a fórmula 2 ∗ index + 1
    public int left(int posicao) {
        return 2 * posicao + 1;
    }

    // right. A direita de um nó no índice index sempre segue a fórmula 2 ∗ ( index + 1 )
    public int right(int posicao) {
        return 2 * (posicao + 1);
    }

    // parent. O pai de um nó no índice index sempre segue a fórmula Math.floorDiv(index−1,2)
    public int parent(int posicao) {
        return Math.floorDiv(posicao - 1, 2);
    }

    public void resize() {
        int[] novo = new int[heap.length * 2];

        for (int i = 0; i <= tail; i++) {
            novo[i] = heap[i];
        }

        heap = novo;
    }

    public void add(int n) {
        if (this.tail >= heap.length - 1)
            this.resize();
        
        this.tail++;
        this.heap[tail] = n;

        cheacapai(this.tail);
    }

    public void cheacapai(int index) {
        if (index == 0) return;

        if (this.heap[parent(index)] < this.heap[index]) {
            int aux = this.heap[parent(index)];
            this.heap[parent(index)] = this.heap[index];
            this.heap[index] = aux;
            cheacapai(parent(index));
        }

    }

    public int remove() {
        if (this.isEmpty())
            return -1;

        int retorno = this.heap[0];

        this.heap[0] = this.heap[this.tail];
        this.tail--;

        concertaHeap(0);

        return retorno;
    }

    public void concertaHeap(int index) {

        int l = left(index);
        int r = right(index);

        // checa se nao tem filhos a direita nem a esquerda.
        if (l > this.tail) return;


        // escolhe o maior filho
        int maior = l;
        if (r <= tail && heap[r] > heap[l]) {
            maior = r;
        }

        // se o pai já é maior, acabou
        if (heap[index] >= heap[maior]) return;

        // troca pai com o maior filho
        int aux = heap[index];
        heap[index] = heap[maior];
        heap[maior] = aux;

        // continua descendo
        concertaHeap(maior);
    }
}