/*
	group : local
	name : Q1.java
	srcPath : /home/aryan/Dropbox/Documents from PC/free/jyoti-ranjan/test/Q1.java
	url : /home/aryan/Dropbox/Documents from PC/free/jyoti-ranjan/test/Q1.java
*/
import java.util.Scanner;

public class Q1 {

  public static Boolean is_substring(String t, String s) {
	  int n=t.length();
	  int m=s.length();

	  for(int i=0;i<m-n;i++){
		if(t.equals(s.substring(i,i+n))){
			return true;
		}
	  }
	  return false;

  }

  public static void main(String[] args) {
    /**
     * s will be IRC
     *
     * if s[n-2,...,0] and s[n-1,...,1] both
     * are a substring of (s+s)
     */

    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    int n = s.length();

    if (n == 1) {
      System.out.println(1);
      sc.close();
      return;
    }

    String t = new StringBuilder(s).reverse().toString();
    s += s;

    String t1 = t.substring(0, n - 1);
    String t2 = t.substring(1, n);

    if (is_substring(t1, s) && is_substring(t2, s)) {
      System.out.println(1);
    } else {
      System.out.println(0);
    }

    sc.close();
  }
}
