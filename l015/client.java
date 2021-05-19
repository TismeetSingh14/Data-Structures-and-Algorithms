public class client {

    // IMPLEMENTATION OF STACK
    public static void stackImplementation() {

        stack st = new stack(6);

        for (int i = 0; i < 6; i++) {
            st.push(i * 10);
        }

        while (!st.isEmpty()) {
            System.out.println(st.pop());
        }
    }

    // IMPLEMENTATION OF DYNAMIC STACK
    public static void dynamicStackImplementation() {
        dynamicStack dst = new dynamicStack(6);

        for (int i = 0; i < 8; i++) {
            dst.push(i * 10);
        }

        while (!dst.isEmpty()) {
            System.out.println(dst.pop());
        }
    }

    // IMPLEMENTATION OF QUEUE
    public static void queueImplementation() throws Exception {
        queue que = new queue(15);

        for (int i = 0; i < 15; i++) {
            que.push(i + 1);
        }

        // que.push(100);

        System.out.println(que);
    }

    // IMPLEMENTATION OF DYNAMIC QUEUE
    public static void dynamicQueueImplementation() throws Exception {
        dynamicQueue dyque = new dynamicQueue(10);

        for (int i = 0; i <= 10; i++) {
            dyque.push(i * 10);
        }

        dyque.push(100);

        System.out.println(dyque);
    }

    // MAIN
    public static void main(String[] args) throws Exception {
        // stackImplementation();
        // dynamicStackImplementation();
        // queueImplementation();
        // dynamicQueueImplementation();
    }
}