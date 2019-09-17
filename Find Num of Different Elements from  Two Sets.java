package genesis;
import java.util.*; 
public class Genesis {
    public static void main(String[] args) {
        Set<Integer> a = new HashSet<Integer>(); 
        a.addAll(Arrays.asList(new Integer[] {1, 2, 3, 4})); 
        Set<Integer> b = new HashSet<Integer>(); 
        b.addAll(Arrays.asList(new Integer[] {1, 7, 5})); 
  
        // To find intersection 
        Set<Integer> intersection = new HashSet<Integer>(a); 
        intersection.retainAll(b); 
        System.out.print("Intersection of the two Set"); 
        System.out.println(intersection); 
        
        int res = a.size() + b.size() - intersection.size()*2;
        System.out.println("Number of Different Elements: " + res); 
    }
}
