import java.util.HashMap;

public class lecture020 {

    public class ListNode {
        int val;
        ListNode next = null;

        Node(int x) {
            this.val = x;
        }
    }

    // PROGRAM 1
    // TO FIND THE MIDDLE NODE OF THE LINKED LIST
    public static ListNode midNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    public static ListNode midNode_(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    // PROGRAM 2
    // TO REVERSE A GIVEN LINKED LIST
    public static ListNode reverseList(ListNode node) {

        ListNode prev = null;
        ListNode curr = node;
        while (curr != null) {
            ListNode forw = curr.next;
            curr.next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }

    // PROGRAM 3
    // TO CHECK WHETHER THE GIVEN LIST IS A PALINDROME OR NOT
    public static boolean checkPalindromeList(ListNode head) {

        if (head == null || head.next == null)
            return true;

        ListNode mid = midNode(head);
        ListNode reverseHead = reverseList(mid);

        while (reverseHead != null) {
            if (head.val != reverseHead.val)
                return false;

            head = head.next;
            reverseHead = reverseHead.next;
        }

        return true;
    }

    // PROGRAM 4
    // TO FOLD A LIST OR REORDER A LIST
    public static void reorderList(ListNode head) {

        if (head == null || head.next == null || head.next.next == null)
            return;

        ListNode mid = midNode_(head);
        ListNode reverseHead = mid.next;
        reverseHead = reverseList(reverseHead);
        mid.next = null;

        while (head != null && reverseHead != null) {
            ListNode temp1 = head.next;
            ListNode temp2 = reverseHead.next;

            head.next = reverseHead;
            reverseHead.next = temp1;

            head = temp1;
            reverseHead = temp2;
        }
    }

    // PROGRAM 5
    // TO CHECK WHETHER THE GIVEN LIST CONTAINS A CYCLE OR NOT
    public static boolean hasCycle(ListNode head) {
        if (head == null || head.next == null)
            return false;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (fast == slow)
                return true;
        }

        return false;
    }

    // PROGRAM 6
    // TO FIND THE NODE IN LIST WHICH CREATES A CYCLE
    public static ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (fast == slow)
                break;
        }

        if (fast != slow)
            return null;

