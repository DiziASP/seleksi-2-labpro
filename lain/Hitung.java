package lain;

import java.util.*;
public class Hitung {
    public static int kombinasi(int N, int M, int K) {

        List<Integer> matrix = new ArrayList<>(M);
        for(int i = 0; i < M; i++) {
            matrix.add(0);
        }

        /* Pendekatan Dynamic Programming */
        for (int i = 0; i < M; i++) {
            matrix.set(i, 1);
        }

        for (int i = 1; i < N; i++) {
            List<Integer> temp = new ArrayList<>(M);
            for (int j = 0; j < M; j++) {
                temp.add(0);
            }
            
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < M; k++) {
                    if (j != k) {
                        if (i - K >= 0) {
                            temp.set(j, temp.get(j) + matrix.get(k));
                        } else {
                            temp.set(j, temp.get(j) + 1);
                        }
                    }
                }
            }
            matrix = temp;
        }
    
        int total = 0;
        for (int i = 0; i < M; i++) {
            total += matrix.get(i);
        }

        return total % 998244353;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int K = scanner.nextInt();

        System.out.println(kombinasi(N, M, K));
        scanner.close();
    }
}
