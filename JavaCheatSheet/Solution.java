package JavaCheatSheet;

import java.util.*;

class BasicCollections {
    BasicCollections() {
        List<Integer> list = new ArrayList<>(); // list.size() gives its size
        list.add(1);
        list.add(2);
        list.set(0, 0); // [1, 2] -> [0, 2] | Time Complexcity = O(1)
        list.add(3);                // [0, 2, 3]        | Time Complexcity = O(1) Can be O(n) when arrayList is full
        list.remove(0);         // [2, 3]           | Time Complexcity = O(n)
        System.out.println(list.get(1)); // 3
        
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
        // Reader reader = new Reader();

        BasicJava basicJava = new BasicJava();
        BasicCollections basicCollections = new BasicCollections();
    }
}
