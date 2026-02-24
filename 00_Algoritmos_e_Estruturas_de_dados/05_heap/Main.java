class Heap {
    int[] heap;
    int tail;

    public Heap() {
        this.heap = new int[10];
        this.tail = -1;
    }

    public Heap(int q) {
        this.heap = new int[q];
        this.tail = -1;
    }

    public boolean isEmpty() {
        return this.tail == -1;
    }

    public boolean isFull() {
        return this.tail >= this.heap.length - 1;
    }

    public int left(int index) {
        return 2 * index + 1;
    }

    public int right(int index) {
        return 2 * (index + 1);
    }

    public int parent(int index) {
        return Math.floorDiv(index - 1, 2);
    }

    public void resize() {
        int[] aux = new int[heap.length * 2];

        for (int i = 0; i <= this.tail; i++) {
            aux[i] = this.heap[i];
        }

        this.heap = aux;
    }

    public void add(int index) {
        if (this.isFull()) this.resize();
        
        this.tail++;
        this.heap[tail] = index;
        heapify(tail);
    }

    public void heapify(int index) {
        if (index == 0) return;

        if (heap[parent(index)] >= heap[index])
            return;

        int aux = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = aux;

        heapify(parent(index));
    }

    public int remove() {
        if (this.isEmpty()) return -1;

        int aux = heap[0];
        heap[0] = heap[tail];
        tail--;

        heapifyreverse(0);
        return aux;
    }

    public void heapifyreverse(int index) {

        int index_l = left(index);
        int index_r = right(index);

        if (index_l > this.tail) return;

        int maior = index_l;
        if (index_r <= tail && heap[index_r] > heap[index_l]) {
            maior = index_r;
        }

        if (heap[index] >= heap[maior]) return;

        int aux = heap[index];
        heap[index] = heap[maior];
        heap[maior] = aux;

        heapifyreverse(maior);
    }

}

public class Main {
    public static void main(String[] args) {
        Heap heap = new Heap();

        heap.add(10);
        heap.add(100);
        heap.add(12);
        heap.add(22);
        heap.add(15);

        System.out.println(heap.remove());
        System.out.println(heap.remove());
        System.out.println(heap.remove());
        System.out.println(heap.remove());
        System.out.println(heap.remove());
    }
}