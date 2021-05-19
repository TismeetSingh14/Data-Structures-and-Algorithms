
// lecture001
public class lecture001 {
    // PROGRAM 2
    // CALCULATING SIMPLE INTEREST
    public static float simpleInterest(float p, float r, float t) {
        float res;
        res = (p * r * t) / 100;
        return res;
    }

    // PROGRAM 3
    // LEARNING TO USE LOOPS
    public static void looping(int a) {
        for (int i = 1; i <= 10; i++) {
            System.out.println(a);
            a += 2;
        }
    }

    // PROGRAM 4
    // MORE ON LOOPS BASIC
    public static void nEvenOdd(int n) {
        System.out.println("even till n");
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                System.out.print(i + " ");
            }
        }

        System.out.println();
        System.out.println("odd till n");
        for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                System.out.print(i + " ");
            }
        }
    }

    // MAIN
    public static void main(String[] args) {
        // PROGRAM 1
        // System.out.println("hello world");
        // System.out.println(simpleInterest(1115,6,3));
        // looping(5);
        // nEvenOdd(50);
    }
}