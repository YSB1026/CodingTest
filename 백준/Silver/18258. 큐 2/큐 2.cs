using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace 백준18258_큐2
{
    class MyQueue<T>
    {
        T[] arr;
        public int capacity { get; private set; }
        public int size { get; private set; }
        int front, rear;

        public MyQueue(int capacity = 30)
        {
            this.capacity = capacity;
            arr = new T[capacity];
            size = 0;
            front = rear = 0;
        }
        private void Resize()
        {
            int newCapacity = this.capacity*2;
            T[] newArr = new T[newCapacity];
            int f = front, i = 0;

            //front부터 rear까지 복사해야하는데, i를 size만큼 반복시키면서 복사
            while (i < size)
            {
                newArr[i] = arr[f];
                f = (f + 1) % capacity;
                i++;
            }

            //resize 이후 arr, capacity, front, rear초기화
            arr = newArr;
            capacity = newCapacity;
            front = 0;
            rear = size;
        }

        public void Push(T element)
        {
            if (size >= capacity)
            {
                Resize();
            }
            arr[rear] = element;
            rear = (rear+1) % capacity;
            size++;
        }

        public T Pop()
        {
            if (size == 0)
            {
                //throw new Exception("");
                return default;
            }

            T frontElemnt = arr[front];
            front = (front+1) % capacity;
            size--;

            return frontElemnt;
        }

        public T GetFront()
        {
            if (size == 0) return default;//throw new Exception("");
            return arr[front];
        }
        public T GetBack()
        {
            if (size==0) return default;//throw new Exception("");
            return (rear==0)? arr[size-1]: arr[rear-1];
        }

        public int IsEmpty()// C나 C++에선 true false는 1,0이라 됐엇는데..
        {
            return size==0 ? 1 : 0;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            using (BufferedStream bsIn = new BufferedStream(Console.OpenStandardInput()))
            using (BufferedStream bsOut = new BufferedStream(Console.OpenStandardOutput()))
            using (StreamReader sr = new StreamReader(bsIn))
            using (StreamWriter sw = new StreamWriter(bsOut))
            {
                StringBuilder sb = new StringBuilder();

                int N = int.Parse(sr.ReadLine());

                MyQueue<int> queue = new MyQueue<int>(N);

                for (int i = 0; i < N; i++)
                {
                    string[] input = sr.ReadLine().Split(' ');
                    string command = input[0];

                    if (command == "push")
                    {
                        int element = int.Parse(input[1]);
                        queue.Push(element);
                    }
                    else if (command == "pop")
                    {
                        int result = queue.Pop();
                        sb.AppendLine(result == default ? "-1" : result.ToString());
                    }
                    else if (command == "size")
                    {
                        sb.AppendLine(queue.size.ToString());
                    }
                    else if (command == "empty")
                    {
                        sb.AppendLine(queue.IsEmpty().ToString());
                    }
                    else if (command == "front")
                    {
                        int front = queue.GetFront();
                        sb.AppendLine(front == default ? "-1" : front.ToString());
                    }
                    else if (command == "back")
                    {
                        int back = queue.GetBack();
                        sb.AppendLine(back == default ? "-1" : back.ToString());
                    }
                }//for


                sw.Write(sb.ToString());
            }//using
        }//main
    }
}