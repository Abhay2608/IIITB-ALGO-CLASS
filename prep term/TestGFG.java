public class TestGFG {
    public static void main(String[] args) {
        TrieGFG trie = new TrieGFG();
        String str[] = {"geeksforgeeks", "geeks", "geek", "geezer"};
        for (int i = 0; i < str.length; i++) {
            String word = str[i];
            trie.insert(word);
        }
        StringBuilder prefix = new StringBuilder();
        TrieGFG.TrieNode pCrawl = TrieGFG.root;
        while(true && pCrawl != null){
            int count = 0;
            int index = 0;
            for(int i=0;i<26;i++){
                if(pCrawl.children[i] != null) {
                    count++;
                    index = i;
                }
            }
            if(count != 1){
                break;
            }
            else{
                prefix.append(Character.toString((char) ('a'+ index)));
                pCrawl = pCrawl.children[index];
            }
        }
        System.out.println(prefix);
    }
}
