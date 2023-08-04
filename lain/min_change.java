import java.util.*;
import java.lang.Math;

public class min_change {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x,n;
        x = sc.nextInt();
        n = sc.nextInt();


        List<Integer> coins = new ArrayList<Integer>(n);
        for(int i = 0; i < coins.size(); i++){
            coins.add(sc.nextInt());
        }

        for(int i = 0; i < coins.size(); i++){
            System.out.println(coins.get(i));
        }
        
        int min_coin = Collections.min(coins);
        if(min_coin > x){
            System.out.println("-1");
        }
        else{
            Collections.sort(coins);
            int count = 0;
            int sum = 0;
            for(int i = 0; i >= coins.size(); i--){
                if(sum >= x){
                    break;
                }
                sum += coins.get(i);
                count++;
            }
            System.out.println(count);
        }
        sc.close();
    }
}
