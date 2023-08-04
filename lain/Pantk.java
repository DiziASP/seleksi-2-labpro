import java.util.*;

public class Pantk {
    public int operate(int num1, int num2, char op){
        switch(op){
            case '+':
                return num1 + num2;
            case '*':
                return num1 * num2;
        }
        return 0;
    }

    public int findSmallest(List<Integer> nums, List<Character> ops, int currentNum, int currentIndex, int currentTotal){
        /* Basis */
        if(currentIndex == ops.size()){
            return currentTotal;
        }

        /* Recursive */

        for(int i = currentIndex; i < ops.size(); i++){
            
        }
        return 0;
    }

    public int getSmallestValue(List<Integer> nums, List<Character> ops){
        return findSmallest(nums, ops, nums.get(0), 0, 0);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        List<Integer> nums = new ArrayList<Integer>(4);
        for(int i = 0; i < 4; i++) {
            nums.add(sc.nextInt());
        }

        List<Character> ops = new ArrayList<Character>(3);
        for(int i = 0; i < 3; i++) {
            ops.add(sc.next().charAt(0));
        }

    }
}
