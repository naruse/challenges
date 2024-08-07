/*
https://leetcode.com/problems/container-with-most-water/description/

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are 
(i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49      [0,1,2,3,4,5,6,7,8]
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section)
 the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1

*/

public class ContainersWithMostWater {

    public int MaxArea(int[] height) {

        int left = 0;
        int right = height.Length-1;
        
        int maxVolume = CalculateVolume(left, right, height);
        
        while(left < right) {

            var leftHeight = height[left];  
            var rightHeight = height[right];

            if(leftHeight < rightHeight) {
                left++;
            } else {
                right--;
            }
            
            var currVol = CalculateVolume(left, right, height);

            maxVolume = Math.Max(maxVolume,currVol);
        }

            
        Console.WriteLine("max: " +  maxVolume);
        return maxVolume;
    }

    int CalculateVolume(int leftColumnIdx, int rightColumnIdx, int[] _heights) {
                int leftColumn = _heights[leftColumnIdx];
                int rightColumn = _heights[rightColumnIdx];
                int lowestHeight = (leftColumn < rightColumn) ? leftColumn : rightColumn;

                int distanceBetweenCounters = rightColumnIdx - leftColumnIdx;
                int currentVolume = lowestHeight*distanceBetweenCounters;

                return currentVolume;
    }
}