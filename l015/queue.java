public class queue {
    protected int[] que;
    protected int size = 0;
    protected int front = 0;
    protected int last = 0;

    protected void resize(int size) {
        this.que = new int[size];
    }

    protected int maxSize() {
        return this.que.length;
    }

    public queue() {
        resize(10);
    }

    public queue(int size) {
        resize(size);
    }

    public queue(int[] arr) {
        resize(2*arr.length);

        for(int i=0;i<arr.length;i++) {
            que[i] = arr[i];
        }

        this.front = 0;
        this.last = arr.length - 1;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append("[ ");

        for (int i = 0; i < this.size; i++) {
            sb.append(this.que[(this.front + i) % this.que.length] + ", ");
        }

        sb.deleteCharAt(sb.length() - 1);
        sb.deleteCharAt(sb.length() - 1);
        sb.append("]");

        return sb.toString();
    }

    // APIs---------------------------------------------------------

    public int size() {
        return this.size;
    }

    public boolean isEmpty() {
        if (this.size == 0)
            return true;
        return false;
    }

    protected void push_(int val) {
        this.que[this.last] = val;
        this.last = (this.last + 1) % this.que.length;
        this.size++;
    }

    public void push(int val) throws Exception {
        if (this.size == this.que.length) {
            throw new Exception("Queue Overflow");
        }

        push_(val);
    }

    protected int pop__() {
        int rv = this.que[this.front];
        this.que[this.front] = 0;
        this.front = (this.front + 1) % this.que.length;
        this.size--;
        return rv;
    }

    protected int pop_() throws Exception {
        if (this.size == 0) {
            throw new Exception("Queue is empty");
        }

        return pop__();
    }

    public int pop() throws Exception {
        int rv = -1;

        try {
            rv = pop_();
        }

        catch (Exception e) {
            System.out.println("END");
        }

        return rv;
    }

    public int front() throws Exception {
        if (this.size == 0) {
            throw new Exception("Queue is empty");
        }

        return this.que[this.front];
    }
}