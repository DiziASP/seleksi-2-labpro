import java.util.*;

public class MinChange {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x, n;
        x = sc.nextInt();
        n = sc.nextInt();

        List<Integer> coins = new ArrayList<Integer>(n);
        for (int i = 0; i < n; i++) {
            int temp = sc.nextInt();
            coins.add(temp);
        }

        Collections.sort(coins, Collections.reverseOrder());

        int count = 0;
        for (int i = 0; i < n; i++) {
            if(x >= coins.get(i)){
                x -= coins.get(i);
                count++;
            }
        }

        if(x == 0){
            System.out.println(count);
        
        } else {
            System.out.println(-1);
        }
        
        sc.close();
    }
}
