public class App {
	public static void main(String[] args) {
		int[] a5050i = new int[func()];
		int[] a5i = { 1, 2, 3, 4, 5 };
		// a5i = { 6, 7, 8, 9, 10 }; - error: illegal start of expression
	}
	public static int func() {
		int sum = 0;
		for (int i = 0; i < 100; ++i) {
			sum += i;
		}
		return sum;
	}
}
