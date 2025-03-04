using System;

namespace 백준10869_사칙연산
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]), b = int.Parse(input[1]);
            Console.WriteLine(a+b);
            Console.WriteLine(a-b);
            Console.WriteLine(a*b);
            Console.WriteLine(a/b);
            Console.WriteLine(a%b);
        }
    }
}
