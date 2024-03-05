package denemexxx;
import java.util.Scanner;
public class denemexxx {
	
	
	public static int tp1_1() {
		int sum=0;
		for(int i=19; i<=202; i+=3) {
			sum+=i;
		}
		return sum;
	}
	
	public static double tp1_2() {
		double sum=0.0;
		for(double i=1; i<Math.sqrt(Integer.MAX_VALUE); i++) {
			sum+=(1/(i*i));
		}
		return Math.sqrt(6*sum);
	}
	
	public static double tp1_3() {
		double sum=0.0;
		int fact = 1;
		for(int i=0; i<(32); i++) {
			
			if(i != 0) {
				fact*=i;
			}
			sum+=1.0/fact;
		}
		return (sum);
	}
	


	public static void tp1_4() {
	    for (int i = 1000; i < 10000; i++) {
	        int number = i;
	        int reverse = 0;
	        int original = i;
	
	        while (number != 0) {
	            int digit = number % 10;
	            reverse = reverse * 10 + digit;
	            number /= 10;
	        }
	
	        if (original == reverse) {
	            System.out.println(original);
	        }
	    }
	}
	
	public static void tp1_5() {
	    for (int i = 10000; i < 100000; i++) {
	        int number = i;
	        int reverse = 0;
	        int original = i;
	
	        while (number != 0) {
	            int digit = number % 10;
	            reverse = reverse * 10 + digit;
	            number /= 10;
	        }
	
	        if (original == reverse) {
	            System.out.println(original);
	        }
	    }
	}
	
	public static void tp1_6() {
		int count=0;
		for(int num=1000; num<10000; num++) {
			int lastDigit=num%10;
			int firstDigit=num/1000;
			if(firstDigit>lastDigit) {
				System.out.println(num);
				count++;
			}
		}
		System.out.print("Ilk rakami son rakamindan buyuk 4 basamakli sayilarin adedi: ");
		System.out.println(count);
	}
	
	public static void tp1_7() {
		int count=0;
		for(int num=100; num<1000; num++) {
			int lastDigit=num%10;
			int firstDigit=num/100;
			int middleDigit=num%100/10;
			if(middleDigit+firstDigit==lastDigit) {
				System.out.println(num);
				count++;
			}
		}
		System.out.print("Ilk iki rakami toplami son rakamina esit 3 basamakli sayilarin adedi: ");
		System.out.println(count);
	}
	
	public static void tp1_8(){
		int count=0;
		for(int num=100;num<1000;num+=2) {
			int lastDigit=num%10;
			int firstDigit=num/100;
			int middleDigit=num%100/10;
			if(firstDigit!=middleDigit && middleDigit!=lastDigit) {
				continue;
			}
			System.out.println(num);
			count++;
		}
		System.out.print("En az iki rakami birbirine esit 3 basamakli sayilarin adedi: ");
		System.out.println(count);
	}
	
	public static void tp1_9() {
		for(int num=1; num<909; num++) {
			
			int sumDigitValue = 0;
			int digit = (int)Math.log10(num)+1;
			for(int i=1; i<=digit; i++) {
				int digitValue = num % (int)Math.pow(10, i) / (int)Math.pow(10, i-1);
				sumDigitValue += digitValue;
			}
			if(sumDigitValue < 9) {
				System.out.print(num);
				System.out.print(" ");
			}
		}
	}
	
	public static void tp1_10() {
		int count=0;
		for(int num=10000; num<100000; num++) {
			int firstTwoDigits = num/1000;
			int lastTwoDigits = num%100;
			if(lastTwoDigits==firstTwoDigits) {
				System.out.println(num);
				count++;
			}
		}
		System.out.print("İlk iki rakami ile son iki rakami birbirine esit 5 basamakli sayilarin adedi: ");
		System.out.println(count);
	}
	
	public static int tp1_11() {
		int X=0;
		for(int i=1; i<125; i++) {
			if(125%i == 200%i && 200%i == 350%i) {
				X=i;
			}
		}
		return X;
	}
	
	public static void tp1_12() {
		int actualYear = 2024;
		for(int year=1900; year<actualYear; year++) {
			int sumofDigitValue=0;
			int tempYear=year;
			while(tempYear>0) {
				sumofDigitValue+=tempYear%10;
				tempYear/=10;
			}
			if(2005-year==sumofDigitValue) {
				System.out.println(year);
			}
		}
	}
	
	public static void tp1_13() {
		for(int a=10;a<100;a++) {
			for(int b=10;b<100;b++) {
				if(100*a+b==11*(a+b)) {
					System.out.printf("The numbers are %d, %d", a, b);
				}
			}
		}
	}
	
	public static int tp1_14() {
		int num = 121212;
		int[] multiplyArray = new int[1000];
		int count=0;
		for(int i=1; i<=(num); i++) {
			if(num%i==0) {
				multiplyArray[count] = i;
				count++;
			}
		}
		System.out.println(multiplyArray[count/2]);
		System.out.println(multiplyArray[count/2-1]);
		System.out.print("the difference is: ");
		return(multiplyArray[count/2]-multiplyArray[count/2-1]);
	}
	
	public static void tp1_15() {
		for(int num=10000;num<100000;num++) {
			boolean isPrime=true;
			for(int m=2; m<=(int)Math.sqrt(num); m++) {
				if(num%m==0) {
					isPrime=false;
				}
			}
			if(isPrime) {
				System.out.println(num);
			}
		}
	}
	
	public static boolean tp1_16() {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		for(int m=2; m<=(int)Math.sqrt(n); m++) {
			if(n%m==0) {
				return false;
			}
		}
		return true;
	}
	
	public static boolean tp1_17() {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		if(n<100 || n>=10000) {
			System.out.println("Lutfen 100 ile 9999 arasi sayi gir!");
			return false;
		}
		int number = n;
        int reverse = 0;
        int original = n;

        while (number != 0) {
            int digit = number % 10;
            reverse = reverse * 10 + digit;
            number /= 10;
        }

        if (original == reverse) {
            return true;
        }
        return false;
	}
	public static void main(String args[]) {
		boolean answer= tp1_17();
		System.out.println(answer);
	}
}
 