import java.util.*;

public class PTK {
    public static int calculate(int a, int b, char op) {
        if (op == '+') {
            return a + b;
        } else if (op == '*') {
            return a * b;
        } else {
            return 0;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        Deque<Integer> nums = new ArrayDeque<>();
        for (int i = 0; i < 4; i++) {
            nums.add(scanner.nextInt());
        }

        char[] ops = new char[3];
        for (int i = 0; i < 3; i++) {
            ops[i] = scanner.next().charAt(0);
        }

        int currOp = 0;
        while (nums.size() > 1) {
            Integer[] temp = nums.toArray(new Integer[nums.size()]);
            nums.clear();
            Arrays.sort(temp);
            for (int i = 0; i < temp.length; i++) {
                nums.add(temp[i]);
            }


            int a,b;
            if(ops[currOp] == '+') {
                a = nums.pollLast();
                b = nums.pollLast();
            } else {
                a = nums.pollFirst();
                b = nums.pollFirst();
            }

            nums.addLast(calculate(a, b, ops[currOp]));
            currOp++;
        }
        
        System.out.println(nums.getFirst());

        scanner.close();
    }
}
