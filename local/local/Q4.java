/*
	group : local
	name : Q4.java
	srcPath : /home/aryan/Dropbox/Documents from PC/free/jyoti-ranjan/test/Q4.java
	url : /home/aryan/Dropbox/Documents from PC/free/jyoti-ranjan/test/Q4.java
*/
import java.util.Scanner;

public class Q4 {
	
	public static void main(String[] args) {
	
		Scanner sc = new Scanner(System.in);

		int n=sc.nextInt();
		int x=sc.nextInt();
		int y=sc.nextInt();

		for(int i=0;i<n;i++){
			int a=sc.nextInt();
			System.out.println((a*y)/x);
		}

		sc.close();
	}
}
