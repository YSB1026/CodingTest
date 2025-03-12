using System;
using System.Collections.Generic;
using System.Text;

class Program
{
    static Dictionary<char, char[]> tree = new Dictionary<char, char[]>();
    static StringBuilder sb = new StringBuilder();

    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        for (int i = 0; i < n; i++)
        {
            string[] input = Console.ReadLine().Split();
            char root = input[0][0];
            char left = input[1][0];
            char right = input[2][0];

            tree[root] = new char[] { left, right };
        }

        Preorder('A');
        sb.AppendLine();
        Inorder('A');
        sb.AppendLine();
        Postorder('A');

        Console.WriteLine(sb.ToString());
    }

    static void Preorder(char root)
    {
        if (root != '.')
        {
            sb.Append(root); // root
            Preorder(tree[root][0]); // left
            Preorder(tree[root][1]); // right
        }
    }

    static void Inorder(char root)
    {
        if (root != '.')
        {
            Inorder(tree[root][0]); // left
            sb.Append(root); // root
            Inorder(tree[root][1]); // right
        }
    }

    static void Postorder(char root)
    {
        if (root != '.')
        {
            Postorder(tree[root][0]); // left
            Postorder(tree[root][1]); // right
            sb.Append(root); // root
        }
    }
}
