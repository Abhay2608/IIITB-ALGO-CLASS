import java.util.*;
import java.io.*;

public class Test{
    static class Tax{
        long amount;
        String name;

        public void setter(String s,long a){
            this.amount = a;
            this.name = s;
        }

    }

    public static void main(String[] args) throws IOException {
        File file = new File("C:\\Users\\Abhay Nanda\\Desktop\\input23.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));
        String st = "";
        PriorityQueue<Tax> maxHeap = new PriorityQueue<Tax>(new Comparator<Tax>() {
            @Override
            public int compare(Tax o1, Tax o2) {
                if((long)o1.amount > (long)o2.amount)   return 1;
                else if((long)o1.amount < (long)o2.amount)  return -1;
                else    return 0;
            }
        });
        PriorityQueue<Tax> minHeap = new PriorityQueue<Tax>(new Comparator<Tax>() {
            @Override
            public int compare(Tax o1, Tax o2) {
                if((long)o1.amount > (long)o2.amount)   return -1;
                else if((long)o1.amount < (long)o2.amount)  return 1;
                else    return 0;
            }
        });
        while ((st = br.readLine()) != null){
            StringTokenizer s = new StringTokenizer(st," ");
            while(s.hasMoreTokens()){
                int i = 0;
                String name = s.nextToken();
                int amount = Integer.parseInt(s.nextToken());
                Tax t1 = new Tax();
                Tax t2 = new Tax();
                t1.amount = amount;
                t1.name = name;
                if(i < 10){
                    minHeap.add(t1);
                    maxHeap.add(t1);
                }
                else{
                    Tax min = minHeap.peek();
                    Tax max = maxHeap.peek();

                    if(min.amount > t1.amount){
                        minHeap.poll();
                        minHeap.add(t1);
                    }
                    if(max.amount < t1.amount){
                        maxHeap.poll();
                        maxHeap.add(t1);
                    }
                }
            }
        }

        StringBuilder highest = new StringBuilder();
        StringBuilder lowest = new StringBuilder();

        int count = 1;
        while(count < 11){

            Tax t = maxHeap.poll();
            highest.append(count).append(":").append(t.name).append(" ").append(t.amount).append("\n");

            t = minHeap.poll();
            lowest.append(count).append(":").append(t.name).append(" ").append(t.amount).append("\n");

            count++;
        }
        System.out.println("Highest Tax Payers:");
        System.out.println(lowest);

        System.out.println("Lowest Tax Payers:");
        System.out.println(highest);
    }
}

