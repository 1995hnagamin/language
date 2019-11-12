public class App {
	public static void main(String[] args) {
		int j = 10;
		if (condition) {
			j = 20;
		}
		System.out.println(j); // OK
		if (condition()) {
			j = 20;
		}
		System.out.println(j); // OK
	}

	public static boolean condition() {
		return true;
	}

	public static boolean condition = false;
}
