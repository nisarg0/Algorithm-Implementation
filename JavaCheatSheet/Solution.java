package JavaCheatSheet;

import java.util.*;
import java.util.stream.Stream;

// Streams are faster and can run parallely leading to better CPU utilization
// Chaining of operations helps save time
class BasicStreams {
    List<String> names = Arrays.asList("John", "Alice", "Bob", "Carol");
    List<String> filteredWords = names.stream()
                                  .map(String::toUpperCase)
                                  .filter(name -> name.startsWith("A"))
                                  .collect(Collectors.toList()); // Alice

    Optional<String> any = names.stream().findAny();
    Collections.sort(names, (s1, s2) -> s1.compareTo(s2));


    List<List<Integer>> numbers = Arrays.asList(Arrays.asList(1, 2), Arrays.asList(3, 4));
    List<Integer> flattenedList = numbers.stream()
                                        .flatMap(List::stream)
                                        .collect(Collectors.toList());
    // Output: [1, 2, 3, 4]


    // Identity is used inside reduce, basically it has its arg type and return type same
    Optional<Integer> sum = numbers.stream().reduce(Integer::sum); // sum = 15
    Optional<Integer> prod = numbers.stream().reduce((a,b) -> a*b); // prod = 120
    Optional<Integer> max = numbers.stream().reduce(Integer::max); // max = 5

    System.out.println("sum = " + sum.getOrDefault(0));

    // Stream.of() is used to create a stream from an array
    Stream<String> namesStream = Stream.of("John", "Alice", "Bob", "Carol");

}

class BasicCollections {
    BasicCollections() {
        List<Integer> list = new ArrayList<>(); // list.size() gives its size
        list.add(1);
        list.add(2);
        list.set(0, 0); // [1, 2] -> [0, 2] | Time Complexcity = O(1)
        list.add(3);                // [0, 2, 3]        | Time Complexcity = O(1) Can be O(n) when arrayList is full
        list.remove(0);         // [2, 3]           | Time Complexcity = O(n)
        System.out.println(list.get(1)); // 3
        
        Collections.sort(list);
        Collections.sort(list, Collections.reverseOrder());

        List<Integer> list2 = new LinkedList<>();
        
        Set<Integer> set = new HashSet<>();
        set.add(1);
        set.add(2);
        set.add(3);
        set.add(2);                   // [1, 2, 3]
        set.remove(3);                // [1, 2] | Time Complexcity = O(1) Will be O(log n) for TreeSet
        set.contains(1);              // true

        set.forEach( ele -> {
            System.out.println(ele);
        });

       /**
        * HashMap Details:
        * 1. Data is stored as Linked list in each bucket
        * 2. In case of high collision (TREEIFY_THRESHOLD, default is 8), it's converted to Red black tree
        * 3. Load Factor: (default 0.75) Number of entries in map if exceeds it, double the bucket count
        */
        HashMap<String, Integer> map = new HashMap<>();
        map.put("Nisarg", 1);
        map.put("Nikhil", 1);
        map.put("Nisarg", map.getOrDefault("Nisarg", 0) + 1);
        map.remove("Nisarg");       // [Nikhil] | Time Complexcity = O(1) Will be O(log n) for TreeMap
        map.get("Nisarg");          // 1        | Time Complexcity = O(1) Will be O(log n) for TreeMap
        
        for( Map.Entry<String, Integer> entry : map.entrySet() ) 
            System.out.println(entry.getKey() + " " + entry.getValue());

        map.forEach( (key, value) -> System.out.println(key + "=" + value) );
    }
}

class BasicJava {

    BasicJava() {
        int n = 10, m = 11;

        int maxVal = Math.max(n, m);
        int minVal = Math.min(n, m);

        int[] arr = new int[n]; // arr.length is its size
        int [] arrDeclared = {1,2,3,4,5,6,7,8,9};

        Arrays.sort(arr);
        Arrays.sort(arr, (a,b) -> b-a); // Sort in descending order

        int[][] arr2d = new int[n][m];
        int[][] arr2dDeclared = {{1,2,3},{4,5,6},{7,8,9}};

        Arrays.sort(arr2d);

        String str1 = "ABCDEF";
        char ch = str1.charAt(0); // A
        String str2 = str1.substring(2); // CDEF
        String str3 = str1.substring(2, 4); // CD
        str2 = str1+str3; //ABCDEFCD

    }
}


class Solution {
    public static void main(String[] args) {

        BasicJava basicJava = new BasicJava();
        BasicCollections basicCollections = new BasicCollections();
    }
}