package JavaCheatSheet;

import java.util.*;

class Reader {

    public void customInputReader() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLine();
        }
        scanner.close();
    
        System.out.println("n = " + n);
        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
    }

    public void fileReader() {
        // todo
    }
       
}

public class InputReader {
    public static void main(String[] args) {
        Reader reader = new Reader();

        reader.customInputReader();
        reader.fileReader();

    }
}
