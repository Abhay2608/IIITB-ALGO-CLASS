import java.util.*;
import java.io.*;
public class Test {
    public static void main(String[] args) throws IOException {
        Trie trie = new Trie();
        File file = new File("C:\\Users\\Abhay Nanda\\Desktop\\test.txt");
        BufferedReader br = new BufferedReader(new FileReader(file));
        String st;
        while ((st = br.readLine()) != null)
            trie.insert(st);

        /*String str[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
        for(int i=0;i<str.length;i++){
            String word = str[i];
            trie.insert(word);
        }*/
        int counter = 0;
        Trie.TrieNode pCrawl = trie.root;
        int indexs = 0;
        String prefix = "";
        while(pCrawl.children.size() == 1 && pCrawl.endOfWord == false ){
            prefix = prefix + Character.toString((pCrawl.children.keySet().toString().charAt(1)));
            pCrawl =  pCrawl.children.firstEntry().getValue();
        }
        if(prefix.length() > 0)
            System.out.println(prefix);
        else
            System.out.println("No Prefix");
        //pCrawl = pCrawl.children.getOrDefault()
    }
}
