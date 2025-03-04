using System;

namespace 백준10171_고양이
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] cat = { 
                "\\    /\\",
                " )  ( \')",
                "(  /  )",
                " \\(__)|"
            };
            foreach(var s in cat) 
                Console.WriteLine(s);
        }
    }
}
