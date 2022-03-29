/*
	group : local
	name : RiseAndFall.java
	srcPath : /home/aryan/Dropbox/Documents from PC/free/jyoti-ranjan/test/RiseAndFall.java
	url : /home/aryan/Dropbox/Documents from PC/free/jyoti-ranjan/test/RiseAndFall.java
*/
import java.util.Scanner;

public class RiseAndFall {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int tc = sc.nextInt();
    while (tc > 0) {
      Boolean found = false;
      String s = sc.next();
      int n = s.length();

	  /**
	   * Logic : just start printing the same character
	   * as soon as you found a strict fall
	   * 
	   * if dont found any strict fall, print
	   * the original string
	   */

      for (int i = 1; i < n; i++) {
        if (Character.compare(s.charAt(i), s.charAt(i - 1)) < 0) {
          for (int j = 0; j < i; j++) {
            System.out.print(s.charAt(j));
          }
          for (int j = i; j < n; j++) {
            System.out.print(s.charAt(i));
          }
          System.out.println();
          found = true;
          break;
        }
      }
      if (found == false) {
        System.out.println(s);
      }
      tc--;
    }
    sc.close();
  }
}
