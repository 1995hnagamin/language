public class App {
	public static void main(String[] args) {
		// byte b = 128; error: incompatible types: possible lossy conversion from int to byte
		byte b = 127;
		b += 1;
		System.out.println(b); // -128
	}
}
