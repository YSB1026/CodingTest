using System;

namespace 백준11382_꼬마정민
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            Console.WriteLine(decimal.Parse(input[0]) + decimal.Parse(input[1]) + decimal.Parse(input[2]));
        }
    }
}
