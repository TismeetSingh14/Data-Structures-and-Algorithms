
// lecture 002
import java.util.Scanner;

public class lecture002 {
    public static Scanner scn = new Scanner(System.in);

    // PROGRAM 1
    // USING LOOPS TO FIND FACTORIAL OF A NUMBER
    public static int factorial(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res = res * i;
        }
        return res;
    }

    // PROGRAM 2
    // USING FACTORIAL FUNCTION TO FIND nCr
    public static int combination(int n, int r) {
        int ans;
        ans = factorial(n) / (factorial(n - r) * factorial(r));
        return ans;
    }

    // PROGRAM 3
    // TO ROTATE A GIVEN NUMBER BY A NUMBER r
    // EXAMPLE-> 12345 r=2
    // OUTPUT-> 34512
    public static int digits(int n)         // FUNCTION TO FIND NO. OF DIGITS
    {
        int count = 0;

        while (n > 0) {
            count++;
            n = n / 10;
        }

        return count;
    }

    public static int rotationOfNumber(int n, int r) {
        int div = 1;
        int mul = 1;
        r = r % digits(n);
        r = r < 0 ? digits(n) + r : r;

        for (int i = 1; i <= digits(n); i++) {
            if (i <= r) {
                mul *= 10;
            }

            else {
                div *= 10;
            }
        }

        int a = n / div;
        int b = n % div;
        int res = b * mul + a;
        return res;
    }

    // PROGRAM 4
    // TO CHECK WHETHER A GIVEN NUMBER IS PRIME
    public static boolean isPrime(int n) {
        for (int i = 2; i * i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    // PROGRAM 5
    /*
     * GIVEN n NUMBER OF BULBS, DURING EACH ITERATION THE BULBS AT MULTIPLE OF SAY 1
     * ARE SWITCHED ON THEN IN THE NEXT ITERATION THE BULBS AT MULTILE OF 2 ARE
     * SWITCHED OFF AND SO ON... FIND AFTER n ITERATIONS WHICH BULBS ARE SWITCHED
     * ON.
     */
    public static void bulbs(int n) {
        for (int i = 1; i * i <= n; i++) {
            System.out.print(i * i + " ");
        }
    }

    // MAIN
    public static void main(String[] args) {
        // int n=scn.nextInt();
        // int r=scn.nextInt();
        // System.out.println(factorial(n));
        // System.out.println(combination(n,r));
        // System.out.println(rotationOfNumber(n,r));
        // System.out.println(isPrime(n));
        // bulbs(n);
    }
}