        slow = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }

        return slow;
    }

    // PROGRAM 7
    // TO FIND THE INTERSECTION NODE OF TWO LINKED LISTS
    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;
        ListNode curr = headB;
        while (curr.next != null)
            curr = curr.next;

        curr.next = headA;
        ListNode cycle = detectCycle(headB);
        curr.next = null;
        return cycle;
    }

    // PROGRAM 8
    // TO ROTATE A LIST K TO THE RIGHT
    public static ListNode rotateRight(ListNode head, int k) {

        if (head == null || head.next == null || k == 0)
            return head;

        int size = 0;
        ListNode curr = head;
        ListNode tail = null;
        while (curr != null) {
            tail = curr;
            curr = curr.next;
            size++;
        }

        k %= size;
        if (k < 0)
            k += size;

        curr = head;
        int count = 1;
        int n = size - k;

        while (count < n) {
            curr = curr.next;
            count++;
        }

        tail.next = head;
        head = curr.next;
        curr.next = null;

        return head;
    }

    // PROGRAM 9
    // TO MERGE TWO SORTED LISTS
    public static ListNode mergeTwoLists(ListNode A, ListNode B) {
        if (A == null)
            return B;
        else if (B == null)
            return A;

        ListNode head = new ListNode(-1);
        ListNode curr = head;

        while (A != null && B != null) {

            if (A.val <= B.val) {
                curr.next = A;
                curr = A;
                A = A.next;
            }

            else {
                curr.next = B;
                curr = B;
                B = B.next;
            }
        }
        if (A != null)
            curr.next = A;
        else if (B != null)
            curr.next = B;

        return head.next;
    }

    // PROGRAM 10
    // TO SORT THE LIST USING MERGE SORT
    public ListNode sortList(ListNode head) {

        if (head == null || head.next == null)
            return head;

        ListNode mid = midNode_(head);
        ListNode nhead = mid.next;
        mid.next = null;

        return mergeTwoLists(sortList(head), sortList(nhead));
    }

    // PROGRAM 11
    // TO MERGE K SORTED LISTS
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0)
            return null;
        return mergeKLists_(lists, 0, lists.length - 1);
    }

    public ListNode mergeKLists_(ListNode[] lists, int si, int ei) {
        if (si == ei)
            return lists[si];
        if (si + 1 == ei)
            return mergeTwoLists(lists[si], lists[ei]);

        int mid = (si + ei) >> 1; // (si+ei)/2;
        ListNode left = mergeKLists_(lists, si, mid);
        ListNode right = mergeKLists_(lists, mid + 1, ei);

        return mergeTwoLists(left, right);
    }

    //TO COPY LIST WITH RANDOM POINTERS
    public static ListNode copyListRandomPointer(ListNode head) {

        // first we try to make new nodes and link them to each other
        ListNode curr = head, forw = null;
        
        while(curr != null) {
            forw = curr.next;

            ListNode copyNode = new ListNode(curr.val);
            curr.next = copyNode;
            copyNode.next = forw;

            curr = forw;
        }

        // second set the random pointers
        curr = head;
        while(curr != null) {
            if(curr.random != null)
                curr.next.random = curr.random.next;
            curr = curr.next.next;    
        }

        // third extract the copy list
        curr = head;
        ListNode newList = new ListNode(-1);
        ListNode newCurr = newList;
        ListNode copyNode = null;

        while(curr != null) {
            forw = curr.next.next;
            copyNode = curr.next;
            newCurr.next = copyNode;
            curr.next = forw;
            curr = forw;
            newCurr = copyNode;
        }

        return newList.next;
    }

    //TO REMOVE NTH ELEMENT FROM THE END OF THE LIST
    public static ListNode removeNthFromEnd(ListNode head, int n) {

        if(n == 0 || head == null) return null;
        if(n == 1 && head.next == null) return null;

        ListNode slow = head, fast = head;

        while(n-->0) {
            fast = fast.next;
        }

        if(fast == null) return head.next;

        while(fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        ListNode temp = slow.next;
        slow.next = slow.next.next;
        temp.next = null;
        return head;
    }

    //TO DIVIDE A LIST ON THE BASIS OF THEIR INDEX(ODD EVEN)
    public static ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null) return head;

        ListNode odd = new ListNode(-1);
        ListNode oitr = odd;

        ListNode even = new ListNode(-1);
        ListNode eitr = even;

        while(head != null) {
            oitr.next = head;
            eitr.next = head.next;

            oitr = oitr.next;
            eitr = eitr.next;

            head = head.next;

            if(head.next != null) 
                head = head.next;
            else
                break;    
        }

        oitr.next = even.next;
        return oitr.next;
    }

    //TO DIVIDE A LIST ON THE BASIS OF THEIR VALUE(ODD EVEN)
    public static ListNode oddEvenListByValue(ListNode head) {
        if(head == null || head.next == null) return head;

        ListNode odd = new ListNode(-1);
        ListNode oitr = odd;

        ListNode even = new ListNode(-1);
        ListNode eitr = even;

        while(head != null) {

            if(head.val%2==0) {
                eitr.next=head;
                eitr=eitr.next;
            }

            else {
                oitr.next=head;
                oitr=oitr.next;
            }

            head = head.next;
        }

        eitr.next = null;
        oitr.next = even.next;
        return oitr.next;
    }

    //LRU CACHE
    public class LRUCache {
        private int capacity;
        private HashMap<Integer,Integer> cache;
        private LinkedList<Integer> ll;

        public LRUCache(int capacity) {
            this.capacity = capacity;
            this.cache = new HashMap<>();
            this.ll = new LinkedList<>();
        }

        void set(int key, int value) {
            
            if(cache.containsKey(key)) {
                ll.remove(key);
                ll.addFirst(key);
                cache.put(key,value);
            }

            else {
                if(ll.size() == capacity) {
                    int temp = ll.removeLast();
                    cache.remove(temp);
                }

                ll.addFirst(key);
                cache.put(key,value);
            }
        }

        int get(int key) {

            if(!cache.containsKey(key))
                return -1;

            else {
                ll.remove(key);
                ll.addFirst(key);
                return cache.get(key);
            }    
        }
    }

    public static void main(String[] args) {

    }
}