import java.util.NoSuchElementException;

class linkedlist<K> {
    private class Node {
        K data = null;
        Node next = null;

        Node(K data) {
            this.data = data;
        }

        @Override
        public String toString() {
            return this.data + "";
        }
    }

    private Node head = null;
    private Node tail = null;
    private int nodecount = 0;

    @Override
    public String toString() {
        Node curr = this.head;
        StringBuilder sb = new StringBuilder();

        sb.append("[");
        while (curr.next != null) {
            sb.append(curr.data + ", ");
            curr = curr.next;
        }
        if (curr != null)
            sb.append(curr.data);
        sb.append("]");

        return sb.toString();
    }

    // ======================================================

    public int size() {
        return this.nodecount;
    }

    public boolean isempty() {
        return this.nodecount == 0;
    }

    public Node getnodeat(int idx) {
        if (idx < 0 || idx >= this.nodecount) {
            throw new NullPointerException();
        }

        Node curr = this.head;
        while (idx-- > 0) {
            curr = curr.next;
        }

        return curr;
    }

    // ==================================================

    private void addfirstnode(Node node) {
        if (this.nodecount == 0) {
            this.tail = node;
        }

        node.next = this.head;
        this.head = node;
        this.nodecount++;
    }

    public void addfirst(K data) {
        Node node = new Node(data);
        addfirstnode(node);
    }

    private void addlastnode(Node node) {
        if (this.nodecount == 0) {
            this.head = node;
            this.tail = node;
        }

        else {
            this.tail.next = node;
            this.tail = node;
        }

        this.nodecount++;
    }

    public void addlast(K data) {
        Node node = new Node(data);
        addlastnode(node);
    }

    private void addatnode(Node node, int idx) {
        if (idx == 0)
            addfirstnode(node);

        else if (idx == this.nodecount)
            addlastnode(node);

        else {
            Node prev = getnodeat(idx - 1);
            Node forw = prev.next;
            prev.next = node;
            node.next = forw;
        }
    }

    public void addat(K data, int idx) {
        if (idx < 0 || idx > this.nodecount)
            throw new NullPointerException();

        Node node = new Node(data);
        addatnode(node, idx);
        this.nodecount++;
    }

    // ====================================================

    public K getfirst() {
        if (this.nodecount == 0)
            throw new NoSuchElementException();

        return this.head.data;
    }

    public K getlast() {
        if (this.nodecount == 0)
            throw new NoSuchElementException();

        return this.tail.data;
    }

    public K getat(int idx) {
        return getnodeat(idx).data;
    }

    // ===================================================

    private Node removefirstnode() {
        Node rn = this.head;

        if (this.nodecount == 1) {
            this.head = null;
            this.tail = null;
        }

        else {
            this.head = this.head.next;
        }

        rn.next = null;
        this.nodecount--;
        return rn;
    }

    public K removefirst() {
        if (this.nodecount == 0)
            throw new NoSuchElementException();

        return removefirstnode().data;
    }

    private Node removelastnode() {
        Node rn = this.head;

        if (this.nodecount == 1) {
            this.head = null;
            this.tail = null;
        }

        else {
            Node secondlast = getnodeat(this.nodecount - 2);
            this.tail = secondlast;
            tail.next = null;
        }

        rn.next = null;
        this.nodecount--;
        return rn;
    }

    public K removelast() {
        if (this.nodecount == 0)
            throw new NoSuchElementException();

        return removelastnode().data;
    }

    private Node removeatnode(int idx) {
        if (idx == 0)
            removefirstnode();

        if (idx == this.nodecount - 1)
            removelastnode();

        Node prev = getnodeat(idx - 1);
        Node forw = prev.next.next;
        Node rn = prev.next;
        prev.next = forw;
        rn.next = null;
        return rn;
    }

    public K removeat(int idx) {
        if (idx < 0 || idx >= this.nodecount)
            throw new NullPointerException();

        this.nodecount--;
        return removeatnode(idx).data;
    }
}