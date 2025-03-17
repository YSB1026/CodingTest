using System;
using System.Text;

namespace 백준2751번_수정렬하기2
{
    class Program
    {
        static void Main(string[] args)
        {
            //1,000,000
            StringBuilder sb = new StringBuilder();
            const int OFFSET = 1_000_000;
            const int MAX = 2_000_001;
            bool[] arr = new bool[MAX]; //-1_000_000 ~ 1_000_000까지.
            int n = int.Parse(Console.ReadLine());
            int num;
            for (int i=0; i<n; i++)
            {
                num = int.Parse(Console.ReadLine());
                arr[num+OFFSET] = true;
            }

            for (int i = 0; i<MAX; i++)
            {
                if (arr[i]) sb.AppendLine((i-OFFSET).ToString());
            }

            Console.WriteLine(sb.ToString());
        }
    }
}
