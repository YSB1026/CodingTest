using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace 백준11650_좌표정렬하기
{
    struct Position: IComparable<Position>
    {
        public int x, y;

        public Position(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
        public int CompareTo(Position other)
        {
            if (x != other.x)
            {
                return x.CompareTo(other.x);
            }
            return y.CompareTo(other.y);
        }

        public override string ToString()
        {
            return $"{x} {y}";
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder sb = new StringBuilder();
            List<Position> positions = new List<Position>();

            int n = int.Parse(Console.ReadLine());

            int x, y;
            for(int i=0; i<n; i++)
            {
                string[] pos = Console.ReadLine().Split(' ');
                x = int.Parse(pos[0]);
                y = int.Parse(pos[1]);
                positions.Add(new Position(x, y));
            }
            positions.Sort();

            foreach (var pos in positions)
            {
                sb.AppendLine(pos.ToString());
            }

            Console.WriteLine(sb.ToString());
        }
    }
}
