/*
	group : local
	name : Source.java
	srcPath : /home/aryan/Dropbox/Documents from PC/free/yashashwini/Source.java
	url : /home/aryan/Dropbox/Documents from PC/free/yashashwini/Source.java
*/
import java.util.*;

public class Source{

	public static void  highestFeedback(int metlife[],int hardfort[],int size){
		for(int i=0;i<size;i++){
			if(metlife[i]>hardfort[i])System.out.println(metlife[i]);
			else System.out.println(hardfort[i]);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if(n<0){
			System.out.println("Invalid array size");
			sc.close();
			return;
		}
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i=0;i<n;i++){
			a[i] = sc.nextInt();
			if(a[i]<0){
				System.out.println("Invalid input");
				sc.close();;
				return;
			}
		}
		for(int i=0;i<n;i++){
			b[i] = sc.nextInt();
			if(b[i]<0){
				System.out.println("Invalid input");
				sc.close();;
				return;
			}
		}
		highestFeedback(a, b, n);
		sc.close();
	}
}