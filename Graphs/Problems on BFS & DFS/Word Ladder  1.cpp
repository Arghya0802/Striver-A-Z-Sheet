// LeetCode: https://leetcode.com/problems/word-ladder/
// GFG: https://practice.geeksforgeeks.org/problems/word-ladder/1

// Word Ladder 1 is also a BFS probelm but we has a bit more implementation and nothing else
// We assume beginWord is at Level 1 and we start our BFS from there onwards
// Everytime we iterate over the Current-Word from the queue and changes every letter one by one, as stated in the question, and checks if it's present in our wordList[] or not
// If it's present, we put it inside our queue with(steps + 1) or (level + 1) as we want to say and delete that word from our set
// This ensures we don't go back to the same word again and get struck in an infinite loop
// In this way, if we encounter our endWord, we return steps
// Otherwise, we return 0 at the end of our while loop

class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string>& wordList) 
    {
        unordered_set<string> set ;
        
        // We put all the words in wordLis[] into our set data structure
        for(string &wd : wordList)
            set.insert(wd) ;

        queue<pair<int , string> > q ; // Queue will store the {Steps , currWord} 

        q.push( {1 , beginWord} ) ; // We push (beginWord , 1) as it's on the First Level

        if(set.find(beginWord) != set.end() ) // We erase beginWord from our set data structure
            set.erase(beginWord) ;
        
        while(q.empty() == false)
        {
            int steps = q.front().first ;
            string word = q.front().second ;
            q.pop() ;

            if(word == endWord) // If our word is equal to endWord, we immediately return steps
                return steps ;

            int len = word.size() ;
            
            // We iterate over the word and changes each of it's character one by one 
            for(int i = 0 ; i < len ; i++)
            {
                char curr = word[i] ;

                for(char ch = 'a' ; ch <= 'z' ; ch++)
                {
                    word[i] = ch ;
                    
                    // If the Changed-Word is present in our set, we immediately put it into our queue with (steps + 1)
                    if(set.find(word) != set.end() )
                    {
                        q.push( {steps + 1 , word} ) ;
                        set.erase(word) ; // We also erase the same word from our queue such that we don't visit it again
                    }
                }

                word[i] = curr ; // We restore the original word again at the end
            }

        }

        return 0 ; // If we couldn't find our endWord at the end, we return 0
    }
};

// Time Complexity:  Variable depens on beginWord and endWord [In my opnion]
// Space Complexity: Again variable and depends on the wordList and the transformations [In my opinion]
