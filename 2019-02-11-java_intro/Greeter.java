public class Greeter {
	public static void main(String[] args) {
		System.out.print("Hello Java world from Mr/s");
		for(String arg : args)
		{
			System.out.print(String.format(" %s", arg));
		}

		System.out.println("");
	}
}
