import java.util.*;
import java.io.*;

public class TrieGFG {
    static final int ALPHABET_SIZE = 26;

    static class TrieNode{
        TrieNode[] children = new TrieNode[ALPHABET_SIZE];
        Boolean isEndOfWord;
        public TrieNode(){
            isEndOfWord = false;
            for(int i=0;i<ALPHABET_SIZE;i++){
                children[i] = null;
            }
        }
    }

    static TrieNode root;
    public TrieGFG(){
        root = new TrieNode();
    }

    static void insert(String key){
        TrieNode pCrawl = root;
        for(int i=0;i<key.length();i++){
            int index = key.charAt(i) - 'a';
            if(pCrawl.children[index] == null){
                pCrawl.children[index] = new TrieNode();
            }
            pCrawl = pCrawl.children[index];
        }
        pCrawl.isEndOfWord = true;
    }

    static boolean search(String key){
        TrieNode pCrawl = root;
        for(int i=0;i<key.length();i++){
            int index = key.charAt(i) - 'a';
            if(pCrawl.children[index] == null){
                return false;
            }
            pCrawl = pCrawl.children[index];
        }
        return ( pCrawl != null && pCrawl.isEndOfWord );
    }

    static void deleteKey(String key){
        delete(root,key);
    }

    static void delete(TrieNode root,String word){
        if(word.length()==0) return;
        char ch = word.charAt(0);
        if(root.children[ch-'a'] != null){
            if(word.length()==1){
                if(root.children[ch-'a'].isEndOfWord){
                    root.children[ch-'a'].isEndOfWord = false;
                }
            }
            else {
                delete(root.children[ch-'a'],word.substring(1,word.length()));
            }
        }
    }
}
