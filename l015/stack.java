public class stack {

    private int[] st;
    private int tos = -1;

    protected void resize(int size) {
        this.st = new int[size];
    }

    protected int maxSize() {
        return this.st.length;
    }

    public stack() {
        resize(10);
    }

    public stack(int size) {
        resize(size);
    }

    public stack(int[] arr) {
        resize(2 * arr.length);

        for (int i = 0; i < arr.length; i++) {
            this.st[i] = arr[i];
        }

        this.tos = arr.length - 1;
    }

    // APIs---------------------------------------------------------

    public int size() {
        return this.tos + 1;
    }

    public boolean isEmpty() {
        if (this.tos == -1)
            return true;
        return false;
    }

    public void push_(int val) {
        this.st[++this.tos] = val;
    }

    public void push(int val) {
        if (this.tos + 1 == this.st.length) {
            System.out.println("Stack Overflow");
        }

        push_(val);
    }

    public int top() {

        if (this.tos == -1) {
            System.out.println("Stack is empty");
            return -1;
        }

        return this.st[this.tos];

    }

    public int pop() {

        if (this.tos == -1) {
            System.out.println("Stack is empty");
            return -1;
        }

        return this.st[this.tos--];
    }
}