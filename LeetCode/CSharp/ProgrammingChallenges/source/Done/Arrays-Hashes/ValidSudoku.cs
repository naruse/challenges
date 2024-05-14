/*
https://leetcode.com/problems/valid-sudoku/description/

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

*/

public class SudokuValidator {

 static char[][] sudokuInput = new char[][]
    {
        new char[] { '8', '3', '.', '.', '7', '.', '.', '.', '.' },
        new char[] { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        new char[] { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        new char[] { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        new char[] { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        new char[] { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        new char[] { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        new char[] { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        new char[] { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };


    public bool Check(char[][] table) {
        int width = 9;
        int height = 9;
        HashSet<char> seenValues = new();

//rows
        for(int i = 0; i < table.Length; i++) {
            for(int j = 0; j < table[i].Length; j++) {
                if(table[i][j] != '.') { // only check the actual numbers
                    if(!seenValues.Contains(table[i][j])) {
                        seenValues.Add(table[i][j]);//check rows
                    } else {
                        return false;
                    }
                }
            }
            seenValues.Clear();
        }
//columns
        seenValues.Clear();
        for(int i = 0; i < table.Length; i++) {
            for(int j = 0; j < table[i].Length; j++) {
                if(table[j][i] != '.') { // only check the actual numbers
                    if(!seenValues.Contains(table[j][i])) {
                        seenValues.Add(table[j][i]);//check columns
                    } else {
                        return false;
                    }
                }
            }
            seenValues.Clear();
        }

// Check sub 3x3 matrices
        seenValues.Clear();
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3;k++) {
                    for(int l = 0; l < 3; l++) {
                        int indexI = k+i*3;
                        int indexJ = l+j*3;
                        
                        if(table[indexI][indexJ] != '.') {
                            if(!seenValues.Contains(table[indexI][indexJ])) {
                                seenValues.Add(table[indexI][indexJ]);//check columns
                            } else {
                                return false;
                            }
                        }
                    }
                }
                seenValues.Clear();
            }
        }

        return true;
    }
}