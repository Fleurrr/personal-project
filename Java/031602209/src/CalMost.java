import java.util.*;

public class CalMost {


    /**
     * @param map the HashMap contain words and amount
     * @return the top 10 amount of the words and amount in list
     */
    public List<Map.Entry<String, Integer>> mostWords(HashMap<String, Integer> map) {
        // convert HashMap to list
        List<Map.Entry<String, Integer>> list = new ArrayList<>(map.entrySet());
        // sort by value then by key
        list.sort(new MapComparator());
        return list.size() < 10 ? list.subList(0, list.size()) : list.subList(0, 10);
    }


    /**
     * This class define how to compare the element in list
     */
    private class MapComparator implements Comparator<Map.Entry<String, Integer>> {
        @Override
        public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
            return o1.getValue().compareTo(o2.getValue()) != 0 ? o1.getValue().compareTo(o2.getValue()) : o1.getKey().compareTo(o2.getKey());
        }
    }


    public static void main(String[] args) {

        HashMap<String, Integer> test = new HashMap<>();
        test.put("aaa1", 543);
        test.put("fshdi", 1343);
        test.put("fshda", 1343);
        test.put("hsdf31", 654);
        test.put("aaa2", 543);

        CalMost calMost = new CalMost();

        List<Map.Entry<String, Integer>> list = calMost.mostWords(test);
        list.forEach(System.out::println);
    }

}
