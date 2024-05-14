/*
https://leetcode.com/problems/palindrome-number/description/

Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

using System.ComponentModel.Design;

class PalindromeChecker {
    int numberToCheck;
    public PalindromeChecker(int num) {
        numberToCheck = num;
    }

    public bool Check() {
        //Console.WriteLine("IntLength: " + IntLength(numberToCheck));

        if(numberToCheck < 0) //neg numbers are not palindrome
            return false;

        var num = numberToCheck;
        //var numLength = IntLength(numberToCheck);

        List<int> numDigits = new List<int>();

        while(num > 0) {
            var digit = num%10;
            
            numDigits.Insert(0, digit);
            num = num/10;
        }

        int counter = 0;
        int backCounter = 0;
        for(int i = 0; i < numDigits.Count; i++) {
            counter = i;
            backCounter = numDigits.Count - 1 - i;
            
            if(counter < backCounter) {
                if(numDigits[counter] == numDigits[backCounter])
                    continue;
                else
                    return false;
            } else {
                break;
            }
        }
        return true;
    }

    //http://www.java2s.com/Code/CSharp/Data-Types/Getthedigitlengthofanintvalue.htm
    private int IntLength(int i) {
      if (i < 0) {
        Console.WriteLine("Negative number");
        return IntLength(i*-1);
      }
      if (i == 0) return 1;
      return (int)Math.Floor(Math.Log10(i)) + 1;
    }
}