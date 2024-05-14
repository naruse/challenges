/*https://leetcode.com/problems/k-closest-points-to-origin/description/

K Closest Points to Origin
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it 
is in).
*/

public class KClosestPoints {
    public int[][] KClosest(int[][] points, int k) {
        PriorityQueue<(int, int) , double> q = new PriorityQueue<(int, int), double>();

        for(int i = 0; i < points.Length; i++) {
            int x = points[i][0];
            int y = points[i][1];
            q.Enqueue((x, y), DistanceToOrigin(x,y));
        }
        
        List<int[]> result = new();

        for(int i = 0; i < k; i++) {
            (int,int) val = q.Dequeue();

            result.Add(new int[] {val.Item1, val.Item2 });
        }

        return result.ToArray();
    }

    double DistanceToOrigin(int x, int y) {
        return Math.Sqrt(Math.Pow((double)x, 2.0) + Math.Pow((double)y, (double)2.0));
    }
}