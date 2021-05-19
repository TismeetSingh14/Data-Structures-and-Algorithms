

public class hashmap<K, V> {
    public class Node {
        K key;
        V value;

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public String toString() {
            return this.key + "=" + this.value;
        }
    }

    private int size = 0;
    private LinkedList<Node>[] buckets = new LinkedList[10];

    public hashmap() {
        reassign();
    }

    private void reassign() {
        for (Integer i = 0; i < buckets.length; i++) {
            buckets[i] = new LinkedList<>();
        }
        this.size = 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("{");

        for (int i = 0; i < buckets.length; i++) {
            if (buckets[i].size() > 0) {
                int size = buckets[i].size();
                LinkedList<Node> list = buckets[i];
                while (size-- > 0) {
                    Node ele = list.getFirst();
                    sb.append(ele.toString() + ",");
                    list.addLast(list.removeFirst());
                }
            }
        }

        sb.deleteCharAt(sb.length() - 1);
        sb.append("}");

        return sb.toString();
    }

    public void put(K key, V value) {
        int code = mybucket(key);
        LinkedList<Node> group = buckets[code];
        Node rn = found_in_group(group, key);

        if (group == null) {
            buckets[code] = new LinkedList<>();
        }

        if (rn != null) {
            rn.value = value;
            this.size++;
        }

        else {
            Node node = new Node(key, value);
            group.addFirst(node);
            this.size++;
        }

        double lambda = group.size() * 1.0 / buckets.length;

        if (lambda >= 0.2) {
            System.out.println("rehash " + group.size());
            rehash();
        }
    }

    public void rehash() {
        LinkedList<Node>[] old = buckets;
        buckets = new LinkedList[buckets.length * 2];

        reassign();

        for (int i = 0; i < old.length; i++) {
            if (old[i].size() > 0) {
                int size = old[i].size();
                LinkedList<Node> group = old[i];
                while (size-- > 0) {
                    Node ele = group.removeFirst();
                    put(ele.key, ele.value);
                }
            }
        }
    }

    public V get(K key) {
        int code = mybucket(key);
        LinkedList<Node> group = buckets[code];
        Node rn = found_in_group(group, key);
        return rn == null ? null : rn.value;
    }

    public Node remove(K key) {
        int code = mybucket(key);
        LinkedList<Node> group = buckets[code];
        Node rn = found_in_group(group, key);

        if (rn != null) {
            this.size--;
            return group.removeFirst();
        }

        else
            System.out.println("element not found");

        return null;
    }

    public ArrayList<K> keyset() {
        ArrayList<K> ans = new ArrayList<>();

        for (int i = 0; i < buckets.length; i++) {
            if (buckets[i].size() > 0) {
                LinkedList<Node> group = buckets[i];
                int size = buckets[i].size();

                while (size-- > 0) {
                    Node ele = group.getFirst();
                    ans.add(ele.key);
                    group.addLast(group.removeFirst());
                }
            }
        }

        return ans;
    }

    public V getORdefault(K key, V def) {
        int code = mybucket(key);
        LinkedList<Node> group = buckets[code];
        Node rn = found_in_group(group, key);
        return rn == null ? def : rn.value;
    }

    public int size() {
        return this.size;
    }

    public boolean containskey(K key) {
        int code = mybucket(key);
        LinkedList<Node> group = buckets[code];
        Node rn = found_in_group(group, key);
        return rn == null ? false : true;
    }

    private Node found_in_group(LinkedList<Node> group, K key) {
        Node rn = null;
        int size = group.size();

        while (size-- > 0) {
            Node temp = group.getFirst();
            if (temp.key == key) {
                rn = temp;
                break;
            }

            group.addLast(group.removeFirst());
        }

        return rn;
    }

    public int myhashcode(K key) {
        Integer val = key.hashCode();
        return Math.abs(val);
    }

    public int mybucket(K key) {
        return myhashcode(key) % buckets.length;
    }
}