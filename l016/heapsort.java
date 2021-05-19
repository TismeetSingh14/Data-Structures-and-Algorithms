public class heapsort {
    public static void swap(int[] arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    public static int compare_to(int[] arr, int chd, int par, boolean ismax) {
        if (ismax) {
            return arr[chd] - arr[par];
        }

        else {
            return arr[par] - arr[chd];
        }
    }

    public static void down_heapify(int[] arr, int idx, int lidx) {
        int max_idx = idx;
        int lci = 2 * idx + 1;
        int rci = 2 * idx + 2;

        if (lci < lidx && compare_to(arr, lci, max_idx, true) > 0) {
            max_idx = lci;
        }

        if (rci < lidx && compare_to(arr, rci, max_idx, true) > 0) {
            max_idx = rci;
        }

        if (max_idx != idx) {
            swap(arr, max_idx, idx);
            down_heapify(arr, max_idx, lidx);
        }
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 30, -2, -3, -4, 5, 7, 8, 9, 22, 11, 13 };

        for (int i = arr.length - 1; i >= 0; i--) {
            down_heapify(arr, i, arr.length - 1);
        }

        for (int i = 0; i < arr.length; i++) {
            for (int k = 0; k < arr.length; k++) {
                System.out.print(arr[k] + " ");
            }
            System.out.println();
            swap(arr, 0, arr.length - i - 1);
            down_heapify(arr, 0, arr.length - i - 1);
        }

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}