import java.util.*;
import java.io.*;

public class Test {
    public static void main(String[] args) throws IOException {
        File file = new File("C:\\Users\\Abhay Nanda\\Desktop\\input.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));
        String st;
        ArrayList<Integer> a = new ArrayList<Integer>();
        a.add(1);
        StringBuilder result = new StringBuilder();
        HashMap<String,Integer> map = new HashMap<String,Integer>();
        while ((st = br.readLine()) != null){
            Integer freq = map.get(st);
            if(freq == null){
                map.put(st,1);
            }
            else{
                result.append(st).append("\n");
            }
        }
        if(result.length() != 0){
            System.out.println(result);
        }
        else
            System.out.println(" No duplicates");
    }
}
