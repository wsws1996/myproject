using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 飞行棋
{
    class Program
    {
        static int[] Maps = new int[100];
        static int[] PlayerPos = new int[2];
        static void Main(string[] args)
        {
            GameShow();
            InitailMap();
            Console.ReadKey();
        }
        /// <summary>
        /// 画游戏头
        /// </summary>
        public static void GameShow()
        {
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine("******************");
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("******************");
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("******************");
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.WriteLine("******飞行棋******");
            Console.ForegroundColor = ConsoleColor.Cyan;
            Console.WriteLine("******************");
            Console.ForegroundColor = ConsoleColor.DarkMagenta;
            Console.WriteLine("******************");
        }

        /// <summary>
        /// 初始化地图
        /// </summary>
        public static void InitailMap()
        {
            int[] luckyturn = { 6, 23, 40, 55, 69, 83 };
            for (int i = 0; i < luckyturn.Length; i++)
            {
                Maps[luckyturn[i]] = 1;
            }
            int[] landMine = { 5, 13, 17, 33, 38, 50, 64, 80, 94 };
            for (int i = 0; i < landMine.Length; i++)
            {
                Maps[landMine[i]] = 2;
            }
            int[] pause = { 9, 27, 60, 93 };
            for (int i = 0; i < pause.Length; i++)
            {
                Maps[pause[i]] = 3;
            }
            int[] timeTunnel = { 20, 25, 45, 63, 72, 88, 90 };
            for (int i = 0; i < timeTunnel.Length; i++)
            {
                Maps[timeTunnel[i]] = 4;
            }
        }

        public static void DrawMap()
        {
            for (int i = 0; i < 30; i++)
            {
                if (PlayerPos[0]==PlayerPos[1]&&PlayerPos[0]==i)
                {
                    Console.Write("<>");
                }
            }
        }
    }
}
