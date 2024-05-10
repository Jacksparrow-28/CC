import java.util.Scanner;
import static java.lang.System.out;

public class TestJNI {
    static {
        System.loadLibrary("cal");
    }

    private native int add(int n1, int n2);
    private native int sub(int n1, int n2);
    private native int mul(int n1, int n2);
    private native int div(int n1, int n2);
    private native String concatStrings(String str1, String str2);
    private native String substring(String str, int start, int end);
    private native int stringLength(String str);
    private native String toUpperCase(String str);

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        out.println("Simple Calculator and String Operations");
        int choice;
        TestJNI calc = new TestJNI();
        
        do {
            out.println("Enter Your choice");
            out.println("1. ADD\n2. SUB\n3. MUL\n4. DIV\n5. Concat Strings\n6. Substring\n7. String Length\n8. Uppercase\n0. Exit");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                case 2:
                case 3:
                case 4:
                    int b, c;
                    out.println("Enter first Number");
                    b = sc.nextInt();
                    out.println("Enter second Number");
                    c = sc.nextInt();
                    switch (choice) {
                        case 1:
                            out.println("Addition is = " + calc.add(b, c));
                            break;
                        case 2:
                            out.println("Subtraction is = " + calc.sub(b, c));
                            break;
                        case 3:
                            out.println("Multiplication is = " + calc.mul(b, c));
                            break;
                        case 4:
                            out.println("Division is = " + calc.div(b, c));
                            break;
                    }
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                    sc.nextLine(); // Consume newline character
                    out.println("Enter a String");
                    String str = sc.nextLine();
                    switch (choice) {
                        case 5:
                            out.println("Concatenated String = " + calc.concatStrings(str, sc.nextLine()));
                            break;
                        case 6:
                            out.println("Substring = " + calc.substring(str, sc.nextInt(), sc.nextInt()));
                            break;
                        case 7:
                            out.println("String Length = " + calc.stringLength(str));
                            break;
                        case 8:
                            out.println("Uppercase String = " + calc.toUpperCase(str));
                            break;
                    }
                    break;
                case 0:
                    break;
                default:
                    out.println("Invalid choice. Please enter a valid choice.");
                    break;
            }
        } while (choice != 0);

        sc.close();
    }
}
