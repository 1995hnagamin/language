public class App {
	public static void main(String[] args) {
		int j;
		if (1 + 2 == 3) {
			j = 10;
		}
		System.out.println(j); // OK

		int i;
		if (condition()) {
			i = 10;
		}
		System.out.println(i); // error: variable i might not have been initialized
	}

	public static boolean condition() {
		return true;
	}
}
