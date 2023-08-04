import java.util.*;

public class BalapSepeda {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N, Q;
        N = sc.nextInt();
        Q = sc.nextInt();

        List<Integer> klasemen = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            klasemen.add(sc.nextInt());
        }

        List<Integer> switch_per_min = new ArrayList<Integer>();
        for (int i = 0; i < Q; i++) {
            switch_per_min.add(sc.nextInt());
        }

        for(int each: switch_per_min) {
            Deque<Integer> dq = new ArrayDeque<Integer>();

            for(int i = 0; i < each; i++) {
                dq.add(sc.nextInt());
            }

            int corrector = 0;
            while(dq.size() > 0) {
                int first = dq.pollFirst();
                int last;

                if(dq.size() > 0) {
                    last = dq.pollLast();
                } else {
                    last = first;
                }

                if(first == last){
                    klasemen.remove(first - 1 - corrector);
                    corrector++;
                }
                else{
                    Collections.swap(klasemen, first - 1, last - 1);
                }
            }
        }

        if(klasemen.size() > 0) {
            System.out.println(klasemen.size() + " " + klasemen.get(0));
        } else {
            System.out.println("Tidak ada pemenang");
        }

        sc.close();
    }
}
