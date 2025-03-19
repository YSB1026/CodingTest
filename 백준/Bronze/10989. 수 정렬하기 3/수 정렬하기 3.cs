using System;
using System.IO;


namespace 백준10989_수정렬하기3
{
    class Program
    {
        static void Main(string[] args)
        {
            //첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다.
            //둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.
            //지금 보니까, 이게 진짜 Counting Sort 쓸만한 문제였네요..
            const int buffer = 131072;
            StreamWriter sw = new StreamWriter(new BufferedStream(Console.OpenStandardOutput(),buffer));

            const int MAX = 10_000;
            int[] arr = new int[MAX];

            int n = int.Parse(Console.ReadLine());
            int num;
            for(int i=0; i<n; i++)
            {
                num = int.Parse(Console.ReadLine());
                arr[num-1]++;
            }

            for(int i=0; i<MAX; i++)
            {
                int cnt = arr[i];
                for(int j=0; j<cnt; j++)
                {
                    sw.WriteLine((i+1).ToString());
                }
            }

            sw.Flush();
        }
    }
}
