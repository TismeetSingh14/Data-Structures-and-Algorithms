import java.util.HashMap;
import java.util.ArrayList;

public class lecture018 {

    // PROGRAM 1
    // MAP BASICS
    public static void mapBasics() {
        HashMap<String, Integer> m = new HashMap<>();

        m.put("IND", 100);
        m.put("USA", 80);
        m.put("ENG", 70);
        m.put("SPN", 50);

        System.out.println(m);

        for (String s : m.keySet()) {
            System.out.println(m.get(s));
        }
    }

    // PROGRAM 2
    // TO RETURN THE FREQUENCY OF ALL THE CHARACTERS IN A STRING
    public static void indexOfCharacters(String s) {
        HashMap<Character, ArrayList<Integer>> hm = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (!hm.containsKey(s.charAt(i)))
                hm.put(s.charAt(i), new ArrayList<Integer>());
            hm.get(s.charAt(i)).add(i);
        }

        for (Character ch : hm.keySet())
            System.out.println(ch + " -> " + hm.get(ch));
    }

    // PROGRAM 3
    // TO RETURN THE FREQUENCY OF ALL THE CHARACTERS IN A STRING
    public static void frequencyOfCharacters(String s) {
        HashMap<Character, Integer> hm = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (!hm.containsKey(s.charAt(i)))
                hm.put(s.charAt(i), 1);
            else
                hm.put(s.charAt(i), hm.get(s.charAt(i)) + 1);
        }

        for (Character ch : hm.keySet())
            System.out.println(ch + " -> " + hm.get(ch));
    }

    // PROGRAM 4
    // TO FIND INTERSECTION OF TWO ARRAYS CHECK LEETCODE 349
    public static void intersectionOfArrays(int[] arr1, int[] arr2) {
        HashMap<Integer, Boolean> map = new HashMap<>();
        ArrayList<Integer> ans = new ArrayList<>();

        for (int i = 0; i < arr1.length; i++) {
            if (!map.containsKey(arr1[i]))
                map.put(arr1[i], true);
        }

        for (int ele : arr2) {
            if (map.containsKey(ele)) {
                map.remove(ele);
                ans.add(ele);
            }
        }

        for (Integer ele : ans)
            System.out.print(ele + " ");
    }

    // PROGRAM 5
    // TO FIND INTERSECTION OF TWO ARRAYS (ANOTHER VERSION) CHECK LEETCODE 350
    public static void intersectionOfArraysNew(int[] arr1, int[] arr2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> ans = new ArrayList<>();

        for (int i = 0; i < arr1.length; i++) {
            if (!map.containsKey(arr1[i]))
                map.put(arr1[i], 0);
            map.put(arr1[i], map.get(arr1[i]) + 1);
        }

        for (int ele : arr2) {
            if (map.containsKey(ele) && map.get(ele) > 0) {
                map.put(ele, map.get(ele) - 1);
                ans.add(ele);
            }
        }

        for (Integer ele : ans)
            System.out.print(ele + " ");
    }

    // PROGRAM 6
    // LONGEST CONSECUTIVE SUBSET/SUBSEQUENCE CHECK LEETCODE 128
    public static int longestConsecutiveSubsequence(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int ele : arr)
            map.put(ele, 1);
        int len = 0;

        for (int ele : arr) {
            if (!map.containsKey(ele))
                continue;

            map.remove(ele);
            int prevEle = ele - 1;
            int nextEle = ele + 1;

            while (map.containsKey(prevEle))
                map.remove(prevEle--);
            while (map.containsKey(nextEle))
                map.remove(nextEle++);

            len = Math.max(len, nextEle - prevEle - 1);
        }

        return len;
    }

    // PROGRAM 7
    // TO FIND THE LONGEST ARITHMETIC SUBSEQUENCE
    public int longestArithSeqLength(int[] arr) {
        int n = arr.length;
        int len = 0;
        HashMap<Integer, Integer>[] dp = new HashMap[n];
        for (int i = 0; i < n; i++)
            dp[i] = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = arr[i] - arr[j];
                dp[i].put(diff, map.getOrDefault(diff, 1) + 1);

                len = Math.max(len, dp[i].get(diff));
            }
        }
        return len;
    }

    public static void mapProblems() {
        String s = "abbababcc";
        // indexOfCharacters(s);
        // frequencyOfCharacters(s);
        int[] arr1 = { 1, 1, 1, 1, 2, 2, 2, 3, 5, 4 };
        int[] arr2 = { 1, 2, 2, 2, 2, 3, 3 };
        // intersectionOfArrays(arr1, arr2);
        // intersectionOfArraysNew(arr1,arr2);
        // int[] arr = {100, 4, 200, 1, 3, 2};
        // System.out.println(longestConsecutiveSubsequence(arr));
    }

    public static void main(String[] args) {
        // mapBasics();
        mapProblems();
    }
}