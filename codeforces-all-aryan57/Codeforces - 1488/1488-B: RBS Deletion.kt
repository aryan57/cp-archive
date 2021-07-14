//https://codeforces.com/contest/1488/problem/B

import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

object Programkt {
    @JvmStatic
    fun main(args: Array<String>) {
        val fs = FastScanner()
        val out = PrintWriter(System.out)
        val testcases = fs.nextInt()
        for (_T in 0 until testcases) {
            val n = fs.nextInt()
            val k = fs.nextInt()
            val s1 = fs.next()
            var t = 0
            var cnt = 0
            for (i in 0 until s1.length) {
                if (s1[i] == '(') t++ else t--
                if (t == 0) cnt++
            }
            out.println(Math.min(n / 2, k + cnt))
        }
        out.close()
    }

    fun sort(a: IntArray) {
        val l = ArrayList<Int>()
        for (i in a) l.add(i)
        Collections.sort(l)
        for (i in a.indices) a[i] = l[i]
    }

    internal class FastScanner {
        @JvmField
        var br = BufferedReader(InputStreamReader(System.`in`))
        @JvmField
        var st = StringTokenizer("")
        operator fun next(): String {
            while (!st.hasMoreTokens()) try {
                st = StringTokenizer(br.readLine())
            } catch (e: IOException) {
                e.printStackTrace()
            }
            return st.nextToken()
        }

        fun nextInt(): Int {
            return next().toInt()
        }

        fun readArray(n: Int): IntArray {
            val a = IntArray(n)
            for (i in 0 until n) a[i] = nextInt()
            return a
        }

        fun nextLong(): Long {
            return next().toLong()
        }
    }
}