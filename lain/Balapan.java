import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Balapan {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Q = scanner.nextInt();

        List<Integer> pembalap = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            pembalap.add(scanner.nextInt());
        }

        List<Integer> switcher = new ArrayList<>();
        for (int i = 0; i < Q; i++) {
            switcher.add(scanner.nextInt());
        }

        for (int s: switcher) {
            List<Integer> posisi = new ArrayList<>();
            for (int j = 0; j < s; j++) {
                posisi.add(scanner.nextInt());
            }

            int left = 0;
            int right = posisi.size() - 1;

            while (left <= right) {
                if(posisi.get(left) == posisi.get(right) || posisi.get(left) == posisi.get(right)) {
                    pembalap.remove(posisi.get(left) - 1);
                    left++;
                    right--;
                    continue;
                }

                int temp = pembalap.get(posisi.get(left) - 1);
                pembalap.set(posisi.get(left) - 1, pembalap.get(posisi.get(right) - 1));
                pembalap.set(posisi.get(right) - 1, temp);
                left++;
                right--;
            }
        }

        int pembalap_tot = pembalap.size();

        if(pembalap_tot > 0) {
            System.out.println(pembalap_tot + " " + pembalap.get(0));
        } else {
            System.out.println("Tidak ada pemenang");
        }

        scanner.close();
    }
}