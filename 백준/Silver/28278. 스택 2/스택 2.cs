using System;
using System.Text;

namespace 백준28278_스택2
{
    class MyStack
    {
        public int Count => tos+1;
        int[] arr;
        int capacity;
        int tos;//top of stack.

        public MyStack(int capacity)
        {
            arr = new int[capacity];
            tos = -1;
        }
        public void Push(int value)
        {
            //resize구현 X, 동적 배열 X
            arr[++tos] = value;
        }
        public int Pop()
        {
            if (tos == -1) return -1;
            int retVal = arr[tos];
            tos--;
            return retVal;
        }
        public int Peek()
        {
            if (tos == -1) return -1;
            return arr[tos];
        }
        public int Size()
        {
            return tos+1;
        }

        public int IsEmpty()
        {
            if (tos==-1) return 1;
            return 0;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            //확인용
            //Stack<int> stack = new Stack<int>();
            //stack.Push(1);
            //stack.Peek();
            //stack.Pop();

            //1. Push
            //2. Pop
            //3. Size(Count)
            //4. IsEmpty
            //5. Peek

            int n = int.Parse(Console.ReadLine());
            MyStack stack = new MyStack(n);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i<n; i++)
            {
                string[] input = Console.ReadLine().Split(' ');
                if (input[0]=="1")
                {
                    stack.Push(int.Parse(input[1]));
                }
                else if (input[0]=="2")
                {
                    sb.AppendLine(stack.Pop().ToString());
                }
                else if (input[0]=="3")
                {
                    sb.AppendLine(stack.Count.ToString());
                }
                else if (input[0]=="4")
                {
                    sb.AppendLine(stack.IsEmpty().ToString());
                }
                else
                {
                    sb.AppendLine(stack.Peek().ToString());
                }
            }//for

            Console.WriteLine(sb.ToString());
        }
    }
}
