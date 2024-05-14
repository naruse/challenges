public class KthLargest {
    
    PriorityQueue<int,int> q;
    
    int kElement;
    //IMPORTANT: WE FORCE the MINHEAP to be of size K, then we can just return the K largest element all the time
    public KthLargest(int k, int[] nums) {
        var nvals = nums.Select(i => (i,i));
        q = new PriorityQueue<int,int>(nvals);// has to be a min heap
        kElement = k;
        
        while(q.Count > k) {
            q.Dequeue();
        }

        /*for(int i = 0; i < nums.Length; i++){
            q.Enqueue(nums[i], nums[i]);
        }*/

    }
    /*
    The largest kth element is equal to the (nums.Length - k) smallest element.
    So to use a minHeap instead of a maxHeap to find the kth largest element, do:
    k = nums.Length - k;
    */

    public int Add(int val) {
        q.Enqueue(val, val);
    
        if(q.Count > kElement)
            q.Dequeue();

        return q.Peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */