import java.util.PriorityQueue;

public class lecture016 {

    // PROGRAM 1
    // TO FIND Kth LARGEST ELEMENT IN AN ARRAY
    int kthLargest(int[] arr) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int size = 0;

        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);

            if (pq.size() > k) {
                pq.poll();
            }
        }

        return pq.peek();
    }

    // PROGRAM 2
    // TO FIND Kth LARGEST ELEMENT IN A SORTED MATRIX
    public static class Pair {
        int ele, i, j;

        Pair(int ele, int i, int j) {
            this.ele = ele;
            this.i = i;
            this.j = j;
        }
    }

    public static int kth_smallest(int[][] arr, int k) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((Pair a, Pair b) -> {
            return a.ele - b.ele;
        }); // makes min heap

        int n = arr.length;
        int m = arr[0].length;

        for (int i = 0; i < n; i++) {
            pq.add(new Pair(arr[i][0], i, 0));
        }

        while (--k > 0) {
            Pair p = pq.poll();
            int x = p.i;
            int y = p.j;

            if (++y < m)
                pq.add(new Pair(arr[x][y], x, y));
        }

        return pq.poll().ele;
    }

    // PROGRAM 3
    // K MOST FREQUENT ELEMENTS IN AN ARRAY REFER LEETOCDE 347
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int ele : nums)
            map.put(ele, map.getOrDefault(ele, 0) + 1);

        // first -> freq, second -> number and by default it is min PQ.
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[0] - b[0];
        });

        for (Integer key : map.keySet()) {
            pq.add(new int[2] { map.get(key), key });
            if (pq.size() > k)
                pq.remove();
        }

        int[] ans = new int[pq.size()];
        int i = 0;
        while (pq.size() != 0) {
            int[] ar = pq.remove();
            ans[i++] = ar[1];
        }

        return ans;
    }

    // PROGRAM 4
    // SWIM IN RISING WATER LEETCODE BFS DIJKSTRA
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int ans = Math.max(grid[0][0], grid[n - 1][n - 1]);

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> { // r,c,h
            return a[2] - b[2];
        });

        boolean[][] vis = new boolean[n][n];
        vis[0][0] = true;

        int[][] dir = { { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 } };
        pq.add(new int[] { 0, 0, grid[0][0] });

        while (pq.size() != 0) {
            int[] vtx = pq.poll();
            ans = Math.max(ans, vtx[2]);

            for (int d = 0; d < 4; d++) {
                int x = vtx[0] + dir[d][0];
                int y = vtx[1] + dir[d][1];

                if (x >= 0 && y >= 0 && x < n && y < n && !vis[x][y]) {
                    if (x == n - 1 && y == n - 1)
                        return ans;
                    pq.add(new int[] { x, y, grid[x][y] });
                    vis[x][y] = true;
                }
            }
        }

        return -1;
    }

    // MAIN
    public static void main(String[] args) {
        int[][] arr = { { 10, 30, 70, 100 }, { 11, 105, 130, 170 }, { 123, 136, 153, 200 } };

        System.out.println(kth_smallest(arr, 5));
    }
}