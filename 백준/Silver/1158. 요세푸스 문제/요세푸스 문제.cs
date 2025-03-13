using System;
using System.Collections.Generic;
using System.Text;

namespace 백준1158_요세푸스문제
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();

            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]), k = int.Parse(input[1]);

            Queue<int> q = new Queue<int>();
            for (int i = 1; i <= n; i++)
            {
                q.Enqueue(i);
            }

            while(q.Count > 0)
            {
                for (int  i = 0; i < k - 1; i++)
                {
                    q.Enqueue(q.Dequeue());
                }
                sb.Append(q.Dequeue() + ", ");
            }

            Console.WriteLine("<" + sb.ToString().Substring(0,sb.Length-2) + ">");
        }
    }
}
