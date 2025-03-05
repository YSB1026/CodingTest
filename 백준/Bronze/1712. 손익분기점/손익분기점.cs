using System;

namespace 백준1712_손익분기점
{
    class Program
    {
        static void Main(string[] args)
        {

            //총 수입(판매비용)이 총 비용(=고정비용+가변비용)보다 많아지게 된다.
            //최초로 총 수입이 총 비용보다 많아져 이익이 발생하는
            //지점을 손익분기점(BREAK-EVEN POINT)이라고 한다.
            //c++로 풀때 왜이렇게 어렵게풀었노;
            int a, b, c;
            string[] input = Console.ReadLine().Split(' ');

            a= int.Parse(input[0]);
            b= int.Parse(input[1]);
            c= int.Parse(input[2]);

            int BREAK_EVEN_POINT;
            if (b>=c) BREAK_EVEN_POINT = -1;
            else
            {
                BREAK_EVEN_POINT = a/Math.Abs(b-c) + 1;
            }

            Console.WriteLine(BREAK_EVEN_POINT);
        }
    }
}
