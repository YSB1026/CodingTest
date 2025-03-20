using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 백준1181_단어정렬
{
    class StringCompare : IComparer<string>
    {
        public int Compare(string a, string b)
        {
            if (a.Length != b.Length)//길이가 짧은 것 부터 정렬 해야합니다.
            {
                return a.Length.CompareTo(b.Length);
            }
            return string.Compare(a, b, StringComparison.Ordinal);//같다면 사전순으로 정렬하면됩니다.
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();

            HashSet<string> set = new HashSet<string>();
            int n = int.Parse(Console.ReadLine());
            for (int i = 0; i<n; i++)
            {
                set.Add(Console.ReadLine());
            }

            List<string> list = set.ToList();   
            list.Sort(new StringCompare());

            foreach (string s in list)
            {
                sb.AppendLine(s);
            }

            Console.WriteLine(sb.ToString());
        }
    }
}
