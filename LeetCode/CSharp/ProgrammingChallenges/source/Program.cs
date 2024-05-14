
class Program
{
    static int[] intInputArr = {1,2,0,1};
    static string strInputArr = "III";


    static void Main(string[] args)
    {

        Console.WriteLine("== Running Program ==\n");


        ValidParentheses l = new ();
        var valid = l.CheckForValidity("([])[]{}");
        
        Console.WriteLine(valid);
        
        Console.WriteLine("== Done ==\n");
    }
}