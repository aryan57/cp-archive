/*
	group : local
	name : Q3.java
	srcPath : /home/aryan/Dropbox/Documents from PC/free/jyoti-ranjan/test/Q3.java
	url : /home/aryan/Dropbox/Documents from PC/free/jyoti-ranjan/test/Q3.java
*/
import java.util.Scanner;

public class Q3 {
	public static void main(String[] args) {
	
		Scanner sc = new Scanner(System.in);

		String p1 = sc.next();
		String p2 = sc.next();

		int ans=1;

		for(int i=0;i<4;i++){
			if(Character.compare(p1.charAt(i), p2.charAt(i))!=0){
				ans*=2;
			}
		}

		System.out.println(ans);

		sc.close();
	
	}
}
