using System;

namespace BOJ_10250
{
    class Program
    {
        static void Main()
        {
            int t;
            int h, w, n;

            t = int.Parse(Console.ReadLine());
            for (int i = 0; i<t; i++)
            {
                string[] _ = Console.ReadLine().Split(' ');
                h = int.Parse(_[0]); w = int.Parse(_[1]); n = int.Parse(_[2]);
                int XX = (int)Math.Ceiling((double)n/h); int YY = n-h*(XX-1);
                string room = YY + XX.ToString("D2");
                Console.WriteLine(room);
            }
        }
    }
}
