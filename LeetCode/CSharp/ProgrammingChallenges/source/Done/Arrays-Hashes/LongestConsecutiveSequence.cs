/*
https://leetcode.com/problems/longest-consecutive-sequence/description/

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

*/

/*
la forma correcta es con un hash set, inicializamos el hash set con nums.
Entonces, para cada numero "num" preguntamos si "num -1" no existe; sino existe quiere decir que potencialmente
es el mas pequeño del set entonces en un while preguntamos si existe un num+1 y empezamos a incrementar currLength
y apenas terminemos el while calculamos el maxLength
static int LongestConsecutive(int[] nums)
    {
        HashSet<int> numSet = new HashSet<int>(nums);
        int maxLength = 0;

        foreach (int num in numSet)
        {
            if (!numSet.Contains(num - 1)) // Check if num is the start of a sequence
            {
                int currentNum = num;
                int currentLength = 1;

                // Increment currentNum and currentLength while consecutive elements exist in the set
                while (numSet.Contains(currentNum + 1))
                {
                    currentNum++;
                    currentLength++;
                }

                maxLength = Math.Max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
*/

public class LongestConsecutiveSequence {
    public int Check(int[] nums) {
        if(nums.Length == 0)
            return 0;
        Array.Sort(nums);
        int longestYet = 1;
        int longest = 1;
        Console.Write(nums[0]+ " "); 
        for(int i = 1; i < nums.Length; i++) {
            Console.Write(nums[i] + " " );
            if(nums[i-1] == nums[i])// hack, al parecer tenemos que contar los duplicados como 1....
                continue;
            
            if(nums[i-1] == nums[i]-1) {
                longest++;
            } else {
                longest = 1;
            }
            
             if(longest > longestYet) {
                longestYet = longest;
            }
        }
    
        Console.WriteLine("\n" + longestYet);
        return longestYet;
        /*
        HashSet<int> hashValues = new HashSet<int>();
        for(int i = 0 ; i < nums.Length; i ++) {
            hashValues.Add(nums[i]);
            Console.Write(nums[i] + " ");
        }
        Console.WriteLine(" === ");
        foreach(var val in hashValues) {
            Console.Write(val + " "); <-- los imprime en orden ascendente :o
        }*/
        
    }
}