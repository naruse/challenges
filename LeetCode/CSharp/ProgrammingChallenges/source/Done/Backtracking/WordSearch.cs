/*
https://leetcode.com/problems/word-search/description/

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
horizontally or vertically neighboring. The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/
public class WordSearch {
    public bool Exist(char[][] board, string word) {
        int m = board.Length, n = board[0].Length;

        bool Dfs(int i, int j, int start) {
            if (start == word.Length)
                return true;
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[start])
                return false;

            char c = board[i][j];
            board[i][j] = '~';
            bool result = Dfs(i + 1, j, start + 1) || Dfs(i - 1, j, start + 1) 
                    || Dfs(i, j + 1, start + 1) || Dfs(i, j - 1, start + 1);
            board[i][j] = c;
            return result;
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (Dfs(i, j, 0))
                    return true;
        return false;
    }
    
}