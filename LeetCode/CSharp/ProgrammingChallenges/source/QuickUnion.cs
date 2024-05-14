using System;

public class QuickUnion {
    private int[] ids;

    public QuickUnion(int N) {
        ids = new int[N];
        for(int i = 0; i < N; i++)
            ids[i] = i;
    }

    private int Root(int i) {
        while(i != ids[i])
            i = ids[i];
        return i;
    }

    public bool Connected(int p, int q) {
        return Root(p) == Root(q);//check p & q have the same root and if they do they are connected
    }

    public void Union(int p, int q) {
        int i = Root(p);
        int j = Root(q);
        ids[i] = j;
    }
}